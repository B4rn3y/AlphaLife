#include "..\..\script_macros.hpp"

_vehicle = param [0,objNull,[objNull]];
if!(_vehicle isKindOf "Landvehicle") exitWith {};
if (player distance _vehicle > 10) exitWith {};


life_action_inUse = true;

_upp = localize "STR_NOTF_Remove_horn";
//Setup our progress bar.
disableSerialization;
"progressBar" cutRsc ["life_progress","PLAIN"];
_ui = uiNamespace getVariable "life_progress";
_progress = _ui displayCtrl 38201;
_pgText = _ui displayCtrl 38202;
_pgText ctrlSetText format ["%2 (1%1)...","%",_upp];
_progress progressSetPosition 0.01;
_cP = 0.01;
_cp_plus = missionNamespace getvariable["alpha_skills_impound",0.01];
for "_i" from 0 to 1 step 0 do {
    uiSleep 0.09;
    _cP = _cP + _cp_plus;
    _progress progressSetPosition _cP;
    _pgText ctrlSetText format ["%3 (%1%2)...",round(_cP * 100),"%",_upp];
    if (_cP >= 1) exitWith {};
    if (player distance _vehicle > 10) exitWith {};
    if (!alive player) exitWith {};
    if !(count crew _vehicle isEqualTo 0) exitWith {};
};

"progressBar" cutText ["","PLAIN"];
if !(count crew _vehicle isEqualTo 0) exitWith {["Das Fahrzeug muss leer sein"] spawn life_fnc_exp_hint; life_action_inUse = false;};
if (player distance _vehicle > 10) exitWith {hint localize "STR_NOTF_ImpoundingCancelled"; life_action_inUse = false;};
if (!alive player) exitWith {life_action_inUse = false;};

[_vehicle,1,0] remoteexec["life_fnc_tuning_update_vehicle",2];
life_action_inUse = false;

["Hupe wurde efolgreich entfernt"] spawn life_fnc_exp_hint;
