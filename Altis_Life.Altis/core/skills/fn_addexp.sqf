

_amount_to_add = param[0,-1,[0]];
_description = param[1,"",[""]];

if(_amount_to_add isEqualTo -1 || _description isEqualTo "" || _amount_to_add isEqualTo 0) exitWith {};

alpha_xp = alpha_xp + _amount_to_add;

if(isnil "TEMP_XP") then {
	TEMP_XP = 0;
};

if(_amount_to_add >= ALPHA_XP_TONXT_LEVEL) then {
	[] call life_fnc_calculate_level;
	playsound "achievement";
	[8] call SOCK_fnc_updatePartial;
	[] call life_fnc_init_skills;
	TEMP_XP = 0;
} else {
	if(TEMP_XP > 3000) then {
		[8] call SOCK_fnc_updatePartial;
		TEMP_XP = 0;
	};

	ALPHA_XP_CUR_LEVEL = ALPHA_XP_CUR_LEVEL + _amount_to_add;
	ALPHA_XP_TONXT_LEVEL = ALPHA_XP_TONXT_LEVEL - _amount_to_add;
};








_text = parsetext format["<t align='left' color='#00FF00'>+%1xp</t><t align='left'> - %2</t>",_amount_to_add,_description];

if(isnil "ALPHA_XP_INFO") then {ALPHA_XP_INFO = [];};

disableSerialization;
_display = finddisplay 46;
private _TextField = _display ctrlCreate ["RscStructuredText", -1];
_TextField ctrlSetStructuredText _text;
_TextField ctrlSetPosition [0.821338 * safezoneW + safezoneX,0.65554 * safezoneH + safezoneY,0.171875 * safezoneW,0.0244444 * safezoneH];
_TextField ctrlCommit 0;
_TextField ctrlSetPosition [0.821338 * safezoneW + safezoneX,0.65554 * safezoneH + safezoneY,0.171875 * safezoneW, ((ctrlTextHeight _TextField)+ (0.005 * safezoneH))];
_TextField ctrlCommit 0;
[_TextField] spawn {
	disableSerialization;
	uisleep 3;
	(_this select 0) ctrlsetfade 1;
	(_this select 0) ctrlCommit 1;
	uisleep 1;
	ctrlDelete (_this select 0);


};
private _posText = (ctrlPosition (_TextField)) select 1;
private _textHigh = (ctrlPosition (_TextField)) select 3;

if (count ALPHA_XP_INFO > 0) then {
 private _activeNotifications = 0;
 {

	 private _ctrlText = _x select 0;
	 if (!isNull _ctrlText) then {
		 _ctrlText ctrlSetPosition [0.821338 * safezoneW + safezoneX, (_posText + _textHigh - 0.25*(0.011 * safezoneH))];
		 _ctrlText ctrlCommit 0.25;
		 _posText = (_posText + _textHigh - 0.25*(0.011 * safezoneH));
		 _textHigh = (ctrlPosition (_ctrlText)) select 3;
	 if (_activeNotifications > 8) then {
		 _ctrlText ctrlSetFade 1;
		 _ctrlText ctrlCommit 0.2;
	 };
	 	_activeNotifications = _activeNotifications + 1;
	 };
 } forEach ALPHA_XP_INFO;
};
ALPHA_XP_INFO = ([[_TextField]] + ALPHA_XP_INFO) select {!isNull (_x select 0)};

[] call life_fnc_hudupdate;