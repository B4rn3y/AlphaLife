#include "..\..\script_macros.hpp"
/*
    File: fn_gangInvitePlayer.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Invites the player into the gang.
*/
private "_unit";
disableSerialization;

if ((lbCurSel 2632) isEqualTo -1) exitWith {hint localize "STR_GNOTF_SelectPerson"};
_unit = [CONTROL_DATA(2632)] call life_fnc_findPlayerOfPID;

if (isNull _unit) exitWith {}; //Bad unit?
if (_unit isEqualTo player) exitWith {hint localize "STR_GNOTF_InviteSelf"};
if (!isNil {(group _unit) getVariable "gang_name"}) exitWith {hint localize "STR_GNOTF_playerAlreadyInGang";}; //Added

if (count(group player getVariable ["gang_members",[]]) isEqualTo (group player getVariable ["gang_maxMembers",8])) exitWith {hint localize "STR_GNOTF_MaxSlot"};

_action = [
    format [localize "STR_GNOTF_InvitePlayerMSG",_unit getVariable ["realname",name _unit]],
    localize "STR_Gang_Invitation",
    localize "STR_Global_Yes",
    localize "STR_Global_No"
] call BIS_fnc_guiMessage;

if (_action) then {
    [profileName,group player] remoteExec ["life_fnc_gangInvite",_unit];
    hint format [localize "STR_GNOTF_InviteSent",_unit getVariable ["realname",name _unit]];
} else {
    hint localize "STR_GNOTF_InviteCancel";
};
