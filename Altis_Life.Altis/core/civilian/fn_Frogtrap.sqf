
private ["_positions","_build_range","_mkrs","_arrows","_mkr","_foreachindex","_arrow","_buchte","_is_near_build_pos","_ret","_pos","_buchte_placed"];
if!(vehicle player isEqualTo player) exitWith {["Das geht nicht im Fahrzeug"] call life_fnc_exp_hint;};

_positions = [[21747.2,14341.7,0.00129235],[21834.4,14381,0.00166595],[21669,14303.4,0.00142905],[21674,14359.5,0.0016464],[21634.1,14350.5,0.00164396],[21591,14331.4,0.0014095],[21556.9,14284,0.00175142],[21524.3,14380.3,0.00145227],[21400.2,14351.1,0.00144982],[21322.6,14421,0.0015121],[21479,14458.1,0.0014291],[21218.7,14454.5,0.00153285],[21159.3,14486,0.00132775],[21347.9,14545.3,0.00141692],[21096.3,14402.5,0.0013327],[21279.3,14613.5,0.00162441],[20887.7,14385.6,0.00150235],[21027.9,14534.7,0.0016073],[20775.4,14585.8,0.00148161],[20995.9,14668.8,0.00150964],[20762.7,14491.6,0.00163415],[21125.9,14633.6,0.00169396],[21235.3,14671.2,0.00152308],[21314.6,14666.2,0.00110674],[20643.1,14570.6,0.00169516],[20702.9,14624.5,0.0014047],[20927.5,14666.8,0.00194174],[20705.6,14714.8,0.00172448],[20579.8,14639.3,0.0015561],[20546.3,14654.3,0.00154138],[20570,14733.6,0.00148766],[20506.4,14772.6,0.00146079],[20600.9,14872.6,0.00144735],[20582.2,14902.9,0.00143764],[21158.3,14798.4,0.00167084],[20966.3,14728.4,0.00150476],[20871.9,14832.2,0.00158051],[20788.3,14827.9,0.00150113],[20788.2,14844.6,0.00144374],[20863.2,14954.6,0.00147058],[20685.5,14923.6,0.00140959],[21151.2,14707.3,0.0012973],[21160.7,14799.5,0.00176483],[21064.4,14865.2,0.00139493],[20991,14805.5,0.00144861],[20970.8,14787.2,0.00136561],[21167,15021,0.00178552],[21414.3,14778.3,0.00146206],[21269.6,14868.2,0.00140467],[21345,14914.3,0.00145839],[21359.6,14952.5,0.00143886],[21036.3,15019,0.00175136],[21019.8,14936.6,0.00151208],[20745.5,15053.8,0.00154379],[20928.8,15168,0.00119227],[21016.1,15136,0.00152183],[21158.6,14940.2,0.00134116],[21359.5,15019.2,0.00126311]];
_build_range = 2;


if(player distance  [21133.1,14675.2,0.00141317] >= 1000) exitWith {
	["Du kannst dieses Item nur im Sumpf benutzen / Siehe Karte"] call life_fnc_exp_hint;
};

ALPHA_FROGTRAPING = true;
["Laufe zu den Markierungen damit die Falle dort automatisch platziert wird, diese Stellen sind ebenfalls auf deiner Karte markiert."] spawn life_fnc_exp_hint;
_A_ID = player addaction ["Abbrechen",{ALPHA_FROGTRAPING = nil;player removeAction (_this select 2);}];


_mkrs = [];
_arrows = [];
{

	_mkr = createMarkerLocal [format["Frog_marker__%1",_foreachindex], _x];
	_mkrs pushback _mkr;
	_mkr setMarkerTypeLocal "hd_dot";
	_mkr setMarkerColorLocal "ColorBlack";


	_objs = nearestObjects[_x,["Land_Cages_F"],4];
	if!(_objs isEqualTo []) then {
		if(damage (_objs select 0) isEqualTo 1) then {
			deleteVehicle (_objs select 0);
		};
	};

} foreach _positions;




_EVH_ID = addMissionEventHandler ["Draw3D", {
_positions = [[21747.2,14341.7,0.00129235],[21834.4,14381,0.00166595],[21669,14303.4,0.00142905],[21674,14359.5,0.0016464],[21634.1,14350.5,0.00164396],[21591,14331.4,0.0014095],[21556.9,14284,0.00175142],[21524.3,14380.3,0.00145227],[21400.2,14351.1,0.00144982],[21322.6,14421,0.0015121],[21479,14458.1,0.0014291],[21218.7,14454.5,0.00153285],[21159.3,14486,0.00132775],[21347.9,14545.3,0.00141692],[21096.3,14402.5,0.0013327],[21279.3,14613.5,0.00162441],[20887.7,14385.6,0.00150235],[21027.9,14534.7,0.0016073],[20775.4,14585.8,0.00148161],[20995.9,14668.8,0.00150964],[20762.7,14491.6,0.00163415],[21125.9,14633.6,0.00169396],[21235.3,14671.2,0.00152308],[21314.6,14666.2,0.00110674],[20643.1,14570.6,0.00169516],[20702.9,14624.5,0.0014047],[20927.5,14666.8,0.00194174],[20705.6,14714.8,0.00172448],[20579.8,14639.3,0.0015561],[20546.3,14654.3,0.00154138],[20570,14733.6,0.00148766],[20506.4,14772.6,0.00146079],[20600.9,14872.6,0.00144735],[20582.2,14902.9,0.00143764],[21158.3,14798.4,0.00167084],[20966.3,14728.4,0.00150476],[20871.9,14832.2,0.00158051],[20788.3,14827.9,0.00150113],[20788.2,14844.6,0.00144374],[20863.2,14954.6,0.00147058],[20685.5,14923.6,0.00140959],[21151.2,14707.3,0.0012973],[21160.7,14799.5,0.00176483],[21064.4,14865.2,0.00139493],[20991,14805.5,0.00144861],[20970.8,14787.2,0.00136561],[21167,15021,0.00178552],[21414.3,14778.3,0.00146206],[21269.6,14868.2,0.00140467],[21345,14914.3,0.00145839],[21359.6,14952.5,0.00143886],[21036.3,15019,0.00175136],[21019.8,14936.6,0.00151208],[20745.5,15053.8,0.00154379],[20928.8,15168,0.00119227],[21016.1,15136,0.00152183],[21158.6,14940.2,0.00134116],[21359.5,15019.2,0.00126311]];
	{

		_draw = true;
		_nearest_trap = nearestObjects[_x,["Land_Cages_F"],5];
		if!(_nearest_trap isEqualTo []) then {
			_trap = _nearest_trap select 0;
			if!(_trap getvariable["trap_time",-1] isEqualTo -1) then {
				_draw = false;
			};
		};


		if(_draw) then {
			drawIcon3D [MISSION_ROOT  + "icons\ico_trap.paa", [1,1,1,1], [(_x select 0),(_x select 1), 1], 0.8, 0.8, 0, format["%1m", round (player distance _x)], 1, 0.025, "EtelkaMonospacePro"];
		};
	} foreach _positions
}];



_buchte = "Land_Cages_F" createVehicleLocal [0,0,0];
_buchte attachto[player,[0,2,0.65]];

_is_near_build_pos = {_ret = [];{if((_buchte distance _x <=_build_range) && count (nearestObjects[player,["Land_Cages_F"],4]) isEqualTo 1) exitWith {_ret = _x};} foreach _positions;_ret };

while {true} do
{
	if(isnil "ALPHA_FROGTRAPING") exitWith {};
	if((missionNamespace getvariable["life_inv_frogtrap",0])<= 0) exitWith {};
	if!(vehicle player isEqualTo player) exitWith {};
	if(player distance [21133.1,14675.2,0.00141317] > 1000) exitWith {};
	_pos = 0 call _is_near_build_pos;
	if!(_pos isEqualTo []) then {
		[false,"frogTrap",1] call life_fnc_handleInv;
		_buchte_placed = "Land_Cages_F" createVehicle [0,0,0];
		_buchte_placed setposatl _pos;
		_buchte_placed setdir (getdir _buchte);
		_buchte_placed setvariable["trap_time",serverTime,true];
		_buchte_placed allowDamage false;


	};
	sleep 2;


};

removeMissionEventHandler ["Draw3D", _EVH_ID];
ALPHA_FROGTRAPING = nil;
deleteVehicle _buchte;
{deleteMarkerLocal _x;} foreach _mkrs;

player removeAction _A_ID;









