#include "..\script_macros.hpp"
/*
    File: configuration.sqf
    Author:

    Description:
    Master Life Configuration File
    This file is to setup variables for the client, there are still other configuration files in the system

*****************************
****** Backend Variables *****
*****************************
*/
life_action_delay = time;
life_trunk_vehicle = objNull;
life_session_completed = false;
life_garage_store = false;
life_session_tries = 0;
life_siren_active = false;
life_clothing_filter = 0;
life_redgull_effect = time;
life_is_processing = false;
life_bail_paid = false;
life_impound_inuse = false;
life_action_inUse = false;
life_spikestrip = objNull;
life_knockout = false;
life_interrupted = false;
life_respawned = false;
life_removeWanted = false;
life_action_gathering = false;
life_god = false;
life_frozen = false;
life_save_gear = [];
life_container_activeObj = objNull;
life_disable_getIn = false;
life_disable_getOut = false;
life_admin_debug = false;
life_civ_position = [];
life_markers = false;
life_markers_active = false;
life_canpay_bail = true;
life_storagePlacing = scriptNull;
life_hideoutBuildings = [];
life_firstSpawn = true;

if(isnil "LIFE_ID_RevealObjects") then {
    LIFE_ID_RevealObjects = -1;
};
LIFE_SAVED_NAME = "";
alpha_frogtime = 300;
alpha_time_wait_light = 0.5; // warnblinker wartezeit
life_fadeSound = 0;
alpha_xp = 0;
alpha_lvl = 0;
alpha_quests = [];
ALPHA_XP_FOR_THIS_LEVEL = 1000;
ALPHA_XP_CUR_LEVEL = 0;
ALPHA_XP_TONXT_LEVEL = getNumber(missionConfigFile >> "Life_Settings" >> "xp_first_level");;

//Minimum and maximum value you can select as radius with the slider
stig_sz_radius_min = 300;
stig_sz_radius_max = 2000;

//Enable/Disable the system for a side. True means the side can use it.
stig_sz_enable_WEST = true;
stig_sz_enable_EAST = true;
stig_sz_enable_GUER = false;
stig_sz_enable_CIV  = false;

//Optional. Here you can add a condition which must return true in order to activate the system for a player.
//Condition is executed locally on the player's machine. Only the condition of the player's side is used.
//For example this is useful if you have a life server and only want players with a minimum level to be able to use the system.
stig_sz_condition_WEST  = {true};
stig_sz_condition_EAST  = {true};
stig_sz_condition_GUER  = {true};
stig_sz_condition_CIV   = {true};

life_barrier_active = false;
life_barrier_activeObj = ObjNull;
life_placeables =
[
    ["Pylon","RoadCone_F"],
    ["Pylon mit Licht","RoadCone_L_F"],
    ["Holzabsperrung","RoadBarrier_F"],
    ["Holzabsperrung mit Licht","RoadBarrier_small_F"],
    ["Kunststoffabsperrung Orange","PlasticBarrier_03_orange_F"],
    ["Betonabsperrung","Land_CncBarrier_stripes_F"],
    ["Tragbares Licht","Land_PortableLight_single_F"],
    ["Tragbares Licht (Doppelt)","Land_PortableLight_double_F"],
    ["Schranke","Land_BarGate_F"]
];
life_bar_placey = [];


life_definePlaceables = //Array aller Absperrungen (Cop + Medic)
[
 "RoadCone_F",
 "RoadCone_L_F",
 "RoadBarrier_F",
 "RoadBarrier_small_F",
 "PlasticBarrier_03_orange_F",
 "Land_CncBarrier_stripes_F",
 "Land_PortableLight_single_F",
 "Land_PortableLight_double_F",
 "Land_BarGate_F"
];
life_bar_limit = 100; //Maximale Anzahl Absperrungen pro Person

//Settings
life_settings_enableNewsBroadcast = profileNamespace getVariable ["life_enableNewsBroadcast", true];
life_settings_enableSidechannel = profileNamespace getVariable ["life_enableSidechannel", true];
life_settings_tagson = profileNamespace getVariable ["life_settings_tagson", true];
life_settings_revealObjects = profileNamespace getVariable ["life_settings_revealObjects", true];
life_settings_viewDistanceFoot = profileNamespace getVariable ["life_viewDistanceFoot", 1250];
life_settings_viewDistanceCar = profileNamespace getVariable ["life_viewDistanceCar", 1250];
life_settings_viewDistanceAir = profileNamespace getVariable ["life_viewDistanceAir", 1250];

//Uniform price (0),Hat Price (1),Glasses Price (2),Vest Price (3),Backpack Price (4)
life_clothing_purchase = [-1, -1, -1, -1, -1];
/*
*****************************
****** Weight Variables *****
*****************************
*/
life_maxWeight = LIFE_SETTINGS(getNumber, "total_maxWeight");
life_carryWeight = 0; //Represents the players current inventory weight (MUST START AT 0).

/*
*****************************
****** Life Variables *******
*****************************
*/
life_net_dropped = false;
life_use_atm = true;
life_is_arrested = false;
life_is_alive = false;
life_delivery_in_progress = false;
life_thirst = 100;
life_hunger = 100;
CASH = 0;

life_istazed = false;
life_isknocked = false;
life_vehicles = [];

/*
    Master Array of items?
*/
//Setup variable inv vars.
{
    missionNamespace setVariable [ITEM_VARNAME(configName _x), 0];
} forEach ("true" configClasses (missionConfigFile >> "VirtualItems"));

/* Setup the BLAH! */
{
    _varName = getText(_x >> "variable");
    _sideFlag = getText(_x >> "side");

    missionNamespace setVariable [LICENSE_VARNAME(_varName,_sideFlag), false];
} forEach ("true" configClasses (missionConfigFile >> "Licenses"));

/* Setup life_hideoutBuildings */
{
    _building = nearestBuilding getMarkerPos _x;
    life_hideoutBuildings pushBack _building
} forEach (LIFE_SETTINGS(getArray,"gang_area"));
