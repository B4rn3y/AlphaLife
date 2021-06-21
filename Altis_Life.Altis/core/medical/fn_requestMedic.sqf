#include "..\..\script_macros.hpp"
/*
    File: fn_requestMedic.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    N/A
*/
private "_medicsOnline";
_medicsOnline = {!(_x isEqualTo player) && {side _x isEqualTo independent} && {alive _x}} count playableUnits > 0; //Check if medics (indep) are in the room.

life_corpse setVariable ["Revive",false,true]; //Set the corpse to a revivable state.
if (_medicsOnline) then {
    //There is medics let's send them the request.
    [life_corpse,profileName] remoteExecCall ["life_fnc_medicRequest",independent];
} else {
    //No medics were online, send it to the police.
    [life_corpse,profileName] remoteExecCall ["life_fnc_medicRequest",west];
};

((findDisplay 7300) displayCtrl 7303) ctrlEnable false;
life_med_calls pushBack [(name player),(getpos life_corpse),"Ich benötige einen Revive - Automatische SOS Nachricht über das Telefon",servertime,"",player];
publicVariable "life_med_calls";