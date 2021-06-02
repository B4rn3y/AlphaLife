#include "..\..\script_macros.hpp"
/*
    File: fn_keyMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Initializes the key menu
    Will be revised.
*/
private ["_display","_time","_gang_key_btn","_vehicles","_plist","_near_units","_veh","_color","_text","_pic"];
disableSerialization;

waitUntil {!isNull (findDisplay 2700)};
_display = findDisplay 2700;
_time = _display displayCtrl 7858;
_time ctrlsettext format["%1:%2",systemtime select 3,systemtime select 4];
_gang_key_btn = _display displayCtrl  2704;
ctrlSetText[2009,format ["%1 / %2", life_carryWeight, life_maxWeight]];
if(playerSide isEqualTo civilian) then {
    if(isnil "life_gangdata") then {
        _gang_key_btn ctrlShow false;
    };
    if(life_gangdata isEqualTo []) then {
        _gang_key_btn ctrlShow false;
    };
};
_vehicles = _display displayCtrl 2701;
lbClear _vehicles;
_plist = _display displayCtrl 2702;
lbClear _plist;
_near_units = [];

{ if (player distance _x < 20) then {_near_units pushBack _x};} forEach playableUnits;

for "_i" from 0 to (count life_vehicles)-1 do {
    _veh = life_vehicles select _i;
    if (!isNull _veh && alive _veh) then {
        _color = ((M_CONFIG(getArray,"LifeCfgVehicles",(typeOf _veh),"textures") select (_veh getVariable "Life_VEH_color")) select 0);
        if (isNil "_color") then {_color = ""};
        _text = format ["(%1)",_color];
        if (_text == "()") then {
            _text = "";
        };

        _name = getText(configFile >> "CfgVehicles" >> (typeOf _veh) >> "displayName");
        _pic = getText(configFile >> "CfgVehicles" >> (typeOf _veh) >> "picture");
        _vehicles lbAdd format ["%1 %3 - [Distance: %2m]",_name,round(player distance _veh),_text];
        if (_pic != "pictureStaticObject") then {
            _vehicles lbSetPicture [(lbSize _vehicles)-1,_pic];
        };
        _vehicles lbSetData [(lbSize _vehicles)-1,str(_i)];
    };
};

{
    if (!isNull _x && alive _x && player distance _x < 20 && !(_x isEqualTo player)) then {
        _plist lbAdd format ["%1 - %2",_x getVariable ["realname",name _x], side _x];
        _plist lbSetData [(lbSize _plist)-1,str(_x)];
    };
} forEach _near_units;

if (((lbSize _vehicles)-1) isEqualTo -1) then {
    _vehicles lbAdd localize "STR_NOTF_noVehOwned";
    _vehicles lbSetData [(lbSize _vehicles)-1,""];
};
