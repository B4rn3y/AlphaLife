private ["_unit","_role","_vehicle","_turret","_nitro","_oil","_light","_display","_str_text_control","_text"];



params ["_unit", "_role", "_vehicle", "_turret"];

if(isNull _vehicle) exitWith {};
if!(_role isEqualTo "driver") exitWith {};
_nitro = _vehicle getVariable["alpha_nitro",-1];
_oil = _vehicle getVariable["alpha_oil",-1];
_light = _vehicle getVariable["alpha_light",-1];
_horn_ID = _vehicle getvariable["alpha_horn",-1];

if(_horn_ID >= 0) then {
	[_vehicle,_horn_ID] spawn {
		sleep 2;
		_horn = ((getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "horns") select (_this select 1)) select 0);

	    (_this select 0) removeWeaponTurret[((_this select 0) currentWeaponTurret [-1]),[-1]];
	    (_this select 0) addWeaponTurret [_horn, [-1]];
	    (_this select 0) setvariable["alpha_horn",nil,true];
	   };
};

if(_nitro isEqualTo -1 && _oil isEqualTo -1 && _light isEqualTo -1) exitWith {};


15 cutRsc ["hud_veh", "PLAIN", -1, false];
_display = uiNamespace getvariable["hud_veh",displayNull];

if(isnull _display) exitWith {};

_str_text_control = _display displayCtrl 1100;


_text = "";

if(_nitro > 0) then {
	_text = _text + format["<t align='right'><img image='icons\ico_nitro.paa'/> [%1x] - E</t><br/>",_nitro];
};

if(_oil > 0) then {
	_text = _text + format["<t align='right'><img image='icons\ico_oilProcessed.paa'/> [%1x] - O</t><br/>",_oil];
};

if(_light >= 0) then {
	_text = _text + format["<t align='right'><img image='icons\ico_light.paa'/> - Ä</t>",_light];
};

_str_text_control ctrlSetStructuredText parseText _text;