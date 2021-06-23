#include "..\..\script_macros.hpp"
/*
    File: fn_keyGive.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Gives a copy of the key for the selected vehicle to the selected player.
    Player must be within range.
*/
private ["_dialog","_list","_plist","_sel","_vehicle","_exit","_players","_owners","_index"];
disableSerialization;

_dialog = findDisplay 2700;
_list = _dialog displayCtrl 2701;
_plist = _dialog displayCtrl 2702;

_sel = lbCurSel _list;
if ((_list lbData _sel) isEqualTo "") exitWith {hint localize "STR_NOTF_didNotSelectVehicle";};
_vehicle = _list lbData _sel;
_vehicle = life_vehicles select parseNumber(_vehicle);

_exit = false;
if(playerSide isEqualTo civilian) then {
	if(isnil "life_gangdata") exitWith {_exit = true};
	if(life_gangdata isEqualTo []) exitWith {_exit = true};
	_players = (playableUnits - [player]) select {if((getplayeruid _x) in (life_gangdata select 5))then{true}else{false}};
	if!(_players isEqualTo []) then {
		_owners = _vehicle getVariable "vehicle_info_owners";
		{
			_uid = getPlayerUID _x;
			_index = [_uid,_owners] call TON_fnc_index;
			if (_index isEqualTo -1) then  {
			    _owners pushBack [_uid,name _x];
			    [_vehicle,_x,profileName] remoteExecCAll ["TON_fnc_clientGetKey",_x];
			};
		} foreach _players;

		_vehicle setVariable ["vehicle_info_owners",_owners,true];
	};
} else {
	_players = (playableUnits - [player]) select {if((side _x) isEqualTo playerSide) then {true}else{false}};
	if!(_players isEqualTo []) then {
		_owners = _vehicle getVariable "vehicle_info_owners";
		{
			_uid = getPlayerUID _x;
			_index = [_uid,_owners] call TON_fnc_index;
			if (_index isEqualTo -1) then  {
			    _owners pushBack [_uid,name _x];
			    [_vehicle,_x,profileName] remoteExecCAll ["TON_fnc_clientGetKey",_x];
			};
		} foreach _players;

		_vehicle setVariable ["vehicle_info_owners",_owners,true];
	};
};


if(_exit) exitWith {["Du bist in keiner Gang"] spawn life_fnc_exp_hint;};


if(playerside isEqualTo civilian) then {
	["Du hast allen aktiven Mitgliedern deiner Gang einen Key gegeben"] spawn life_fnc_exp_hint;
} else {
	["Du hast allen aktiven Kollegen einen Key gegeben"] spawn life_fnc_exp_hint;
};

