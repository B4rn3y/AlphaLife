#include "..\..\script_macros.hpp"
/*
    File: fn_receiveMoney.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Receives money
*/

params [
    ["_unit","",[""]],
    ["_val","",[""]],
    ["_from",objNull,[objNull]]
];

if (_unit isEqualTo "" || isNull _from || _val isEqualTo "") exitWith {};
if !((getplayeruid player) isEqualTo _unit) exitWith {};
if (!([_val] call TON_fnc_isnumber)) exitWith {};

hint format [localize "STR_NOTF_GivenMoney",_from getVariable ["realname",name _from],[(parseNumber (_val))] call life_fnc_numberText];
CASH = CASH + parseNumber(_val);
[0] call SOCK_fnc_updatePartial;