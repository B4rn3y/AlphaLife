/*
    File: fn_spawnPointSelected.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Sorts out the spawn point selected and does a map zoom.
*/
disableSerialization;
private ["_control","_selection","_spCfg","_sp"];
_control = [_this,0,controlNull,[controlNull]] call BIS_fnc_param;
_selection = [_this,1,0,[0]] call BIS_fnc_param;

_display = findDisplay 38500;
_spawn_btn = _display displayCtrl 7755;

_spawn_btn ctrlEnable true;


_spCfg = [playerSide] call life_fnc_spawnPointCfg;
_sp = _spCfg select _selection;
//[((findDisplay 38500) displayCtrl 38502),1,0.1,getMarkerPos (_sp select 0)] call life_fnc_setMapPosition;
life_spawn_point = _sp;




//[getMarkerPos (_sp select 0),75,75,25,0.1,"LIFE_SpawnMenu_Showcase",true] spawn life_Fnc_circleCamera3D;
cutText ["", "BLACK OUT"];
life_cam_shop_3D_pos = getMarkerPos (_sp select 0);

uisleep 1.3;

cutText ["", "PLAIN", 2];