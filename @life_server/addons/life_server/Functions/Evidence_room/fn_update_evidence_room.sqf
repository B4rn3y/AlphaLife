
private ["_chest_id","_box","_containerID","_trunkData","_query","_vehItems","_vehMags","_vehWeapons","_vehBackpacks","_cargo"];

z_items = param[0,false,[false]];
_chest_id = param[1,-1,[-1]];

_box = missionNamespace getvariable[format["evidence_box_%1",_chest_id],-1];

if(isnil "_box") exitWith {};
if(isnull _box) exitWith {};
if((_box getvariable["evidence_chest",-1]) isEqualTo -1) exitWith {};
if!(_box getvariable["safe_open",false]) exitWith {};
_containerID = _box getVariable ["evidence_chest",-1];
if (_containerID isEqualTo -1) exitWith {}; //Dafuq?

if(z_items) then {
	_trunkData = _box getVariable ["Trunk",[[],0]];

	if (_containerID isEqualTo -1) exitWith {}; //Dafuq?

	_trunkData = [_trunkData] call DB_fnc_mresArray;
	_query = format ["UPDATE evidence_room SET inventory='%1' WHERE id='%2'",_trunkData,_containerID];

	[_query,1] call DB_fnc_asyncCall;
} else {
	_vehItems = getItemCargo _box;
	_vehMags = getMagazineCargo _box;
	_vehWeapons = getWeaponCargo _box;
	_vehBackpacks = getBackpackCargo _box;
	_cargo = [_vehItems,_vehMags,_vehWeapons,_vehBackpacks];

	_cargo = [_cargo] call DB_fnc_mresArray;

	_query = format ["UPDATE evidence_room SET gear='%1' WHERE id='%2'",_cargo,_containerID];

	[_query,1] call DB_fnc_asyncCall;
};





