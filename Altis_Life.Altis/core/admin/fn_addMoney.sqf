private ["_display","_btn1","_btn2"];
closeDialog 0;
_obj = param[0,"",[""]];
if(_obj isEqualTo "") exitWith {
	disableSerialization;
	createDialog "RscDisplayPassword";
	ctrlSetText [1002,"amount:"];
	ctrlSetText [1000,"Add Money to your Player"];
	ctrlshow [1,true];
	ctrlshow [2,true];

	_display = findDisplay 64;
	_btn1 = _display displayctrl 2;
	_btn1 ctrlSetText "Close";
	_btn1 buttonSetAction "closeDialog 0";

	_display = findDisplay 64;
	_btn2 = _display displayctrl 1;
	_btn2 ctrlSetText "Accept";
	_btn2 buttonSetAction
	"
		_display = findDisplay 64;
		_textCode = _display displayctrl 101;
		_exec = ctrlText 101;
		_name = name player;
		_number = parseNumber _exec;
		if (_number > 0) then
		{
		alpha_cash = alpha_cash + _number;
		Hint format [""You added %1 $"",_exec];
		};


	";
};

_obj = call compile _obj;
if(isnil "_obj") exitWith {["EROR: player nicht gefunden"] spawn life_Fnc_exp_hint};
if(isnull _obj ) exitWith {["EROR: player nicht gefunden"] spawn life_Fnc_exp_hint};

disableSerialization;
createDialog "RscDisplayPassword";
ctrlSetText [1002,"amount:"];
ctrlSetText [1000,"Add Money to another Player"];
ctrlshow [1,true];
ctrlshow [2,true];

_display = findDisplay 64;
_btn1 = _display displayctrl 2;
_btn1 ctrlSetText "Close";
_btn1 buttonSetAction "closeDialog 0";

_display = findDisplay 64;
_btn2 = _display displayctrl 1;
_btn2 ctrlSetText "Accept";
_btn2 buttonSetAction
format["
	_display = findDisplay 64;
	_textCode = _display displayctrl 101;
	_exec = ctrlText 101;
	_name = name player;
	_number = parseNumber _exec;
	if (_number > 0) then
	{
	[%1,_number,player] remoteExecCall [""life_fnc_receiveMoney_admin"",%1];
	[""Transactions success""] spawn life_Fnc_exp_hint;
 	};


",getplayeruid _obj];

