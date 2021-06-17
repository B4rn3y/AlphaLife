

private ["_safezone_marker","_pos","_size","_dir","_trigger"];

_safezone_marker =
[
	"safezone_kavala",
	"safezone_athira",
	"safezone_sofia",
	"safezone_pyrgos"
];




{
	_pos = getMarkerPos _x;
	_size = markerSize _x;
	_dir = markerDir _x;
	_trigger = createTrigger["EmptyDetector",_pos,false];

	_trigger setTriggerArea [_size select 0, _size select 1, _dir, false];
	_trigger setTriggerActivation ["ANYPLAYER", "PRESENT", true];


	_trigger setTriggerStatements
	[
		"player in thisList || (vehicle player) in thisList",
		"player allowDamage false;vehicle player allowDamage false; systemchat ""Safezone betreten"";",
		"player allowDamage true;vehicle player allowDamage true; systemchat ""Safezone verlassen"";"
	];
} foreach _safezone_marker;