#include "..\..\script_macros.hpp"
/*
    File: fn_vehInvSearch.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Searches the vehicle for illegal items.
*/
private ["_vehicle","_list","_vehicleInfo","_items_for_evidence_room","_value","_illegalValue","_var","_val","_isIllegalItem","_illegalPrice","_illegalItemProcessed"];
_vehicle = cursorObject;
_list = ["Air","Ship","LandVehicle"];
if (isNull _vehicle || {!(KINDOF_ARRAY(_vehicle,_list))}) exitWith {};

_vehicleInfo = _vehicle getVariable ["Trunk",[]];
if (count _vehicleInfo isEqualTo 0) exitWith {hint localize "STR_Cop_VehEmpty"};

_items_for_evidence_room = [];
_value = 0;
_illegalValue = 0;
{
    _var = _x select 0;
    _val = _x select 1;
    _isIllegalItem = M_CONFIG(getNumber,"VirtualItems",_var,"illegal");
    if (_isIllegalItem isEqualTo 1 ) then{
        _items_for_evidence_room pushBack [_var,_val];
        _illegalPrice = M_CONFIG(getNumber,"VirtualItems",_var,"sellPrice");
        if (!isNull (missionConfigFile >> "VirtualItems" >> _var >> "processedItem")) then {
            _illegalItemProcessed = M_CONFIG(getText,"VirtualItems",_var,"processedItem");
            _illegalPrice = M_CONFIG(getNumber,"VirtualItems",_illegalItemProcessed,"sellPrice");
        };

        _illegalValue = _illegalValue + (round(_val * _illegalPrice / 2));
    };
} forEach (_vehicleInfo select 0);

[round(_illegalValue*0.001),"Konfiszierung"] spawn life_fnc_addexp;

if!(_items_for_evidence_room isEqualTo []) then {
    if!(isnil "evidence_box_0") then {
        if!(isnull evidence_box_0) then { // Check if the box is really there so the server does not have to
            [_items_for_evidence_room] remoteExec["life_fnc_insert_items_evidence_room",2];
        };
    };
};

_value = _illegalValue;
if (_value > 0) then {
    [0,"STR_NOTF_VehContraband",true,[[_value] call life_fnc_numberText]] remoteExecCall ["life_fnc_broadcast",RCLIENT];
    BANK = BANK + _value;
    [1] call SOCK_fnc_updatePartial;
    _vehicle setVariable ["Trunk",[[],0],true];
} else {
    hint localize "STR_Cop_NoIllegalVeh";
};
