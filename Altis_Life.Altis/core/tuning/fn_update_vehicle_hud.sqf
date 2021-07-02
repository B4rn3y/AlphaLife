
private ["_vehicle","_role","_nitro","_oil","_light","_display","_str_text_control","_text"];

_vehicle = vehicle player;

if(isNull _vehicle) exitWith {};
if!(_vehicle isKindOf "LandVehicle") exitWith {};
if!((driver _vehicle) isEqualTo player) exitWith {};

_nitro = _vehicle getVariable["alpha_nitro",-1];
_oil = _vehicle getVariable["alpha_oil",-1];
_light = _vehicle getVariable["alpha_light",-1];

if(_nitro isEqualTo -1 && _oil isEqualTo -1 && _light isEqualTo -1) exitWith {};


_display = uiNamespace getvariable["hud_veh",displayNull];

if(isnull _display) then {
	15 cutRsc ["hud_veh", "PLAIN", -1, false];
};

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