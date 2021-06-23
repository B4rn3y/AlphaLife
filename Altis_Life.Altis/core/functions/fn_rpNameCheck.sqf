private ["_charrules", "_name", "_parts", "_amount", "_spaces", "_cplNames"];

_charrules = [65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,97,98,99,100,
101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,246,228,252,214,196,220,223,32];

_name = toArray _this; //profileName
_parts = _this splitString " "; //name parts
_amount = {_x == 32} count _name; //count spaces
_spaces = [];
_cplNames = 0;


{
	if (_x == 32) then {_spaces append [_forEachIndex]}; //get all spaces from _name and save the index into _spaces
} forEach _name;
{
	if (count _x > 2) then {_cplNames = _cplNames + 1}; //For every namepart over 2 digits increment _cplnames
}forEach _parts;

hint format ["_name: %1 _parts: %2 _spaces: %3 _amount: %4", _name, _parts, _spaces, _amount];

try {
	if (_amount == 0) then { //no spaces
		throw "Es sind nur Namen bestehend aus Vor- und Nachnamen gestattet";
	};
	if (_amount > 3) then { // too much spaces
		throw "Zu viele Leerzeichen im Namen!";
	};
	if (_spaces find 0 != -1 || _spaces find (count _name -1) != -1) then { // spaces on first or last char
		throw "Leerzeichen am Anfang oder am Ende des Namens sind untersagt!";
	};
	if (count _parts -1 > _cplNames) then { // more then one 2 char element
		throw "In deinem Namen ist nur ein Teil des Namens mit weniger als 3 Buchstaben erlaubt!";
	};
	{
		if (!(_x in _charrules)) then {
			throw "In deinem Namen sind ausschließlich Buchstaben des deutschen Alphabets gestattet!"
		};
	}forEach _name;
	
	"";
} catch {
	_exception;
};
