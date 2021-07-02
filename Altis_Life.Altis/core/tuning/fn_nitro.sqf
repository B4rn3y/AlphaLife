private ["_vehicle","_vel","_dir","_speed","_tmp"];

alpha_nitro = true;
[vehicle player,"speed",100,1] remoteExecCall ["life_fnc_say3D",-2];
_vehicle = vehicle player;
_vel = velocity _vehicle;
_dir = direction _vehicle;
_speed = 35;
_vehicle setVelocity [   (_vel select 0) + (sin _dir * _speed),    (_vel select 1) + (cos _dir * _speed),    (_vel select 2)  ];
_tmp = _vehicle getvariable["alpha_nitro",0];
if(_tmp > 1) then {
	_tmp = _tmp - 1;
	_vehicle setvariable["alpha_nitro",_tmp,true];
} else {
	_vehicle setvariable["alpha_nitro",nil,true];
};

[] call life_fnc_update_vehicle_hud;

if!(39 in alpha_quests)then {
    [39] spawn life_fnc_quest_achieved;
};

alpha_nitro = nil;