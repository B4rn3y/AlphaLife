
_amount = param[0,-1,[0]];
if(_amount isEqualTo -1) exitWith {};

[format["Durch die Kontrolle über die Gang Area hast du $%1 auf dein Konto bekommen.",[_amount] call life_fnc_numbertext]] spawn life_fnc_exp_hint;

alpha_atmbank = alpha_atmbank + _amount;