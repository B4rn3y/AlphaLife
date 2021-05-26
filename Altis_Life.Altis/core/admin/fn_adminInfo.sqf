#include "..\..\script_macros.hpp"
/*
    File: fn_adminInfo.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Output information received to admin menu.
*/
private ["_ret","_unit","_prim","_sec","_vest","_uni","_bp","_attach","_steamName","_secondary"];
_ret = _this;
disableSerialization;

_unit = _ret select 3;
_prim = if (!(primaryWeapon _unit isEqualTo "")) then { FETCH_CONFIG2(getText,"CfgWeapons",primaryWeapon _unit,"displayName")} else {"None"};
_sec = if (!(handgunWeapon _unit isEqualTo "")) then { FETCH_CONFIG2(getText,"CfgWeapons",handgunWeapon _unit,"displayName")} else {"None"};
_vest = if (!(vest _unit isEqualTo "")) then { FETCH_CONFIG2(getText,"CfgWeapons",vest _unit,"displayName")} else {"None"};
_uni = if (!(uniform _unit isEqualTo "")) then { FETCH_CONFIG2(getText,"CfgWeapons",uniform _unit,"displayName")} else {"None"};
_bp = if (!(backpack _unit isEqualTo "")) then {FETCH_CONFIG2(getText,"CfgVehicles",backpack _unit,"displayName")} else {"None"};

_attach = [];
_secondary = [];
if (!(primaryWeapon _unit isEqualTo "")) then {
    {
        if (!(_x isEqualTo "")) then {
            _attach pushBack (FETCH_CONFIG2(getText,"CfgWeapons",_x,"displayName"));
        };
    } forEach (primaryWeaponItems _unit);
};

if (!(handgunItems _unit isEqualTo "")) then {
    {
        if (!(_x isEqualTo "")) then {
            _secondary pushBack (FETCH_CONFIG2(getText,"CfgWeapons",_x,"displayName"));
        };
    } forEach (handgunItems _unit);
};

_steamName = _ret select 4;
if (!((_ret select 4) isEqualType "")) then {
    _steamName = "Not a Steam User!";
};

if (count _attach isEqualTo 0) then {_attach = "None"};
if (count _secondary isEqualTo 0) then {_secondary = "None"};
CONTROL(9000,1100) ctrlSetStructuredText parseText (format["<t size='2.0' color='#FF0000' align='center'>SERVER INFO:</t> <br/> <t align='left'>BLUFOR</t><t align='right'>%1</t> <br/> <t align='left'>INDEPENDENT</t> <t align='right'>%2</t> <br/> <t align='left'>OPFOR</t> <t align='right'>%3</t> <br/> <t align='left'>CIVS</t> <t align='right'>%4</t> <br/> <t align='left'>ALLE:</t><t align='right'>%5</t> <br/> <t align='left'>Admin-LVL:</t><t align='right'>%6</t><br/><br/>",playersNumber west,playersNumber independent,playersNumber east,playersNumber civilian,count(playableUnits),(call life_adminlevel)] + format ["<t size='.7'>Name: %1<br/>Steam Name: %10<br/>Player UID: %11<br/>Player Side: %12<br/>Bank: %2<br/>Money: %3<br/>Uniform: %4<br/>Vest: %5<br/>Backpack: %6<br/>Primary: %7<br/>Handgun: %8<br/><t align='center'>Primary Attachments</t><br/>%9<br/><t align='center'>Secondary Attachments</t><br/>%13<br/></t>",
_unit getVariable ["realname",name _unit],[(_ret select 0)] call life_fnc_numberText,[(_ret select 1)] call life_fnc_numberText, _uni,_vest,_bp,_prim,_sec,_attach,_steamName,(_ret select 5),(_ret select 6),_secondary]);
