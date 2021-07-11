
private ["_index","_text"];

_index = param[0,-1,[0]];
_text = param[1,"",[""]];
if(_index isEqualTo -1) exitWith {};

switch (_index) do
{
    case 0:
    {
        life_gangdata set[5,(group player getVariable["gang_members",[]])];
    };

    case 1:
    {
        life_gangdata set[1,(group player getVariable["gang_owner",""])];
    };

    case 2:
    {
        life_gangdata set[3,(group player getVariable["gang_maxmembers",""])];
    };

    case 3:
    {
        life_gangData set[6,(group player getVariable["gang_alliances",[]])];
    };

    case 4:
    {
        life_gangData set[8,(group player getVariable["gang_tax",0])];
    };

    case 5:
    {
        life_gangData set[9,(group player getVariable["gang_public",0])];
    };
};

if!(_text isEqualTo "") then {
    [_text] spawn life_fnc_exp_hint;
};

if!(isnull(findDisplay 2620)) then {
    [] call life_fnc_gangMenu;
};