





private ["_first_time","_hazards_suits","_time","_time_effect_to_change","_center","_dis","_w8"];

_first_time = true;
_hazards_suits = getarray(missionConfigFile >> "Life_Settings" >> "hazard_suits");
_time = diag_tickTime;
_time_effect_to_change = diag_tickTime;
_center = getmarkerpos "uran_field";
while {True} do {

    _dis = player distance _center;

    _w8 = _dis /240;
    if(_w8 <= 0) then {_w8 = 0.01;};

    playSound "radiation";
    sleep _w8;


    if((diag_tickTime - _time) > 1) then {
        _time = diag_tickTime;
        if!((uniform player) in _hazards_suits) then {
            if(_first_time) then {
                rad_effect = ppEffectCreate ["ChromAberration",2000];
                rad_effect ppEffectEnable true;
                rad_effect ppEffectAdjust [0.01, 0.01, true];
                rad_effect ppEffectCommit 1;
                _time_effect_to_change = diag_tickTime + selectRandom[6,8,10];
                _first_time = false;
                ["Du erleidest Schaden durch Strahlung, verlasse dieses Gebiet oder ziehe einen Hazard Suit an!"] spawn life_Fnc_exp_hint;
            };

            player setdamage (damage player + 0.01);
            if(_time_effect_to_change < diag_tickTime) then {
                rad_effect ppEffectAdjust [random 0.1, random 0.1, true];
                rad_effect ppEffectCommit 1;
                _time_effect_to_change = diag_tickTime + selectRandom[6,8,10];
            };

        } else {
            _first_time = true;
            if!(isnil "rad_effect") then {
                ppEffectDestroy rad_effect;
                rad_effect = nil;
            };
        };
    };

    if!(isnil "life_exited_radiation_zone") exitWith {
        if!(isnil "rad_effect") then {
            ppEffectDestroy rad_effect;
            rad_effect = nil;
        };
        life_exited_radiation_zone = nil;
    };
};