/*
	File: fn_oilspill_receive.sqf
	Author: Bloodwyn

	Description:
	Does........things. Pretty strange coding
*/

sleep 0.1;
_time=time+25;


waitUntil {(vehicle player distance (_this select 0) < 2.5) || time > _time};


if(time > _time)exitWith{};

_t=time+1.2;

_vel=velocity vehicle player;
if!(41 in alpha_quests)then {
    [41] spawn life_fnc_quest_achieved;
};
while{_t>time}do{
	vehicle player setVelocity _vel;
};