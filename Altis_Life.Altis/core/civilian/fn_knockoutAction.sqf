#include "..\..\script_macros.hpp"
/*
    File: fn_knockoutAction.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Knocks out the target.
*/
private "_target";
_target = param [0,objNull,[objNull]];
_name = param[1,profileName,[""]];

//Error checks
if (isNull _target) exitWith {};
if (!isPlayer _target) exitWith {};
if (player distance _target > 4) exitWith {};
life_knockout = true;
if!(_target isEqualTo player) then {

	if!(16 in alpha_quests)then {
	    [16] spawn life_fnc_quest_achieved;
	};

	if((_target getVariable["rank",0]>7) && !(34 in alpha_quests)) then {
		[34] spawn life_fnc_quest_achieved;
	};

	if((_target getVariable["rank",0]>0) && !(23 in alpha_quests)) then {
		[23] spawn life_fnc_quest_achieved;
	};

	[player,"AwopPercMstpSgthWrflDnon_End2"] remoteExecCall ["life_fnc_animSync",RCLIENT];
	sleep 0.08;
};
[_target,_name] remoteExec ["life_fnc_knockedOut",_target];

sleep 3;
life_knockout = false;
