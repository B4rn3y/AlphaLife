



private ["_quests_to_check","_quest","_var"];


_quests_to_check =
[
	[9,license_civ_driver],
	[10,license_civ_gun],
	[11,license_civ_pilot],
	[12,license_civ_boat],
	[27,license_civ_rebel],
	[37,license_civ_mercenary],
	[38,license_civ_alpha]
];


sleep 60;

waitUntil {sleep 5; !dialog};

{
	_quest = _x select 0;
	_var = _x select 1;
	if(!(_quest in alpha_quests) && _var) then {
		[_quest] call life_fnc_quest_achieved;

	};

	sleep 20;

} foreach _quests_to_check;


sleep 20;

if(isnil "life_gangdata") exitWith  {};
if(life_gangdata isEqualTo []) exitWith  {};

if((life_gangdata select 1) isEqualTo (getPlayerUID player) && !(24 in alpha_quests)) then {
	[24] call life_fnc_quest_achieved;
};

if!(25 in alpha_quests) then {
	[25] call life_fnc_quest_achieved;
};