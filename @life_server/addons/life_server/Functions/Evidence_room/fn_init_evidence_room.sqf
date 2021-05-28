// "O_CargoNet_01_ammo_F"  [[20897.3,19228.3,0.600667],62.4938]
//mil_triangle


private ["_query","_queryResult","_classname","_pos","_dir","_trunk","_gear","_chest","_foreachindex","_marker","_items","_mags","_weapons","_backpacks"];

_pos = [20902.4,19233.8,0.00143909];
_dome = nearestObject [_pos,"Land_Dome_Big_F"];
_rsb = nearestObject [_pos,"Land_Research_HQ_F"];

for "_i" from 1 to 3 do {_dome animateSource [format ["Door_%1_source", _i], 0];_dome setVariable [format ["bis_disabled_Door_%1",_i],1,true];};

for "_i" from 1 to 2 do {_rsb animateSource [format ["Door_%1_source", _i], 0];_rsb setVariable [format ["bis_disabled_Door_%1",_i],1,true];};

_dome setVariable ["locked",true,true];
_rsb setVariable ["locked",true,true];
_dome allowDamage false;
_rsb allowDamage false;


_query = "SELECT classname,pos,inventory,gear, id FROM `evidence_room`";
_queryResult = [_query,2,true] call DB_fnc_asyncCall;



{
	_classname = _x select 0;
    _classname = call compile _classname;
	_pos = (call compile(_x select 1)) select 0;
	_dir = (call compile(_x select 1)) select 1;
    _trunk = [_x select 2] call DB_fnc_mresToArray; // z items
    if (_trunk isEqualType "") then {_trunk = call compile format ["%1", _trunk];};
	_gear = [_x select 3] call DB_fnc_mresToArray; // weapons and shit
    if (_gear isEqualType "") then {_gear = call compile format ["%1", _gear];};
	_id = _x select 4;



    call compile format["evidence_box_%1 = ""%2"" createVehicle [0,0,0];publicVariable ""evidence_box_%1"";",_id,_classname]; // hotfix weil setvehiclevarname und pubvar nicht zu funktionieren scheint
    _chest = missionNamespace getvariable[format["evidence_box_%1",_id],objNull];
	_chest setdir _dir;
	_chest setposatl _pos;
	_chest setdir _dir;
	_chest allowdamage false;
	_chest setvariable["evidence_chest",_id,true];
    _chest setvariable["safe_open",false,true];
	[_chest] call life_fnc_clearVehicleAmmo;
	//_chest setVehicleVarName format["evidence_box_%1",_id];
	//publicVariable format["evidence_box_%1",_id];



	_marker = createMarker[format["ALPHA_evidence_%1",_id],_pos];
	_marker setMarkertype "mil_triangle";
	_marker setmarkertext localize format["$STR_MAR_Evidence_Room"];


	clearWeaponCargoGlobal _chest;
    clearItemCargoGlobal _chest;
    clearMagazineCargoGlobal _chest;
    clearBackpackCargoGlobal _chest;
    if (count _gear > 0) then {
        _items = _gear select 0;
        _mags = _gear select 1;
        _weapons = _gear select 2;
        _backpacks = _gear select 3;
        for "_i" from 0 to ((count (_items select 0)) - 1) do {
            _chest addItemCargoGlobal [((_items select 0) select _i), ((_items select 1) select _i)];
        };
        for "_i" from 0 to ((count (_mags select 0)) - 1) do{
            _chest addMagazineCargoGlobal [((_mags select 0) select _i), ((_mags select 1) select _i)];
        };
        for "_i" from 0 to ((count (_weapons select 0)) - 1) do{
            _chest addWeaponCargoGlobal [((_weapons select 0) select _i), ((_weapons select 1) select _i)];
        };
        for "_i" from 0 to ((count (_backpacks select 0)) - 1) do{
            _chest addBackpackCargoGlobal [((_backpacks select 0) select _i), ((_backpacks select 1) select _i)];
        };
    };

    _chest setVariable ["Trunk",_trunk,true];


} foreach _queryResult;