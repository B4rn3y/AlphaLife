#include "..\..\script_macros.hpp"

private ["_owner","_public"];

_owner = (group player) getVariable["gang_owner",""];


if!((getplayeruid player) isEqualTo _owner) exitWith {["Nur der Gründer kann dies tun"] spawn life_fnc_exp_hint;};
if!(isnil "life_time_wait_public") exitWith {["Das geht jetzt noch nicht"] spawn life_fnc_exp_hint;};

_public = (group player) getVariable["gang_public",0];


if(_public isEqualTo 0) then {
	(group player) setVariable["gang_public",1,true];
} else {
	(group player) setVariable["gang_public",0,true];
};

life_time_wait_public = true;

[5,if(_public isEqualTo 0) then {"Der Gründer hat die Gang öffentlich gemacht"} else {"Der Gründer hat die Gang für die Öffenltichkeit geschlossen"}] remoteExec["life_fnc_gangUpdate_client",(group player)];





if (life_HC_isActive) then {
    [11,group player] remoteExec ["HC_fnc_updateGang",HC_Life]; //Update the database.
} else {
    [11,group player] remoteExec ["TON_fnc_updateGang",RSERV]; //Update the database.
};

0 spawn {sleep 10; life_time_wait_public = nil;};