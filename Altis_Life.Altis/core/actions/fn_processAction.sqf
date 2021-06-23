#include "..\..\script_macros.hpp"
/*
    File: fn_processAction.sqf
    Author: Bryan "Tonic" Boardwine
    Modified : NiiRoZz

    Description:
    Master handling for processing an item.
    NiiRoZz : Added multiprocess
*/

private ["_vendor","_type","_xp_per_weight","_filter","_materialsRequired","_materialsGiven","_noLicenseCost","_text","_itemInfo","_oldItem","_newItem","_cost","_upp","_exit","_totalConversions","_var","_hasLicense","_minimumConversions","_oldItemWeight","_weight","_newItemWeight","_netChange","_freeSpace","_estConversions"];
_vendor = [_this,0,objNull,[objNull]] call BIS_fnc_param;
_type = [_this,3,"",[""]] call BIS_fnc_param;
_xp_per_weight = 50;
//Error check
if (isNull _vendor || _type isEqualTo "" || (player distance _vendor > 10)) exitWith {};
life_action_inUse = true;//Lock out other actions during processing.

if (isClass (missionConfigFile >> "ProcessAction" >> _type)) then {
    _filter = false;
    _materialsRequired = M_CONFIG(getArray,"ProcessAction",_type,"MaterialsReq");
    _materialsGiven = M_CONFIG(getArray,"ProcessAction",_type,"MaterialsGive");
    _noLicenseCost = M_CONFIG(getNumber,"ProcessAction",_type,"NoLicenseCost");
    _text = M_CONFIG(getText,"ProcessAction",_type,"Text");
} else {_filter = true;};

_cp_plus = missionNamespace getvariable[format["alpha_skills_%1",_type],0.01];

if (_filter) exitWith {life_action_inUse = false;};

_itemInfo = [_materialsRequired,_materialsGiven,_noLicenseCost,(localize format ["%1",_text])];
if (count _itemInfo isEqualTo 0) exitWith {life_action_inUse = false;};

//Setup vars.
_oldItem = _itemInfo select 0;
_newItem = _itemInfo select 1;
_cost = _itemInfo select 2;
_upp = _itemInfo select 3;
_exit = false;
if (count _oldItem isEqualTo 0) exitWith {life_action_inUse = false;};

_totalConversions = [];
{
    _var = ITEM_VALUE(_x select 0);
    if (_var isEqualTo 0) exitWith {_exit = true;};
    if (_var < (_x select 1)) exitWith {_exit = true;};
    _totalConversions pushBack (floor (_var/(_x select 1)));
} forEach _oldItem;

if (_exit) exitWith {life_is_processing = false; hint localize "STR_NOTF_NotEnoughItemProcess"; life_action_inUse = false;};

if (_vendor in [mari_processor,coke_processor,heroin_processor]) then {
    _hasLicense = true;
} else {
    _hasLicense = LICENSE_VALUE(_type,"civ");
};

_cost = _cost * (count _oldItem);

_minimumConversions = _totalConversions call BIS_fnc_lowestNum;
_oldItemWeight = 0;
{
    _weight = ([_x select 0] call life_fnc_itemWeight) * (_x select 1);
    _oldItemWeight = _oldItemWeight + _weight;
} count _oldItem;


_newItemWeight = 0;
{
    _weight = ([_x select 0] call life_fnc_itemWeight) * (_x select 1);
    _newItemWeight = _newItemWeight + _weight;
} count _newItem;

_exit = false;

if (_newItemWeight > _oldItemWeight) then {
    _netChange = _newItemWeight - _oldItemWeight;
    _freeSpace = life_maxWeight - life_carryWeight;
    if (_freeSpace < _netChange) exitWith {_exit = true;};
    private _estConversions = floor(_freeSpace / _netChange);
    if (_estConversions < _minimumConversions) then {
        _minimumConversions = _estConversions;
    };
};

if (_exit) exitWith {hint localize "STR_Process_Weight"; life_is_processing = false; life_action_inUse = false;};

//Setup our progress bar.
disableSerialization;


life_is_processing = true;

_vendor setVariable["percent",1];
[_vendor,_upp] spawn life_fnc_processEVH;
_cP = 0.01;

if (_hasLicense) then {
    for "_i" from 0 to 1 step 0 do {
        uiSleep  0.28;
        _cP = _cP + _cp_plus;
        _vendor setVariable["percent",_cP*100];
        if (_cP >= 1) exitWith {};
        if (player distance _vendor > 10) exitWith {};
    };
    if (player distance _vendor > 10) exitWith {hint localize "STR_Process_Stay";  life_is_processing = false; life_action_inUse = false;};

    {
        [false,(_x select 0),((_x select 1)*(_minimumConversions))] call life_fnc_handleInv;
    } count _oldItem;

    {
        [true,(_x select 0),((_x select 1)*(_minimumConversions))] call life_fnc_handleInv;
    } count _newItem;

    [_xp_per_weight * _oldItemWeight,"Verarbeitung"] spawn life_fnc_addexp;

    if (_minimumConversions isEqualTo (_totalConversions call BIS_fnc_lowestNum)) then {hint localize "STR_NOTF_ItemProcess";} else {hint localize "STR_Process_Partial";};
    life_is_processing = false; life_action_inUse = false;
} else {
    if (CASH < _cost) exitWith {hint format [localize "STR_Process_License",[_cost] call life_fnc_numberText]; "progressBar" cutText ["","PLAIN"]; life_is_processing = false; life_action_inUse = false;};

    for "_i" from 0 to 1 step 0 do {
        uiSleep  0.9;
        _cP = _cP + _cp_plus;
        _vendor setVariable["percent",_cP*100];
        if (_cP >= 1) exitWith {};
        if (player distance _vendor > 10) exitWith {};
    };

    if (player distance _vendor > 10) exitWith {hint localize "STR_Process_Stay";  life_is_processing = false; life_action_inUse = false;};
    if (CASH < _cost) exitWith {hint format [localize "STR_Process_License",[_cost] call life_fnc_numberText];  life_is_processing = false; life_action_inUse = false;};

    {
        [false,(_x select 0),((_x select 1)*(_minimumConversions))] call life_fnc_handleInv;
    } count _oldItem;

    {
        [true,(_x select 0),((_x select 1)*(_minimumConversions))] call life_fnc_handleInv;
    } count _newItem;

    [_xp_per_weight * _oldItemWeight,"Verarbeitung"] spawn life_fnc_addexp;

    if (_minimumConversions isEqualTo (_totalConversions call BIS_fnc_lowestNum)) then {hint localize "STR_NOTF_ItemProcess";} else {hint localize "STR_Process_Partial";};
    CASH = CASH - _cost;
    [0] call SOCK_fnc_updatePartial;
    life_is_processing = false;
    life_action_inUse = false;
};

