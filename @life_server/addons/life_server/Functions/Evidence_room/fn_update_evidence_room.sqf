
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





_goods_value = 0;
{
    _item = _x select 0;
    _amount = _x select 1;
    if!(gettext (missionConfigFile >> "VirtualItems" >> _item >> "processedItem") isEqualTo "") then {
        _item = gettext (missionConfigFile >> "VirtualItems" >> _item >> "processedItem");
    };
    _item_value = getNumber (missionConfigFile >> "VirtualItems" >> _item >> "sellPrice");
    if(_item_value > 0) then {
        _goods_value = _goods_value + (_item_value * _amount);
    };

} foreach ((evidence_box_0 getVariable["trunk",[[],0]]) select 0);

_markername = "evidence_room";
_markername setMarkerText format ["Asservatenkammer - Waffen: %1 - Theor. Warenwert: $%2", count (weaponCargo evidence_box_0),[_goods_value] call life_fnc_numbertext];