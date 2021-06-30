
if (!([false,"painkiller",1] call life_fnc_handleInv)) exitWith {}; //Error?

titletext["Du spürst wie die Schmerzmittel langsam anfangen zu wirken...","PLAIN DOWN"];

if!(7 in alpha_quests) then {
    [7] spawn life_fnc_quest_achieved;
};

for "_d" from 0 to 100 do {
    player setdamage (damage player - 0.01);
    sleep 0.3;
    if(damage player isEqualTo 0) exitWith {};
};