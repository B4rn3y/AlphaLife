

//if(true) exitWith {};
_quest_ID = param[0,-1,[-1]];




if(_quest_ID in alpha_quests) exitWith {};
if(_quest_ID isEqualTo -1) exitWith {};


//Normale Quest
_UID = getplayeruid player;
_achievement = [_quest_ID] call life_fnc_quest_config_index;


_money = _achievement select 5;
_XP = _achievement select 4;
[_XP,format["%1 - done",_achievement select 1]] call life_fnc_addexp;
[] spawn (compile(_achievement select 6));
alpha_atmbank = alpha_atmbank + _money;



alpha_quests pushBackUnique _quest_ID;


[9] call SOCK_fnc_updatePartial;




[_achievement,_UID] spawn {
	_ach = _this select 0;
	_playerid = _this select 1;
	waitUntil {sleep 0.3;isnil "ALPHA_QUEST_ACHIEVED"};
	if(isnil "ALPHA_QUEST_ACHIEVED") then {ALPHA_QUEST_ACHIEVED = true;};
	 [parseText format [ "<t align='center' size='1.2'><t font='PuristaBold' size='1.6'>""%1""</t></t><br/><t align='center' size='1.2'>%2</t> <br/><br/> <t size='1.7' align='center' color='#01DF01'>BESTANDEN!</t> ", toUpper (_ach select 1), (_ach select 2)], [0.16925,-0.1668,0.660353,0.636768], nil, 7, 0.7, 0] spawn BIS_fnc_textTiles;

	playsound "achievement";

	[0,(format ["Der Spieler %1 hat den Erfolg ""%2"" freigeschaltet.", profileName, toUpper (_ach select 1)]),false] remoteExecCall["life_fnc_broadcast",-2];

	sleep 13;
	ALPHA_QUEST_ACHIEVED = nil;
};