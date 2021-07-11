#include "..\..\script_macros.hpp"

disableSerialization;
_control = _this select 0;
_index = _this select 1;

if(isnil "life_vehicles_garage_save") exitWith {};


_display = findDisplay 2800;
_lb = _display displayCtrl 2802;
_combo = _display displayCtrl 2100;


lbClear _lb;

switch (_index) do
{
    case 1: // gangs
    {
        {
            _gang_id = _x select 15;
            if!(_gang_id isEqualTo -1) then {
                _vehicleInfo = [(_x select 2)] call life_fnc_fetchVehInfo;
                _lb lbAdd (_vehicleInfo select 3);
                _tmp = [(_x select 2),(_x select 8),(_x select 9),(_x select 10),(_x select 11),(_x select 12),(_x select 13),(_x select 14),(_x select 0),(_x select 15),(_x select 4)];
                _tmp = str(_tmp);
                _lb lbSetData [(lbSize _lb)-1,_tmp];
                _lb lbSetPicture [(lbSize _lb)-1,(_vehicleInfo select 2)];
                _lb lbSetValue [(lbSize _lb)-1,(_x select 0)];
            };
        } forEach life_vehicles_garage_save;
    };

    default
    {
        {
            _gang_id = _x select 15;
            if(_gang_id isEqualTo -1) then {
                _vehicleInfo = [(_x select 2)] call life_fnc_fetchVehInfo;
                _lb lbAdd (_vehicleInfo select 3);
                _tmp = [(_x select 2),(_x select 8),(_x select 9),(_x select 10),(_x select 11),(_x select 12),(_x select 13),(_x select 14),(_x select 0),(_x select 15),(_x select 4)];
                _tmp = str(_tmp);
                _lb lbSetData [(lbSize _lb)-1,_tmp];
                _lb lbSetPicture [(lbSize _lb)-1,(_vehicleInfo select 2)];
                _lb lbSetValue [(lbSize _lb)-1,(_x select 0)];
            };
        } forEach life_vehicles_garage_save;
    };
};
