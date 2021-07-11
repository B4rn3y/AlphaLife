#include "..\..\script_macros.hpp"

private ["_add","_display","_lb","_index","_data","_pid","_vid","_gang_id","_index_vehicles","_foreachindex","_cur_entry"];

_add = param[0,false,[false]];

_display = findDisplay 2800;
_lb = _display displayCtrl 2802;

_index = lbCurSel 2802;
if (_index isEqualTo -1) exitWith {hint localize "STR_Global_NoSelection"};
_data = lbData[2802,_index];
_data = (call compile format ["%1",_data]);
_pid = _data select 10;
_vid = lbValue[2802,_index];

if(_vid isEqualTo -1 || !(_pid isEqualTo getPlayerUID player) || isnil "life_vehicles_garage_save") exitWith {};
if(life_vehicles_garage_save isEqualTo []) exitWith {};

_gang_id = if(_add) then {(group player) getVariable["gang_id",-1]} else {-1};

if(_add && _gang_id isEqualTo -1) exitWith {};

_lb lbDelete _index;


_index_vehicles = -1;
{
    if((_x select 0) isEqualTo _vid) exitWith {_index_vehicles = _foreachindex;};
} foreach life_vehicles_garage_save;

if!(_index_vehicles isEqualTo -1) then {
    _cur_entry = life_vehicles_garage_save select _index_vehicles;
    if(_add) then {
        _cur_entry set[15,_gang_id];
    } else {
        _cur_entry set[15,-1];
    };
    life_vehicles_garage_save set[_index_vehicles,_cur_entry];
};

if (life_HC_isActive) then {
    [_vid,_pid,_gang_id] remoteExec ["HC_fnc_garage_set_gang",HC_Life];
} else {
    [_vid,_pid,_gang_id] remoteExec ["TON_fnc_garage_set_gang",RSERV];
};