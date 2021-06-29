/*
	File: fn_unlockVeh.sqf

	Author: Blackd0g modified by Teebaron

	Description:
	Allows to enter locked Vehicles
*/
private ["_position","_veh","_vehicle"];
_vehicle = cursorObject;
_position = param [3,"",[""]];

if(_position isEqualTo "exit") then {
		_vehicle = vehicle player;
	};

// Error Checks
if(playerSide isEqualTo civilian || isNull _vehicle || _vehicle distance player > 30) exitWith {};

switch (_position) do
{
	case "GetIn":
	{
		_vehicle lock false;
		if((driver _vehicle) isEqualTo objNull) then {
			player action ["getInDriver", _vehicle];
		} else {
			player action ["getInCargo", _vehicle];
		};
		_vehicle lock true;
	};

	case "exit":
	{
		_vehicle = vehicle player;
		_vehicle lock false;
		player action ["getOut", _vehicle];
		_vehicle lock true;
	};
};



