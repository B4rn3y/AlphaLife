#include "..\..\script_macros.hpp"



private ["_display","_time","_listbox","_items","_items_sellable","_items_farm_and_sellble","_sell_price","_icon","_illegal","_ID"];
disableSerialization;
createDialog "player_inv_market";
waitUntil {!isNull (findDisplay 9001)};
_display = findDisplay 9001;
_time = _display displayCtrl 7858;
_time ctrlsettext format["%1:%2",systemtime select 3,systemtime select 4];
ctrlSetText[2009,format ["%1 / %2", life_carryWeight, life_maxWeight]];

_listbox = _display displayCtrl 1500;






_items = [];
{
	{_items pushBackUnique (_x select 0);} foreach (getArray(_x >> "MaterialsGive"));
} foreach ("true" configClasses(missionConfigFile >> "ProcessAction"));


_items_sellable = [];

{
	{_items_sellable pushBackUnique _x;} foreach (getArray(_x >> "items"));
} foreach ("true" configClasses(missionConfigFile >> "VirtualShops"));

_items_farm_and_sellble = [];
{
	if(_x in _items_sellable) then {
		_items_farm_and_sellble pushBackUnique _x;
	};
} foreach _items;

_items_farm_and_sellble pushBackUnique "turtle_raw";
_items_farm_and_sellble pushBackUnique "goldbar";

{
	_sell_price = getNumber(missionConfigFile >> "VirtualItems" >> _x >> "sellPrice");
	_name = localize getText (missionConfigFile >> "VirtualItems" >> _x >> "displayName");
	_icon = getText (missionConfigFile >> "VirtualItems" >> _x >> "icon");
	_illegal = if(getNumber(missionConfigFile >> "VirtualItems" >> _x >> "illegal") isEqualTo 1) then {true} else {false};

	_ID = _listbox lbadd _name;
	_listbox lbSetPicture[_ID,_icon];
	_listbox lbSetData[_ID,_x];

	if(_illegal) then {
		_listbox lbSetColor[_ID,[1,0,0,1]];
	};


} foreach _items_farm_and_sellble;

if!(_items_farm_and_sellble isEqualTo []) then {
	_listbox lbSetCurSel 0;
};