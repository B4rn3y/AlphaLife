private ["_skills","_cond","_needed_lvl","_var","_value"];

[] call life_fnc_calculate_level;
_skills = getarray(missionConfigFile >> "CfgSkills" >> "skills");

{
	_cond = _x select 2;
	if(call compile _cond) then {
		{
			_cond = _x select 2;
			if(call compile _cond) then {
				{
					_needed_lvl = _x select 0;
					_var = _x select 3;
					_value = _x select 4;
					if(alpha_lvl >= _needed_lvl) then {
						if(_var isEqualType "") then {
							missionNamespace setvariable[format["alpha_skills_%1",_var],_value];
						} else {
							{
								missionNamespace setvariable[format["alpha_skills_%1",_x],_value];
							} foreach _var;
						};
					};
				} foreach (_x select 1);
			};
		} foreach (_x select 1);
	};
} foreach _skills;

