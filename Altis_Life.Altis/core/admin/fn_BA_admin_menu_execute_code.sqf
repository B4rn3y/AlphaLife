

private ["_display","_lb_AllPlayers","_lb_options","_data"];

if((call life_adminlevel) <= 0) exitWith {hint "Kein Admin!";};

_display = findDisplay 9000;
if(isnull _display) exitWith {};
_lb_AllPlayers = _display displayCtrl 1501;
_lb_options = _display displayCtrl 1500;
_data = _lb_options lbData (lbCurSel _lb_options);
if(_data isEqualTo "") exitWith {};

call compile _data;



