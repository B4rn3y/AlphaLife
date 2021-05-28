
private ["_weapons_items_magazines","_backpacks","_vehItems","_vehMags","_vehWeapons","_vehBackpacks","_cargo","_query"];

_weapons_items_magazines = param[0,[],[[]]];
_backpacks = param[1,[],[[]]];

if(_weapons_items_magazines isEqualTo [] && _backpacks isEqualTo []) exitWith {};

if(isnil "evidence_box_0") exitWith {};
if(isnull evidence_box_0) exitWith {};
if((evidence_box_0 getvariable["evidence_chest",-1]) isEqualTo -1) exitWith {};
if(evidence_box_0 getvariable["safe_open",false]) exitWith {};

{
	evidence_box_0 addItemCargoGlobal[_x,1];
} foreach _weapons_items_magazines;

{
	evidence_box_0 addBackpackCargoGlobal[_x,1];
} foreach _backpacks;


_vehItems = getItemCargo evidence_box_0;
_vehMags = getMagazineCargo evidence_box_0;
_vehWeapons = getWeaponCargo evidence_box_0;
_vehBackpacks = getBackpackCargo evidence_box_0;
_cargo = [_vehItems,_vehMags,_vehWeapons,_vehBackpacks];

_cargo = [_cargo] call DB_fnc_mresArray;

_query = format ["UPDATE evidence_room SET gear='%1' WHERE id='%2'",_cargo,(evidence_box_0 getvariable["evidence_chest",-1])];

[_query,1] call DB_fnc_asyncCall;