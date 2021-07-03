#include "..\..\script_macros.hpp"
/*
    File: fn_insureCar.sqf
    Author: Guit0x "Lintox"
    Description:
    Insure a vehicle from the garage.
*/
private["_vehicle","_vehicleLife","_vid","_pid","_unit","_multiplier","_price","_purchasePrice","_insurancePrice"];
disableSerialization;
if ((lbCurSel 2802) isEqualTo -1) exitWith {hint localize "STR_Global_NoSelection"};
_vehicle = lbData[2802,(lbCurSel 2802)];
_vehicle = (call compile format["%1",_vehicle]) select 0;
_vehicleLife = _vehicle;
_vid = lbValue[2802,(lbCurSel 2802)];
_pid = getPlayerUID player;
_unit = player;
if(isNil "_vehicle") exitWith {hint localize "STR_Garage_Selection_Error"};
if ((time - life_action_delay) < 1.5) exitWith {hint localize "STR_NOTF_ActionDelay";};
if (!isClass (missionConfigFile >> "LifeCfgVehicles" >> _vehicleLife)) then {
    _vehicleLife = "Default"; //Use Default class if it doesn't exist
    diag_log format["%1: LifeCfgVehicles class doesn't exist",_vehicle];
};
_price = 0;
_multiplier = LIFE_SETTINGS(getNumber,"vehicle_insurance_multiplier");
switch (playerSide) do {
    case civilian: {
        _price = M_CONFIG(getNumber,"LifeCfgVehicles",_vehicleLife,"price");
    };
    case west: {
        _price = if(M_CONFIG(getNumber,"LifeCfgVehicles",_vehicleLife,"price_cop") isEqualTo 0) then {M_CONFIG(getNumber,"LifeCfgVehicles",_vehicleLife,"price")} else {M_CONFIG(getNumber,"LifeCfgVehicles",_vehicleLife,"price_cop")};
    };
    case independent: {
        _price = if(M_CONFIG(getNumber,"LifeCfgVehicles",_vehicleLife,"price_med") isEqualTo 0) then {M_CONFIG(getNumber,"LifeCfgVehicles",_vehicleLife,"price")} else {M_CONFIG(getNumber,"LifeCfgVehicles",_vehicleLife,"price_med")};
    };
};
_insurancePrice = _price * _multiplier;
_insurancePrice = round (_insurancePrice);
if(!(_insurancePrice isEqualType 0) || _insurancePrice < 1) then {_insurancePrice = 500};
if(BANK < _insurancePrice) exitWith {hint format[(localize "STR_GNOTF_NotEnoughMoney"),[_insurancePrice] call life_fnc_numberText];};

_action = [
    format["Bist du dir sicher, dass du $%1 für eine Versicherung ausgeben willst?",_insurancePrice],
    "BESTÄTIGUNG",
    "NE",
    "JA"
    ] call BIS_fnc_guiMessage;

if(BANK < _insurancePrice) exitWith {hint format[(localize "STR_GNOTF_NotEnoughMoney"),[_insurancePrice] call life_fnc_numberText];};
if!(_action) then {

    if (life_HC_isActive) then {
        [_vid,_pid] remoteExecCall ["HC_fnc_insureCar",HC_Life];
    } else {
        [_vid,_pid] remoteExecCall ["TON_fnc_insureCar",RSERV];
    };
    ["Versicherung erfolgreich gekauft"] spawn life_fnc_exp_hint;
    BANK = BANK - _insurancePrice;
    [2] call SOCK_fnc_updatePartial;
    life_action_delay = time;
    closeDialog 0;
};