#include "..\..\script_macros.hpp"
/*
    File: fn_gather.sqf
    Author: Devilfloh

    Description:
    Main functionality for gathering.
*/
private ["_maxGather","_resource","_amount","_maxGather","_requiredItem"];
if (life_action_inUse) exitWith {};
if !(isNull objectParent player) exitWith {};
if (player getVariable "restrained") exitWith {hint localize "STR_NOTF_isrestrained";};
if (player getVariable "playerSurrender") exitWith {hint localize "STR_NOTF_surrender";};

life_action_gathering = true;

life_action_inUse = true;
_zone = "";
_requiredItem = "";
_exit = false;

_resourceCfg = missionConfigFile >> "CfgGather" >> "Resources";
for "_i" from 0 to count(_resourceCfg)-1 do {

    _curConfig = _resourceCfg select _i;
    _resource = configName _curConfig;
    _maxGather = getNumber(_curConfig >> "amount");
    _zoneSize = getNumber(_curConfig >> "zoneSize");
    _resourceZones = getArray(_curConfig >> "zones");
    _requiredItem = getText(_curConfig >> "item");
    {
        if ((player distance (getMarkerPos _x)) < _zoneSize) exitWith {_zone = _x;};
    } forEach _resourceZones;

    if (_zone != "") exitWith {};
};

if (_zone isEqualTo "") exitWith {life_action_inUse = false; life_action_gathering = false;};

if (_requiredItem != "") then {
    _valItem = missionNamespace getVariable "life_inv_" + _requiredItem;

    if (_valItem < 1) exitWith {
        switch (_requiredItem) do {
         //Messages here
        };
        life_action_inUse = false;
        life_action_gathering = false;
        _exit = true;
    };
};

if (_exit) exitWith {life_action_inUse = false;life_action_gathering = false;};

_pos = getposatl player;

While{True} do {
    if((getPosATL player) distance _pos > 0.5) exitWith {};

    _amount = round(random(_maxGather)) + 1;
    _diff = [_resource,_amount,life_carryWeight,life_maxWeight] call life_fnc_calWeightDiff;
    if (_diff isEqualTo 0) exitWith {
        hint localize "STR_NOTF_InvFull";
        life_action_inUse = false;
        life_action_gathering = false;
    };

    switch (_requiredItem) do {
        case "pickaxe": {[player,"mining",35,1] remoteExecCall ["life_fnc_say3D",RCLIENT]};
        default {[player,"harvest",35,1] remoteExecCall ["life_fnc_say3D",RCLIENT]};
    };

    for "_i" from 0 to 4 do {
        if(surfaceIsWater (visiblePositionASL player)) then {
            if((getPosATL player) distance _pos > 0.5) exitWith {};
            sleep 0.85;
        } else {
            player playMoveNow "AinvPercMstpSnonWnonDnon_Putdown_AmovPercMstpSnonWnonDnon";
            waitUntil{animationState player != "AinvPercMstpSnonWnonDnon_Putdown_AmovPercMstpSnonWnonDnon";};
            if((getPosATL player) distance _pos > 0.5) exitWith {};
            sleep 0.5;
        };
    };
    if((getPosATL player) distance _pos > 0.5) exitWith {};
    if !([true,_resource,_diff] call life_fnc_handleInv) exitWith {};

    if(_resource isEqualTo "unwashed_uran" && !(31 in alpha_quests)) then {
        [31] spawn life_fnc_quest_achieved;
    };

    sleep 1;
};

life_action_inUse = false;
life_action_gathering = false;
