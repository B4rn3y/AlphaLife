


private ["_items","_trunk","_trunk_items","_trunk_weight","_item_name","_item_value","_itemWeight","_index","_trunkData","_query"];
_items = param[0,[],[[]]];  // like this [["apple",1],["copper",2]]

if(_items isEqualTo []) exitWith {};

if(isnil "evidence_box_0") exitWith {};
if(isnull evidence_box_0) exitWith {};
if((evidence_box_0 getvariable["evidence_chest",-1]) isEqualTo -1) exitWith {};
if(evidence_box_0 getvariable["safe_open",false]) exitWith {};




_trunk = evidence_box_0 getvariable["trunk",[[],0]];
_trunk_items = _trunk select 0;
_trunk_weight = _trunk select 1;

{
	_item_name = _x select 0;
	_item_value = _x select 1;
	_itemWeight = ([_item_name] call life_fnc_itemWeight) * _item_value;
	_index = [_item_name, _trunk_items] call TON_fnc_index;
	if(_index isEqualTo -1) then {
		_trunk_items pushBack _x;
	} else {
        _trunk_items set[_index,[_item_name,((_trunk_items select _index) select 1) + _item_value]];
	};
	_trunk_weight = _trunk_weight + _itemWeight;

} foreach _items;

evidence_box_0 setvariable["trunk",[_trunk_items,_trunk_weight],true];


_trunkData = [(evidence_box_0 getVariable["trunk",[[],0]])] call DB_fnc_mresArray;
_query = format ["UPDATE evidence_room SET inventory='%1' WHERE id='%2'",_trunkData,(evidence_box_0 getvariable["evidence_chest",-1])];

[_query,1] call DB_fnc_asyncCall;



