/*
	File: fn_mapMarkerPlayer.sqf
	Author: Barney

	Description:
	Marks gang members for each others. Only initializes when the actual map is open.
*/




sleep 0.5;
if(visibleMap) then {
	if(!isnil "mapm") exitWith {};
	waitUntil {visibleMap};

	_units_to_show = switch (playerside) do
	{
		case west:
		{
			playableUnits select {(side _x) isEqualTo west};
		};

		case independent:
		{
			playableUnits select {(side _x) isEqualTo independent};
		};

		case civilian:
		{
			if(isnull (group player)) then {[player]} else {units (group player)};
		};

		default
		{
			[]
		};
	};


	_markers = [];
	//Create markers
	{
		_marker = createMarkerLocal [format["%1_marker",_x],visiblePosition _x];
		_marker setMarkerColorLocal "ColorBlue";
		_marker setMarkerTypeLocal "Mil_dot";
		_marker setMarkerTextLocal format["%1", name _x];

		_markers pushBack [_marker,_x];
	} foreach _units_to_show;


	_alliances_ids = [];
	{_alliances_ids pushBackUnique (_x select 0);} foreach ((group player) getVariable["gang_alliances",[]]);

	if!(_alliances_ids isEqualTo []) then {
		{
			if((_x getVariable["gang_id",-1]) in _alliances_ids) then {
				_gang_name = _x getVariable["gang_name","Unbekannt"];
				{
					_marker = createMarkerLocal [format["%1_marker",_x],visiblePosition _x];
					_marker setMarkerColorLocal "ColorOrange";
					_marker setMarkerTypeLocal "Mil_dot";
					_marker setMarkerTextLocal format["[%2] %1", name _x,_gang_name];

					_markers pushBack [_marker,_x];
				} foreach (units _x);
			};
		} foreach allGroups;

	};


	while {visibleMap} do
	{
		{
			private["_marker","_unit"];
			_marker = _x select 0;
			_unit = _x select 1;
			if(!isNil "_unit") then
			{
				if(!isNull _unit) then
				{
					_marker setMarkerPosLocal (visiblePosition _unit);
				};
			};
		} foreach _markers;

		if(!visibleMap) exitWith {};
		sleep 0.02;
	};

	{deleteMarkerLocal (_x select 0);} foreach _markers;
	_markers = [];
	_units_to_show = [];


};