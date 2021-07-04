#include "..\..\script_macros.hpp"

private ["_display","_time","_lic","_side","_struct","_displayName"];

disableSerialization;
createDialog "licenses_new_menu";
waitUntil {!isNull (findDisplay 9580)};
_display = findDisplay 9580;
_time = _display displayCtrl 7858;
_lic = _display displayCtrl 2014;
_time ctrlsettext format["%1:%2",systemtime select 3,systemtime select 4];
ctrlSetText[2009,format ["%1 / %2", life_carryWeight, life_maxWeight]];

_side = switch (playerSide) do {case west:{"cop"}; case civilian:{"civ"}; case independent:{"med"};};
_struct = "";
{
    _displayName = getText(_x >> "displayName");

    if (LICENSE_VALUE(configName _x,_side)) then {
    	if((localize _displayName) isEqualTo "") then {
    		_struct = _struct + format ["%1<br/>",_displayName];
    	} else {
        	_struct = _struct + format ["%1<br/>",localize _displayName];
        };
    };
} forEach (format ["getText(_x >> 'side') isEqualTo '%1'",_side] configClasses (missionConfigFile >> "Licenses"));

if (_struct isEqualTo "") then {
    _struct = "No Licenses";
};

_lic ctrlSetStructuredText parseText format ["
<t size='0.8px'>
%1
</t>
",_struct];