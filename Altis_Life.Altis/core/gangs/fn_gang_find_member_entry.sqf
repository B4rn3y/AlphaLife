
private ["_pid","_ret"];

_pid = param[0,"",[""]];
if(_pid isEqualTo "") exitWith {[]};

if(isnil "life_gangdata") exitWith {[]};
if(life_gangdata isEqualTo []) exitWith {[]};
_ret = [];
{
    if((_x select 2) isEqualTo _pid) exitWith {_ret = _x;};
} foreach (life_gangdata select 5);

_ret