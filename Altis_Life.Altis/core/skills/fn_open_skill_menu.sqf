


if!(createDialog "skills") exitWith {};

_display = findDisplay 258645;
_time = _display displayCtrl 8888;
_time ctrlsettext format["%1:%2",systemtime select 3,systemtime select 4];
ctrlSetText[2009,format ["%1 / %2", life_carryWeight, life_maxWeight]];
_str_text_Skill_beschreibung = _display displayCtrl 1101;

_str_text_Skill_beschreibung ctrlSetStructuredText parsetext "<br/><t color='#FF8000' align='center'>Information:</t> <br/><t size='1.0'  align='center'>Die Skills werden automatisch freigeschaltet wenn du das jeweilige Level erreichst!</t>";

_tv = (finddisplay 258645) ctrlCreate ["RscTreeSearch", -1];
_tv ctrlSetFont "PuristaMedium";
_tv ctrlSetFontHeight 0.035;
_tv ctrlSetPosition [0.0909089,0.185186,0.682071,0.524242];
_tv ctrlSetBackgroundColor [0,0,0,0.25];
_tv ctrlCommit 0;
_tv ctrlAddEventHandler ["TreeSelChanged","_this call life_fnc_skill_menu_TreeSelChanged"];
tvClear _TV;


_skills = getarray(missionConfigFile >> "CfgSkills" >> "skills");


_ID1 = 0;
_ID2 = 0;
_ID3 = 0;

{
	_type_overall = _x select 0;
	_cond = _x select 2;
	if(call compile _cond) then {
		_ID1 = _tv tvAdd[[],_type_overall];
		{
			_type_spec = _x select 0;
			_cond = _x select 2;
			if(call compile _cond) then {
				_ID2 = _tv tvAdd[[_ID1],_type_spec];
				{
					_lvl_needed = _x select 0;
					_short_descr = _x select 1;
					_longer_descr = _x select 2;
					_var = _x select 3;
					_value = _x select 4;
					_ID3 = _tv tvAdd[[_ID1,_ID2],format["[%2] %1",_short_descr,_lvl_needed]];
					_tv tvSetData [[_ID1,_ID2,_ID3],str[_lvl_needed,_longer_descr]];
					if(alpha_lvl >= _lvl_needed) then {
						_tv tvSetColor[[_ID1,_ID2,_ID3],[0.004,0.875,0.227,1]];
					} else {
						_tv tvSetColor[[_ID1,_ID2,_ID3],[0.98,0.345,0.345,1]];
					};

				} foreach (_x select 1);
			};
		} foreach (_x select 1);
	};
} foreach _skills;
tvExpandAll _tv;

waitUntil {isnull(findDisplay 258645)};

ctrlDelete _tv;