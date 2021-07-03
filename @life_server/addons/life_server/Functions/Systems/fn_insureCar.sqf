




private ["_vid","_pid","_query"];

_vid = [_this,0,-1,[0]] call BIS_fnc_param;
_pid = [_this,1,"",[""]] call BIS_fnc_param;

if(_vid isEqualTo -1 || _pid isEqualTo "") exitWith {};


_query = format["UPDATE vehicles SET insure='1' WHERE pid='%1' AND id='%2'",_pid,_vid];


[_query,1] call DB_fnc_asyncCall;