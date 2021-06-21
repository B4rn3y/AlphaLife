#include "..\..\script_macros.hpp"
/*
    File: fn_vInteractionMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Replaces the mass add actions for various vehicle actions.
*/
#define Btn1 37450
#define Btn2 37451
#define Btn3 37452
#define Btn4 37453
#define Btn5 37454
#define Btn6 37455
#define Title 37699

private ["_display","_Btn1","_Btn2","_Btn3","_Btn4","_Btn5","_Btn6"];
if (!dialog) then {
    createDialog "poss_Menu";
};
disableSerialization;


_display = findDisplay 37699;
_Btn1 = _display displayCtrl Btn1;
_Btn2 = _display displayCtrl Btn2;
_Btn3 = _display displayCtrl Btn3;
_Btn4 = _display displayCtrl Btn4;
_Btn5 = _display displayCtrl Btn5;
_Btn6 = _display displayCtrl Btn6;




switch (playerSide) do
{
    case west:
    {
        _Btn1 ctrlSetText "Wanted Menu";
        _Btn1 buttonSetAction "closeDialog 0;[] call life_fnc_wantedMenu;";

        _Btn2 ctrlSetText "Dispatch Menu";
        _Btn2 buttonSetAction "closeDialog 0;0 call life_call_start;";

        _Btn3 ctrlSetText "Placeables Menu";
        _Btn3 buttonSetAction "closeDialog 0;0 spawn life_fnc_placeablesMenu;";
        {
            _x ctrlShow false;
        } foreach [_Btn4,_Btn5,_Btn6];
    };

    case independent:
    {
        _Btn1 ctrlSetText "Dispatch Menu";
        _Btn1 buttonSetAction "closeDialog 0;0 call life_call_start;";

        _Btn2 ctrlSetText "Placeables Menu";
        _Btn2 buttonSetAction "closeDialog 0;0 spawn life_fnc_placeablesMenu;";
        {
            _x ctrlShow false;
        } foreach [_Btn3,_Btn4,_Btn5,_Btn6];
    };
};




