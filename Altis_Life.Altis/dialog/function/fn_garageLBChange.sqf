#include "..\..\script_macros.hpp"
/*
    File: fn_garageLBChange.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Can't be bothered to answer it.. Already deleted it by accident..
*/
disableSerialization;
private ["_control","_index","_dataArr","_className","_classNameLife","_display","_insure_btn","_gang_btn","_vehicleColor","_vehicleInfo","_trunkSpace","_storageFee","_price","_purchasePrice","_sellMultiplier","_retrievePrice","_sellPrice","_vehicleskins","_foreachindex","_material_ID","_material"];
_control = _this select 0;
_index = _this select 1;

//Fetch some information.
_dataArr = CONTROL_DATAI(_control,_index);
_dataArr = call compile format ["%1",_dataArr];
_className = (_dataArr select 0);
_classNameLife = _className;

_display = findDisplay 2800;
_insure_btn = _display displayCtrl 97480;
_gang_btn = _display displayCtrl 2404;
_unimpound_btn = _display displayCtrl 5213;
_sell_btn = _display displayCtrl  7845;

_sell_btn ctrlEnable true;
_unimpound_btn ctrlEnable true;
if((_dataArr select 7) isEqualTo 1) then {
    _insure_btn ctrlEnable false;
} else {
    _insure_btn ctrlEnable true;
};

if (!isClass (missionConfigFile >> "LifeCfgVehicles" >> _classNameLife)) then {
    _classNameLife = "Default"; //Use Default class if it doesn't exist
    diag_log format ["%1: LifeCfgVehicles class doesn't exist",_className];
};
_vehicleColor = "Default";
if!((_dataArr select 1) isEqualTo -1) then {
    _vehicleColor = ((M_CONFIG(getArray,"LifeCfgVehicles",_classNameLife,"textures") select (_dataArr select 1)) select 0);
};
if (isNil "_vehicleColor") then {_vehicleColor = "Default";};

_vehicleInfo = [_className] call life_fnc_fetchVehInfo;
_trunkSpace = [_className] call life_fnc_vehicleWeightCfg;


_storageFee = LIFE_SETTINGS(getNumber,"vehicle_storage_fee_multiplier");


_price = switch (playerSide) do
{
    case west:
    {
        if(getnumber(missionConfigFile >> "LifeCfgVehicles" >> _classNameLife>>"price_cop") isEqualTo 0) then {M_CONFIG(getNumber,"LifeCfgVehicles",_classNameLife,"price")} else {getnumber(missionConfigFile >> "LifeCfgVehicles" >> _classNameLife>>"price_cop")};
    };

    case independent:
    {
        if(getnumber(missionConfigFile >> "LifeCfgVehicles" >> _classNameLife>>"price_med") isEqualTo 0) then {M_CONFIG(getNumber,"LifeCfgVehicles",_classNameLife,"price")} else {getnumber(missionConfigFile >> "LifeCfgVehicles" >> _classNameLife>>"price_med")};
    };

    default
    {
        M_CONFIG(getNumber,"LifeCfgVehicles",_classNameLife,"price");
    };
};


switch (playerSide) do {
    case civilian: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_CIVILIAN");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_CIVILIAN");
    };
    case west: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_COP");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_COP");
    };
    case independent: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_MEDIC");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_MEDIC");
    };
    case east: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_OPFOR");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_OPFOR");
    };
};
_retrievePrice = _purchasePrice * _storageFee;
_sellPrice = _purchasePrice * _sellMultiplier;

if (!(_sellPrice isEqualType 0) || _sellPrice < 1) then {_sellPrice = 500;};
if (!(_retrievePrice isEqualType 0) || _retrievePrice < 1) then {_retrievePrice = 500;};

(CONTROL(2800,2803)) ctrlSetStructuredText parseText format [
    (localize "STR_Shop_Veh_UI_RetrievalP")+ " <t color='#8cff9b'>$%1</t><br/>"
    +(localize "STR_Shop_Veh_UI_SellP")+ " <t color='#8cff9b'>$%2</t><br/>"
    +(localize "STR_Shop_Veh_UI_Color")+ " %8<br/>"
    +(localize "STR_Shop_Veh_UI_MaxSpeed")+ " %3 km/h<br/>"
    +(localize "STR_Shop_Veh_UI_HPower")+ " %4<br/>"
    +(localize "STR_Shop_Veh_UI_PSeats")+ " %5<br/>"
    +(localize "STR_Shop_Veh_UI_Trunk")+ " %6<br/>"
    +(localize "STR_Shop_Veh_UI_Fuel")+ " %7<br/>"
    +(localize "STR_Shop_Veh_UI_insured")+ " %9<br/>"
    +(localize "STR_Shop_Veh_UI_nitro")+ " %10<br/>"
    +(localize "STR_Shop_Veh_UI_oil")+ " %11<br/>",
[_retrievePrice] call life_fnc_numberText,
[_sellPrice] call life_fnc_numberText,
(_vehicleInfo select 8),
(_vehicleInfo select 11),
(_vehicleInfo select 10),
if (_trunkSpace isEqualTo -1) then {"None"} else {_trunkSpace},
(_vehicleInfo select 12),
_vehicleColor,
(_dataArr select 7),
(_dataArr select 2),
(_dataArr select 3)
];

ctrlShow[2803,true]; // str text
ctrlShow[2830,true]; // veh info
ctrlShow[2810,true]; // right bckgrnd
if(!(playerSide in [west,opfor,independent]) && ((_dataArr select 10) isEqualTo getplayeruid player) && ((group player getVariable["gang_id",-1]) != -1)) then {
    ctrlShow[2404,true];
    if((_dataArr select 9) isEqualTo -1) then {
        _gang_btn ctrlSetText localize "STR_gang_garage_add";
        _gang_btn buttonSetAction "[true] spawn life_fnc_garage_set_gang;";
    } else {
        _gang_btn ctrlSetText localize "STR_gang_garage_remove";
        _gang_btn buttonSetAction "[false] spawn life_fnc_garage_set_gang;";
    };
} else {
    ctrlShow[2404,false];
};

if(!((_dataArr select 9) isEqualTo -1) && !((_dataArr select 10) isEqualTo getplayeruid player)) then {
    _entry = [getplayeruid player] call life_fnc_gang_find_member_entry;
    if(_entry isEqualTo []) exitWith {_unimpound_btn ctrlEnable false;};
    if((_entry select 10) isEqualTo 1) then {
        _unimpound_btn ctrlEnable true;
    } else {
        _unimpound_btn ctrlEnable false;
    };
};

if!((_dataArr select 9) isEqualTo -1) then {
    _sell_btn ctrlEnable false;
};


deleteVehicle LIFE_Garage_show_vehicle;

waitUntil {if(isnil "LIFE_Garage_show_vehicle") exitWith{true}; isnull LIFE_Garage_show_vehicle};



LIFE_Garage_show_vehicle = _className createVehicleLocal [23194.8,28544,50000.861];
LIFE_Garage_show_vehicle setposatl [21085.9,7202.44,3.93473];
LIFE_Garage_show_vehicle enableSimulation false;
LIFE_Garage_show_vehicle setDir 359.072;


_vehicleskins = [];
if!((_dataArr select 1) isEqualTo -1) then {
    _vehicleskins = ((M_CONFIG(getArray,"LifeCfgVehicles",_classNameLife,"textures") select (_dataArr select 1)) select 2);
};

if(isnil "_vehicleskins") then {_vehicleskins = [];};

{LIFE_Garage_show_vehicle setObjectTexture[_foreachindex,_x];} foreach _vehicleskins;
_material_ID = _dataArr select 6;
if!(_material_ID isEqualTo -1) then {
    _material = (getarray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "materials") select _material_ID) select 0;
    {
        LIFE_Garage_show_vehicle setObjectMaterial[_foreachindex, _material];
    } foreach (getObjectMaterials LIFE_Garage_show_vehicle);
};