

private ["_vehicle","_type","_lightcolor","_lights","_classname","_conf","_lightfront_right","_lightfront_left","_lightback_left","_lightback_right"];

_vehicle =param[0,objNull,[objNull]];
_type = param[1,"W_light",["W_light"]];

if(isnull _vehicle) exitWith {};
_lightcolor = [1,0.502,0];
_lights = [];
_classname = typeof _vehicle;

_conf = [_classname] call life_fnc_lightconfig;
if(_conf isEqualTo "ERROR") exitWith {};
titletext["Warnblinker AN","PLAIN DOWN"];

switch (_type) do
{
	case "W_light":
	{
		_lightfront_right = _conf select 0;
		_lightfront_left = _conf select 1;
		_lightback_left = _conf select 2;
		_lightback_right = _conf select 3;
		_vehicle setvariable["W_light",true,true];
		_lights = [_lightfront_right,_lightfront_left,_lightback_left,_lightback_right];
	};

	case "bl_l":
	{
		_lightfront_left = _conf select 1;
		_lightback_left = _conf select 2;
		_vehicle setvariable["bl",true,true];
		_lights = [_lightfront_left,_lightback_left];
	};

	case "bl_r":
	{
		_lightfront_right = _conf select 0;
		_lightback_right = _conf select 3;
		_vehicle setvariable["bl",true,true];
		_lights = [_lightfront_right,_lightback_right];
	};

};





[_vehicle,_lightcolor,_lights] remoteExec["life_fnc_LightsLoop",-2];

///////////////////////////////////




















