#include "..\..\script_macros.hpp"
/*
    File: fn_demoChargeTimer.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Starts the "Demo" timer for the police.
*/
private ["_evidence_room","_vault","_uiDisp","_timer","_time"];
_evidence_room = param[0,false,[false]];
_vault = fed_bank;
if(_evidence_room) then {_vault = evidence_box_0};
disableSerialization;
"lifeTimer" cutRsc ["life_timer","PLAIN"];
_uiDisp = uiNamespace getVariable "life_timer";
_timer = _uiDisp displayCtrl 38301;
_time = time + (5 * 60);

for "_i" from 0 to 1 step 0 do {
    if (isNull _uiDisp) then {
        "lifeTimer" cutRsc ["life_timer","PLAIN"];
        _uiDisp = uiNamespace getVariable "life_timer";
        _timer = _uiDisp displayCtrl 38301;
    };
    if (round(_time - time) < 1) exitWith {};
    if (!(_vault getVariable ["chargeplaced",false])) exitWith {};
    _timer ctrlSetText format ["%1",[(_time - time),"MM:SS.MS"] call BIS_fnc_secondsToString];
    sleep 0.08;
};
"lifeTimer" cutText["","PLAIN"];