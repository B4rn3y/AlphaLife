/*
    File: fn_insertVehicle.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Inserts the vehicle into the database
*/
private ["_side","_type","_className","_color","_plate","_vehicle","_query","_queryresult"];
params [
    "_uid",
    "_side",
    "_type",
    "_className",
    ["_color",-1,[0]],
    ["_plate",-1,[0]],
    ["_vehicle",objNull,[objNull]]
];

//Stop bad data being passed.
if (_uid isEqualTo "" || _side isEqualTo "" || _type isEqualTo "" || _className isEqualTo ""  || _plate isEqualTo -1 || isnull _vehicle) exitWith {};

_query = format ["INSERT INTO vehicles (side, classname, type, pid, alive, active, inventory, color, plate, gear, damage) VALUES ('%1', '%2', '%3', '%4', '1','1','""[[],0]""', '%5', '%6','""[]""','""[]""')",_side,_className,_type,_uid,_color,_plate];


[_query,1] call DB_fnc_asyncCall;

uisleep 0.35;

_query = format["SELECT id FROM vehicles WHERE pid ='%1' AND plate='%2';",_uid,_plate];
_queryresult = [_query,2] call DB_fnc_asyncCall;
if(_queryresult isEqualTo []) exitWith {};



_vehicle setVariable ["dbInfo",[_uid,(_queryresult select 0),0],true];