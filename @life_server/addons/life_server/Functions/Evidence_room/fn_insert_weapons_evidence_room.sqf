
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