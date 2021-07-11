#include "..\..\script_macros.hpp"
/*
    File: fn_gangNewLeader.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Something about being a quitter.
*/
private ["_unit","_unitID","_members","_action","_index"];
disableSerialization;

if ((lbCurSel 2621) isEqualTo -1) exitWith {hint localize "STR_GNOTF_TransferSelect"};
_unit_PID = CONTROL_DATA(2621);
_entry = [_unit_PID] call life_fnc_gang_find_member_entry;
if(_entry isEqualTo []) exitWith {hint "ERROR";};
if (_unit_PID == getplayeruid player) exitWith {hint localize "STR_GNOTF_TransferSelf"};
if!(getPlayerUID player isEqualTo ((group player) getvariable["gang_owner",""])) exitWith {hint "Du bist nicht der Leader"};
_action = [
    format [localize "STR_GNOTF_TransferMSG",_entry select 1],
    localize "STR_Gang_Transfer",
    localize "STR_Global_Yes",
    localize "STR_Global_No"
] call BIS_fnc_guiMessage;

if (_action) then {
    if (_unit_PID isEqualTo "") exitWith {hint localize "STR_GNOTF_badUID";}; //Unlikely?
    group player setVariable ["gang_owner",_unit_PID,true];
    _obj = [_unit_PID] call life_fnc_findPlayerOfPID;
    if!(isnull _obj) then {
        group player selectLeader _obj;
        [_obj,group player] remoteExec ["TON_fnc_clientGangLeader",_obj]; //Boot that bitch!
    };
    [1,format["%1 hat %2 zum neuen Gründer ernannt",profileName, _entry select 1]] remoteExec["life_fnc_gangUpdate_client",(group player)];
    if (life_HC_isActive) then {
        [3,group player,getPlayerUID player] remoteExec ["HC_fnc_updateGang",HC_Life]; //Update the database.
    } else {
        [3,group player,getPlayerUID player] remoteExec ["TON_fnc_updateGang",RSERV]; //Update the database.
    };

} else {
    hint localize "STR_GNOTF_TransferCancel";
};
[] call life_fnc_gangMenu;
