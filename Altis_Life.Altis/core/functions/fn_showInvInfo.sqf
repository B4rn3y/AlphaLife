/*
	File: fn_handleInv.sqf
	Author: Bryan "Tonic" Boardwine

	Description:
	Do I really need one?
*/

if(isnil "life_session_completed") exitWith {};
if!(life_session_completed) exitWith {};

if(dialog) exitWith {};
private ["_add","_item","_amount","_addstr","_text","_display","_TextField","_posText","_textHigh","_activeNotifications","_ctrlText"];



_add = param[0,true,[true]];
_item = param[1,"",[""]];
_amount = param[2,0,[0]];

if(_item isEqualTo "" OR _amount isEqualTo 0) exitWith {};
if(isnil "ALPHA_ITEM_INV_INFO") then {ALPHA_ITEM_INV_INFO = [];};


_addstr = if(_add) then {"+"} else {"-"};
if(_add) then {
	_text = parsetext format["<t align='left' color='#00FF00'>%1</t><t align='left'>%2 </t><img size='1'  image='%3'/>   <t align='left' color='#00FF00'>%4</t>",_addstr,_amount,(gettext(missionConfigFile >> "VirtualItems" >> _item >> "icon")),( localize gettext(missionConfigFile >> "VirtualItems" >> _item >> "displayname"))];
} else {
	_text = parsetext format["<t align='left' color='#FF0000'>%1</t><t align='left'>%2 </t><img size='1'  image='%3'/>   <t align='left' color='#FF0000'>%4</t>",_addstr,_amount,(gettext(missionConfigFile >> "VirtualItems" >> _item >> "icon")),( localize gettext(missionConfigFile >> "VirtualItems" >> _item >> "displayname"))];
};

disableSerialization;
_display = finddisplay 46;
private _TextField = _display ctrlCreate ["RscStructuredText", -1];
_TextField ctrlSetStructuredText _text;
_TextField ctrlSetPosition [0.499484 * safezoneW + safezoneX,0.5 * safezoneH + safezoneY,0.171875 * safezoneW,0.0244444 * safezoneH];
_TextField ctrlCommit 0;
_TextField ctrlSetPosition [0.499484 * safezoneW + safezoneX,0.5 * safezoneH + safezoneY,0.171875 * safezoneW, ((ctrlTextHeight _TextField)+ (0.005 * safezoneH))];
_TextField ctrlCommit 0;
[_TextField] spawn {
	disableSerialization;
	uisleep 3;
	(_this select 0) ctrlsetfade 1;
	(_this select 0) ctrlCommit 1;
	uisleep 1;
	ctrlDelete (_this select 0);


};
private _posText = (ctrlPosition (_TextField)) select 1;
private _textHigh = (ctrlPosition (_TextField)) select 3;

if (count ALPHA_ITEM_INV_INFO > 0) then {
 private _activeNotifications = 0;
 {

 private _ctrlText = _x select 0;
 if (!isNull _ctrlText) then {
 _ctrlText ctrlSetPosition [0.499484 * safezoneW + safezoneX, (_posText + _textHigh - 0.25*(0.011 * safezoneH))];
 _ctrlText ctrlCommit 0.25;
 _posText = (_posText + _textHigh - 0.25*(0.011 * safezoneH));
 _textHigh = (ctrlPosition (_ctrlText)) select 3;
 if (_activeNotifications > 8) then {
 _ctrlText ctrlSetFade 1;
 _ctrlText ctrlCommit 0.2;
 };
 _activeNotifications = _activeNotifications + 1;
 };
 } forEach ALPHA_ITEM_INV_INFO;
};
ALPHA_ITEM_INV_INFO = ([[_TextField]] + ALPHA_ITEM_INV_INFO) select {!isNull (_x select 0)};