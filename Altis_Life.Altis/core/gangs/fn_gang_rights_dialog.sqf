#include "..\..\script_macros.hpp"

private ["_update","_exit","_entry","_unitID","_members","_index","_foreachindex","_display","_lb","_str_text"];

_update = param[0,false,[false]];

_exit = false;
_entry = [];

if!(_update) then {
	if ((lbCurSel 2621) isEqualTo -1) exitWith {hint localize "STR_GNOTF_SelectKick";_exit = true;};

	_unitID = lbData[2621,(lbCurSel 2621)];

	if (_unitID isEqualTo getPlayerUID player) exitWith {["Wegen Leuten wie dir muss man hier ewig viele Kontrollstrukturen machen, ich hasse dich >:("] spawn life_fnc_exp_hint;_exit = true;};


	_members = group player getVariable "gang_members";
	if (isNil "_members") exitWith {_exit = true;};
	if (!(_members isEqualType [])) exitWith {_exit = true;};

	_index = -1;
	{
		if((_x select 2) isEqualTo _unitID) exitWith {_index = _foreachindex};
	} foreach _members;
	if(_index isEqualTo -1) exitWith {["Spieler konnte nicht gefunden werden O.o"] spawn life_fnc_exp_hint;_exit = true;};


	_entry = _members select _index;

	if!(createDialog "gang_set_rights") exitWith {_exit = true;};

} else {
	if(isnull (findDisplay 23541)) exitWith {_exit = true;};
};

if!(isnil "life_gang_rights_save") then {
	_entry = life_gang_rights_save;
};

if(_exit) exitWith {};

_display = findDisplay 23541;

_lb = _display displayCtrl 1500;
_str_text = _display displayCtrl 1100;
_str_text_header = _display displayCtrl 1000;

_str_text_header ctrlSetStructuredText parseText format["<t color='#FF8000'>Rechte: </t><t>%1</t>",_entry select 1];

_str_text ctrlSetStructuredText parseText "<t color='#FF8000' align='center'>Information:</t><br/><t  align='center'>Doppelklick auf die Rechte ändert diese. Wenn du fertig bist Menü einfach schließen, die Rechte werden dann automatisch übernommen.</t>";
lbClear _lb;

{
	switch (_foreachindex) do
	{
		case 4: // invite
		{
			_id = _lb lbadd "- Einladen";
			_lb lbSetValue[_id,_foreachindex];
			if(_x isEqualTo 1) then {
				_lb lbSetColor[_id,[0,1,0,1]];
			} else {
				_lb lbSetColor[_id,[1,0,0,1]];
			};
		};

		case 5: // expand
		{
			_id = _lb lbadd "- Gang erweitern";
			_lb lbSetValue[_id,_foreachindex];
			if(_x isEqualTo 1) then {
				_lb lbSetColor[_id,[0,1,0,1]];
			} else {
				_lb lbSetColor[_id,[1,0,0,1]];
			};
		};

		case 6: // withdraw
		{
			_id = _lb lbadd "- Geld vom Gangkonto abheben";
			_lb lbSetValue[_id,_foreachindex];
			if(_x isEqualTo 1) then {
				_lb lbSetColor[_id,[0,1,0,1]];
			} else {
				_lb lbSetColor[_id,[1,0,0,1]];
			};
		};

		case 7: // skins
		{
			_id = _lb lbadd "- Zugriff auf Gangskins (falls vorhanden)";
			_lb lbSetValue[_id,_foreachindex];
			if(_x isEqualTo 1) then {
				_lb lbSetColor[_id,[0,1,0,1]];
			} else {
				_lb lbSetColor[_id,[1,0,0,1]];
			};
		};

		case 8: // kick
		{
			_id = _lb lbadd "- Mitglieder kicken";
			_lb lbSetValue[_id,_foreachindex];
			if(_x isEqualTo 1) then {
				_lb lbSetColor[_id,[0,1,0,1]];
			} else {
				_lb lbSetColor[_id,[1,0,0,1]];
			};
		};

		case 9: // house
		{
			_id = _lb lbadd "- Zugriff auf das Gang-Haus (falls vorhanden)";
			_lb lbSetValue[_id,_foreachindex];
			if(_x isEqualTo 1) then {
				_lb lbSetColor[_id,[0,1,0,1]];
			} else {
				_lb lbSetColor[_id,[1,0,0,1]];
			};
		};

		case 10: // garage
		{
			_id = _lb lbadd "- Zugriff auf die Gang-Garage";
			_lb lbSetValue[_id,_foreachindex];
			if(_x isEqualTo 1) then {
				_lb lbSetColor[_id,[0,1,0,1]];
			} else {
				_lb lbSetColor[_id,[1,0,0,1]];
			};
		};
	};


} foreach _entry;



if!(_update) then {

	life_gang_rights_save = _entry;
	waitUntil {isnull (findDisplay 23541)};

	if(isnil "life_gangs_made_a_change") exitWith {life_gang_rights_save=nil;};

	life_gangs_made_a_change = nil;

	_members = (group player) getVariable["gang_members",[]];
	_index = -1;
	{
		if((_x select 2) isEqualTo (life_gang_rights_save select 2)) exitWith {_index = _foreachindex;};
	} foreach _members;

	_members set[_index,life_gang_rights_save];
	(group player) setVariable["gang_members",_members,true];
	[0,format["Der Gründer hat die Rechte von %1 verändert",life_gang_rights_save select 1]] remoteExec["life_fnc_gangUpdate_client",(group player)];


	if (life_HC_isActive) then {
	    [10,group player,life_gang_rights_save] remoteExec ["HC_fnc_updateGang",HC_Life]; //Update the database.
	} else {
	    [10,group player,life_gang_rights_save] remoteExec ["TON_fnc_updateGang",RSERV]; //Update the database.
	};
	life_gang_rights_save = nil;
};