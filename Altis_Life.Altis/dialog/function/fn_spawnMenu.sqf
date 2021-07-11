/*
    File: fn_spawnMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Initializes the spawn point selection menu.
*/
private ["_spCfg","_sp","_ctrl"];
disableSerialization;

if (life_is_arrested) exitWith {
    [] call life_fnc_respawned;
};

if (life_respawned) then {
    [] call life_fnc_respawned;
};
cutText["","BLACK FADED"];
0 cutFadeOut 9999999;
if (!(createDialog "life_spawn_selection")) exitWith {[] call life_fnc_spawnMenu;};
(findDisplay 38500) displaySetEventHandler ["keyDown","_this call life_fnc_displayHandler"];

_display = findDisplay 38500;
_spawn_btn = _display displayCtrl 7755;

_spawn_btn ctrlEnable false;


_spCfg = [playerSide] call life_fnc_spawnPointCfg;

_ctrl = ((findDisplay 38500) displayCtrl 38510);
{
    _ctrl lnbAddRow[(_spCfg select _ForEachIndex) select 1,(_spCfg select _ForEachIndex) select 0,""];
    _ctrl lnbSetPicture[[_ForEachIndex,0],(_spCfg select _ForEachIndex) select 2];
    _ctrl lnbSetData[[_ForEachIndex,0],(_spCfg select _ForEachIndex) select 0];
} forEach _spCfg;


_spCfg = [playerSide] call life_fnc_spawnPointCfg;
_sp = _spCfg select 0;




LIFE_SpawnMenu_Showcase = true;
[getMarkerPos (_sp select 0),75,75,25,0.1,"LIFE_SpawnMenu_Showcase"] spawn life_Fnc_circleCamera3D;

waitUntil {isnull(findDisplay 38500);};
LIFE_SpawnMenu_Showcase = nil;