#include "\life_server\script_macros.hpp"
/*
    File: fn_insertGang.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Inserts the gang into the database.
*/
private ["_ownerID","_gangName","_gangTag","_query","_queryResult","_gang_id"];
params [
    ["_ownerID",objNull,[objNull]],
    ["_uid","",[""]],
    ["_gangName","",[""]],
    ["_gangTag","",[""]]
];
_group = group _ownerID;

if (isNull _ownerID || _uid isEqualTo "" || _gangName isEqualTo "" || _gangTag isEqualTo "") exitWith {}; //Fail

_gangName = [_gangName] call DB_fnc_mresString;
_query = format ["SELECT id FROM gangs WHERE name='%1';",_gangName];

_queryResult = [_query,2] call DB_fnc_asyncCall;

//Check to see if the gang name already exists.
if (!(count _queryResult isEqualTo 0)) exitWith {
    ["There is already a gang created with that name please pick another name."] remoteExecCall ["life_fnc_exp_hint",_ownerID];
    life_action_gangInUse = nil;
    (owner _ownerID) publicVariableClient "life_action_gangInUse";
};

_query = format ["SELECT id FROM gang_members WHERE pid = '%1';",_uid];

_queryResult = [_query,2] call DB_fnc_asyncCall;

//Check to see if this person already owns or belongs to a gang.
if (!(count _queryResult isEqualTo 0)) exitWith {
    ["You are currently already active in a gang, please leave the gang first."] remoteExecCall ["life_fnc_exp_hint",_ownerID];
    life_action_gangInUse = nil;
    (owner _ownerID) publicVariableClient "life_action_gangInUse";
};


_query = format ["INSERT INTO gangs (name, tag) VALUES('%1','%2')",_gangName,_gangTag];
[_query,1] call DB_fnc_asyncCall;
uiSleep 0.35;

_query = format ["SELECT id FROM gangs WHERE name='%1';",_gangName];
_queryResult = [_query,2] call DB_fnc_asyncCall;


if (count _queryResult isEqualTo 0) exitWith {
    ["Es gab einen Error beim Erstellen der Gang :O"] remoteExecCall ["life_fnc_exp_hint",_ownerID];
    life_action_gangInUse = nil;
    (owner _ownerID) publicVariableClient "life_action_gangInUse";
};

_gang_id = _queryResult select 0;

_query = format ["INSERT INTO gang_members (gang_id, pid, leader, right_invite, right_expand, right_withdraw, right_skins, right_kick,right_house,right_garage) VALUES('%1','%2','1','1','1','1','1','1','1','1')",_gang_id,_uid];
[_query,1] call DB_fnc_asyncCall;



_group setVariable ["gang_id",_gang_id,true];
_group setVariable ["gang_owner",_uid,true];
_group setVariable ["gang_name",_gangName,true];
_group setVariable ["gang_maxMembers",8,true];
_group setVariable ["gang_bank",0,true];
_group setVariable ["gang_members",[[_gang_id,name _ownerID, _uid,1,1,1,1,1,1]],true];
_group setVariable ["gang_alliances",[],true];
_group setVariable ["gang_tag",_gangTag,true];
_group setVariable ["gang_tax",0,true];
_group setVariable ["gang_public",0,true];



[_group] remoteExec ["life_fnc_gangCreated",_ownerID];
