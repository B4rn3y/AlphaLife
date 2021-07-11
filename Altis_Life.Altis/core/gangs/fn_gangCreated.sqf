#include "..\..\script_macros.hpp"
/*
    File: fn_gangCreated.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Tells the player that the gang is created and throws him into it.
*/
private "_group";
life_action_gangInUse = nil;

if (BANK < (LIFE_SETTINGS(getNumber,"gang_price"))) exitWith {
    hint format [localize "STR_GNOTF_NotEnoughMoney",[((LIFE_SETTINGS(getNumber,"gang_price"))-BANK)] call life_fnc_numberText];
    [group player] remoteExec ["TON_fnc_removeGang",RSERV];
};

BANK = BANK - LIFE_SETTINGS(getNumber,"gang_price");
[1] call SOCK_fnc_updatePartial;

if!(24 in alpha_quests) then {
	[24] call life_fnc_quest_achieved;
};

[format [localize "STR_GNOTF_CreateSuccess",(group player) getVariable "gang_name",[(LIFE_SETTINGS(getNumber,"gang_price"))] call life_fnc_numberText]] spawn life_fnc_exp_hint;

uisleep 0.35;

life_gangData = [];
life_gangData set[0,((group player) getVariable["gang_id",-1])];  // id
life_gangData set[1,getPlayerUID player];  // owner
life_gangData set[2,((group player) getVariable["gang_name",""])];  // name
life_gangData set[3,8];  // maxmembers
life_gangData set[4,0];  // bank
life_gangData set[5,[[((group player) getVariable["gang_id",-1]),name player, getPlayerUID player,1,1,1,1,1,1,1,1]]];  // members
life_gangData set[6,[]];  // alliances
life_gangData set[7,((group player) getVariable["gang_tag",""])];  // tag
life_gangData set[8,0];  // tax
life_gangData set[9,0];  // public

[] spawn life_fnc_gangMenu;