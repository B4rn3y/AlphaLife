#include "..\..\script_macros.hpp"
/*
    File: fn_clearVehicleAmmo.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Clears the vehicle of ammo types that we don't want.

    Syntax: _vehicle removeMagazinesTurret [magazineName, turretPath]
    Documentation: https://community.bistudio.com/wiki/removeMagazinesTurret
*/
private ["_vehicle","_veh"];
_vehicle = [_this,0,objNull,[objNull]] call BIS_fnc_param;
if (isNull _vehicle) exitWith {};
_veh = typeOf _vehicle;

if (_veh isEqualTo "B_Boat_Armed_01_minigun_F") then {
    _vehicle removeMagazinesTurret ["200Rnd_40mm_G_belt",[0]];
};

if (_veh isEqualTo "B_APC_Wheeled_01_cannon_F") then {
    _vehicle removeMagazinesTurret ["60Rnd_40mm_GPR_Tracer_Red_shells",[0]];
    _vehicle removeMagazinesTurret ["40Rnd_40mm_APFSDS_Tracer_Red_shells",[0]];
};

if (_veh isEqualTo "O_Heli_Attack_02_black_F") then {
    _vehicle removeMagazinesTurret ["250Rnd_30mm_APDS_shells",[0]];
    _vehicle removeMagazinesTurret ["8Rnd_LG_scalpel",[0]];
    _vehicle removeMagazinesTurret ["38Rnd_80mm_rockets",[0]];
};

if (_veh isEqualTo "B_Heli_Transport_01_F") then {  // ghost hawk
    _vehicle removeMagazinesTurret ["2000Rnd_65x39_Belt_Tracer_Red",[1]];
    _vehicle removeMagazinesTurret ["2000Rnd_65x39_Belt_Tracer_Red",[2]];
};

if (_veh isEqualTo "O_Heli_Attack_02_dynamicLoadout_F") then {   // kajman
    {_vehicle removeMagazinesTurret [_x,[0]];} foreach ["250Rnd_30mm_HE_shells_Tracer_Green","250Rnd_30mm_APDS_shells_Tracer_Green","Laserbatteries","PylonRack_4Rnd_LG_scalpel","PylonRack_19Rnd_Rocket_Skyfire","PylonRack_19Rnd_Rocket_Skyfire","PylonRack_4Rnd_LG_scalpel"];
};

if (_veh isEqualTo "B_Heli_Attack_01_dynamicLoadout_F") then {   // Blackfoot
    {_vehicle removeMagazinesTurret [_x,[0]];} foreach ["1000Rnd_20mm_shells","Laserbatteries","PylonMissile_1Rnd_AAA_missiles","PylonMissile_1Rnd_AAA_missiles","PylonRack_12Rnd_PG_missiles","PylonRack_12Rnd_PG_missiles","PylonMissile_1Rnd_AAA_missiles","PylonMissile_1Rnd_AAA_missiles"];
};

if (_veh isEqualTo "O_T_VTOL_02_vehicle_dynamicLoadout_F") then {   // y-32
    {_vehicle removeMagazinesTurret [_x,[0]];} foreach ["250Rnd_30mm_HE_shells_Tracer_Green","250Rnd_30mm_APDS_shells_Tracer_Green","Laserbatteries","PylonRack_4Rnd_LG_scalpel","PylonRack_19Rnd_Rocket_Skyfire","PylonRack_19Rnd_Rocket_Skyfire","PylonRack_4Rnd_LG_scalpel"];
};





clearWeaponCargoGlobal _vehicle;
clearMagazineCargoGlobal _vehicle;
clearItemCargoGlobal _vehicle;
clearBackpackCargoGlobal _vehicle;
