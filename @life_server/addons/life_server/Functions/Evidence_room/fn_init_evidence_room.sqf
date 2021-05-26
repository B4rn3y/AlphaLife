
//mil_triangle



_query = "SELECT classname,pos,inventory,gear, id FROM `evidence_room`";
_queryResult = [_query,2,true] call DB_fnc_asyncCall;

diag_log str _queryResult;
{
	diag_log str _x;
    diag_log typename _x;
    diag_log typename (_x select 0);
    diag_log typename (_x select 1);
    diag_log typename (_x select 2);
    diag_log typename (_x select 3);
    diag_log typename (_x select 4);

} foreach _queryResult;

{
	_classname = _x select 0;
	_pos = (call compile(_x select 1)) select 0;
	_dir = (call compile(_x select 1)) select 1;
	_inv = _x select 2; // t-items
	_gear = _x select 3; // weapons and shit
	_id = _x select 4;


	_chest = _classname createVehicle [0,0,0];
	_chest setdir _dir;
	_chest setposatl _pos;
	_chest setdir _dir;
	_chest allowdamage false;
	_chest setvariable["evidence_chest",_id,true];
	[_chest] call life_fnc_clearVehicleAmmo;  // maximumload 22000  configfile >> "CfgVehicles" >> "B_CargoNet_01_ammo_F" >> "maximumLoad"

	_marker = createMarker[format["ALPHA_evidence_%1",_id],_pos];
	_marker setMarkertype "mil_triangle";
	_marker setmarkertext format[""];


} foreach _queryResult;