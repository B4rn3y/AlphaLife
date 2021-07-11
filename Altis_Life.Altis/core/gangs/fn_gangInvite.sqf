#include "..\..\script_macros.hpp"
/*
    File: fn_gangInvite.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Prompts the player about an invite.
*/
private ["_action","_grpMembers"];
params [
    ["_name","",[""]],
    ["_group",grpNull,[grpNull]]
];

if (_name isEqualTo "" || isNull _group) exitWith {}; //Fail horn anyone?
if (!isNil {(group player) getVariable "gang_name"}) exitWith {hint localize "STR_GNOTF_AlreadyInGang";};

_gangName = _group getVariable "gang_name";
_action = [
    format [localize "STR_GNOTF_InviteMSG",_name,_gangName],
    localize "STR_Gang_Invitation",
    localize "STR_Global_Yes",
    localize "STR_Global_No"
] call BIS_fnc_guiMessage;

if (_action) then {
    [player] joinSilent _group;
    _grpMembers = _group getVariable["gang_members",[]];
    _grpMembers pushBack [_group getVariable["gang_id",-1], name player, getPlayerUID player,0,0,0,0,0,0,0,0];
    _group setVariable["gang_members",_grpMembers,true];

    life_gangData = [];
    life_gangData set[0,(_group getVariable["gang_id",-1])];  // id
    life_gangData set[1,(_group getVariable["gang_owner",""])];  // owner
    life_gangData set[2,(_group getVariable["gang_name",""])];  // name
    life_gangData set[3,(_group getVariable["gang_maxMembers",8])];  // maxmembers
    life_gangData set[4,(_group getVariable["gang_bank",0])];  // bank
    life_gangData set[5,(_group getVariable["gang_members",[]])];  // members
    life_gangData set[6,(_group getVariable["gang_alliances",[]])];  // alliances
    life_gangData set[7,(_group getVariable["gang_tag",""])];  // tag
    life_gangData set[8,(_group getVariable["gang_tax",0])];  // tax
    life_gangData set[9,(_group getVariable["gang_public",0])];  // public

    [0,format["%1 ist der Gang auf Einladung von %2 beigetreten",profileName, _name]] remoteExec["life_fnc_gangUpdate_client",_group];
    if (life_HC_isActive) then {
        [4,_group, getPlayerUID player] remoteExecCall ["HC_fnc_updateGang",HC_Life];
    } else {
        [4,_group, getPlayerUID player] remoteExecCall ["TON_fnc_updateGang",RSERV];
    };

    if!(25 in alpha_quests) then {
        [25] call life_fnc_quest_achieved;
    };

};
