#include "..\..\script_macros.hpp"
/*
    File: fn_hudUpdate.sqf
    Author: Daniel Stuart

    Description:
    Updates the HUD when it needs to.
*/
disableSerialization;

private ["_display","_h_f","_h_e","_F_f","_F_e","_W_f","_W_e","_progressbar","_text_in_progressbar","_LVL_ANZEIGE","_earplugs","_control_full","_control_empty","_value","_pos_f"];


_display = uiNamespace getvariable["playerHUD",displayNull];
if(isnull _display) exitWith {[] call life_fnc_hudSetup;};
_h_f = _display displayCtrl 3200;
_h_e = _display displayCtrl 3201;
_F_f = _display displayCtrl 3202;
_F_e = _display displayCtrl 3203;
_W_f = _display displayCtrl 3204;
_W_e = _display displayCtrl 3205;



_progressbar = _display displayCtrl 1100;
_text_in_progressbar = _display displayCtrl 1099;
_LVL_ANZEIGE = _display displayCtrl 1101;
_progressbar progressSetPosition (if(ALPHA_XP_CUR_LEVEL isEqualTo 0 || ALPHA_XP_TONXT_LEVEL isEqualTo 0 || ALPHA_XP_FOR_THIS_LEVEL isEqualTo 0) then {0} else {ALPHA_XP_CUR_LEVEL/ALPHA_XP_FOR_THIS_LEVEL});
_text_in_progressbar ctrlSetStructuredText parsetext format["<t size='1.0' align='center'>%1 / %2</t>",ALPHA_XP_CUR_LEVEL,ALPHA_XP_FOR_THIS_LEVEL];
_LVL_ANZEIGE ctrlSetStructuredText parsetext format["<t size='0.9' align='center'>%1</t>",alpha_lvl];

_earplugs = _display displayCtrl 3000;

if(life_fadeSound isEqualTo 0) then {
	_earplugs ctrlShow false;
} else {
	_earplugs ctrlShow true;
};



{
	_control_full = _x select 0;
	_control_empty = _x select 1;
	_value = (_x select 2)/100;
	_control_empty progressSetPosition (1-_value);
	_pos_f = ctrlPosition _control_full; // [x, y, w, h]
	_control_empty ctrlSetPosition[_pos_f select 0,(_pos_f select 1)-((_pos_f select 3)*_value),_pos_f select 2, _pos_f select 3];
	_control_empty ctrlCommit 0;
} foreach
[
	[_h_f,_h_e,((1 - damage player) *100)],
	[_F_f,_F_e,life_hunger],
	[_W_f,_W_e,life_thirst]
];

