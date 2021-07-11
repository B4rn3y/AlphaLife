
#include "..\..\script_macros.hpp"

private ["_display","_listNBox","_cur_sel","_gang_id","_grp","_grpMembers"];


_display = findDisplay 518845;
_listNBox = _display displayCtrl 1500;


_cur_sel = lnbCurSelRow _listNBox;
if(_cur_sel isEqualTo -1) exitWith {["Du hast Nichts ausgewählt"] spawn life_fnc_exp_hint;};



_gang_id = _listNBox lnbValue [_cur_sel, 0];

if(_gang_id isEqualTo -1) exitWith {["Keine valide Gang?"] spawn life_fnc_exp_hint;};

_grp = grpNull;
{
    if(_x getVariable["gang_id",-1] isEqualTo _gang_id) exitWith {_grp = _x;};
} foreach (allGroups);

if(isnull _grp) exitWith {["Die Gang konnte nicht gefunden werden O.o"] spawn life_fnc_exp_hint;};

_grpMembers = _group getVariable["gang_members",[]];
if(_grpMembers isEqualTo []) exitWith {};

[player] joinSilent _grp;


_grpMembers pushBack [_gang_id, name player, getPlayerUID player,0,0,0,0,0,0,0,0];
_grp setVariable["gang_members",_grpMembers,true];

life_gangData = [];
life_gangData set[0,_gang_id];  // id
life_gangData set[1,(_grp getVariable["gang_owner",""])];  // owner
life_gangData set[2,(_grp getVariable["gang_name",""])];  // name
life_gangData set[3,(_grp getVariable["gang_maxMembers",8])];  // maxmembers
life_gangData set[4,(_grp getVariable["gang_bank",0])];  // bank
life_gangData set[5,(_grp getVariable["gang_members",[]])];  // members
life_gangData set[6,(_grp getVariable["gang_alliances",[]])];  // alliances
life_gangData set[7,(_grp getVariable["gang_tag",""])];  // tag
life_gangData set[8,(_grp getVariable["gang_tax",0])];  // tax
life_gangData set[9,(_grp getVariable["gang_public",0])];  // public

[0,format["%1 ist der Gang beigetreten",profileName]] remoteExec["life_fnc_gangUpdate_client",_grp];

if (life_HC_isActive) then {
    [4,_group, getPlayerUID player] remoteExecCall ["HC_fnc_updateGang",HC_Life];
} else {
    [4,_group, getPlayerUID player] remoteExecCall ["TON_fnc_updateGang",RSERV];
};

if!(25 in alpha_quests) then {
    [25] call life_fnc_quest_achieved;
};