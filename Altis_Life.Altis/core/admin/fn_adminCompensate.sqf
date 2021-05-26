#include "..\..\script_macros.hpp"
/*
    File: fn_adminCompensate.sqf
    Author: ColinM9991

    Description:
    Figure it out.
*/
private ["_value","_action"];
if (FETCH_CONST(life_adminlevel) < 1) exitWith {closeDialog 0; hint localize "STR_ANOTF_ErrorLevel";};

_obj = param[0,"",[""]];
if(_obj isEqualTo "") exitWith {

    _value = parseNumber(ctrlText 9922);
    if (_value < 0) exitWith {};
    if (_value > 999999) exitWith {hint localize "STR_ANOTF_Fail"};

    _action = [
        format [localize "STR_ANOTF_CompWarn",[_value] call life_fnc_numberText],
        localize "STR_Admin_Compensate",
        localize "STR_Global_Yes",
        localize "STR_Global_No"
    ] call BIS_fnc_guiMessage;

    if (_action) then {
        CASH = CASH + _value;
        [format [localize "STR_ANOTF_Success",[_value] call life_fnc_numberText]] spawn life_fnc_exp_hint;
        closeDialog 0;
    } else {
        hint localize "STR_NOTF_ActionCancel";
        closeDialog 0;
    };
};

_obj = call compile format ["%1", _obj];
if(isnil "_obj") exitWith {["ERROR: Player nicht gefunden"] spawn life_fnc_exp_hint};
if(isnull _obj) exitWith {["ERROR: Player nicht gefunden"] spawn life_fnc_exp_hint};
_value = parseNumber(ctrlText 9922);
if (_value < 0) exitWith {};
if (_value > 999999) exitWith {hint localize "STR_ANOTF_Fail"};

_action = [
    format [localize "STR_ANOTF_CompWarn",[_value] call life_fnc_numberText],
    localize "STR_Admin_Compensate",
    localize "STR_Global_Yes",
    localize "STR_Global_No"
] call BIS_fnc_guiMessage;

if (_action) then {
    [_obj,_value,player] remoteExecCall ["life_fnc_receiveMoney",_obj];
    [format ["Du hast %2 %1$ gegeben",[_value] call life_fnc_numberText, name _obj]] spawn life_fnc_exp_hint;
    closeDialog 0;
} else {
    [localize "STR_NOTF_ActionCancel"] spawn life_fnc_exp_hint;
    closeDialog 0;
};
