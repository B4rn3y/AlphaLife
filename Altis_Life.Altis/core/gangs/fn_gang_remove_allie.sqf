

#include "..\..\script_macros.hpp"


private ["_display","_listNBox","_cur_sel","_my_gang_id","_gang_id","_grp","_alliances","_index","_foreachindex"];

_display = findDisplay 518845;
_listNBox = _display displayCtrl 1500;


_cur_sel = lnbCurSelRow _listNBox;
if(_cur_sel isEqualTo -1) exitWith {["Du hast Nichts ausgewählt"] spawn life_fnc_exp_hint;};

_my_gang_id = (group player) getVariable["gang_id",-1];
if(_my_gang_id isEqualTo -1) exitWith {["Probleme oder so in meiner Gang? Exiting"] spawn life_fnc_exp_hint;};

_gang_id = _listNBox lnbValue [_cur_sel, 0];

if(_gang_id isEqualTo -1) exitWith {["Keine valide Gang?"] spawn life_fnc_exp_hint;};

_grp = grpNull;
{
    if(_x getVariable["gang_id",-1] isEqualTo _gang_id) exitWith {_grp = _x;};
} foreach (allGroups);

if!(isnull _grp) then {
	_alliances = (group player) getVariable["gang_alliances",[]];
	_index = -1;
	{if((_x select 0) isEqualTo _gang_id) exitWith {_index = _foreachindex;};} foreach _alliances;
	_alliances deleteAt _index;
	(group player) setVariable["gang_alliances",_alliances,true];
	[3,format["Ihr habt die Allianz mit %1 beendet",(_grp getVariable["gang_name",""])]] remoteExec["life_fnc_gangUpdate_client",(group player)];



	_alliances = _grp getVariable["gang_alliances",[]];
	_index = -1;
	{if((_x select 0) isEqualTo _my_gang_id) exitWith {_index = _foreachindex;};} foreach _alliances;
	_alliances deleteAt _index;
	_grp setVariable["gang_alliances",_alliances,true];
	[3] remoteExec["life_fnc_gangUpdate_client",_grp];

	if (life_HC_isActive) then {
	    [7,group player,((group player) getVariable["gang_alliances",[]]),_gang_id,(_grp getVariable["gang_alliances",[]])] remoteExec ["HC_fnc_updateGang",HC_Life]; //Update the database.
	} else {
	    [7,group player,((group player) getVariable["gang_alliances",[]]),_gang_id,(_grp getVariable["gang_alliances",[]])] remoteExec ["TON_fnc_updateGang",RSERV]; //Update the database.
	};

} else {
	_alliances = (group player) getVariable["gang_alliances",[]];
	_index = -1;
	{if((_x select 0) isEqualTo _gang_id) exitWith {_index = _foreachindex;};} foreach _alliances;
	_gang_name = ((_alliances select _index) select 1);
	_alliances deleteAt _index;
	(group player) setVariable["gang_alliances",_alliances,true];
	[3,format["Ihr habt die Allianz mit %1 beendet",_gang_name]] remoteExec["life_fnc_gangUpdate_client",(group player)];

	if (life_HC_isActive) then {
	    [8,group player,_alliances,_gang_id] remoteExec ["HC_fnc_updateGang",HC_Life]; //Update the database.
	} else {
	    [8,group player,_alliances,_gang_id] remoteExec ["TON_fnc_updateGang",RSERV]; //Update the database.
	};

};





if!(isnull findDisplay 518845) then {
	[] call life_fnc_gang_allie_menu;
};







