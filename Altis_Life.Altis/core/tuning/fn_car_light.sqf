

private ["_vehicle","_light_index","_light_obj","_color","_pos","_brightness"];

if!(isnil "alpha_lights_tuning") exitWith {["Das geht jetzt noch nicht!"] spawn life_fnc_exp_hint;};

_vehicle = vehicle player;

if(isNull _vehicle) exitWith {};
if!(_vehicle isKindOf "LandVehicle") exitWith {};
if!((driver _vehicle) isEqualTo player) exitWith {};



_light_index = _vehicle getvariable["alpha_light",-1];

if(_light_index isEqualTo -1) exitWith {};

alpha_lights_tuning = true;

_light_obj = _vehicle getvariable["alpha_light_obj",objNull];

if(isnull _light_obj) then {
	_color = (getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "light_color") select _light_index) select 1;

	_pos = [];
	{
		if((_x select 0) isEqualTo (typeof _vehicle)) exitWith {_pos = _x select 1;};
	} foreach getArray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "vehicle_light_pos");

	if(_pos isEqualTo []) exitWith {};

	_light_obj = "#lightpoint" createVehicle getPosatl _vehicle;
	_light_obj lightAttachObject[_vehicle,_pos];
	_light_obj setLightColor _color;
	_light_obj setLightAmbient _color;
	_light_obj setLightDayLight true;

	_light_obj setLightAttenuation [0.181, 0, 1000,2000];
	_light_obj setLightFlareSize 0.38;
	_light_obj setLightFlareMaxDistance 150;
	_light_obj setLightUseFlare true;

	_brightness = 30;
    if (sunOrMoon < 1) then {
        _brightness = 2;
    };
	_light_obj setLightBrightness _brightness;
	_vehicle setvariable["alpha_light_obj",_light_obj,true];
	["Beleuchtung: AN"] spawn life_fnc_exp_hint;
} else {
	lightDetachObject _light_obj;
	deleteVehicle _light_obj;
	_vehicle setvariable["alpha_light_obj",nil,true];
	["Beleuchtung: AUS"] spawn life_fnc_exp_hint;
};


sleep 4;
alpha_lights_tuning = nil;