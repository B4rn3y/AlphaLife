#include "..\..\script_macros.hpp"
/*
    File: fn_openInventory.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Starts the initialization of vehicle virtual inventory menu.
*/
private ["_vehicle","_veh_data"];
if (dialog) exitWith {};
_vehicle = [_this,0,objNull,[objNull]] call BIS_fnc_param;
if (isNull _vehicle || !(_vehicle isKindOf "Car" || _vehicle isKindOf "Air" || _vehicle isKindOf "Ship" || _vehicle isKindOf "Box_IND_Grenades_F" || _vehicle isKindOf "B_supplyCrate_F" || _vehicle isKindOf "Land_Cages_F")) exitWith {}; //Either a null or invalid vehicle type.
if ((_vehicle getVariable ["trunk_in_use",false])) exitWith {hint localize "STR_MISC_VehInvUse"};
_vehicle setVariable ["trunk_in_use",true,true];
_vehicle setVariable ["trunk_in_use_by",player,true];
if (!createDialog "TrunkMenu") exitWith {hint localize "STR_MISC_DialogError";}; //Couldn't create the menu?
disableSerialization;

//LSD Falle

if(_vehicle isKindOf "Land_Cages_F") then {
    ctrlSetText[3501,"Froschfalle"];

    _timeDelta = serverTime-(_vehicle getVariable["trap_time",serverTime]);
    _count = round(_timeDelta / alpha_frogtime);
    if(_count > 0) then {
        _vehicle setVariable["trap_time",serverTime,true];
        _veh_data = _vehicle getVariable ["Trunk",[[],0]];
        _inv = _veh_data select 0;
        _item = "frog";
        _countTemp = round((30-(_veh_data select 1)) / (getnumber (missionConfigFile >> "VirtualItems" >> _item >> "weight")));
        if(_countTemp<_count) then {_count = _countTemp};
        _weight = (_veh_data select 1) +  _count * (getnumber (missionConfigFile >> "VirtualItems" >> _item >> "weight"));
        //if(_weight > 30) exitWith {systemChat "Die Falle ist voll"};

        _index = [_item,_inv] call TON_fnc_index;
        if(_index == -1) then
        {
            _inv pushBack [_item,_count];
        }
            else
        {
            _val = (_inv select _index) select 1;
            _inv set[_index,[_item,_val + _count]];
        };

        _vehicle setVariable["Trunk",[_inv,_weight],true];
    };

} else {
    if (_vehicle isKindOf "Box_IND_Grenades_F" || _vehicle isKindOf "B_supplyCrate_F") then {
        ctrlSetText[3501,format [(localize "STR_MISC_HouseStorage")+ " - %1",getText(configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "displayName")]];
    } else {
        ctrlSetText[3501,format [(localize "STR_MISC_VehStorage")+ " - %1",getText(configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "displayName")]];
    };
};


_veh_data = [_vehicle] call life_fnc_vehicleWeight;

if (_veh_data select 0 isEqualTo -1) exitWith {closeDialog 0; _vehicle setVariable ["trunk_in_use",false,true]; hint localize "STR_MISC_NoStorageVeh";};

ctrlSetText[3504,format [(localize "STR_MISC_Weight")+ " %1/%2",_veh_data select 1,_veh_data select 0]];
[_vehicle] call life_fnc_vehInventory;
life_trunk_vehicle = _vehicle;

_vehicle spawn {
    waitUntil {isNull (findDisplay 3500)};
    _this setVariable ["trunk_in_use",false,true];
    if (_this isKindOf "Box_IND_Grenades_F" || _this isKindOf "B_supplyCrate_F") then {

        if (life_HC_isActive) then {
            [_this] remoteExecCall ["HC_fnc_updateHouseTrunk",HC_Life];
        } else {
            [_this] remoteExecCall ["TON_fnc_updateHouseTrunk",2];
        };
    };
};

if (LIFE_SETTINGS(getNumber,"save_vehicle_virtualItems") isEqualTo 1) then {
    _vehicle spawn {
        waitUntil {isNull (findDisplay 3500)};
        _this setVariable ["trunk_in_use",false,true];
        if ((_this isKindOf "Car") || (_this isKindOf "Air") || (_this isKindOf "Ship")) then {
            [] call SOCK_fnc_updateRequest;

            if (life_HC_isActive) then {
                [_this,2] remoteExecCall ["HC_fnc_vehicleUpdate",HC_Life];
            } else {
                [_this,2] remoteExecCall ["TON_fnc_vehicleUpdate",2];
            };
        };
    };
};
