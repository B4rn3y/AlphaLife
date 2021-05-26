#include "..\..\script_macros.hpp"
/*
    File: fn_adminQuery.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Starts the query on a player.
*/
private ["_text","_info","_prim","_sec","_vest","_uni","_bp","_attach","_tmp"];
disableSerialization;
if (!isNil "admin_query_ip") exitWith {hint localize "STR_ANOTF_Query_2"};
_text = CONTROL(9000,1100);
_info = lbData[1501,lbCurSel (1501)];
diag_log _info;
_info = call compile format ["%1", _info];

if (isNil "_info") exitWith {_text ctrlSetStructuredText parsetext (format["<t size='2.0' color='#FF0000' align='center'>SERVER INFO:</t> <br/> <t align='left'>BLUFOR</t><t align='right'>%1</t> <br/> <t align='left'>INDEPENDENT</t> <t align='right'>%2</t> <br/> <t align='left'>OPFOR</t> <t align='right'>%3</t> <br/> <t align='left'>CIVS</t> <t align='right'>%4</t> <br/> <t align='left'>ALLE:</t><t align='right'>%5</t> <br/> <t align='left'>Admin-LVL:</t><t align='right'>%6</t><br/><br/>",playersNumber west,playersNumber independent,playersNumber east,playersNumber civilian,count(playableUnits),(call life_adminlevel)] + localize "STR_ANOTF_QueryFail");};
if (isNull _info) exitWith {_text ctrlSetStructuredText parsetext (format["<t size='2.0' color='#FF0000' align='center'>SERVER INFO:</t> <br/> <t align='left'>BLUFOR</t><t align='right'>%1</t> <br/> <t align='left'>INDEPENDENT</t> <t align='right'>%2</t> <br/> <t align='left'>OPFOR</t> <t align='right'>%3</t> <br/> <t align='left'>CIVS</t> <t align='right'>%4</t> <br/> <t align='left'>ALLE:</t><t align='right'>%5</t> <br/> <t align='left'>Admin-LVL:</t><t align='right'>%6</t><br/><br/>",playersNumber west,playersNumber independent,playersNumber east,playersNumber civilian,count(playableUnits),(call life_adminlevel)] + localize "STR_ANOTF_QueryFail");};
[player] remoteExec ["TON_fnc_player_query",_info];
_text ctrlSetStructuredText parsetext (format["<t size='2.0' color='#FF0000' align='center'>SERVER INFO:</t> <br/> <t align='left'>BLUFOR</t><t align='right'>%1</t> <br/> <t align='left'>INDEPENDENT</t> <t align='right'>%2</t> <br/> <t align='left'>OPFOR</t> <t align='right'>%3</t> <br/> <t align='left'>CIVS</t> <t align='right'>%4</t> <br/> <t align='left'>ALLE:</t><t align='right'>%5</t> <br/> <t align='left'>Admin-LVL:</t><t align='right'>%6</t><br/><br/>",playersNumber west,playersNumber independent,playersNumber east,playersNumber civilian,count(playableUnits),(call life_adminlevel)] + (localize "STR_ANOTF_Query"));





