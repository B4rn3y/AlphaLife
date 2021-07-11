


private ["_join_gang","_exit","_display","_listNBox","_btn_1","_btn_2","_gang_id","_alliances","_alliances_gang_ids","_gang_name"];

_join_gang = param[0,false,[false]];

_exit = false;
_display = findDisplay 518845;
if(isnull _display) then {
    if!(createDialog "gang_join") exitWith {_exit = true};
};
if(_exit) exitWith {};
_display = findDisplay 518845;
_listNBox = _display displayCtrl 1500;
_btn_1 = _display displayCtrl 2400;
_btn_2 = _display displayCtrl 2401;





lnbClear _listNBox;


if(_join_gang) then {

    _btn_1 buttonSetAction "[] spawn life_fnc_gangJoin;";
    _btn_1 ctrlSetText "Join";
    _btn_1 ctrlShow true;
    _btn_2 ctrlshow false;

    {
        _gang_id = _x getVariable["gang_id",-1];
        if!(_gang_id isEqualTo -1) then {
            _id = _listNBox lnbAddRow [_x getVariable["gang_name","no name"], if(_x getVariable["gang_public",0] isEqualTo 1) then {"Öffentlich"} else {"Geschlossen"}];
            if(_x getVariable["gang_public",0] isEqualTo 1) then {
                _listNBox lnbSetColor[[_id,0],[0,1,0,1]];
                _listNBox lnbSetColor[[_id,1],[0,1,0,1]];
            } else {
                _listNBox lnbSetColor[[_id,0],[1,0,0,1]];
                _listNBox lnbSetColor[[_id,1],[1,0,0,1]];
            };
            _listNBox lnbSetValue[[_id,0],_gang_id];
            _listNBox lnbSetValue[[_id,1],_gang_id];

        };
    } foreach (allGroups - [group player]);
} else {
    /*
    [
        [Gang ID, Gang Name]
    ]
    */

    _btn_1 buttonSetAction "[] spawn life_fnc_gang_invite_allie;";
    _btn_1 ctrlSetText "Set Allie";
    _btn_1 ctrlShow true;
    _btn_2 ctrlshow true;
    _btn_2 ctrlSetText "Remove Allie";
    _btn_2 buttonSetAction "[] spawn life_fnc_gang_remove_allie;";

    _alliances = (group player) getVariable["gang_alliances",[]];
    _alliances_gang_ids = [];
    {_alliances_gang_ids pushBackUnique (_x select 0);} foreach _alliances;

    {
        _gang_id = _x getVariable["gang_id",-1];
        if!(_gang_id isEqualTo -1) then {

            if(_gang_id in _alliances_gang_ids) then {
                _id = _listNBox lnbAddRow [format["[Verbündet] %1",_x getVariable["gang_name","no name"]], if(_x getVariable["gang_public",0] isEqualTo 1) then {"Öffentlich"} else {"Geschlossen"}];
                _alliances_gang_ids = _alliances_gang_ids - [_gang_id];
                _listNBox lnbSetColor[[_id,0],[0,1,0,1]];
                _listNBox lnbSetColor[[_id,1],[0,1,0,1]];
                _listNBox lnbSetValue[[_id,0],_gang_id];
                _listNBox lnbSetValue[[_id,1],_gang_id];
            } else {
                _id = _listNBox lnbAddRow [_x getVariable["gang_name","no name"], if(_x getVariable["gang_public",0] isEqualTo 1) then {"Öffentlich"} else {"Geschlossen"}];
                _listNBox lnbSetValue[[_id,0],_gang_id];
                _listNBox lnbSetValue[[_id,1],_gang_id];
            };
        };
    } foreach (allGroups - [group player]);


    {
        _gang_id = _x;
        _gang_name = "no name";
        {if((_x select 0) isEqualTo _gang_id) exitWith {_gang_name = _x select 1;};} foreach _alliances;

        _id = _listNBox lnbAddRow [format["[Verbündet] %1",_gang_name], "Unbekannt"];
        _listNBox lnbSetColor[[_id,0],[1,0,0,1]];
        _listNBox lnbSetColor[[_id,1],[1,0,0,1]];
        _listNBox lnbSetValue[[_id,0],_gang_id];
        _listNBox lnbSetValue[[_id,1],_gang_id];

    } foreach _alliances_gang_ids;


};