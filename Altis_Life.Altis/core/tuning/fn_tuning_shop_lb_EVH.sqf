
private ["_display","_lb","_combo","_cur_sel_combo","_cur_sel_lb","_material","_foreachindex","_color","_pos","_brightness"];
_display = findDisplay 57742;

if(isnull _display) exitWith {};
if(isnull life_tuning_vehicle) exitWith {};
_lb = _display displayCtrl 1500;
_combo = _display displayCtrl 2100;


_cur_sel_combo = lbCurSel _combo;
if(_cur_sel_combo isEqualTo -1) exitWith {};
_cur_sel_lb = lbCurSel _lb;
if(_cur_sel_lb isEqualTo -1) exitWith {};





switch (_cur_sel_combo) do
{
	case 0:  // Folierungen
	{
		_material = (getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "materials") select _cur_sel_lb) select 0;
		{
			life_tuning_vehicle setObjectMaterial[_foreachindex, _material];
		} foreach (getObjectMaterials life_tuning_vehicle);


	};

	case 1:  // Hupen
	{
		playsound ((getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "horns") select _cur_sel_lb) select 0);
	};

	case 2:  // Anderes
	{

	};

	case 3:  // Unterbodenbeleuchtung
	{
		_color = (getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "light_color") select _cur_sel_lb) select 1;

		_pos = [];
		{
			if((_x select 0) isEqualTo (typeof life_tuning_vehicle)) exitWith {_pos = _x select 1;};
		} foreach getArray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "vehicle_light_pos");

		if(_pos isEqualTo []) exitWith {};

		if(isnil "life_tuning_light") then {
			life_tuning_light = "#lightpoint" createVehicleLocal getPosatl life_tuning_vehicle;
			life_tuning_light lightAttachObject[life_tuning_vehicle,_pos];
			life_tuning_light setLightColor _color;
			life_tuning_light setLightAmbient _color;
			life_tuning_light setLightDayLight true;

			life_tuning_light setLightAttenuation [0.181, 0, 1000,2000];
			life_tuning_light setLightFlareSize 0.38;
			life_tuning_light setLightFlareMaxDistance 150;
			life_tuning_light setLightUseFlare true;

			_brightness = 200;
		    if (sunOrMoon < 1) then {
		        _brightness = 200;
		    };
			life_tuning_light setLightBrightness _brightness;

		} else {
			life_tuning_light setLightColor _color;
			life_tuning_light setLightAmbient _color;
			_brightness = 30;
		    if (sunOrMoon < 1) then {
		        _brightness = 30;
		    };
			life_tuning_light setLightBrightness _brightness;
		};


	};
};

