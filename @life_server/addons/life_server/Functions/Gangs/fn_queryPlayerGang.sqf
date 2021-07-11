/*
    File: fn_queryPlayerGang.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Queries to see if the player belongs to any gang.
*/
private ["_query","_queryResult","_result_gang"];


_query = format ["SELECT gang_members.gang_id,players.name, gang_members.pid, gang_members.leader, gang_members.right_invite, gang_members.right_expand, gang_members.right_withdraw, gang_members.right_skins, gang_members.right_kick, gang_members.right_house, gang_members.right_garage FROM gang_members LEFT JOIN players ON gang_members.pid = players.pid where gang_members.gang_id in(Select gang_id from gang_members where pid = '%1');",_this];
_queryResult = [_query,2,true] call DB_fnc_asyncCall;


if !(count _queryResult isEqualTo 0) then {
    _query = format ["SELECT id, name, tag, alliances, maxmembers, bank, tax, public FROM gangs WHERE id = '%1';",((_queryResult select 0)select 0)];
    _queryResult = [_queryResult];

    _result_gang = [_query,2] call DB_fnc_asyncCall;
    if(count _result_gang > 0) then {
    	_result_gang set[3,[_result_gang select 3] call DB_fnc_mresToArray];
    };
    _queryResult pushBack _result_gang;
};

_queryResult
