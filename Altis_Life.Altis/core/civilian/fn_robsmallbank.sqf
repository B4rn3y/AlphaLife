


private ["_caller","_actionId","_arguments","_min_cops","_max_distance_rob","_abort_capturing","_marker","_cP","_random_money"];


params ["_target", "_caller", "_actionId", "_arguments"];


if!(playerside isEqualTo civilian) exitWith {};

if((primaryWeapon player) isEqualTo "" && (handgunWeapon player) isEqualTo "") exitWith {["Du versuchst unbewaffnet eine Bank auszurauben, der Besitzer verpügelt dich"] spawn life_fnc_exp_hint;[player,"Filialleiter"] spawn life_fnc_knockoutAction;};

_min_cops = 0;
_max_distance_rob = 7;
if(playersnumber west < _min_cops) exitWith {[format["Es müssen mindestens %1 Cops online sein um dies tun zu können",_min_cops]] spawn life_fnc_exp_hint;};


if(isnull([(_target getVariable["capturing",""])] call life_fnc_findplayerofpid)) then {
    _target setVariable["capturing",nil,true];
};

if!((_target getVariable["capturing",""]) isEqualTo "") exitWith {["Diese Bank wird bereits ausgeraubt"] spawn life_fnc_exp_hint;};
if!(isnil "small_bank_station_capturing") exitWith {};

_abort_capturing = {
    small_bank_station_capturing = nil;
    deleteMarker _marker;
    _target setvariable["capturing",nil,true];
};


small_bank_station_capturing = true;

["ALARM: Eine kleine Bank wird ausgeraubt, schaut auf die Karte!"] remoteExec["life_fnc_exp_hint",west];

_marker = createMarker [format["ROBBING_%1",random(10000)], _target];
_marker setMarkerText "!Bankraub!";
_marker setMarkerType "mil_warning";
_marker setMarkerColor "ColorRed";



_target setVariable["percent",1];
_target setvariable["capturing",getplayeruid player,true];
[_target,"Ausrauben","small_bank_station_capturing"] spawn life_fnc_processEVH;
_cP = 0.01;


for "_i" from 0 to 1 step 0 do {
    uiSleep  7.2;
    _cP = _cP + 0.01;
    _target setVariable["percent",_cP*100];
    if (_cP >= 1) exitWith {};
    if (player distance _target > _max_distance_rob) exitWith {};
    if(player getVariable ["restrained",false]) exitWith {};
    if!(alive player) exitWith {};
};






if!(alive player) exitWith {call _abort_capturing;};
if(player getVariable ["restrained",false]) exitWith {["Ausrauben wird abgebrochen."] spawn life_fnc_exp_hint;call _abort_capturing;};
if (player distance _target > _max_distance_rob) exitWith {[format["Bleibe in der Nähe vom Besitzer, max. %1m",_max_distance_rob]] spawn life_fnc_exp_hint;call _abort_capturing;};
_random_money = random[500000,600000,800000];
alpha_cash = alpha_cash + round(_random_money);

if!(43 in alpha_quests)then {
    [43] spawn life_fnc_quest_achieved;
};

[format["Ausrauben erfolgreich, du hast $%1 gestohlen",[_random_money] call life_fnc_numbertext]] spawn life_fnc_exp_hint;

call _abort_capturing;