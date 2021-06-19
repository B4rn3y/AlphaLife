


private ["_caller","_actionId","_arguments","_min_cops","_max_distance_rob","_abort_capturing","_marker","_cP","_random_money"];


params ["_target", "_caller", "_actionId", "_arguments"];


if!(playerside isEqualTo civilian) exitWith {};

if((primaryWeapon player) isEqualTo "" && (handgunWeapon player) isEqualTo "") exitWith {["Du versuchst unbewaffnet eine Tankstelle auszurauben, der Besitzer verpügelt dich"] spawn life_fnc_exp_hint;[player,"Tankstellenbesitzer"] spawn life_fnc_knockoutAction;};

_min_cops = 2;
_max_distance_rob = 7;
if(playersnumber west < _min_cops) exitWith {[format["Es müssen mindestens %1 Cops online sein um dies tun zu können",_min_cops]] spawn life_fnc_exp_hint;};


if!((_target getVariable["capturing",""]) isEqualTo "") exitWith {["Diese Tankstelle wird bereits ausgeraubt"] spawn life_fnc_exp_hint;};
if!(isnil "gas_station_capturing") exitWith {};

_abort_capturing = {
    gas_station_capturing = nil;
    deleteMarker _marker;
    _target setvariable["capturing",nil,true];
};


gas_station_capturing = true;

["ALARM: Eine Tankstelle wird ausgeraubt, schaut auf die Karte!"] remoteExec["life_fnc_exp_hint",west];

_marker = createMarker [format["ROBBING_%1",random(10000)], _target];
_marker setMarkerText "Tankstellenraub!";
_marker setMarkerType "mil_warning";
_marker setMarkerColor "ColorRed";



_target setVariable["percent",1];
_target setvariable["capturing",getplayeruid player,true];
[_target,"Robbing","gas_station_capturing"] spawn life_fnc_processEVH;
_cP = 0.01;


for "_i" from 0 to 1 step 0 do {
    uiSleep  6;
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
_random_money = random[50000,125000,200000];
alpha_cash = alpha_cash + _random_money;

[format["Ausrauben erfolgreich, du hast $%1 gestohlen",[_random_money] call life_fnc_numbertext]] spawn life_fnc_exp_hint;

call _abort_capturing;