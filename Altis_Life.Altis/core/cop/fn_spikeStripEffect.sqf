/*
    File: fn_spikeStripEffect.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Doesn't work without the server-side effect but shifted part of it clientside
    so code can easily be changed. Ultimately it just pops the tires.
*/
private ["_vehicle"];
_vehicle = [_this,0,objNull,[objNull]] call BIS_fnc_param;
if (isNull _vehicle) exitWith {}; //Bad vehicle type

_vehicle setHitPointDamage["HitLFWheel",1];
_vehicle setHitPointDamage["HitRFWheel",1];


if(((driver _vehicle) isEqualTo player) && !(29 in alpha_quests)) then {
	[29] spawn life_fnc_quest_achieved;
};