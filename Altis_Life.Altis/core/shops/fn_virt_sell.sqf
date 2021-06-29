#include "..\..\script_macros.hpp"
/*
    File: fn_virt_sell.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Sell a virtual item to the store / shop
*/
private ["_sell_all","_type","_price","_amount","_array","_ind","_val"];
if ((lbCurSel 2402) isEqualTo -1) exitWith {};
_sell_all = param[0,false,[false]];

_type = lbData[2402,(lbCurSel 2402)];
_price = M_CONFIG(getNumber,"VirtualItems",_type,"sellPrice");
if (_price isEqualTo -1) exitWith {};

_amount = ctrlText 2405;
if (!([_amount] call TON_fnc_isnumber)) exitWith {hint localize "STR_Shop_Virt_NoNum";};
_amount = parseNumber (_amount);

if(_sell_all) then {
    _amount = ITEM_VALUE(_type);
};

if (_amount > (ITEM_VALUE(_type))) exitWith {hint localize "STR_Shop_Virt_NotEnough"};
if ((time - life_action_delay) < 0.2) exitWith {hint localize "STR_NOTF_ActionDelay";};
life_action_delay = time;

_price = (_price * _amount);
_name = M_CONFIG(getText,"VirtualItems",_type,"displayName");
if ([false,_type,_amount] call life_fnc_handleInv) then {
    hint format [localize "STR_Shop_Virt_SellItem",_amount,(localize _name),[_price] call life_fnc_numberText];
    CASH = CASH + _price;
    [0] call SOCK_fnc_updatePartial;
    [] call life_fnc_virt_update;

    //check quests
    if(_type isEqualTo "apple" && !(1 in alpha_quests))then {
        [1] spawn life_fnc_quest_achieved;
    };

    if(_type isEqualTo "iron_refined" && !(2 in alpha_quests))then {
        [2] spawn life_fnc_quest_achieved;
    };

    if(_type isEqualTo "copper_refined" && !(3 in alpha_quests))then {
        [3] spawn life_fnc_quest_achieved;
    };

    if(_type isEqualTo "turtle_raw" && !(18 in alpha_quests))then {
        [18] spawn life_fnc_quest_achieved;
    };

    if(_type isEqualTo "lsd" && !(33 in alpha_quests))then {
        [33] spawn life_fnc_quest_achieved;
    };

    if(_type in["lsd","cocaine_processed","heroin_processed","marijuana"] && !(28 in alpha_quests))then {
        [28] spawn life_fnc_quest_achieved;
    };



};

if (life_shop_type isEqualTo "drugdealer") then {
    private ["_array","_ind","_val"];
    _array = life_shop_npc getVariable ["sellers",[]];
    _ind = [getPlayerUID player,_array] call TON_fnc_index;
    if (!(_ind isEqualTo -1)) then {
        _val = ((_array select _ind) select 2);
        _val = _val + _price;
        _array set[_ind,[getPlayerUID player,profileName,_val]];
        life_shop_npc setVariable ["sellers",_array,true];
    } else {
        _array pushBack [getPlayerUID player,profileName,_price];
        life_shop_npc setVariable ["sellers",_array,true];
    };
};

if (life_shop_type isEqualTo "gold" && (LIFE_SETTINGS(getNumber,"noatm_timer")) > 0) then {
    [] spawn {
        life_use_atm = false;
        sleep ((LIFE_SETTINGS(getNumber,"noatm_timer")) * 60);
        life_use_atm = true;
    };
};

[3] call SOCK_fnc_updatePartial;