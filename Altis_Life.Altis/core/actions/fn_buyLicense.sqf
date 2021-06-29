#include "..\..\script_macros.hpp"
/*
    File: fn_buyLicense.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Called when purchasing a license. May need to be revised.
*/
private ["_type","_varName","_displayName","_sideFlag","_price"];
_type = _this select 3;

if (!isClass (missionConfigFile >> "Licenses" >> _type)) exitWith {}; //Bad entry?
_displayName = M_CONFIG(getText,"Licenses",_type,"displayName");
_price = M_CONFIG(getNumber,"Licenses",_type,"price");
_sideFlag = M_CONFIG(getText,"Licenses",_type,"side");
_varName = LICENSE_VARNAME(_type,_sideFlag);

if (CASH < _price) exitWith {hint format [localize "STR_NOTF_NE_1",[_price] call life_fnc_numberText,localize _displayName];};
CASH = CASH - _price;

[0] call SOCK_fnc_updatePartial;


[round(_price * 0.001),"Lizenzkauf"] spawn life_fnc_addexp;

if(_type isEqualTo "driver" && !(9 in alpha_quests))then {
    [9] spawn life_fnc_quest_achieved;
};

if(_type isEqualTo "gun" && !(10 in alpha_quests))then {
    [10] spawn life_fnc_quest_achieved;
};

if(_type isEqualTo "pilot" && !(11 in alpha_quests))then {
    [11] spawn life_fnc_quest_achieved;
};

if(_type isEqualTo "boat" && !(12 in alpha_quests))then {
    [12] spawn life_fnc_quest_achieved;
};

if(_type isEqualTo "rebel" && !(27 in alpha_quests))then {
    [27] spawn life_fnc_quest_achieved;
};

if(_type isEqualTo "mercenary" && !(37 in alpha_quests))then {
    [37] spawn life_fnc_quest_achieved;
};

if(_type isEqualTo "alpha" && !(38 in alpha_quests))then {
    [38] spawn life_fnc_quest_achieved;
};

titleText[format [localize "STR_NOTF_B_1", localize _displayName,[_price] call life_fnc_numberText],"PLAIN"];
missionNamespace setVariable [_varName,true];

[2] call SOCK_fnc_updatePartial;
