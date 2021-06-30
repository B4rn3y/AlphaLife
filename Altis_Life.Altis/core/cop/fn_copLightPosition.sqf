
private ["_vehicle","_side","_clr","_pos"];
_vehicle = param[0,objNull,[objNull]];
_side = param[1,sideUnknown,[sideUnknown]];

if!(_side isEqualTo sideUnknown) exitWith {

    _clr = switch (_side) do
    {
        case west:
        {

            [
                [0.1, 0.1, 20],
                [20, 0.1, 0.1]
            ]
        };

        case independent:
        {

            [
                [0.1, 0.1, 20],
                [0.1, 0.1, 20]
            ]
        };

        default
        {
            []
        };
    };

    _clr
};

_pos = switch (typeOf _vehicle) do {
    case "C_Offroad_01_F": {
        [[-0.37, 0.0, 0.56], [0.37, 0.0, 0.56]];
    };
    case "B_MRAP_01_F": {
        [[-0.37, -1.9, 0.7], [0.37, -1.9, 0.7]];
    };
    case "I_MRAP_03_F": {
        [[-0.8,0,0.75], [0.8,0,0.75]];
    };
    case "O_Truck_03_covered_F": { // tempest abgedeckt
        [[0.5,2,1.1], [-0.5,2,1.1]];
    };
    case "O_Truck_03_medical_F": { // tempest abgedeckt sani
        [[0.5,2,1.1], [-0.5,2,1.1]];
    };
    case "B_LSV_01_unarmed_F": {
        [[0.75,0,0.1], [-0.75,0,0.1]];
    };
    case "I_Truck_02_medical_F": {
        [[0.5,2.8,0.8], [-0.5,2.8,0.8]];
    };
    case "B_Truck_01_medical_F": {
        [[0.5,4.2,0.78], [-0.5,4.2,0.78]];
    };
    case "I_E_Van_02_transport_MP_F": {
        [[0.4,1.55,1.4], [-0.4,1.55,1.4]];
    };
    case "B_Quadbike_01_F": {
        [[0.3,0.7,-0.3], [-0.3,0.7,-0.3]];
    };
    case "C_SUV_01_F": {
        [[-0.37,-1.2,0.42], [0.37,-1.2,0.42]];
    };
    case "C_Hatchback_01_sport_F": {
        [[-0.35,-0.2,0.25], [0.35,-0.2,0.25]];
    };
    case "B_Heli_Light_01_F": {
        [[-0.37, 0.0, -0.80], [0.37, 0.0, -0.80]];
    };
    case "B_Heli_Transport_01_F": {
        [[-0.5, 0.0, 0.81], [0.5, 0.0, 0.81]];
    };
    default {
        [];
    };
};


_pos