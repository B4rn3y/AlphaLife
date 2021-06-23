
private ["_control","_index","_display","_str_text_Skill_beschreibung","_data","_needed_lvl","_descr"];


disableSerialization;

if(isnull(finddisplay 258645)) exitwith {};
_control = _this select 0;
_index = _this select 1;


_display = findDisplay 258645;


_str_text_Skill_beschreibung = _display displayCtrl 1101;

_data = _control tvData (tvCurSel _control);
if(_data isEqualTo "") exitWith {};
_data = call compile _data;
_needed_lvl = _data select 0;
_descr = _data select 1;

_str_text_Skill_beschreibung ctrlSetStructuredText parsetext format["<br/><t color='#FF8000' align='center'>Benötigtes Level:</t> <br/><t size='1.4' align='center'>%1</t><br/><br/><t color='#FF8000' align='center'>Beschreibung:</t> <br/><t align='center'>%2</t>",_needed_lvl,_descr];































