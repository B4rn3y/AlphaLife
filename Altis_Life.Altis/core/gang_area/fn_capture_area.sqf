#include "..\..\script_macros.hpp"



private ["_markername_radius","_markername_text","_max_distance_laptop","_laptop","_cur_area_setting","_er","_gang_name","_gang_id","_abort_capturing","_cP"];

_markername_radius = "gang_area_radius";
_markername_text = "gang_area_text";
_max_distance_laptop = 10;

_laptop = [_this,0,objNull,[objNull]] call BIS_fnc_param;


if((count playableUnits) < getnumber(missionConfigFile >> "Life_Settings" >> "min_player_gang_area")) exitWith {[format["ABORTING: Es müssen mindestens %1 Spieler online sein um die Gang Area einnehmen zu können",getnumber(missionConfigFile >> "Life_Settings" >> "min_player_gang_area")]] spawn life_fnc_exp_hint;};
_exit = false;
if!(playerSide in [west,civilian]) exitWith {};
if(isnull _laptop) exitWith {};
if(isnil "life_gangdata" && playerside isEqualTo civilian) exitWith {};
if(playerSide isEqualTo civilian) then {
    if(life_gangdata isEqualTo [] && playerside isEqualTo civilian) exitWith {_exit=true;["Du musst in einer Gang sein um die Gang-Area einnehmen zu können"] spawn life_fnc_exp_hint;};
};
if(_exit) exitWith {};
if!(_laptop getVariable["capturing",""] isEqualTo "") exitWith {["Die Gang-Area wird bereits eingenommen."] spawn life_fnc_exp_hint;};
_cur_area_setting = _laptop getvariable["gang_area_info",[]];

_er = false;
if(count _cur_area_setting > 0 && playerside isEqualTo civilian) then {
    if(playerside isEqualTo civilian) then {
        if((_cur_area_setting select 0)isEqualTo (life_gangdata select 0)) exitWith {_er=true;};
    } else {
        if((_cur_area_setting select 0)isEqualTo "Polizei") exitWith {_er=true;};
    };
};

if(_er) exitWith {["ERROR: Die Gang-Area gehört bereits eurer Gang."] spawn life_fnc_exp_hint;};
_gang_name = if(playerSide isEqualTo west) then {"Polizei"} else {life_gangdata select 2};
_gang_id = if(playerSide isEqualTo west) then {"Polizei"} else {life_gangdata select 0};



_markername_radius setMarkerColor "ColorOrange";
_markername_text setMarkerColor "ColorOrange";
_markername_text setMarkerText format["Gang Area PVP: Wird eingenommen durch: %1",_gang_name];

_abort_capturing = {
    _markername_radius setMarkerColor "ColorBlue";
    _markername_text setMarkerColor "ColorBlue";
    _markername_text setMarkerText "";
    _laptop setvariable["capturing",nil,true];
    _laptop setvariable["abort",nil,true];
    gang_area_capturing = nil;

    if!(_cur_area_setting isEqualTo []) then {
        _markername_radius setMarkerColor "ColorRed";
        _markername_text setMarkerColor "ColorRed";
        _markername_text setMarkerText format["Gang Area PVP: Eingenommen durch: %1",_cur_area_setting select 1];
    };
};

gang_area_capturing = true;
_laptop setVariable["percent",1];
_laptop setvariable["capturing",getplayeruid player,true];
[_laptop,"Capturing","gang_area_capturing"] spawn life_fnc_processEVH;
_cP = 0.01;


for "_i" from 0 to 1 step 0 do {
    uiSleep  3;
    _cP = _cP + 0.01;
    _laptop setVariable["percent",_cP*100];
    if (_cP >= 1) exitWith {};
    if (player distance _laptop > _max_distance_laptop) exitWith {};
    if(player getVariable ["restrained",false]) exitWith {};
    if!(alive player) exitWith {};
    if(playerSide isEqualTo civilian) then {
        if(life_gangdata isEqualTo [] && playerside isEqualTo civilian) exitWith {_exit=true;};
    };
    if(isnil "life_gangdata" && playerside isEqualTo civilian) exitWith {};
    if((count playableUnits) < getnumber(missionConfigFile >> "Life_Settings" >> "min_player_gang_area")) exitWith {};
    if(_laptop getVariable["abort",false]) exitWith {};
};
if(_laptop getVariable["abort",false]) exitWith {call _abort_capturing;};
if((count playableUnits) < getnumber(missionConfigFile >> "Life_Settings" >> "min_player_gang_area")) exitWith {[format["ABORTING: Es müssen mindestens %1 Spieler online sein um die Gang Area einnehmen zu können",getnumber(missionConfigFile >> "Life_Settings" >> "min_player_gang_area")]] spawn life_fnc_exp_hint;call _abort_capturing;};
if(isnil "life_gangdata" && playerside isEqualTo civilian) exitWith {["Du musst in einer Gang sein um die Gang-Area einnehmen zu können"] spawn life_fnc_exp_hint;call _abort_capturing;};
if(playerSide isEqualTo civilian) then {
    if(life_gangdata isEqualTo [] && playerside isEqualTo civilian) exitWith {_exit=true;["Du musst in einer Gang sein um die Gang-Area einnehmen zu können"] spawn life_fnc_exp_hint;};
};
if(_exit) exitWith {call _abort_capturing;};
if!(alive player) exitWith {call _abort_capturing;};
if(player getVariable ["restrained",false]) exitWith {["Einnehmen wird abgebrochen."] spawn life_fnc_exp_hint;call _abort_capturing;};
if (player distance _laptop > _max_distance_laptop) exitWith {[format["Bleibe in der Nähe vom Laptop, max. %1m",_max_distance_laptop]] spawn life_fnc_exp_hint;call _abort_capturing;};




_markername_radius setMarkerColor "ColorRed";
_markername_text setMarkerColor "ColorRed";
_laptop setvariable["capturing",nil,true];
gang_area_capturing = nil;

_markername_text setMarkerText format["Gang Area PVP: Eingenommen durch: %1",_gang_name];

_laptop setvariable["gang_area_info",[_gang_id,_gang_name],true];

if!(26 in alpha_quests) then {
    [26] call life_fnc_quest_achieved;
};

if!(playerside isEqualTo west) then {
    [3,format["%1h %2min: %3 und seine Gang %4 haben die Gang Area eingenommen",date select 3,date select 4,profileName, (group player) getVariable["gang_name",""]]] remoteExec ['life_fnc_centerMsg',-2,false];
} else {
    [3,format["%1h %2min: %3 hat im Namen der Polizei die Gang Area eingenommen",date select 3,date select 4,profileName, (group player) getVariable["gang_name",""]]] remoteExec ['life_fnc_centerMsg',-2,false];
};

[format["Du hast erfolgreich die Gang-Area eingenommen. Ihr erhaltet nun alle %1 Minuten pro Gangmitglied $%2 solange die Gang-Area euch gehört.",(getnumber(missionConfigFile >> "Life_Settings" >> "gang_area_paycheck_timer")/60),getnumber(missionConfigFile >> "Life_Settings" >> "gang_area_paycheck")]] spawn life_fnc_exp_hint;


/*
this addAction ["Capture Gang Area",life_fnc_capture_area,"",0,false,false,"",'_target getvariable["capturing",""] isEqualTo ""'];
this addAction ["Abort Capture",{(_this select 0) setvariable["abort",true];},"",0,false,false,"",'!(_target getvariable["capturing",""] isEqualTo "")'];

*/






