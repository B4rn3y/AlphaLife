#include "..\..\script_macros.hpp"
/*
    File: fn_seizeClient.sqf
    Author: Daniel "Skalicon" Larusso

    Description:
    Removes the players weapons client side
*/
private ["_exempt","_headgear","_vest","_uniform","_items_to_go_to_the_evidence_room","_foreachindex"];
_exempt = LIFE_SETTINGS(getArray,"seize_exempt");
_headgear = LIFE_SETTINGS(getArray,"seize_headgear");
_vest = LIFE_SETTINGS(getArray,"seize_vest");
_uniform = LIFE_SETTINGS(getArray,"seize_uniform");

_items_to_go_to_the_evidence_room = [];
/*
{
    if (!(_x in _exempt)) then {
        player removeWeapon _x;
    };
} forEach weapons player;
*/

{
    if (!(_x in _exempt)) then {
        switch (_foreachindex) do
        {
            case 1:
            {
                {
                    if!(_x isEqualTo "") then {
                        _items_to_go_to_the_evidence_room pushback _x;
                    };
                } foreach (handgunItems player);
            };

            case 2:
            {
                {
                    if!(_x isEqualTo "") then {
                        _items_to_go_to_the_evidence_room pushback _x;
                    };
                } foreach (secondaryWeaponItems player);
            };

            default
            {
                {
                    if!(_x isEqualTo "") then {
                        _items_to_go_to_the_evidence_room pushback _x;
                    };
                } foreach (primaryWeaponitems player);
            };
        };
        _items_to_go_to_the_evidence_room pushback _x;
        player removeWeapon _x;
    };
} foreach [primaryWeapon player, handgunWeapon player, secondaryWeapon player];

{
    if (!(_x in _exempt)) then {
        _items_to_go_to_the_evidence_room pushback _x;
        player removeItemFromUniform _x;
    };
} forEach uniformItems player;

{
    if (!(_x in _exempt)) then {
        _items_to_go_to_the_evidence_room pushback _x;
        player removeItemFromVest _x;
    };
} forEach vestItems player;

{
    if (!(_x in _exempt)) then {
        _items_to_go_to_the_evidence_room pushback _x;
        player removeItemFromBackpack _x;
    };
} forEach backpackItems player;

{
    if (!(_x in _exempt)) then {
        _items_to_go_to_the_evidence_room pushback _x;
        player removeMagazine _x;
    };
} forEach magazines player;

if (uniform player in _uniform) then {_items_to_go_to_the_evidence_room pushback (uniform player);removeUniform player;};
if (vest player in _vest) then {_items_to_go_to_the_evidence_room pushback (vest player);removeVest player;};
if (headgear player in _headgear) then {_items_to_go_to_the_evidence_room pushback (headgear player);removeHeadgear player;};

if!(_items_to_go_to_the_evidence_room isEqualTo []) then {
    [100,"Beschlagnahmt"] spawn life_fnc_addexp;
    if!(isnil "evidence_box_0") then {
        if!(isnull evidence_box_0) then { // Check if the box is really there so the server does not have to
            [_items_to_go_to_the_evidence_room] remoteExec["life_fnc_insert_weapons_evidence_room",2];
        };
    };
};

[] call SOCK_fnc_updateRequest;
titleText[localize "STR_NOTF_SeizeIllegals","PLAIN"];
