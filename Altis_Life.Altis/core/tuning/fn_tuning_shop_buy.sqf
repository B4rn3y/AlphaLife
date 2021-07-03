
private ["_display","_lb","_combo","_cur_sel_combo","_cur_sel_lb","_price","_material","_foreachindex","_horn"];

_display = findDisplay 57742;

_lb = _display displayCtrl 1500;
_combo = _display displayCtrl 2100;

_cur_sel_combo = lbCurSel _combo;
if(_cur_sel_combo isEqualTo -1) exitWith {};
_cur_sel_lb = lbCurSel _lb;
if(_cur_sel_lb isEqualTo -1) exitWith {};



switch (_cur_sel_combo) do
{
	case 0: // Folierungen
	{

		_price  = ((getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "materials") select _cur_sel_lb) select 2);
		if((alpha_atmbank - _price) < 0) exitWith {["Du hast nicht genügend Geld auf dem Konto!"] spawn life_fnc_exp_hint;};
		alpha_atmbank = alpha_atmbank - _price;
		[1] call SOCK_fnc_updatePartial;

		_material = (getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "materials") select _cur_sel_lb) select 0;
		{
			life_tuning_original_vehicle setObjectMaterialGlobal[_foreachindex, _material];
		} foreach (getObjectMaterials life_tuning_original_vehicle);

		[life_tuning_original_vehicle,_cur_sel_combo,_cur_sel_lb] remoteexec["life_fnc_tuning_update_vehicle",2];
		["Folierung wurde erfolgreich gekauft"] spawn life_fnc_exp_hint;
		if!(42 in alpha_quests)then {
		    [42] spawn life_fnc_quest_achieved;
		};
	};


	case 1: // Hupen
	{
		_price = ((getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "horns") select _cur_sel_lb) select 2);
		if((alpha_atmbank - _price) < 0) exitWith {["Du hast nicht genügend Geld auf dem Konto!"] spawn life_fnc_exp_hint;};
		alpha_atmbank = alpha_atmbank - _price;
		[1] call SOCK_fnc_updatePartial;

		/*
		_horn = ((getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "horns") select _cur_sel_lb) select 0);

		life_tuning_original_vehicle removeWeaponTurret[life_tuning_original_vehicle currentWeaponTurret [-1],[-1]];
		life_tuning_original_vehicle addWeaponTurret [_horn, [-1]];
		*/

		[life_tuning_original_vehicle,_cur_sel_combo,_cur_sel_lb] remoteexec["life_fnc_tuning_update_vehicle",2];
		["Hupe wurde erfolgreich gekauft"] spawn life_fnc_exp_hint;
		if!(42 in alpha_quests)then {
		    [42] spawn life_fnc_quest_achieved;
		};
	};


	case 2: // Anderes
	{
		if(_cur_sel_lb isEqualTo 0) then {
			_price = getnumber(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "nitro_cost");
			if((alpha_atmbank - _price) < 0) exitWith {["Du hast nicht genügend Geld auf dem Konto!"] spawn life_fnc_exp_hint;};
			alpha_atmbank = alpha_atmbank - _price;
			[1] call SOCK_fnc_updatePartial;


			[life_tuning_original_vehicle,_cur_sel_combo,_cur_sel_lb] remoteexec["life_fnc_tuning_update_vehicle",2];
			["Nitro wurde erfolgreich gekauft"] spawn life_fnc_exp_hint;
			if!(42 in alpha_quests)then {
			    [42] spawn life_fnc_quest_achieved;
			};
		} else {
			_price = getnumber(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "oil_cost");
			if((alpha_atmbank - _price) < 0) exitWith {["Du hast nicht genügend Geld auf dem Konto!"] spawn life_fnc_exp_hint;};
			alpha_atmbank = alpha_atmbank - _price;
			[1] call SOCK_fnc_updatePartial;


			[life_tuning_original_vehicle,_cur_sel_combo,_cur_sel_lb] remoteexec["life_fnc_tuning_update_vehicle",2];
			["Öl wurde erfolgreich gekauft"] spawn life_fnc_exp_hint;
			if!(42 in alpha_quests)then {
			    [42] spawn life_fnc_quest_achieved;
			};
		};
	};

	case 3: // Unterbodenbeleuchtung
	{
		_price = ((getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "light_color") select _cur_sel_lb) select 2);
		if((alpha_atmbank - _price) < 0) exitWith {["Du hast nicht genügend Geld auf dem Konto!"] spawn life_fnc_exp_hint;};
		alpha_atmbank = alpha_atmbank - _price;
		[1] call SOCK_fnc_updatePartial;

		[life_tuning_original_vehicle,_cur_sel_combo,_cur_sel_lb] remoteexec["life_fnc_tuning_update_vehicle",2];
		["Beleuchtung wurde erfolgreich gekauft"] spawn life_fnc_exp_hint;
		if!(42 in alpha_quests)then {
		    [42] spawn life_fnc_quest_achieved;
		};
	};
};

