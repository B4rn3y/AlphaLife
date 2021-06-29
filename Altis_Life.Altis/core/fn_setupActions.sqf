/*
    File: fn_setupActions.sqf
    Author:

    Description:
    Master addAction file handler for all client-based actions.
*/

life_actions = [];

switch (playerSide) do {

    //Civilian
    case civilian: {
        //Drop fishing net
        life_actions pushBack (player addAction[localize "STR_pAct_DropFishingNet",life_fnc_dropFishingNet,"",0,false,false,"",'
        (surfaceisWater (getPos vehicle player)) && (vehicle player isKindOf "Ship") && life_carryWeight < life_maxWeight && speed (vehicle player) < 2 && speed (vehicle player) > -1 && !life_net_dropped ']);

        //Rob person
        life_actions pushBack (player addAction[localize "STR_pAct_RobPerson",life_fnc_robAction,"",0,false,false,"",'
        !isNull cursorObject && player distance cursorObject < 3.5 && isPlayer cursorObject && animationState cursorObject == "Incapacitated" && !(cursorObject getVariable ["robbed",false]) ']);
    };
    //Cops
    case west: {
        life_actions pushBack (player addAction["<t color='#1E90FF'>[Aussteigen] Fahrzeug",life_fnc_unlockVeh,"exit",100,false,false,"",'!isnull objectParent player']);
        life_actions pushBack (player addAction["<t color='#1E90FF'>[Einsteigen] Fahrzeug",life_fnc_unlockVeh,"GetIn",100,false,false,"",'(cursorObject isKindOf "LandVehicle" || cursorObject isKindOf "Air" || cursorObject isKindOf "Ship") && isnull objectParent player && ((player distance cursorObject) < 10)']);
     };

    //EMS
    case independent: { };

};
