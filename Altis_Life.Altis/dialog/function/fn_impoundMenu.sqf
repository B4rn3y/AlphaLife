#include "..\..\script_macros.hpp"
/*
    File: fn_impoundMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Not actually a impound menu, may act as confusion to some but that is what I wanted.
    The purpose of this menu is it is now called a 'Garage' where vehicles are stored (persistent ones).
*/
private ["_vehicles","_lb"];
disableSerialization;
_vehicles = param [0,[],[[]]];

ctrlShow[2803,false]; // str text
ctrlShow[2830,false]; // veh info
ctrlShow[2810,false]; // right bckgrnd
ctrlShow[2404,false];   // gang btn
waitUntil {!isNull (findDisplay 2800)};

life_vehicles_garage_save = _vehicles;

_display = findDisplay 2800;
_lb = _display displayCtrl 2802;
_combo = _display displayCtrl 2100;
lbClear _combo;
lbClear _lb;


LIFE_VehGarage_Showcase = true;
[[21085.9,7201.58,5.7],15,15,3,0.1,"LIFE_VehGarage_Showcase"] spawn life_Fnc_circleCamera3D;


_show_room = [["Land_Dome_Big_F",[21086.8,7199.9,3.88774],0],["Land_PortableLight_double_F",[21078.7,7195.17,3.66855],227.292],["Land_PortableLight_double_F",[21092.2,7193.85,3.80264],131.95],["Land_PortableLight_double_F",[21080.9,7209.95,4.00876],326.079],["Land_PortableLight_double_F",[21093,7208.36,4.08824],47.7692],["Land_PortableLight_double_F",[21101.5,7197.07,3.91327],329.594],["Land_Coil_F",[21064.6,7200.63,3.22322],0.00143561],["Land_LampShabby_F",[21103,7201.69,4.045],267.77],["Land_FireExtinguisher_F",[21103.3,7197.6,3.93197],353.125],["Land_Pier_F",[21102.5,7193.01,1.53366],8.28224],["Land_LampShabby_F",[21064.2,7202.5,3.33553],88.8603],["Land_Cargo40_sand_F",[21074.1,7181.28,3.0691],32.8585],["Land_Coil_F",[21064.4,7204.58,3.33729],0.000455395],["Land_WeldingTrolley_01_F",[21101.7,7188.86,3.70779],97.5309],["Land_SatelliteAntenna_01_F",[21104.3,7199.76,7.13806],0],["Land_PlasticCase_01_medium_F",[21099.1,7212.9,4.30378],226.583],["Land_WoodenBox_F",[21066.9,7186.62,2.83461],86.5753],["Land_Device_disassembled_F",[21100.3,7211.49,4.23639],47.0605],["Land_MetalBarrel_F",[21098.5,7213.78,4.28577],359.976],["Land_Bricks_V3_F",[21069.3,7214.23,3.70424],47.331],["Land_WoodenBox_F",[21064.9,7189.44,2.85561],62.1137],["Land_WoodenBox_F",[21065.8,7187.57,2.81824],62.1295],["Land_LampShabby_F",[21081.2,7177.84,3.14989],357.512],["Land_WoodenBox_F",[21065.7,7187.58,3.19738],63.4137],["Land_Screwdriver_V2_F",[21102.6,7188.76,3.70034],229.345],["WaterPump_01_sand_F",[21080.2,7220.12,4.13105],159.77],["Land_PalletTrolley_01_yellow_F",[21092.9,7218.44,4.34195],0.993044],["Land_PlasticCase_01_medium_F",[21099.6,7213.54,4.32705],226.749],["Land_DieselGroundPowerUnit_01_F",[21078.1,7219.82,4.11824],340.367],["Land_Gloves_F",[21102.8,7188.7,3.70652],0.000113535],["Land_CampingTable_F",[21103,7188.68,3.70648],188.279],["Land_Hammer_F",[21103.1,7188.65,4.45588],69.9273],["Land_CinderBlocks_F",[21068.5,7215.19,3.68999],138.133],["Land_Pier_F",[21061.4,7198.99,0.744287],8.28224],["Land_Meter3m_F",[21103.4,7188.46,4.46652],327.766],["Land_Pier_F",[21104.5,7206.95,1.83323],8.28224],["Land_LampShabby_F",[21090.8,7177.68,3.38489],357.512],["Land_WaterTank_F",[21074.8,7219.42,4.05663],64.2634],["Land_CinderBlocks_F",[21069.3,7216.14,3.73354],138.12],["Land_DrillAku_F",[21103.7,7188.62,4.46954],0.0232012],["Land_Workbench_01_F",[21071.1,7217.58,3.8229],322.603],["Land_WaterTank_F",[21076.1,7220.14,4.10188],64.4041],["Land_LampShabby_F",[21081.5,7221.55,4.1745],181.553],["Land_CanisterFuel_F",[21104,7188.04,3.69744],8.15235],["Land_Pallets_stack_F",[21093.8,7219.61,4.41606],200.359],["Land_LampShabby_F",[21090.6,7221.74,4.444],180.442],["Land_EngineCrane_01_F",[21107.4,7192.92,3.78341],36.0993],["Land_Pallets_stack_F",[21094.3,7221.05,4.48628],200.355],["Land_PortableLight_double_F",[21103.3,7183.87,3.63823],171.579],["Land_Pallets_stack_F",[21095.8,7220.47,4.49989],200.359],["Land_GasTank_01_khaki_F",[21105.8,7187.87,3.69241],245.642],["Land_Pallets_stack_F",[21095.4,7220.7,5.31479],200.346],["Land_Pier_F",[21063.6,7213.35,1.1566],8.28224],["Land_GasTank_01_yellow_F",[21106.3,7188.26,3.69676],0.00139872],["Land_GasTank_01_khaki_F",[21106.6,7188.58,3.70014],0.0148735],["Land_PortableLight_double_F",[21108.8,7196.83,3.94507],63.2222],["Land_GasTank_01_khaki_F",[21106.2,7187.68,3.68772],245.646],["Land_CargoBox_V1_F",[21108.7,7202.47,4.06814],0.00289701],["Land_Pier_F",[21100.5,7178.94,1.19231],8.28224],["Land_Pier_F",[21059.5,7184.86,1.90735e-006],8.28224],["Land_Pier_F",[21106.6,7221.37,2.43676],8.28224],["Land_LandMark_F",[21080.5,7232.31,-0.00107193],184.949],["Land_Pier_F",[21065.5,7227.29,1.36568],8.28224],["Land_LandMark_F",[21122.4,7224.03,-0.000293732],184.949]];



_objects = [];
{
    _classname = _x select 0;
    _pos = _x select 1;
    _dir = _x select 2;

    _obj = _classname createVehicleLocal [0,0,0];
    _obj setposatl _pos;
    _obj setdir _dir;
    _objects pushBack _obj;

    if!(_classname in ["Land_LampShabby_F","Land_PortableLight_double_F"]) then {
        _obj enableSimulation false;

    };
    _obj allowdamage false;
} foreach _show_room;



LIFE_Garage_show_vehicle = objNull;
_combo lbAdd localize "STR_garage_your_vehicles_combo";
_combo lbAdd localize "STR_garage_gang_vehicles_combo";
_combo lbSetCurSel 0;

waitUntil {isNull (findDisplay 2800)};
LIFE_VehGarage_Showcase = nil;
life_vehicles_garage_save = nil;
{deleteVehicle _x;} foreach _objects;

if!(isnil "LIFE_Garage_show_vehicle") then
{
    deleteVehicle LIFE_Garage_show_vehicle;
    LIFE_Garage_show_vehicle = nil;
};
