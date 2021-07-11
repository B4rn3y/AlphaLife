private ["_entry_pos","_display","_lb","_value"];

if(isnull (findDisplay 23541)) exitWith {};
if ((lbCurSel 1500) isEqualTo -1) exitWith {};
if(isnil "life_gang_rights_save") exitWith {};
_entry_pos = lbValue[1500,(lbCurSel 1500)];



_display = findDisplay 23541;

_lb = _display displayCtrl 1500;



_value = life_gang_rights_save select _entry_pos;
if(_value isEqualTo 1) then {_value = 0;} else {_value = 1;};

life_gang_rights_save set[_entry_pos,_value];


life_gangs_made_a_change = true;

[true] spawn life_fnc_gang_rights_dialog;


