/*
	File: fn_oilspill_fire.sqf
	Author: Bloodwyn

	Description:
	Spawns the oilspills + remoteexec
*/

alpha_oil = true;
_alloil=[];
for "_i" from 1 to 15 step 1 do
{
	_temp= createSimpleObject ["a3\structures_f_kart\civ\sportsgrounds\oil_spill.p3d",[0,0,0]];
	_temp setpos (vehicle player modelToWorld  [1-(random 2),-2.5,0]);
	_alloil pushBack _temp;
	sleep 0.05;
};

_targets=([player,700] call life_fnc_nearplayers);
_targetf=[];
{if (vehicle _x != _x && vehicle _x isKindOf "LandVehicle" && (driver (vehicle _x)) isEqualTo _x)then{_targetf pushBack _x}}foreach _targets;

[_alloil select 7] remoteexec ["life_fnc_oilspill_receive", _targetf];


_tmp = vehicle player getvariable["alpha_oil",0];
if(_tmp > 1) then {
	_tmp = _tmp - 1;
	vehicle player setvariable["alpha_oil",_tmp,true];
} else {
	vehicle player setvariable["alpha_oil",nil,true];
};

alpha_oil = nil;
["Öl platziert"] spawn life_fnc_exp_hint;
[] call life_fnc_update_vehicle_hud;

if!(40 in alpha_quests)then {
    [40] spawn life_fnc_quest_achieved;
};
sleep 25;
{deleteVehicle _x}foreach _alloil;

