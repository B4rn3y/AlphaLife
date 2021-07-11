#include "..\..\script_macros.hpp"
private ["_grp","_gang_id","_gang_name","_alliances"];


_grp = param[0,grpNull,[grpNull]];

if(isnull _grp) exitWith {};

_gang_id = _grp getvariable["gang_id",-1];
if(_gang_id isEqualTo -1) exitWith {};

_gang_name = _grp getvariable["gang_name",""];
if(_gang_name isEqualTo "") exitWith {};

_alliances = (group player) getVariable["gang_alliances",[]];
_alliances pushBack [_gang_id,_gang_name];
(group player) setVariable["gang_alliances",_alliances,true];
[3,format["Ihr seid eine Allianz mit %1 eingegangen",(_grp getVariable["gang_name",""])]] remoteExec["life_fnc_gangUpdate_client",(group player)];


if (life_HC_isActive) then {
    [7,group player,_alliances,_grp getVariable["gang_id",-1],_grp getVariable["gang_alliances",[]]] remoteExec ["HC_fnc_updateGang",HC_Life]; //Update the database.
} else {
    [7,group player,_alliances,_grp getVariable["gang_id",-1],_grp getVariable["gang_alliances",[]]] remoteExec ["TON_fnc_updateGang",RSERV]; //Update the database.
};

if!(isnull findDisplay 518845) then {
	[] call life_fnc_gang_allie_menu;
};