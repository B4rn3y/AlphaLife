/*
    Author: GetSomePanda / Panda
    SteamID: 76561198145366418
    File Name: fn_handleBlastingCharge.sqf
    Information: Nothing really special, just handles the fed explosion over the server so if the client who place the charge logs out it still blows up.
*/
private ["_vault","_sender","_time","_bomb"];
_vault = param[0,objNull,[objNull]];
_sender = param[1,objNull,[objNull]];
if(isnull _vault) exitWith {};
_time = time + (15 * 60);
waitUntil{(round(_time - time) < 1)};
sleep 0.9;
if (!(_vault getVariable["chargeplaced",false])) exitWith {};

_bomb = "Bo_GBU12_LGB_MI10" createVehicle [getPosATL _vault select 0, getPosATL _vault select 1, (getPosATL _vault select 2)+0.5];
_vault setVariable ["chargeplaced",false,true];
_vault setVariable ["safe_open",true,true];

if!(isnull _sender) then {
	[35] remoteexec["life_fnc_quest_achieved",_sender];
};