#include "\life_server\script_macros.hpp"
/*
    File: fn_updateGang.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Updates the gang information?
*/
private ["_mode","_groupID","_bank","_maxMembers","_members","_owner","_query","_deposit","_value","_unit","_cash","_funds","_pid","_alliances_first_gang","_gang_id_2","_alliances_2nd_gang","_alliances_my_gang","_gang_id_other_gang","_queryresult","_alliances","_index","_foreachindex"];
params [
    ["_mode",0,[0]],
    ["_group",grpNull,[grpNull]]
];

if (isNull _group) exitWith {}; //FAIL

_groupID = _group getVariable ["gang_id",-1];
if (_groupID isEqualTo -1) exitWith {};

switch (_mode) do {
    case 0: {
        _bank = [(_group getVariable ["gang_bank",0])] call DB_fnc_numberSafe;
        _maxMembers = _group getVariable ["gang_maxMembers",8];
        _members = [(_group getVariable "gang_members")] call DB_fnc_mresArray;
        _owner = _group getVariable ["gang_owner",""];
        if (_owner isEqualTo "") exitWith {};

        _query = format ["UPDATE gangs SET bank='%1', maxmembers='%2', owner='%3' WHERE id='%4'",_bank,_maxMembers,_owner,_groupID];
    };

    case 1: {
        params [
            "",
            "",
            ["_deposit",false,[false]],
            ["_value",0,[0]],
            ["_unit",objNull,[objNull]],
            ["_cash",0,[0]]
        ];

        private _funds = _group getVariable ["gang_bank",0];
        if (_deposit) then {
            _funds = _funds + _value;
            _group setVariable ["gang_bank",_funds,true];
            [1,"STR_ATM_DepositSuccessG",true,[_value]] remoteExecCall ["life_fnc_broadcast",remoteExecutedOwner];
            _cash = _cash - _value;
        } else {
            if (_value > _funds) exitWith {
                [1,"STR_ATM_NotEnoughFundsG",true] remoteExecCall ["life_fnc_broadcast",remoteExecutedOwner];
                breakOut "";
            };
            _funds = _funds - _value;
            _group setVariable ["gang_bank",_funds,true];
            [_value] remoteExecCall ["life_fnc_gangBankResponse",remoteExecutedOwner];
            _cash = _cash + _value;
        };
        if (LIFE_SETTINGS(getNumber,"player_moneyLog") isEqualTo 1) then {
            if (LIFE_SETTINGS(getNumber,"battlEye_friendlyLogging") isEqualTo 1) then {
                diag_log (format [localize "STR_DL_ML_withdrewGang_BEF",_value,[_funds] call life_fnc_numberText,[0] call life_fnc_numberText,[_cash] call life_fnc_numberText]);
            } else {
                diag_log (format [localize "STR_DL_ML_withdrewGang",name _unit,(getPlayerUID _unit),_value,[_funds] call life_fnc_numberText,[0] call life_fnc_numberText,[_cash] call life_fnc_numberText]);
            };
        };
        _query = format ["UPDATE gangs SET bank='%1' WHERE id='%2'",([_funds] call DB_fnc_numberSafe),_groupID];
        [getPlayerUID _unit,side _unit,_cash,0] call DB_fnc_updatePartial;
    };

    case 2: {
        _query = format ["UPDATE gangs SET maxmembers='%1' WHERE id='%2'",(_group getVariable ["gang_maxMembers",8]),_groupID];
    };

    case 3: {
        params [
            "",
            "",
            ["_pid","",[""]]
        ];
        _owner = _group getVariable ["gang_owner",""];
        if (_owner isEqualTo "") exitWith {};
        _query = format ["UPDATE gang_members SET leader='0' WHERE gang_id='%1';",_groupID];
        [_query,1] call DB_fnc_asyncCall;
        _query = format ["UPDATE gang_members SET leader='1',right_invite='1',right_expand='1',right_withdraw='1',right_skins='1',righ
        ='1',right_house='1',right_garage='1' WHERE gang_id='%1' and pid = '%2';",_groupID,_owner];
    };

    case 4: {
        params [
            "",
            "",
            ["_pid","",[""]]
        ];

        if(_pid isEqualTo "") exitWith {};
        _query = format ["INSERT INTO gang_members (gang_id, pid, leader, right_invite, right_expand, right_withdraw, right_skins, right_kick) VALUES('%1','%2','0','0','0','0','0','0')",_groupID,_pid];

    };

    case 5: {
        _query = format ["UPDATE gangs SET bank='%1' WHERE id='%2'",(_group getVariable ["gang_bank",0]),_groupID];
    };

    case 6: {
        params [
            "",
            "",
            ["_pid","",[""]]
        ];

        if(_pid isEqualTo "") exitWith {};
        _query = format ["DELETE FROM gang_members WHERE gang_id = '%1' and pid = '%2';",_groupID,_pid];

    };

    case 7: {
        params [
            "",
            "",
            ["_alliances_first_gang",[],[[]]],
            ["_gang_id_2",-1,[0]],
            ["_alliances_2nd_gang",[],[[]]]
        ];

        if(_gang_id_2 isEqualTo -1) exitWith {};

        _alliances_first_gang = [_alliances_first_gang] call DB_fnc_mresArray;
        _alliances_2nd_gang = [_alliances_2nd_gang] call DB_fnc_mresArray;


        _query = format ["UPDATE gangs SET alliances = '%1' WHERE id = '%2';",_alliances_first_gang, _groupID];
        [_query,1] call DB_fnc_asyncCall;
        _query = format ["UPDATE gangs SET alliances = '%1' WHERE id = '%2';",_alliances_2nd_gang, _gang_id_2];
    };

    case 8: {
        params [
            "",
            "",
            ["_alliances_my_gang",[],[[]]],
            ["_gang_id_other_gang",-1,[0]]
        ];

        if(_gang_id_other_gang isEqualTo -1) exitWith {};

        _alliances_my_gang = [_alliances_my_gang] call DB_fnc_mresArray;


        _query = format ["UPDATE gangs SET alliances = '%1' WHERE id = '%2';",_alliances_my_gang, _groupID];
        [_query,1] call DB_fnc_asyncCall;
        _query = format ["SELECT alliances FROM gangs WHERE id = '%1';",_gang_id_other_gang];
        _queryresult = [_query,2] call DB_fnc_asyncCall;
        _alliances = [_queryresult select 0] call DB_fnc_mresToArray;
        _index = -1;
        {
            if((_x select 0) isEqualTo _groupID)exitWith {_index = _foreachindex};
        } foreach _alliances;
        if(_index isEqualTo -1) exitWith {_query = nil;};
        _alliances deleteAt _index;
        _query = format ["UPDATE gangs SET alliances = '%1' WHERE id = '%2';",([_alliances] call DB_fnc_mresArray), _gang_id_other_gang];
    };

    case 9: {
        _query = format ["UPDATE gangs SET tax='%1' WHERE id='%2'",(_group getVariable ["gang_tax",0]),_groupID];
    };

    case 10: {
        params [
            "",
            "",
            ["_player_entry",[],[[]]]
        ];

        if(_player_entry isEqualTo [] || count _player_entry != 11) exitWith {};

        _query = format["UPDATE gang_members SET right_invite='%1',right_expand='%2',right_withdraw='%3', right_skins='%4',right_kick='%5',right_house='%6',right_garage='%7' WHERE pid='%8' AND gang_id='%9'",(_player_entry select 4),(_player_entry select 5),(_player_entry select 6),(_player_entry select 7),(_player_entry select 8),(_player_entry select 9),(_player_entry select 10),(_player_entry select 2),(_player_entry select 0)];
    };

    case 11: {
        _query = format ["UPDATE gangs SET public='%1' WHERE id='%2'",(_group getVariable ["gang_public",0]),_groupID];
    };
};

if (!isNil "_query") then {
    [_query,1] call DB_fnc_asyncCall;
};
