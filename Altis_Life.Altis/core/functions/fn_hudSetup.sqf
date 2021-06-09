#include "..\..\script_macros.hpp"
/*
    File: fn_hudSetup.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Setups the hud for the player?
*/
disableSerialization;

cutRsc ["playerHUD", "PLAIN", 4, false];
_display = uiNamespace getvariable["playerHUD",displayNull];
if(isnull _display) exitWith {diag_log "ERROR - Creating HUD Display fn_hudSetup.sqf line 13"};
_h_f = _display displayCtrl 3200;
_h_e = _display displayCtrl 3201;
_F_f = _display displayCtrl 3202;
_F_e = _display displayCtrl 3203;
_W_f = _display displayCtrl 3204;
_W_e = _display displayCtrl 3205;

{
    _x progressSetPosition 1;
} foreach [_h_f,_h_e,_F_f,_F_e,_W_f,_W_e];

[] call life_fnc_hudUpdate;

[] spawn
{
    private ["_dam"];
    for "_i" from 0 to 1 step 0 do {
        _dam = damage player;
        waitUntil {!((damage player) isEqualTo _dam)};
        [] call life_fnc_hudUpdate;
    };
};
