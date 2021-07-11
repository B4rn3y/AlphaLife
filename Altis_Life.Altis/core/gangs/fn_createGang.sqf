#include "..\..\script_macros.hpp"
/*
    File: fn_createGang.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Pulls up the menu and creates the gang with the name the user enters in.
*/
private ["_display","_btn_create","_btn_join_gang","_edit_gang_tag","_gangName","_length","_chrByte","_allowed","_badChar","_gang_tag"];
disableSerialization;
_display = findDisplay 2520;
_btn_create = _display displayCtrl 5555;
_btn_join_gang = _display displayCtrl 2401;
_edit_gang_tag = _display displayCtrl 1401;
_gangName = ctrlText (CONTROL(2520,2522));
_length = count (toArray(_gangName));
_chrByte = toArray (_gangName);
if(_gangName isEqualTo "") exitWith {["Du hast keinen Gangnamen eingegeben."] spawn life_fnc_exp_hint;};
_allowed = toArray("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_ ");
if (_length > 32) exitWith {hint localize "STR_GNOTF_Over32"};
_badChar = false;
{if (!(_x in _allowed)) exitWith {_badChar = true;};} forEach _chrByte;
if (_badChar) exitWith {hint localize "STR_GNOTF_IncorrectChar";};

_gang_tag = ctrlText _edit_gang_tag;
_length = count (toArray(_gang_tag));
_chrByte = toArray (_gang_tag);
_allowed = toArray("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_ ");
if(_gang_tag isEqualTo "") exitWith {["Du hast keinen Gang-Tag eingegeben."] spawn life_fnc_exp_hint;};
if (_length > 4) exitWith {["Tags dürfen maximal 4 Zeichen lang sein"] spawn life_fnc_exp_hint;};
_badChar = false;
{if (!(_x in _allowed)) exitWith {_badChar = true;};} forEach _chrByte;
if (_badChar) exitWith {["Du hast ein nicht erlaubtes Zeichen in deinem Gang Tag"] spawn life_fnc_exp_hint;};


if (BANK < (LIFE_SETTINGS(getNumber,"gang_price"))) exitWith {hint format [localize "STR_GNOTF_NotEnoughMoney",[((LIFE_SETTINGS(getNumber,"gang_price")) - BANK)] call life_fnc_numberText];};

if (life_HC_isActive) then {
    [player,getPlayerUID player,_gangName,_gang_tag] remoteExec ["HC_fnc_insertGang",HC_Life];
} else {
    [player,getPlayerUID player,_gangName,_gang_tag] remoteExec ["TON_fnc_insertGang",RSERV];
};


if (LIFE_SETTINGS(getNumber,"player_advancedLog") isEqualTo 1) then {
    if (LIFE_SETTINGS(getNumber,"battlEye_friendlyLogging") isEqualTo 1) then {
        advanced_log = format [localize "STR_DL_AL_createdGang_BEF",_gangName,(LIFE_SETTINGS(getNumber,"gang_price"))];
    } else {
        advanced_log = format [localize "STR_DL_AL_createdGang",profileName,(getPlayerUID player),_gangName,(LIFE_SETTINGS(getNumber,"gang_price"))];
    };
    publicVariableServer "advanced_log";
};

[localize "STR_NOTF_SendingData"] spawn life_fnc_exp_hint;
closeDialog 0;
life_action_gangInUse = true;
