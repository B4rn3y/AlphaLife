
private ["_grp","_requester","_gang_id","_gang_name","_action","_alliances"];

_grp = param[0,grpNull,[grpNull]];
_requester = param[1,objNull,[objNull]];

if(isnull _grp || isnull _requester) exitWith {};

_gang_id = _grp getvariable["gang_id",-1];
if(_gang_id isEqualTo -1) exitWith {};

_gang_name = _grp getvariable["gang_name",""];
if(_gang_name isEqualTo "") exitWith {};


_action = [
    format ["Die Gang %2 (Anführer: %1) möchte mit deiner Gang ein Bündnis eingehen, solltest du annehmen werdet ihr euch gegenseitig auf der Karte sehen können.", name _requester, _gang_name],
    "Einladung",
    "Annehmen",
    "Ablehnen"
] call BIS_fnc_guiMessage;

if(_action) then {
	_alliances = (group player) getVariable["gang_alliances",[]];
	_alliances pushBack [_gang_id,_gang_name];
	(group player) setVariable["gang_alliances",_alliances,true];
	[3] remoteExec["life_fnc_gangUpdate_client",(group player)];

	[group player] remoteExec ["life_fnc_gang_invite_allie_resp_received",_requester];
} else {
	[format["Die Gang %1 hat die Allianz abgelehnt",(group player) getVariable["gang_name","No name"]]] remoteExec["life_fnc_exp_hint",_requester];
};