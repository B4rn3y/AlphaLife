#include "..\..\script_macros.hpp"
/*
    File: fn_initGang.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Main initialization for gangs.
*/
private ["_exitLoop","_group","_wait"];
if !(playerSide isEqualTo civilian) exitWith {}; //What in the hell?
[player] joinSilent (createGroup civilian);
if (count life_gangData isEqualTo 0) exitWith {}; //Dafuq?

_life_gangdata_save = life_gangData;
life_gangData = [];
life_gangData set[0,(_life_gangdata_save select 1) select 0];  // id

_owner = "";
{
    if((_x select 3) isEqualTo 1) exitWith {_owner=_x select 2;};
} foreach (_life_gangdata_save select 0);

life_gangData set[1,_owner];  // owner
life_gangData set[2,(_life_gangdata_save select 1) select 1];  // name
life_gangData set[3,(_life_gangdata_save select 1) select 4];  // maxmembers
life_gangData set[4,(_life_gangdata_save select 1) select 5];  // bank
life_gangData set[5,(_life_gangdata_save select 0)];  // members
life_gangData set[6,(_life_gangdata_save select 1) select 3];  // alliances
life_gangData set[7,(_life_gangdata_save select 1) select 2];  // tag
life_gangData set[8,(_life_gangdata_save select 1) select 6];  // tax
life_gangData set[9,(_life_gangdata_save select 1) select 7];  // public


// life_gangdata = [id, owner, name, maxmembers, bank, members, alliances, tag, tax, public]

/*
[
    [
        [1,"Inch Messerschmitt","76561198158204122",0,1,1,1,1,1],
        [1,"Barney","76561198018512569",1,1,1,1,1,1]
    ],
    [1,"Dein Gangname","DGN",[],8,0,0,0]
]
*/


_wait = round(random(8));
sleep _wait;

//Loop through to make sure there is not a group already created with the gang.
_exitLoop = false;
{
    _groupName = _x getVariable "gang_name";
    if (!isNil "_groupName") then {
        _groupOwner = _x getVariable ["gang_owner",""];
        _groupID = _x getVariable "gang_id";
        if (_groupOwner isEqualTo "" || isNil "_groupID") exitWith {}; //Seriously?
        if ((life_gangData select 0) isEqualTo _groupID && {(life_gangData select 1) isEqualTo _groupOwner}) exitWith {_group = _x; _exitLoop = true;};
    };
} forEach allGroups;

if (!isNil "_group") then {
    [player] joinSilent _group;
    if ((life_gangData select 1) isEqualTo getPlayerUID player) then {
        _group selectLeader player;
        [player,_group] remoteExecCall ["TON_fnc_clientGangLeader",(units _group)];
    };
} else {
    _group = group player;
    _group setVariable ["gang_id",(life_gangData select 0),true];
    _group setVariable ["gang_owner",(life_gangData select 1),true];
    _group setVariable ["gang_name",(life_gangData select 2),true];
    _group setVariable ["gang_maxMembers",(life_gangData select 3),true];
    _group setVariable ["gang_bank",(life_gangData select 4),true];
    _group setVariable ["gang_members",(life_gangData select 5),true];
    _group setVariable ["gang_alliances",(life_gangData select 6),true];
    _group setVariable ["gang_tag",(life_gangData select 7),true];
    _group setVariable ["gang_tax",(life_gangData select 8),true];
    _group setVariable ["gang_public",(life_gangData select 9),true];
};
