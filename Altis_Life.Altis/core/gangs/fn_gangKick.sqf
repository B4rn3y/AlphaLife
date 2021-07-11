#include "..\..\script_macros.hpp"
/*
    File: fn_gangKick.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Kicks a player from your gang.
*/
private ["_unit","_unitID","_members"];
disableSerialization;

if ((lbCurSel 2621) isEqualTo -1) exitWith {hint localize "STR_GNOTF_SelectKick"};
_unitID = CONTROL_DATA(2621);

if (_unitID == getPlayerUID player) exitWith {hint localize "STR_GNOTF_KickSelf"};


if(_unitID isEqualTo ((group player) getVariable["gang_owner",""])) exitWith {["Den Leader kann man nicht kicken"] spawn life_fnc_exp_hint;};

_members = group player getVariable "gang_members";
if (isNil "_members") exitWith {};
if (!(_members isEqualType [])) exitWith {};

_index = -1;
{
	if((_x select 2) isEqualTo _unitID) exitWith {_index = _foreachindex};
} foreach _members;
if(_index isEqualTo -1) exitWith {};
_name_kicked = ((_members select _index) select 1);

_members deleteAt _index;
group player setVariable ["gang_members",_members,true];



_obj = [_unitID] call life_fnc_findPlayerOfPID;
if!(isnull _obj) then {
    [_obj,group player] remoteExec ["TON_fnc_clientGangKick",_obj]; //Boot that bitch!
};

if (life_HC_isActive) then {
    [6,group player,_unitID] remoteExec ["HC_fnc_updateGang",HC_Life]; //Update the database.
} else {
    [6,group player,_unitID] remoteExec ["TON_fnc_updateGang",RSERV]; //Update the database.
};

[0,format ["%1 wurde von %1 aus der Gang gekickt",_name_kicked, profileName]] remoteExec["life_fnc_gangUpdate_client",(group player)];

[] call life_fnc_gangMenu;
