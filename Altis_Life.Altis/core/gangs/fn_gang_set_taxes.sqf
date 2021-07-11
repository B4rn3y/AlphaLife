#include "..\..\script_macros.hpp"

private ["_max_percentage","_display","_edit","_percentage"];
_max_percentage = 50;
_display = findDisplay 84785;

_edit = _display displayCtrl 1400;


_percentage = ctrlText _edit;

if(_percentage isEqualTo "") exitWith {["Du hast Nichts eingegeben"] spawn life_fnc_exp_hint;};


if!([_percentage] call TON_fnc_isNumber) exitWith {["Du musst eine Zahl eingeben (Ich hasse dich)"] spawn life_fnc_exp_hint;};


_percentage = parseNumber _percentage;


if(_percentage < 0 || _percentage > _max_percentage) exitWith {[format["Die Steuern dürfen nur zwischen 0%1 und %2%1 sein","%",_max_percentage]] spawn life_fnc_exp_hint;};


(group player) setVariable["gang_tax",_percentage,true];
[4,"Der Gründer hat die Gang-Steuern geändert"] remoteExec["life_fnc_gangUpdate_client",(group player)];


if (life_HC_isActive) then {
    [9,group player] remoteExec ["HC_fnc_updateGang",HC_Life]; //Update the database.
} else {
    [9,group player] remoteExec ["TON_fnc_updateGang",RSERV]; //Update the database.
};


closeDialog 84785;