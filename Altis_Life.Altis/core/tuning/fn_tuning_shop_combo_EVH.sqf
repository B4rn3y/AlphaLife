private ["_display","_lb","_combo","_cur_sel","_foreachindex"];


_display = findDisplay 57742;

if(isnull _display) exitWith {};

_lb = _display displayCtrl 1500;
_combo = _display displayCtrl 2100;


_cur_sel = lbCurSel _combo;
if(_cur_sel isEqualTo -1) exitWith {};



lbclear _lb;

{
	life_tuning_vehicle setObjectMaterial[_foreachindex,_x];
} foreach (getObjectMaterials life_tuning_original_vehicle);

if!(isnil "life_tuning_light") then {
	detach life_tuning_light;
	deleteVehicle life_tuning_light;
	life_tuning_light = nil;
};

switch (_cur_sel) do
{
	case 0:  // Folierungen
	{
		{
			_lb lbadd format["$%1 - %2",[_x select 2] call life_fnc_numbertext,_x select 1];
		} foreach getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "materials");
		_lb lbSetCurSel 0;
	};

	case 1:  // Hupen
	{
		{
			_lb lbadd format["$%1 - %2",[_x select 2] call life_fnc_numbertext,_x select 1];
		} foreach getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "horns");
		_lb lbSetCurSel 0;
	};

	case 2:  // Anderes
	{
		_lb lbadd format["$%2 - [%1x] Nitro",getnumber(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "nitro_amount"),[getnumber(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "nitro_cost")] call life_fnc_numbertext];
		_lb lbadd format["$%2 - [%1x] Oil",getnumber(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "oil_amount"),[getnumber(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "oil_cost")] call life_fnc_numbertext];
		_lb lbSetCurSel 0;
	};

	case 3:  // Unterbodenbeleuchtung
	{
		{
			_lb lbadd format["$%1 - %2",[_x select 2] call life_fnc_numbertext,_x select 0];
		} foreach getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "light_color");
		_lb lbSetCurSel 0;
	};
};

