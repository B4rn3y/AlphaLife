




private ["_display","_listNBox","_cur_sel","_gang_id","_grp","_gang_owner","_obj"];

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

_gang_owner = _grp getVariable["gang_owner",""];
if(_gang_owner isEqualTo "") exitWith {};

_obj = [_gang_owner] call life_fnc_findPlayerOfPID;
if(isnull _obj) exitWith {["Der Anführer dieser Gruppierung ist nicht online."] spawn life_fnc_exp_hint;};


if(missionNamespace getVariable[format["alpha_group_time_%1",_gang_owner], false]) exitWith {["Du hast dieser Gang eben erst eine Anfrage geschickt, dies geht jetzt noch nicht"] spawn life_fnc_exp_hint;};

["Anfrage wurde an der Anführer dieser Gang gesendet"] spawn life_fnc_exp_hint;

[group player, player] remoteExec["life_fnc_gang_invite_allie_received",_obj];


missionNamespace setvariable[format["alpha_group_time_%1",_gang_owner], true];


_gang_owner spawn { sleep 60; missionNamespace setvariable[format["alpha_group_time_%1",_this], nil];};