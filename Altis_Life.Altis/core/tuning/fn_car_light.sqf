

private ["_vehicle","_light_index","_light_obj","_color","_pos","_brightness"];

if!(isnil "alpha_lights_tuning") exitWith {["Das geht jetzt noch nicht!"] spawn life_fnc_exp_hint;};

_vehicle = vehicle player;

if(isNull _vehicle) exitWith {};
if!(_vehicle isKindOf "LandVehicle") exitWith {};
if!((driver _vehicle) isEqualTo player) exitWith {};



_light_index = _vehicle getvariable["alpha_light",-1];

if(_light_index isEqualTo -1) exitWith {};

alpha_lights_tuning = true;

_light_on = _vehicle getvariable["alpha_light_bool",false];

if(_light_on) then {
	[_vehicle,false] remoteExec["life_Fnc_car_light_receive",-2];
	_vehicle setvariable["alpha_light_bool",nil,true];
	["Beleuchtung: AUS"] spawn life_fnc_exp_hint;
} else {
	[_vehicle,true] remoteExec["life_Fnc_car_light_receive",-2];
	_vehicle setvariable["alpha_light_bool",true,true];
	["Beleuchtung: AN"] spawn life_fnc_exp_hint;
};


sleep 4;
alpha_lights_tuning = nil;