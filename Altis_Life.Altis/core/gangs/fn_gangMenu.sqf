#include "..\..\script_macros.hpp"
/*
    File: fn_gangMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    31 hours of no sleep screw your description.

    [1,"76561198018512569","Dein Gangname",8,0,[[1,"Inch Messerschmitt","76561198158204122",0,1,1,1,1,1],[1,"Barney","76561198018512569",1,1,1,1,1,1]],[],"DGN",0,0]

*/
private ["_ownerID","_gangName","_gangBank","_gangMax","_display","_upgrade_btn","_kick_btn","_new_leader_btn","_invite_btn","_disband_btn","_rights_btn","_alliances_btn","_tax_btn","_str_text","_player_entry","_members","_pid","_is_lead","_obj","_color","_grpMembers","_allUnits","_ctrl"];
disableSerialization;
if (isNull (findDisplay 2620)) then {
    if (!(createDialog "Life_My_Gang_Diag")) exitWith {}; //NOOOOOOOOOOOOOOOOOOOOOOOoooooooooooooOOOOOOOOOOOOOOOOOOOOOOOOOOO00000000000000oooooo
};
ctrlSetText[7858,format["%1:%2",systemtime select 3,systemtime select 4]];
ctrlSetText[2009,format ["%1 / %2", life_carryWeight, life_maxWeight]];
_ownerID = group player getVariable ["gang_owner",""];
if (_ownerID isEqualTo "") exitWith {closeDialog 0;}; //Bad juju

_gangName = group player getVariable "gang_name";
_gangBank = group player getVariable "gang_bank";
_gangMax = group player getVariable "gang_maxMembers";



_display = findDisplay 2620;
_upgrade_btn = _display displayCtrl 2622;
_kick_btn = _display displayCtrl 2624;
_new_leader_btn = _display displayCtrl 2625;
_invite_btn = _display displayCtrl 2630;
_disband_btn = _display displayCtrl 2631;
_rights_btn = _display displayCtrl 2406;
_alliances_btn = _display displayCtrl 2407;
_tax_btn = _display displayCtrl 2408;
_public_btn = _display displayCtrl 2409;

_str_text = _display displayCtrl 601;

{_x ctrlEnable false;} foreach [_upgrade_btn, _kick_btn, _new_leader_btn, _invite_btn, _disband_btn, _rights_btn, _alliances_btn, _tax_btn,_public_btn];

_player_entry = [getplayeruid player] call life_fnc_gang_find_member_entry;
if!(_player_entry isEqualTo []) then {
     {
        switch (_forEachIndex) do
        {
            case 0:
            {
                if((_player_entry select 5) isEqualTo 1) then {
                    _upgrade_btn ctrlEnable true;
                };
            };

            case 1:
            {
                if((_player_entry select 8) isEqualTo 1) then {
                    _kick_btn ctrlEnable true;
                };
            };

            case 2:
            {
                if((_player_entry select 3) isEqualTo 1) then {
                    _new_leader_btn ctrlEnable true;
                };
            };

            case 3:
            {
                if((_player_entry select 4) isEqualTo 1) then {
                    _invite_btn ctrlEnable true;
                };
            };

            case 4:
            {
                if((_player_entry select 3) isEqualTo 1) then {
                    _disband_btn ctrlEnable true;
                };
            };

            case 5:
            {
                if((_player_entry select 3) isEqualTo 1) then {
                    _rights_btn ctrlEnable true;
                };
            };

            case 6:
            {
                if((_player_entry select 3) isEqualTo 1) then {
                    _alliances_btn ctrlEnable true;
                };
            };

            case 7:
            {
                if((_player_entry select 3) isEqualTo 1) then {
                    _tax_btn ctrlEnable true;
                };
            };

            case 8:
            {
                if((_player_entry select 3) isEqualTo 1) then {
                    _public_btn ctrlEnable true;
                };
            };
        };

    } foreach [_upgrade_btn, _kick_btn, _new_leader_btn, _invite_btn, _disband_btn, _rights_btn, _alliances_btn, _tax_btn,_public_btn];
};




_str_text ctrlSetStructuredText parsetext format["<t size='1' align='left'>Gangname: [%8] %1</t><t size='1' align='right'>Gang-ID: %2</t><br/><t size='1' align='left'>Gang-Bank: $%3</t><t size='1' align='right'>Gang-Steuern: %4%5</t><br/><t size='1' align='left'>Slotzahl: %6</t><t size='1' align='right'>Öffentlich: %7</t>",(group player) getVariable["gang_name",""],(group player) getVariable["gang_id",-1],[(group player) getVariable["gang_bank",0]] call life_fnc_numberText,(group player) getVariable["gang_tax",0],"%",(group player) getVariable["gang_maxMembers",8],if((group player) getVariable["gang_public",0] isEqualTo 1) then {"Ja"} else {"Ne"},(group player) getVariable["gang_tag",""]];


//Loop through the players.
_members = _display displayCtrl 2621;
lbClear _members;
{
    _name = _x select 1;
    _pid = _x select 2;
    _is_lead = _x select 3;
    _obj = [_pid] call life_fnc_findPlayerOfPID;
    _color = if(isnull _obj) then {[1,0,0,1]} else {if(side _obj in [west,independent,opfor]) then {[1,0.502,0,1]} else {[0.004,0.875,0.004,1]}};
    if(_is_lead isEqualTo 1) then {
        _id = _members lbAdd format ["[Gründer] " + "%1",_x select 1];
        _members lbSetData [_id,_x select 2];
        _members lbSetColor[_id,_color];
    } else {
        _id = _members lbAdd format ["%1",_x select 1];
        _members lbSetData [_id,_x select 2];
        _members lbSetColor[_id,_color];
    };
} forEach ((group player)getVariable["gang_members",[]]);

_grpMembers = units group player;
_allUnits = playableUnits;

//Clear out the list..
{
    if (_x in _grpMembers || ((side _x) in [west,independent,opfor]) || !(isNil {(group _x) getVariable "gang_id"})) then {
        _allUnits deleteAt _forEachIndex;
    };
} forEach _allUnits;

_ctrl = _display displayCtrl 2632;
lbClear _ctrl; //Purge the list
{
    _ctrl lbAdd format ["%1",name _x];
    _ctrl lbSetData [(lbSize _ctrl)-1,getplayeruid _x];
} forEach _allUnits;
