#include "..\..\script_macros.hpp"
/*
    File: fn_p_openMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Opens the players virtual inventory menu
*/
if (!alive player || dialog) exitWith {}; //Prevent them from opening this for exploits while dead.
createDialog "playerSettings";
disableSerialization;

switch (playerSide) do {
    case west: {
        ctrlShow[1204,false]; // dont show gang stuff - hide picture and btn
        ctrlShow[3004,false];
    };

    case civilian: {

    };

    case independent: {
        ctrlShow[1204,false]; // dont show gang stuff - hide picture and btn
        ctrlShow[3004,false];
    };
};

if (FETCH_CONST(life_adminlevel) < 1) then {
    ctrlShow[1208,false];
    ctrlShow[3008,false];
};

[] call life_fnc_p_updateMenu;
