#include "..\..\script_macros.hpp"
/*
    File: fn_onTakeItem.sqf
    Author: Bryan "Tonic" Boardwine
    Description:
    Blocks the unit from taking something they should not have.
*/
private ["_unit","_item","_restrictedClothing","_restrictedWeapons"];
_unit = [_this,0,objNull,[objNull]] call BIS_fnc_param;
_container = [_this,1,objNull,[objNull]] call BIS_fnc_param;
_item = [_this,2,"",[""]] call BIS_fnc_param;

if (isNull _unit || _item isEqualTo "") exitWith {}; //Bad thingies?
_restrictedClothing = LIFE_SETTINGS(getArray,"restricted_uniforms");
_restrictedWeapons = LIFE_SETTINGS(getArray,"restricted_weapons");

switch (playerSide) do
{

};