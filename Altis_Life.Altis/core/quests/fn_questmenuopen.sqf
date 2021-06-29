private ["_display","_time","_listbox","_str_text","_progressbar","_ret","_quest_config","_count_all_quests","_count_done_quests","_perc","_bar","_D","_ID"];



// [-0.0195705,-0.104647,1.08561,1.18714]



disableSerialization;
if!(createDialog "alpha_quest") exitWith {};
waitUntil {!isnull(finddisplay 5223)};

_display = findDisplay 5223;

_time = _display displayCtrl 8888;
_time ctrlsettext format["%1:%2",systemtime select 3,systemtime select 4];
ctrlSetText[2009,format ["%1 / %2", life_carryWeight, life_maxWeight]];

_listbox = _display displayCtrl 1500;
_str_text = _display displayCtrl 1101;

_progressbar = _display displayCtrl 38201;

_ret = [nil,true] call life_fnc_quest_config_index;
_quest_config =  getArray (missionConfigFile >> "cfgQuests" >> "Quests" >> "Quests");
_count_all_quests = _ret select 0;
_count_done_quests = _ret select 1;

_perc = if(_count_done_quests isEqualTo 0 || _count_all_quests isEqualTo 0) then {0} else {_count_done_quests/_count_all_quests};



[_progressbar,_perc] spawn {
	disableSerialization;
	_bar = _this select 0;
	_perc = _this select 1;
	for "_D" from 0 to round(_perc*100) do {
		_bar progressSetPosition (_D/100);
		sleep 0.013;
		if(isNull (findDisplay 5223)) exitWith {};
	};


};







if(_count_done_quests isEqualTo _count_all_quests) then {
	_str_text ctrlSetStructuredText parsetext format[" <t color='#FAFAFA' align='center'>ALL DONE</t>"];

} else {
	_str_text ctrlSetStructuredText parsetext format[" <t color='#FAFAFA' align='center'>[%1%2] DONE</t>",round(_perc * 100),"%"];
	_str_text ctrlSetTooltip format["Quests: %1/%2",_count_done_quests,_count_all_quests];

};




{
	{
		if(typename _x isEqualTo "STRING") then {
			_ID = _listbox lbadd  _x;
			_listbox lbSetValue[_ID,-1];
			_listbox lbSetColor [_ID, [1,0.502,0,1]];
		} else {
			{
				_ID = _listbox lbadd  format["  %1",(_x select 1)];
				if((_x select 0) in alpha_quests) then {
					_listbox lbsetcolor[_ID,[0.004,0.875,0.004,1]];
				};
				_listbox lbSetValue[_ID,(_x select 0)];
			} foreach (_x)
		};
	} foreach _x;

} foreach _quest_config;





_listbox lbSetCurSel 1;


