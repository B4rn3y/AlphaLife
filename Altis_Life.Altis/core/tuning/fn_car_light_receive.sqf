
private ["_vehicle","_on_off","_light_index","_light_Obj","_light_obj","_color","_pos","_brightness"];



_vehicle = param[0,objNull,[objNull]];
_on_off = param[1,false,[false]];
if(isNull _vehicle) exitWith {};
if!(_vehicle isKindOf "LandVehicle") exitWith {};



_light_index = _vehicle getvariable["alpha_light",-1];

if(_light_index isEqualTo -1) exitWith {};


if!(_on_off) then {

	_light_Obj = _vehicle getvariable["alpha_light_obj",objNull];
	if!(isNull _light_obj) then {
		lightDetachObject _light_obj;
		deleteVehicle _light_obj;
		_vehicle setvariable["alpha_light_obj",nil];
	};
} else {


	_color = (getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "light_color") select _light_index) select 1;

	_pos = [];
	{
		if((_x select 0) isEqualTo (typeof _vehicle)) exitWith {_pos = _x select 1;};
	} foreach getArray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "vehicle_light_pos");

	if(_pos isEqualTo []) exitWith {};

	_light_obj = "#lightpoint" createVehiclelocal getPosatl _vehicle;
	_light_obj lightAttachObject[_vehicle,_pos];
	_light_obj setLightColor _color;
	_light_obj setLightAmbient _color;
	_light_obj setLightDayLight true;

	_light_obj setLightAttenuation [0.181, 0, 1000,2000];
	_light_obj setLightFlareSize 0.38;
	_light_obj setLightFlareMaxDistance 150;
	_light_obj setLightUseFlare true;

	_brightness = 200;
    if (sunOrMoon < 1) then {
        _brightness = 4;
    };
	_light_obj setLightBrightness _brightness;
	_vehicle setvariable["alpha_light_obj",_light_obj];
};
