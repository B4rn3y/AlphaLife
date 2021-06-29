

// [-0.0195705,-0.104647,1.08561,1.18714]


private ["_display","_listbox","_str_text","_sel","_val","_ret"];

disableSerialization;
_display = findDisplay 5223;

_listbox = _display displayCtrl 1500;
_str_text = _display displayCtrl 1100;



_sel = lbCurSel _listbox;
if(_sel isEqualTo -1) exitWith {};
_val = _listbox lbValue _sel;
if(_val isEqualTo -1) exitWith {};

_ret = [_val] call life_fnc_quest_config_index;



if(_val in alpha_quests) then {
	_str_text ctrlSetStructuredText parsetext format["<t align='center' size='1.5'>""%1""</t> <br/><br/><t color='#FF8000' align='left'>Challenge:</t> <br/><t align='center'>%2</t><br/><br/><t color='#FF8000' align='left'>Belohnung:</t> <br/><t align='center'>%3</t><br/><br/><t color='#01DF01' align='center' size='1.2'>BESTANDEN</t>",_ret select 1,_ret select 2,_ret select 3];
} else {
	_str_text ctrlSetStructuredText parsetext format["<t align='center' size='1.5'>""%1""</t> <br/><br/><t color='#FF8000' align='left'>Challenge:</t> <br/><t align='center'>%2</t><br/><br/><t color='#FF8000' align='left'>Belohnung:</t> <br/><t align='center'>%3</t>",_ret select 1,_ret select 2,_ret select 3];
};





