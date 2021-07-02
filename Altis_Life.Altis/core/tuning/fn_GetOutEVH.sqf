private ["_unit","_role","_vehicle","_turret","_display"];


params ["_unit", "_role", "_vehicle", "_turret"];



_display = uiNamespace getvariable["hud_veh",displayNull];
if(isnull _display) exitWith {};

15 cutText ["", "PLAIN"];

uiNamespace setvariable["hud_veh",nil];