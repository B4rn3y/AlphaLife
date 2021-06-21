#include "..\..\script_macros.hpp"
/*
    File: fn_ticketPrompt
    Author: Bryan "Tonic" Boardwine

    Description:
    Prompts the player that he is being ticketed.
*/
private ["_cop","_val"];
if (!isNull (findDisplay 2600)) exitWith {}; //Already at the ticket menu, block for abuse?
_cop = _this select 0;
if (isNull _cop) exitWith {};
_val = _this select 1;

createDialog "life_ticket_pay";
disableSerialization;
waitUntil {!isNull (findDisplay 2600)};

life_ticket_paid = false;
life_ticket_val = _val;
life_ticket_cop = _cop;
if((side _cop) isEqualTo west) then {
    CONTROL(2600,2601) ctrlSetStructuredText parseText format ["<t align='center'><t size='.8px'>" +(localize "STR_Cop_Ticket_GUI_Given"),_cop getVariable ["realname",name _cop],_val];
} else {
    CONTROL(2600,2601) ctrlSetStructuredText parseText format ["<t align='center'><t size='.8px'>" +(localize "STR_Med_Bill_GUI_Given"),_cop getVariable ["realname",name _cop],_val];
};

(side _cop) spawn {
    _side = _this;
    disableSerialization;
    waitUntil {life_ticket_paid || (isNull (findDisplay 2600))};
    if (isNull (findDisplay 2600) && !life_ticket_paid) then {
        if(_side isEqualTo west) then {
            [0,"STR_Cop_Ticket_Refuse",true,[profileName]] remoteExecCall ["life_fnc_broadcast",west];
            [1,"STR_Cop_Ticket_Refuse",true,[profileName]] remoteExecCall ["life_fnc_broadcast",life_ticket_cop];
        } else {
            [0,"STR_Med_Bill_Refuse",true,[profileName]] remoteExecCall ["life_fnc_broadcast",independent];
            [1,"STR_Med_Bill_Refuse",true,[profileName]] remoteExecCall ["life_fnc_broadcast",life_ticket_cop];
        };
    };
};