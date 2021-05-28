#include "..\..\script_macros.hpp"
/*
    File: fn_searchClient.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Searches the player and he returns information back to the player.
*/
private ["_cop","_inv","_robber","_items_for_evidence_room","_var","_val"];
params [
    ["_cop",objNull,[objNull]]
];
if (isNull _cop) exitWith {};

_inv = [];
_robber = false;
_items_for_evidence_room = [];
//Illegal items
{
    _var = configName(_x);
    _val = ITEM_VALUE(_var);
    if (_val > 0) then {
        _inv pushBack [_var,_val];
        [false,_var,_val] call life_fnc_handleInv;
        _items_for_evidence_room pushBack [_var,_val];
    };
} forEach ("getNumber(_x >> 'illegal') isEqualTo 1" configClasses (missionConfigFile >> "VirtualItems"));

if (!life_use_atm) then  {
    CASH = 0;
    _robber = true;
};

if!(_items_for_evidence_room isEqualTo []) then {
    if!(isnil "evidence_box_0") then {
        if!(isnull evidence_box_0) then { // Check if the box is really there so the server does not have to
            [_items_for_evidence_room] remoteExec["life_fnc_insert_items_evidence_room",2];
        };
    };
};

[player,_inv,_robber] remoteExec ["life_fnc_copSearch",_cop];
