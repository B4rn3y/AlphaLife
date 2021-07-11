#include "..\..\script_macros.hpp"
/*
    File: fn_gangLeave.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    32 hours later...
*/
private ["_unitID ","_members"];
if (getPlayerUID player isEqualTo (group player getVariable "gang_owner")) exitWith {hint localize "STR_GNOTF_LeaderLeave"};

_unitID = getPlayerUID player;
_members = group player getVariable "gang_members";
if (isNil "_members") exitWith {};
if (!(_members isEqualType [])) exitWith {};

_index = -1;
{
	if((_x select 2) isEqualTo _unitID) exitWith {_index = _foreachindex};
} foreach _members;
if(_index isEqualTo -1) exitWith {};

_members deleteAt _index;
group player setVariable ["gang_members",_members,true];
[0,format["%1 hat die Gang verlassen",profileName]] remoteExec["life_fnc_gangUpdate_client",(group player)];


if (life_HC_isActive) then {
    [6,group player,_unitID] remoteExec ["HC_fnc_updateGang",HC_Life]; //Update the database.
} else {
    [6,group player,_unitID] remoteExec ["TON_fnc_updateGang",RSERV]; //Update the database.
};

[player,group player] remoteExec ["TON_fnc_clientGangLeft",player];

closeDialog 0;
