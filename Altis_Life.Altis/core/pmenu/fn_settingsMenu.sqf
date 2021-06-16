#include "..\..\script_macros.hpp"
/*
    File: fn_settingsMenu
    Author: Bryan "Tonic" Boardwine

    Description:
    Setup the settings menu.
*/
if (isNull (findDisplay 2900)) then {
    if (!createDialog "SettingsMenu") exitWith {hint localize "STR_NOTF_menuWillNotOpen";};
};

disableSerialization;

ctrlSetText[2902, format ["%1", life_settings_viewDistanceFoot]];
ctrlSetText[2912, format ["%1", life_settings_viewDistanceCar]];
ctrlSetText[2922, format ["%1", life_settings_viewDistanceAir]];

_display = findDisplay 2900;
_side = _display displayCtrl 2971;
_broadcast = _display displayCtrl 2973;
_tags = _display displayCtrl 2970;
_objects = _display displayCtrl 2972;
_edit_your_pid = _display displayCtrl 1780;


ctrlSetText[7858,format["%1:%2",systemtime select 3,systemtime select 4]];
ctrlSetText[2009,format ["%1 / %2", life_carryWeight, life_maxWeight]];

_edit_your_pid ctrlSetText (getPlayerUID player);

/*
CONTROL(2900,2971) cbSetChecked life_settings_enableSidechannel;
CONTROL(2900,2973) cbSetChecked life_settings_enableNewsBroadcast;
CONTROL(2900,2970) cbSetChecked life_settings_tagson;
CONTROL(2900,2972) cbSetChecked life_settings_revealObjects;
*/

/* Set up the sliders */
{
    slidersetRange [(_x select 0),100,8000];
    CONTROL(2900,(_x select 0)) sliderSetSpeed [100,100,100];
    sliderSetPosition [(_x select 0),(_x select 1)];
} forEach [[2901,life_settings_viewDistanceFoot],[2911,life_settings_viewDistanceCar],[2921,life_settings_viewDistanceAir]];


if (isNil "life_settings_revealObjects") then {
    life_settings_enableNewsBroadcast = profileNamespace setVariable ["life_enableNewsBroadcast",true];
    life_settings_enableSidechannel = profileNamespace setVariable ["life_enableSidechannel",true];
    life_settings_tagson = profileNamespace setVariable ["life_settings_tagson",true];
    life_settings_revealObjects = profileNamespace setVariable ["life_settings_revealObjects",true];
};

/*
if(life_settings_enableSidechannel) then {
    _side ctrlSetTextColor [0,1,0,1];
    _side ctrlSetText "ON";
    _side buttonSetAction "['sidechat',0] call life_fnc_s_onCheckedChange; [] call life_fnc_settingsMenu;";
} else {
    _side ctrlSetTextColor [1,0,0,1];
    _side ctrlSetText "OFF";
    _side buttonSetAction "['sidechat',1] call life_fnc_s_onCheckedChange; [] call life_fnc_settingsMenu;";
};
*/
if(life_settings_enableNewsBroadcast) then {
    _broadcast ctrlSetTextColor [0,1,0,1];
    _broadcast ctrlSetText "ON";
    _broadcast buttonSetAction "['broadcast',0] call life_fnc_s_onCheckedChange; [] call life_fnc_settingsMenu;";
} else {
    _broadcast ctrlSetTextColor [1,0,0,1];
    _broadcast ctrlSetText "OFF";
    _broadcast buttonSetAction "['broadcast',1] call life_fnc_s_onCheckedChange; [] call life_fnc_settingsMenu;";
};

if(life_settings_tagson) then {
    _tags ctrlSetTextColor [0,1,0,1];
    _tags ctrlSetText "ON";
    _tags buttonSetAction "['tags',0] call life_fnc_s_onCheckedChange; [] call life_fnc_settingsMenu;";
} else {
    _tags ctrlSetTextColor [1,0,0,1];
    _tags ctrlSetText "OFF";
    _tags buttonSetAction "['tags',1] call life_fnc_s_onCheckedChange; [] call life_fnc_settingsMenu;";
};

if(life_settings_revealObjects) then {
    _objects ctrlSetTextColor [0,1,0,1];
    _objects ctrlSetText "ON";
    _objects buttonSetAction "['objects',0] call life_fnc_s_onCheckedChange; [] call life_fnc_settingsMenu;";
} else {
    _objects ctrlSetTextColor [1,0,0,1];
    _objects ctrlSetText "OFF";
    _objects buttonSetAction "['objects',1] call life_fnc_s_onCheckedChange; [] call life_fnc_settingsMenu;";
};

