#include "\life_server\script_macros.hpp"
/*
    File: fn_removeGang.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Removes gang from database
*/
private ["_group","_groupID"];
_group = param [0,grpNull,[grpNull]];
if (isNull _group) exitWith {};

_groupID = _group getVariable ["gang_id",-1];
if (_groupID isEqualTo -1) exitWith {};

[format ["DELETE FROM gangs WHERE id = '%1';",_groupID],1] call DB_fnc_asyncCall;
[format ["DELETE FROM gang_members WHERE gang_id = '%1';",_groupID],1] call DB_fnc_asyncCall;

{_group setVariable [_x,nil,true];} forEach ["gang_id","gang_owner","gang_name","gang_members","gang_maxmembers","gang_bank","gang_alliances","gang_tag","gang_tax","gang_public"];


[_group] remoteExecCall ["life_fnc_gangDisbanded",(units _group)];
waitUntil {(units _group) isEqualTo []};
deleteGroup _group;