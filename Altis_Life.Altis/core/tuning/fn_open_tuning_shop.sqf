
/*
_car = "B_Truck_01_box_F" createvehiclelocal [9733.63,11430.6,33.7023];
_car allowDamage false;
_car setposatl [9733.63,11430.6,33.7023];
_car setdir 271.876;
blah = _car;
*/
private ["_caller","_actionId","_arguments","_near_vehicles","_vehicle","_owners","_exit","_foreachindex","_display","_lb","_combo","_exists"];

params ["_target", "_caller", "_actionId", "_arguments"];

_near_vehicles = nearestObjects[_target,["Landvehicle"],20];

if(_near_vehicles isEqualTo []) exitWith {["Es ist kein Fahrzeug in der Nähe"] spawn life_fnc_exp_hint;};



_vehicle = _near_vehicles select 0;

_owners = _vehicle getvariable ["vehicle_info_owners",[]];

if(_owners isEqualTo []) exitWith {["Dieses Fahrzeug gehört niemandem"] spawn life_fnc_exp_hint;};

if!(((_owners select 0) select 0) isEqualTo (getPlayerUID player)) exitWith {["Dieses Fahrzeug gehört nicht dir"] spawn life_fnc_exp_hint;};




_exit = {
	life_tuning_objs pushBack life_tuning_vehicle;
	life_shop_cam cameraEffect ["terminate", "Back"];
	camDestroy life_shop_cam;

	{deleteVehicle _x;} foreach life_tuning_objs;
	life_tuning_vehicle = nil;
	life_tuning_objs = nil;
	if!(isnil "life_tuning_light") then {
		detach life_tuning_light;
		deleteVehicle life_tuning_light;
	};
	life_tuning_light = nil;
	life_tuning_original_vehicle = nil;
};

call life_fnc_create_tuning_shop;

life_tuning_original_vehicle = _vehicle;

life_tuning_vehicle = (typeof _vehicle) createVehicleLocal [9733.63,11430.6,33.7023];
life_tuning_vehicle allowDamage false;
life_tuning_vehicle setposatl [9733.63,11430.6,33.7023];
life_tuning_vehicle setdir 271.876;

{
	life_tuning_vehicle setObjectTexture[_foreachindex,_x];
} foreach (getObjectTextures _vehicle);

{
	life_tuning_vehicle setObjectMaterial[_foreachindex,_x];
} foreach (getObjectMaterials _vehicle);


life_shop_cam = "CAMERA" camCreate [9732.93,11424.5,35.6338];
showCinemaBorder false;
life_shop_cam cameraEffect ["Internal", "Back"];
life_shop_cam camSetTarget life_tuning_vehicle;
life_shop_cam camSetPos [9732.93,11424.5,35.6338];
life_shop_cam camSetFOV .75;
life_shop_cam camSetFocus [50, 0];
life_shop_cam camCommit 0;


if!(createDialog "tuning") exitWith {call _exit};


_display = findDisplay 57742;

_lb = _display displayCtrl 1500;
_combo = _display displayCtrl 2100;

_combo lbadd "Folierungen";
_combo lbadd "Hupen";
_combo lbadd "Anderes";

_exists = false;
{
	if((_x select 0) isEqualTo (typeof _vehicle)) exitWith {_exists = true;};
} foreach getArray(missionConfigFile >> "Tuning_Conf" >> "Conf" >> "vehicle_light_pos");

if(_exists) then {
	_combo lbadd "Unterbodenbeleuchtung";
};

_combo lbSetCurSel 0;





waitUntil {isnull (findDisplay 57742)};

call _exit;


