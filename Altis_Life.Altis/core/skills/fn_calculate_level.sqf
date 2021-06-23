

if(isnil "alpha_xp") then {alpha_xp = 0;};



_first_level_xp = getNumber(missionConfigFile >> "Life_Settings" >> "xp_first_level");
_xp_gain_per_level = getNumber(missionConfigFile >> "Life_Settings" >> "xp_gain_level");





_temp_xp = _first_level_xp;
_xp_this_level = _first_level_xp;
_temp_lvl = 0;
while{TRUE} do {
	if(_temp_xp > alpha_xp) exitWith {};
	_temp_lvl = _temp_lvl + 1;
	_xp_this_level = _first_level_xp + (_xp_gain_per_level * _temp_lvl);
	_temp_xp = _temp_xp + _xp_this_level;
};
alpha_lvl = _temp_lvl;
ALPHA_XP_CUR_LEVEL = alpha_xp - (_temp_xp - _xp_this_level);
ALPHA_XP_TONXT_LEVEL = _temp_xp - alpha_xp;
ALPHA_XP_FOR_THIS_LEVEL = _xp_this_level;


[] call life_fnc_hudupdate