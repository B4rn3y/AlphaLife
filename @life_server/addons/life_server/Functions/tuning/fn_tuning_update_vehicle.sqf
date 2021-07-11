

private ["_vehicle","_index","_index_item","_dbInfo","_plate","_query"];

_vehicle = param[0,objNull,[objNull]];
_index = param[1,-1,[2]];
_index_item = param[2,-1,[2]];

if(_index isEqualTo -1) exitWith {};
if(_index_item isEqualTo -1) exitWith {};

// 0 - Folien
// 1 - Hupen
// 2 - Anderes
// 3 - Unterbodenbeleuchtung




_dbInfo = _vehicle getVariable ["dbInfo",[]];
if (count _dbInfo isEqualTo 0) exitWith {};
_uid = _dbInfo select 0;
_plate = _dbInfo select 1;




switch (_index) do
{
	case 0:  // folien
	{
		_query = format["UPDATE vehicles SET material = '%1' WHERE pid = '%2' and id = '%3';",_index_item,_uid,_plate];
		[_query,1] call DB_fnc_asyncCall;
	};

	case 1:  // hupen
	{
		_query = format["UPDATE vehicles SET horn = '%1' WHERE pid = '%2' and id = '%3';",_index_item,_uid,_plate];
		[_query,1] call DB_fnc_asyncCall;
		_vehicle setVariable["alpha_horn",_index_item,true];
	};

	case 2:  // anderes
	{
		if(_index_item isEqualTo 0) then {
			_query = format["UPDATE vehicles SET nitro = '%1' WHERE pid = '%2' and id = '%3';",getnumber(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "nitro_amount"),_uid,_plate];
			[_query,1] call DB_fnc_asyncCall;
			_vehicle setvariable["alpha_nitro",getnumber(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "nitro_amount"),true];
		} else {
			_query = format["UPDATE vehicles SET oil = '%1' WHERE pid = '%2' and id = '%3';",getnumber(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "oil_amount"),_uid,_plate];
			[_query,1] call DB_fnc_asyncCall;
			_vehicle setvariable["alpha_oil",getnumber(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "oil_amount"),true];
		};
	};

	case 3:  // lights
	{
		_query = format["UPDATE vehicles SET light = '%1' WHERE pid = '%2' and id = '%3';",_index_item,_uid,_plate];
		[_query,1] call DB_fnc_asyncCall;
		_vehicle setvariable["alpha_light",_index_item,true];
	};

};



