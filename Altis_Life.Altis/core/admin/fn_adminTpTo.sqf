#include "..\..\script_macros.hpp"
/*
    File: fn_adminTpHere.sqf
    Author: ColinM9991

    Description:
    Teleport selected player to you.
*/
if (FETCH_CONST(life_adminlevel) < 1) exitWith {closeDialog 0;};

private _target = lbData[1501,lbCurSel (1501)];
_target = call compile format ["%1", _target];
if (isNil "_target" || isNull _target) exitWith {};
if (_target == player) exitWith {hint localize "STR_ANOTF_Error";};

if (!(vehicle _target isEqualTo _target)) exitWith {hint localize "STR_Admin_CannotTpHere"};
player setPos (getPos _target);
hint format ["Du hast dich zu %1 teleportiert",_target getVariable ["realname",name _target]];
