#include "..\..\script_macros.hpp"



private ["_display","_time","_listbox","_str_text","_cur_sel","_item_name","_data","_displayname","_sell_price","_icon","_illegal","_find_items_needed_to_craft","_ret","_cur_config","_items","_item_circle","_needed_items","_string","_foreachindex","_arr","_dealers","_dealer"];


_display = findDisplay 9001;

if(isnull _display) exitWith {};

_time = _display displayCtrl 7858;
_time ctrlsettext format["%1:%2",systemtime select 3,systemtime select 4];
ctrlSetText[2009,format ["%1 / %2", life_carryWeight, life_maxWeight]];

_listbox = _display displayCtrl 1500;
_str_text = _display displayCtrl 1100;

_cur_sel = lbCurSel _listbox;

if(_cur_sel isEqualTo -1) exitWith {};

_item_name = _listbox lbData _cur_sel;

if(_data isEqualTo "") exitWith {};


_displayname = localize getText (missionConfigFile >> "VirtualItems" >> _item_name >> "displayName");
_sell_price = getNumber(missionConfigFile >> "VirtualItems" >> _item_name >> "sellPrice");
_icon = getText (missionConfigFile >> "VirtualItems" >> _item_name >> "icon");
_illegal = if(getNumber(missionConfigFile >> "VirtualItems" >> _item_name >> "illegal") isEqualTo 1) then {true} else {false};


_find_items_needed_to_craft =
{
	_ret = [];
	{
		_cur_config = _x;
		{
			if((_x select 0) in _this) then {
				{_ret pushback (_x select 0);} foreach (getarray(_cur_config >> "MaterialsReq"));
			};

		} foreach (getArray(_x >> "MaterialsGive"));
	} foreach ("true" configClasses(missionConfigFile >> "ProcessAction"));
	_ret;
};

_items = [_item_name];
_item_circle = [_item_name];
while{true} do {
	_needed_items = _items call _find_items_needed_to_craft;
	if(_needed_items isEqualTo []) exitWith {};
	_item_circle pushBack _needed_items;
	_items = _needed_items;

};

reverse _item_circle;
_string = format["<br/><t align='center' size='1.4'>%1$</t><br/><t align='center' color='%3' size='1.1'>%2</t><br/><br/><t align='center' size='1.2'>Farmrouten:</t><br/>",[_sell_price] call life_Fnc_numbertext,if(_illegal) then {"Illegal"} else{"Legal"},if(_illegal) then {"#ff0000"} else{"#08FF00"}];


{
	if(typeName _x isEqualTo "ARRAY") then {
		if!(count _x > 1) then {
			if(_foreachindex isEqualTo 0) then {
				_string = _string + format["<img image='%1'/> %2",getText (missionConfigFile >> "VirtualItems" >> (_x select 0) >> "icon"),localize getText (missionConfigFile >> "VirtualItems" >> (_x select 0) >> "displayName")];
			} else {
				_string = _string + format["  >>  <img image='%1'/> %2",getText (missionConfigFile >> "VirtualItems" >> (_x select 0) >> "icon"),localize getText (missionConfigFile >> "VirtualItems" >> (_x select 0) >> "displayName")];
			};
		} else {
			if!(_foreachindex isEqualTo 0) then {
				_string = _string + "  >>  ";
			};
			_arr = _x;
			{
				if(((count _arr) -1) isEqualTo _foreachindex) then {
					_string = _string + format["<img image='%1'/> %2",getText (missionConfigFile >> "VirtualItems" >> _x >> "icon"),localize getText (missionConfigFile >> "VirtualItems" >> _x >> "displayName")];
				} else {
					_string = _string + format["<img image='%1'/> %2/",getText (missionConfigFile >> "VirtualItems" >> _x >> "icon"),localize getText (missionConfigFile >> "VirtualItems" >> _x >> "displayName")];
				};
			} foreach _arr;
		};
	} else {
		if(_foreachindex isEqualTo 0) then {
				_string = _string + format["<img image='%1'/> %2",getText (missionConfigFile >> "VirtualItems" >> _x >> "icon"),localize getText (missionConfigFile >> "VirtualItems" >> _x >> "displayName")];
			} else {
				_string = _string + format["  >>  <img image='%1'/> %2",getText (missionConfigFile >> "VirtualItems" >> _x >> "icon"),localize getText (missionConfigFile >> "VirtualItems" >> _x >> "displayName")];
			};
	};
} foreach _item_circle;


_dealers = [];
{
	_dealer = localize getText(_x >> "name");
	if(_item_name in getArray(_x >> "items")) then {
		_dealers pushBackUnique localize getText(_x >> "name");
	};
} foreach ("true" configClasses(missionConfigFile >> "VirtualShops"));

_string = _string + " >>  ";


{
	if((count _dealers - 1) isEqualTo _foreachindex) then {
		_string = _string + format["<img image='%1'/> %2","icons\ico_dealer.paa",_x];
	} else {
		_string = _string + format["<img image='%1'/> %2/","icons\ico_dealer.paa",_x];
	};
} foreach _dealers;


_str_text ctrlSetStructuredText parseText _string;

