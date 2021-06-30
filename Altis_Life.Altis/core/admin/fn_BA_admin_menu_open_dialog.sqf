private ["_display","_lb_AllPlayers","_lb_options","_strText_INFO","_count","_west","_independent","_east","_civilian","_weapon"];

disableSerialization;


if((call life_adminlevel) <= 0) exitWith {hint "Kein Admin!";};

closeDialog 0;
createDialog "BA_admin_menu";
waitUntil {!isnull (findDisplay 9000);};
showchat false;
_display = findDisplay 9000;
//Listboxes
_lb_AllPlayers = _display displayCtrl 1501;
_lb_options = _display displayCtrl 1500;
_strText_INFO = _display displayCtrl 1100;



lbClear _lb_AllPlayers;
lbClear _lb_options;


_strText_INFO ctrlSetStructuredText parseText format["<t size='2.0' color='#FF0000' align='center'>SERVER INFO:</t> <br/> <t align='left'>BLUFOR</t><t align='right'>%1</t> <br/> <t align='left'>INDEPENDENT</t> <t align='right'>%2</t> <br/> <t align='left'>OPFOR</t> <t align='right'>%3</t> <br/> <t align='left'>CIVS</t> <t align='right'>%4</t> <br/> <t align='left'>ALLE:</t><t align='right'>%5</t> <br/> <t align='left'>Admin-LVL:</t><t align='right'>%6</t>",playersNumber west,playersNumber independent,playersNumber east,playersNumber civilian,count(playableUnits),(call life_adminlevel)];






_count = 0;

_west = [];
_independent = [];
_east = [];
_civilian = [];


{
	switch(side _x) do {
	case west: { _west pushback _x;};
	case independent: {_independent pushback _x;};
	case east: {_east pushback _x;};
	default {_civilian pushback _x;};

	};

} foreach playableUnits;


_lb_AllPlayers lbadd "--== WEST ==--";
_lb_AllPlayers lbsetdata[_count,""];
_lb_AllPlayers lbSetColor[_count,[0.506,0.506,0.969,1]];
_count = _count + 1;
{
	if(!alive _x) then {
		_lb_AllPlayers lbadd format["%1 - dead",name _x];
	} else {
		_lb_AllPlayers lbadd format["%1",name _x];
	};

	if(vehicle _x == _x) then {
		_weapon = primaryWeapon _x;

		if(_weapon != "")  then {
			_lb_AllPlayers lbSetPicture[_count,getText(configFile >> "CfgWeapons" >> _weapon >> "picture")];
		};
	} else {

		_lb_AllPlayers lbSetPicture[_count,getText(configFile >> "CfgVehicles" >> (typeof (vehicle _x)) >> "picture")];

	};

	_lb_AllPlayers lbsetdata[_count,(str _x)];
	_lb_AllPlayers lbSetColor[_count,[0.506,0.506,0.969,1]];
	_count = _count + 1;


} foreach _west;


_lb_AllPlayers lbadd "--== INDEPENDENT ==--";
_lb_AllPlayers lbsetdata[_count,""];
_lb_AllPlayers lbSetColor[_count,[0.004,0.875,0.004,1]];
_count = _count + 1;
{
	if(!alive _x) then {
		_lb_AllPlayers lbadd format["%1 - dead",name _x];
	} else {
		_lb_AllPlayers lbadd format["%1",name _x];
	};

	if(vehicle _x == _x) then {
		_weapon = primaryWeapon _x;

		if(_weapon != "")  then {
			_lb_AllPlayers lbSetPicture[_count,getText(configFile >> "CfgWeapons" >> _weapon >> "picture")];
		};
	} else {

		_lb_AllPlayers lbSetPicture[_count,getText(configFile >> "CfgVehicles" >> (typeof (vehicle _x)) >> "picture")];

	};

	_lb_AllPlayers lbsetdata[_count,( str _x)];
	_lb_AllPlayers lbSetColor[_count,[0.004,0.875,0.004,1]];
	_count = _count + 1;


} foreach _independent;


_lb_AllPlayers lbadd "--== OPFOR ==--";
_lb_AllPlayers lbsetdata[_count,""];
_lb_AllPlayers lbSetColor[_count,[1,0,0,1]];
_count = _count + 1;
{
	if(!alive _x) then {
		_lb_AllPlayers lbadd format["%1 - dead",name _x];
	} else {
		_lb_AllPlayers lbadd format["%1",name _x];
	};

	if(vehicle _x == _x) then {
		_weapon = primaryWeapon _x;

		if(_weapon != "")  then {
			_lb_AllPlayers lbSetPicture[_count,getText(configFile >> "CfgWeapons" >> _weapon >> "picture")];
		};
	} else {

		_lb_AllPlayers lbSetPicture[_count,getText(configFile >> "CfgVehicles" >> (typeof (vehicle _x)) >> "picture")];

	};
	_lb_AllPlayers lbsetdata[_count,(str _x)];
	_lb_AllPlayers lbSetColor[_count,[1,0,0,1]];
	_count = _count + 1;


} foreach _east;

_lb_AllPlayers lbadd "--== CIVILIANS ==--";
_lb_AllPlayers lbsetdata[_count,""];
_lb_AllPlayers lbSetColor[_count,[1,0,1,1]];
_count = _count + 1;
{
	if(!alive _x) then {
		_lb_AllPlayers lbadd format["%1 - dead",name _x];
	} else {
		_lb_AllPlayers lbadd format["%1",name _x];
	};

	if(vehicle _x == _x) then {
		_weapon = primaryWeapon _x;

		if(_weapon != "")  then {
			_lb_AllPlayers lbSetPicture[_count,getText(configFile >> "CfgWeapons" >> _weapon >> "picture")];
		};
	} else {

		_lb_AllPlayers lbSetPicture[_count,getText(configFile >> "CfgVehicles" >> (typeof (vehicle _x)) >> "picture")];

	};

	_lb_AllPlayers lbsetdata[_count,(str _x)];
	_lb_AllPlayers lbSetColor[_count,[1,0,1,1]];
	_count = _count + 1;


} foreach _civilian;



{
	if(count(_x) isEqualTo 1) then {
		_lb_options lbadd (_x select 0);
	} else {
		if((call life_adminlevel) >= (_x select 2)) then {
			_id = _lb_options lbadd (_x select 0);
			_lb_options lbsetdata[_id,_x select 1];
		};
	};
} foreach (getArray (missionConfigFile >> "Admin_Conf" >> "Conf" >> "Scripts"));





waitUntil {isnull (findDisplay 9000);};

showchat true;




