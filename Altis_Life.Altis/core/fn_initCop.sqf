#include "..\script_macros.hpp"
/*
    File: fn_initCop.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Cop Initialization file.
*/
waitUntil {!(isNull (findDisplay 46))};

if (life_blacklisted) exitWith {
    ["Blacklisted",false,true] call BIS_fnc_endMission;
    sleep 30;
};

//if (!(str(player) in ["cop_1","cop_2","cop_3","cop_4"])) then {
if ((FETCH_CONST(life_coplevel) isEqualTo 0) && (FETCH_CONST(life_adminlevel) isEqualTo 0)) then {
    ["NotWhitelisted",false,true] call BIS_fnc_endMission;
    sleep 35;
};
//};

0 call life_fnc_copcallmanagement;

[] spawn life_fnc_init_exclusion_zones;

player setVariable ["rank",(FETCH_CONST(life_coplevel)),true];

(unitBackpack player) setObjectTextureGlobal [0, ""];

[] spawn life_fnc_spawnMenu;
waitUntil{!isNull (findDisplay 38500)}; //Wait for the spawn selection to be open.
waitUntil{isNull (findDisplay 38500)}; //Wait for the spawn selection to be done.
