

if (isnil("playerInvisible")) then {playerInvisible = 0;};

if (playerInvisible == 0) then
{
	playerInvisible = 1;
	player setVariable["playerInvisible",true, true];
	cutText ["Player is invisible: " + str(playerInvisible), "PLAIN DOWN"];
	["Player is invisible ON"] call life_fnc_exp_hint;
	// [[vehicle player],"lhm_fnc_invisibleOn",false,false] call lhm_fnc_mp;
	[vehicle player] remoteexec["life_fnc_invisibleOn",2];

}
else
{
	playerInvisible = 0;
	player setVariable["playerInvisible",nil, true];
	cutText ["Player is invisible: " + str(playerInvisible), "PLAIN DOWN"];
	["Player is invisible OFF"] call life_fnc_exp_hint;
	// [[vehicle player],"lhm_fnc_invisibleOff",false,false] call lhm_fnc_mp;
	[vehicle player] remoteexec["life_fnc_invisibleOff",2];
};

// [["admin",(format["%1 with UID %2 has used Invisible Script",name player,getPlayerUID player])],"TON_fnc_externLog",false,false] call lhm_fnc_mp;