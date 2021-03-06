class CarShops {
    /*
    *    ARRAY FORMAT:
    *        0: STRING (Classname)
    *        1: STRING (Condition)
    *    FORMAT:
    *        STRING (Conditions) - Must return boolean :
    *            String can contain any amount of conditions, aslong as the entire
    *            string returns a boolean. This allows you to check any levels, licenses etc,
    *            in any combination. For example:
    *                "call life_coplevel && license_civ_someLicense"
    *            This will also let you call any other function.
    *
    *   BLUFOR Vehicle classnames can be found here: https://community.bistudio.com/wiki/Arma_3_CfgVehicles_WEST
    *   OPFOR Vehicle classnames can be found here: https://community.bistudio.com/wiki/Arma_3_CfgVehicles_EAST
    *   Independent Vehicle classnames can be found here: https://community.bistudio.com/wiki/Arma_3_CfgVehicles_GUER
    *   Civilian Vehicle classnames can be found here: https://community.bistudio.com/wiki/Arma_3_CfgVehicles_CIV
    */
    class civ_car {
        side = "civ";
        conditions = "";
        vehicles[] = {
            { "B_Quadbike_01_F", "" },
            { "C_Offroad_01_F", "" },
            { "C_SUV_01_F", "" },
            { "C_Offroad_02_unarmed_F", "" },//Apex DLC
            { "C_Hatchback_01_sport_F", "" }
        };
    };

    class kart_shop {
        side = "civ";
        conditions = "";
        vehicles[] = {
            { "C_Kart_01_Blu_F", "" },
            { "C_Kart_01_Fuel_F", "" },
            { "C_Kart_01_Red_F", "" },
            { "C_Kart_01_Vrana_F", "" }
        };
    };

    class civ_truck {
        side = "civ";
        conditions = "";
        vehicles[] = {
            { "C_Van_01_box_F", "" },
            { "C_Van_01_fuel_F", "" },
            { "C_Van_02_transport_F", "" },
            { "O_Truck_02_transport_F", "" },
            { "O_Truck_02_covered_F", "" },
            { "O_Truck_03_transport_F", "" },
            { "O_Truck_03_covered_F", "" },
            { "B_T_Truck_01_covered_F", "" },
            { "B_T_Truck_01_box_F", "" },
            { "B_T_Truck_01_fuel_F", "" },
            { "O_Truck_03_device_F", "" }
        };
    };

    class civ_air {
        side = "civ";
        conditions = "";
        vehicles[] = {
            { "C_Heli_Light_01_civil_F", "" },
            { "O_Heli_Light_02_unarmed_F", "" },
            { "I_Heli_Transport_02_F", "" },
            { "O_Heli_Transport_04_box_F", "" },
            { "B_T_VTOL_01_infantry_F", "" },
            { "B_Heli_Transport_03_unarmed_F", "" },
            { "C_Plane_Civil_01_racing_F", "" }
        };
    };

     class civ_ship {
        side = "civ";
        conditions = "";
        vehicles[] = {
			{ "C_Scooter_Transport_01_F", "" },
            { "B_Boat_Transport_01_F", "" },
            { "C_Boat_Civil_01_F", "" },
            { "I_C_Boat_Transport_02_F", "" }
        };
    };

    class reb_car {
        side = "civ";
        conditions = "";
        vehicles[] = {
            { "B_LSV_01_unarmed_F", "" },
            { "O_T_LSV_02_unarmed_F", "" },
            { "B_Heli_Light_01_F", ""}
        };
    };

    class mercenary_car {
        side = "civ";
        conditions = "";
        vehicles[] = {
            { "I_MRAP_03_F", "" },
            { "B_MRAP_01_F", "" },
            { "O_MRAP_02_F", "" },
            { "I_Heli_light_03_unarmed_F", "" }
        };
    };

    class alpha_car {
        side = "civ";
        conditions = "";
        vehicles[] = {
            { "B_Heli_Attack_01_dynamicLoadout_F", "" },
            { "O_Heli_Attack_02_dynamicLoadout_F", "" },
            { "B_Heli_Transport_01_F", "" },
            { "O_T_VTOL_02_vehicle_dynamicLoadout_F", "" }
        };
    };

    class med_shop {
        side = "med";
        conditions = "";
        vehicles[] = {
            { "C_SUV_01_F", "" },
            { "I_Truck_02_medical_F", "" },
            { "O_Truck_03_medical_F", "" },
            { "B_Truck_01_medical_F", "" },
            { "I_E_Van_02_transport_MP_F", "" }  // Van
        };
    };

    class med_air_hs {
        side = "med";
        conditions = "";
        vehicles[] = {
            { "B_Heli_Light_01_F", "" },
            { "O_Heli_Light_02_unarmed_F", "" }
        };
    };

    class cop_car {
        side = "cop";
        conditions = "call life_Coplevel > 0";
        vehicles[] = {
            {"B_Quadbike_01_F",""},
            { "C_Offroad_01_F", "" },
            { "C_SUV_01_F", "" },
            { "C_Hatchback_01_sport_F", "call life_Coplevel > 1" },
            { "B_LSV_01_unarmed_F","call life_Coplevel > 2"},   //prowler
            { "O_Truck_03_covered_F","call life_Coplevel > 5"},   // tempest abgedeckt
            { "I_MRAP_03_F","call life_Coplevel > 5"}, // strier
            { "B_MRAP_01_F", "call life_Coplevel > 3" } // hunter
        };
    };

    class cop_air {
        side = "cop";
        conditions = "call life_Coplevel > 0";
        vehicles[] = {
            { "B_Heli_Light_01_F", "call life_Coplevel > 2" },
            {"I_Heli_light_03_unarmed_F","call life_Coplevel > 4"},  // hellcat
            {"B_Heli_Attack_01_dynamicLoadout_F","call life_Coplevel > 4"},   // blackfoot
            { "B_Heli_Transport_01_F", "call life_Coplevel > 5" }     // ghost hawk
        };
    };

    class swat_car {
        side = "cop";
        conditions = "call life_swatlevel > 0";
        vehicles[] = {
            {"C_Hatchback_01_sport_F", ""},
            {"C_SUV_01_F",""},
            {"I_MRAP_03_F",""},   // strider
            {"B_MRAP_01_F", ""}   // hunter
        };
    };

    class swat_air {
        side = "cop";
        conditions = "call life_swatlevel > 0";
        vehicles[] = {
            { "B_Heli_Transport_01_F", "" },     // ghost hawk
            { "B_Heli_Light_01_F", ""}
        };
    };

    class cop_ship {
        side = "cop";
        conditions = "";
        vehicles[] = {
            { "B_Boat_Transport_01_F", "" },
            { "C_Boat_Civil_01_police_F", "" },
            { "C_Boat_Transport_02_F", "" }, //Apex DLC
            { "B_Boat_Armed_01_minigun_F", "call life_coplevel >= 3" },
            { "B_SDV_01_F", "" }
        };
    };
};

class LifeCfgVehicles {
    /*
    *    Vehicle Configs (Contains textures and other stuff)
    *
    *    "price" is the price before any multipliers set in Master_Config are applied.
    *
    *    Default Multiplier Values & Calculations:
    *       Civilian [Purchase, Sell]: [1.0, 0.5]
    *       Cop [Purchase, Sell]: [0.5, 0.5]
    *       Medic [Purchase, Sell]: [0.75, 0.5]
    *       ChopShop: Payout = price * 0.25
    *       GarageSell: Payout = price * [0.5, 0.5, 0.5, -1]
    *       Cop Impound: Payout = price * 0.1
    *       Pull Vehicle from Garage: Cost = price * [1, 0.5, 0.75, -1] * [0.5, 0.5, 0.5, -1]
    *           -- Pull Vehicle & GarageSell Array Explanation = [civ,cop,medic,east]
    *
    *       1: STRING (Condition)
    *    Textures config follows { Texture Name, side, {texture(s)path}, Condition}
    *    Texture(s)path follows this format:
    *    INDEX 0: Texture Layer 0
    *    INDEX 1: Texture Layer 1
    *    INDEX 2: Texture Layer 2
    *    etc etc etc
    *
    */

    class Default {
        vItemSpace = -1;
        conditions = "";
        price = -1;
        textures[] = {};
    };

    // Prowler  [a3\soft_f_exp\lsv_01\data\nato_lsv_adds_olive_co.paa"]
    class B_LSV_01_unarmed_F {
        vItemSpace = 150;
        conditions = "";
        price = 500000;
        price_cop = 45000;
        textures[] = {
            { "COP", "cop", {
                "textures\COP_Vehicles\COP_Prowler1.paa",
                "textures\COP_Vehicles\COP_Prowler2.paa",
                "textures\COP_Vehicles\COP_Prowler3.paa",
                "textures\COP_Vehicles\COP_Prowler4.paa"
            }, "" },
            { "Olive", "reb", {
                "a3\soft_f_exp\lsv_01\data\nato_lsv_01_olive_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_02_olive_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_03_olive_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_adds_olive_co.paa"
            }, "" },
            { "Sand", "reb", {
                "a3\soft_f_exp\lsv_01\data\nato_lsv_01_sand_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_02_sand_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_03_sand_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_adds_sand_co.paa"
            }, "" },
            { "Dazzle", "reb", {
                "a3\soft_f_exp\lsv_01\data\nato_lsv_01_dazzle_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_02_olive_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_03_olive_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_adds_olive_co.paa"
            }, "" },
            { "Merc", "merc", {
                "a3\soft_f_exp\lsv_01\data\nato_lsv_01_olive_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_02_olive_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_03_olive_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_adds_olive_co.paa"
            }, "" },
            { "Alpha", "alpha", {
                "a3\soft_f_exp\lsv_01\data\nato_lsv_01_olive_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_02_olive_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_03_olive_co.paa",
                "a3\soft_f_exp\lsv_01\data\nato_lsv_adds_olive_co.paa"
            }, "" }
        };
    };

    // Apex DLC
    class C_Boat_Transport_02_F {
        vItemSpace = 100;
        conditions = "license_civ_boat || {!(playerSide isEqualTo civilian)}";
        price = 22000;
        textures[] = {
            { "Civilian", "civ", {
                "\A3\Boat_F_Exp\Boat_Transport_02\Data\Boat_Transport_02_exterior_civilian_CO.paa"
            }, "" },
            { "Black", "cop", {
                "\A3\Boat_F_Exp\Boat_Transport_02\Data\Boat_Transport_02_exterior_CO.paa"
            }, "" }
        };
    };

    // Apex DLC
    class C_Offroad_02_unarmed_F {
        vItemSpace = 75;
        conditions = "license_civ_driver || {!(playerSide isEqualTo civilian)}";
        price = 40000;
        textures[] = {
            { "Black", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa"
            }, "" },
            { "Blue", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa"
            }, "" },
            { "Green", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_green_co.paa"
            }, "" },
            { "Orange", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_orange_co.paa"
            }, "" },
            { "Red", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_red_co.paa"
            }, "" },
            { "White", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_white_co.paa"
            }, "" }
        };
    };

    // Apex DLC
    class C_Plane_Civil_01_F {
        vItemSpace = 75;
        conditions = "license_civ_pilot || {!(playerSide isEqualTo civilian)}";
        price = 150000;
        textures[] = {
            { "Racing (Tan Interior)", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Racer_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Racer_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"
            }, "" },
            { "Racing", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Racer_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Racer_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"
            }, "" },
            { "Red Line (Tan Interior)", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"
            }, "" },
            { "Red Line", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"
            }, "" },
            { "Tribal (Tan Interior)", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"
            }, "" },
            { "Tribal", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"
            }, "" },
            { "Blue Wave (Tan Interior)", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Wave_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Wave_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"
            }, "" },
            { "Blue Wave", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Wave_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Wave_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"
            }, "" }
        };
    };

    // Apex DLC
    class C_Scooter_Transport_01_F {
        vItemSpace = 150;
        conditions = "license_civ_boat || {!(playerSide isEqualTo civilian)}";
        price = 250000;
        textures[] = {
            { "Black", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Black_CO.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Black_CO.paa"
            }, "" },
            { "Blue", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Blue_co.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Blue_co.paa"
            }, "" },
            { "Grey", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Grey_co.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Grey_co.paa"
            }, "" },
            { "Green", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Lime_co.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Lime_co.paa"
            }, "" },
            { "Red", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Red_CO.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_CO.paa"
            }, "" },
            { "White", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_CO.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_CO.paa"
            }, "" },
            { "Yellow", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Yellow_CO.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Yellow_CO.paa"
            }, "" }
        };
    };

    // Apex DLC
    class O_T_LSV_02_unarmed_F {
        vItemSpace = 75;
		conditions = "license_civ_rebel || license_civ_mercenary || license_civ_alpha || !(playerSide isEqualTo civilian)";
        price = 500000;
        textures[] = {
            { "Arid", "reb", {
                "\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_01_arid_CO.paa",
                "\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_02_arid_CO.paa",
                "\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_03_arid_CO.paa"
            }, "" },
            { "Black", "reb", {
                "\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_01_black_CO.paa",
                "\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_02_black_CO.paa",
                "\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_03_black_CO.paa"
            }, "" },
            { "Green Hex", "reb", {
                "\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_01_ghex_CO.paa",
                "\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa",
                "\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_03_ghex_CO.paa"
            }, "" },
            { "ANG", "reb", {
                "textures\GANG_Vehicles\ANG_Quilin_1.jpg",
                "textures\GANG_Vehicles\ANG_Quilin_2.jpg",
                "textures\GANG_Vehicles\ANG_Quilin_3.jpg"
            }, "((group player) getvariable[""gang_id"",-1]) isEqualTo 23" }

        };
    };

    class B_Heli_Attack_01_dynamicLoadout_F {
        vItemSpace = 200;
		conditions = "license_civ_alpha || !(playerSide isEqualTo civilian)";
		price = 20000000;
        price_cop = 450000;
        textures[] = {
            { "Black", "cop", {
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)"
            }, "" }
        };
    };

    class I_E_Van_02_transport_MP_F {
        vItemSpace = 200;
        conditions = "";
        price = 150000;
        price_cop = 70000;
        price_med = 70000;
        textures[] = {
            { "Medic", "med", {
                "textures\MEDIC_Vehicles\MEDIC_van.jpg"
            }, "" }
        };
    };

    class O_Heli_Attack_02_dynamicLoadout_F {
        vItemSpace = 200;
		conditions = "license_civ_alpha || !(playerSide isEqualTo civilian)";
		price = 27500000;
        textures[] = {};
    };

    class B_CTRG_Heli_Transport_01_sand_F {
        vItemSpace = 200;
		conditions = "license_civ_alpha || !(playerSide isEqualTo civilian)";
		price = 5500000;
        textures[] = {};
    };

    class O_T_VTOL_02_vehicle_dynamicLoadout_F {
        vItemSpace = 1000;
		conditions = "license_civ_alpha || !(playerSide isEqualTo civilian)";
		price = 45000000;
        textures[] = {};
    };


    class C_Plane_Civil_01_racing_F {
        vItemSpace = 100;
        conditions = "";
        textures[] = {};
        price = 350000;
    };

    class I_Heli_light_03_unarmed_F {
        vItemSpace = 150;
		conditions = "license_civ_rebel || license_civ_mercenary || license_civ_alpha || !(playerSide isEqualTo civilian)";
        textures[] = {
            { "COP", "cop", {
                "textures\COP_Vehicles\COP_Hellcat.paa"
            }, "" },
            { "MED", "med", {
                "textures\MEDIC_Vehicles\MEDIC_hellcat.jpg"
            }, "" }
        };
        price = 7500000;
        price_cop = 350000;
        price_med = 150000;
    };

    class I_MRAP_03_F {
        vItemSpace = 125;
		conditions = "license_civ_rebel || license_civ_mercenary || license_civ_alpha || !(playerSide isEqualTo civilian)";
        textures[] = {
            { "COP", "cop", {
                "textures\COP_Vehicles\COP_Strider.paa"
            }, "" },
            { "SEK", "swat", {
                "textures\COP_Vehicles\SEK_Strider.paa"
            }, "" }
        };
        price = 9500000;
        price_cop = 200000;
    };

    class B_T_LSV_01_unarmed_F {
        vItemSpace = 75;
		conditions = "license_civ_rebel || license_civ_mercenary || license_civ_alpha || !(playerSide isEqualTo civilian)";
        textures[] = {};
        price = 500000;
    };

    class I_C_Boat_Transport_02_F {
        vItemSpace = 1000;
        conditions = "license_civ_boat || {!(playerSide isEqualTo civilian)}";
        price = 3500000;
        textures[] = {};
    };

    class I_Heli_Transport_02_F {
        vItemSpace = 650;
        conditions = "license_civ_pilot || {license_med_mAir} || {(playerSide isEqualTo west)}";
        price = 5500000;
        textures[] = {};
    };

    class B_Heli_Transport_03_unarmed_F {
        vItemSpace = 1000;
        conditions = "license_civ_pilot || {!(playerSide isEqualTo civilian)}";
        price = 25000000;
        textures[] = {};
    };


    class B_T_VTOL_01_infantry_F {
        vItemSpace = 2000;
        conditions = "license_civ_pilot || {!(playerSide isEqualTo civilian)}";
        price = 55000000;
        textures[] = {};
    };

    class O_Heli_Transport_04_box_F {
        vItemSpace = 850;
        conditions = "license_civ_pilot || {!(playerSide isEqualTo civilian)}";
        price = 15000000;
        textures[] = {};
    };

    class I_LT_01_scout_F {
        vItemSpace = 125;
        conditions = "license_civ_pilot || {!(playerSide isEqualTo civilian)}";
        price = 350000;
        textures[] = {};
    };

    class O_Truck_02_covered_F {
        vItemSpace = 450;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 600000;
        textures[] = {};
    };

    class O_Truck_02_transport_F {
        vItemSpace = 350;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 350000;
        textures[] = {};
    };

    class C_Van_02_transport_F {
        vItemSpace = 200;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 300000;
        textures[] = {};
    };

    class I_Truck_02_medical_F {
        vItemSpace = 150;
        conditions = "";
        price = 25000;
        textures[] = {};
    };

    class O_Truck_03_medical_F {
        vItemSpace = 200;
        conditions = "";
        price = 45000;
        textures[] = {};
    };

    class B_Truck_01_medical_F {
        vItemSpace = 250;
        conditions = "";
        price = 60000;
        textures[] = {};
    };

    class C_Rubberboat {
        vItemSpace = 45;
        conditions = "license_civ_boat || {!(playerSide isEqualTo civilian)}";
        price = 5000;
        textures[] = { };
    };

    class B_Heli_Transport_01_F {
        vItemSpace = 200;
        conditions = "license_cop_cAir || {!(playerSide isEqualTo west)}";
        price = 25000000;
        price_cop = 400000;
        textures[] = {
            { "Black", "cop", {
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)"
            }, "" },
            { "SEK", "swat", {
                "textures\COP_Vehicles\SEK_GhosthawkFRONT.paa",
                "textures\COP_Vehicles\SEK_GhosthawkBACK.paa"
            }, "" }
        };
    };

    class B_MRAP_01_hmg_F {
        vItemSpace = 100;
        conditions = "";
        price = 750000;
        textures[] = {
            { "Black", "cop", {
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)"
            }, "" }
        };
    };

    class B_Boat_Armed_01_minigun_F {
        vItemSpace = 175;
        conditions = "license_cop_cg || {!(playerSide isEqualTo west)}";
        price = 75000;
        textures[] = { };
    };

    class B_Boat_Transport_01_F {
        vItemSpace = 350;
        conditions = "license_civ_boat || {!(playerSide isEqualTo civilian)}";
        price = 500000;
        textures[] = { };
    };

    class O_Truck_03_transport_F {
        vItemSpace = 650;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 2500000;
        textures[] = { };
    };

    class O_Truck_03_device_F {
        vItemSpace = 900;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 30000000;
        textures[] = { };
    };

    class O_CargoNet_01_ammo_F {
        vItemSpace = 50000000;
        conditions = "";
        price = -1;
        textures[] = {};
    };

    class Land_CargoBox_V1_F {
        vItemSpace = 5000;
        conditions = "";
        price = -1;
        textures[] = {};
    };

    class Box_IND_Grenades_F {
        vItemSpace = 350;
        conditions = "";
        price = -1;
        textures[] = {};
    };

    class B_supplyCrate_F {
        vItemSpace = 700;
        conditions = "";
        price = -1;
        textures[] = {};
    };

    class Land_Cages_F {
        vItemSpace = 30;
        conditions = "";
        price = -1;
        textures[] = {};
    };

    class B_G_Offroad_01_F {
        vItemSpace = 65;
        conditions = "";
        price = 12500;
        textures[] = { };
    };

    class B_G_Offroad_01_armed_F {
        vItemSpace = 65;
        conditions = "license_civ_rebel || {!(playerSide isEqualTo civilian)}";
        price = 750000;
        textures[] = { };
    };

    class C_Boat_Civil_01_F {
        vItemSpace = 650;
        conditions = "license_civ_boat || {!(playerSide isEqualTo civilian)}";
        price = 1500000;
        textures[] = { };
    };

    class C_Boat_Civil_01_police_F {
        vItemSpace = 85;
        conditions = "license_cop_cg || {!(playerSide isEqualTo west)}";
        price = 20000;
        textures[] = { };
    };

    class B_Truck_01_box_F {
        vItemSpace = 450;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 350000;
        textures[] = { };
    };

    class B_Truck_01_transport_F {
        vItemSpace = 325;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 275000;
        textures[] = { };
    };

    class O_MRAP_02_F {
        vItemSpace = 125;
		conditions = "license_civ_rebel || license_civ_mercenary || license_civ_alpha || !(playerSide isEqualTo civilian)";
        price = 6500000;
        textures[] = { };
    };

    class C_Offroad_01_F {
        vItemSpace = 100;
        conditions = "license_civ_driver || {!(playerSide isEqualTo civilian)}";
        price = 25000;
        price_cop = 15000;
        textures[] = {
            { "Red", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa"
            }, "" },
            { "Yellow", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE01_CO.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE01_CO.paa"
            }, "" },
            { "White", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa"
            }, "" },
            { "Blue", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa"
            }, "" },
            { "Dark Red", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa"
            }, "" },
            { "Blue / White", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa"
            }, "" },
            { "Taxi", "civ", {
                "#(argb,8,8,3)color(0.6,0.3,0.01,1)"
            }, "" },
            { "Police", "cop", {
                "textures\COP_Vehicles\COP_Offroader.paa"
            }, "" }
        };
    };

    class C_Kart_01_Blu_F {
        vItemSpace = 20;
        conditions = "license_civ_driver || {!(playerSide isEqualTo civilian)}";
        price = 15000;
        textures[] = {};
    };
/*
To edit another information in this classes you can use this exemple.
class C_Kart_01_Fuel_F : C_Kart_01_Blu_F{
    vItemSpace = 40;
    price = ;
};

will modify the virtual space and the price of the vehicle, but other information such as license and textures will pick up the vehicle declare at : Vehicle {};
*/
    class C_Kart_01_Fuel_F : C_Kart_01_Blu_F{}; // Get all information of C_Kart_01_Blu_F
    class C_Kart_01_Red_F : C_Kart_01_Blu_F{};
    class C_Kart_01_Vrana_F : C_Kart_01_Blu_F{};

    class C_Hatchback_01_sport_F {
        vItemSpace = 70;
        conditions = "license_civ_driver || {!(playerSide isEqualTo civilian)}";
        price = 150000;
        price_cop = 45000;
        textures[] = {
            { "Red", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa"
            }, "" },
            { "Dark Blue", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa"
            }, "" },
            { "Orange", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa"
            }, "" },
            { "Black / White", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa"
            }, "" },
            { "Beige", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa"
            }, "" },
            { "Green", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport06_co.paa"
            }, "" },
            { "Police", "cop", {
                "textures\COP_Vehicles\COP_Limo.paa"
            }, "" },
            { "ZIVIL", "swat", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport06_co.paa"
            }, "" }
        };
    };

    class B_Quadbike_01_F {
        vItemSpace = 50;
        conditions = "license_civ_driver || {!(playerSide isEqualTo civilian)}";
        price = 10000;
        price_cop = 7500;
        textures[] = {
            { "Black", "cop", {
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)"
            }, "" },
            { "Digi Desert", "reb", {
                "\A3\Soft_F\Quadbike_01\Data\quadbike_01_opfor_co.paa"
            }, "" },
            { "Black", "civ", {
                "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_black_co.paa"
            }, "" },
            { "Blue", "civ", {
                "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_blue_co.paa"
            }, "" },
            { "Red", "civ", {
                "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_red_co.paa"
            }, "" },
            { "White", "civ", {
                "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_white_co.paa"
            }, "" },
            { "Digi Green", "civ", {
                "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_indp_co.paa"
            }, "" },
            { "Hunter Camo", "civ", {
                "\a3\soft_f_gamma\Quadbike_01\data\quadbike_01_indp_hunter_co.paa"
            }, "" }
        };
    };

    class I_Truck_02_covered_F {
        vItemSpace = 250;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 100000;
        textures[] = {
            { "Orange", "civ", {
                "\A3\Soft_F_Beta\Truck_02\data\truck_02_kab_co.paa",
                "\a3\soft_f_beta\Truck_02\data\truck_02_kuz_co.paa"
            }, "" },
            { "Black", "cop", {
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)"
            }, "" }
        };
    };

    class I_Truck_02_transport_F {
        vItemSpace = 200;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 75000;
        textures[] = {
            { "Orange", "civ", {
                "\A3\Soft_F_Beta\Truck_02\data\truck_02_kab_co.paa",
                "\a3\soft_f_beta\Truck_02\data\truck_02_kuz_co.paa"
            }, "" },
            { "Black", "cop", {
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)"
            }, "" }
        };
    };

    class B_T_Truck_01_fuel_F {
        vItemSpace = 1000;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 6500000;
        textures[] = {};
    };

    class B_T_Truck_01_box_F {
        vItemSpace = 1500;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 15000000;
        textures[] = {};
    };

    class B_T_Truck_01_covered_F {
        vItemSpace = 1000;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 6500000;
        textures[] = {};
    };

    class O_Truck_03_covered_F {
        vItemSpace = 800;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 4500000;
        price_cop = 250000;
        textures[] = {
            { "Black", "cop", {
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)"
            }, "" }
        };
    };

    class C_Hatchback_01_F {
        vItemSpace = 40;
        conditions = "license_civ_driver || {!(playerSide isEqualTo civilian)}";
        price = 9500;
        textures[] = {
            { "Beige", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa"
            }, "" },
            { "Green", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa"
            }, "" },
            { "Blue", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa"
            }, "" },
            { "Dark Blue", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa"
            }, "" },
            { "Yellow", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa"
            }, "" },
            { "White", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa"
            }, "" },
            { "Grey", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa"
            }, "" },
            { "Black", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa"
            }, "" }
        };
    };

    class C_SUV_01_F {
        vItemSpace = 75;
        conditions = "license_civ_driver || {!(playerSide isEqualTo civilian)}";
        price = 40000;
        price_cop = 22500;
        price_med = 15000;
        textures[] = {
            { "Dark Red", "civ", {
                "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa"
            }, "" },
            { "Silver", "civ", {
                "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa"
            }, "" },
            { "Orange", "civ", {
                "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa"
            }, "" },
            { "Police", "cop", {
                "textures\COP_Vehicles\COP_SUV.paa"
            }, "" },
            { "MED", "med", {
                "textures\MEDIC_Vehicles\MEDIC_suv.jpg"
            }, "" },
            { "ZIVIL", "swat", {
                "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa"
            }, "" }
        };
    };

    class C_Van_01_transport_F {
        vItemSpace = 100;
        conditions = "license_civ_driver || {!(playerSide isEqualTo civilian)}";
        price = 45000;
        textures[] = {
            { "White", "civ", {
                "\a3\soft_f_gamma\Van_01\Data\van_01_ext_co.paa"
            }, "" },
            { "Red", "civ", {
                "\a3\soft_f_gamma\Van_01\Data\van_01_ext_red_co.paa"
            }, "" }
        };
    };

    class C_Van_01_box_F {
        vItemSpace = 250;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 125000;
        textures[] = {
            { "White", "civ", {
                "\a3\soft_f_gamma\Van_01\Data\van_01_ext_co.paa"
            }, "" },
            { "Red", "civ", {
                "\a3\soft_f_gamma\Van_01\Data\van_01_ext_red_co.paa"
            }, "" }
        };
    };

    class B_MRAP_01_F {
        vItemSpace = 125;
		conditions = "license_civ_rebel || license_civ_mercenary || license_civ_alpha || !(playerSide isEqualTo civilian)";
        price = 8500000;
        price_cop = 450000;
        textures[] = {
            { "COP", "cop", {
                "textures\COP_Vehicles\COP_Hunterfront.paa",
                "textures\COP_Vehicles\COP_Hunterback.paa"
            }, "" },
            { "REB", "reb", {
                "a3\soft_f\mrap_01\data\mrap_01_base_co.paa",
                "a3\soft_f\mrap_01\data\mrap_01_adds_co.paa"
            }, "" },
            { "REB", "alpha", {
                "a3\soft_f\mrap_01\data\mrap_01_base_co.paa",
                "a3\soft_f\mrap_01\data\mrap_01_adds_co.paa"
            }, "" },
            { "REB", "merc", {
                "a3\soft_f\mrap_01\data\mrap_01_base_co.paa",
                "a3\soft_f\mrap_01\data\mrap_01_adds_co.paa"
            }, "" },
            { "SEK", "swat", {
                "textures\COP_Vehicles\SEK_hunter_front.paa",
                "textures\COP_Vehicles\SEK_hunter_back.paa"
            }, "" }
        };
    };

     class B_Heli_Light_01_stripped_F {
        vItemSpace = 90;
        conditions = "";
        price = 275000;
        textures[] = {
            { "Rebel Digital", "reb", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_digital_co.paa"
            }, "" }
        };
    };

    class B_Heli_Light_01_F {
        vItemSpace = 90;
        conditions = "license_civ_pilot || {license_cop_cAir} || {license_med_mAir}";
        price = 350000;
        price_cop = 150000;
        price_med = 100000;
        textures[] = {
            { "Police", "cop", {
                "textures\COP_Vehicles\COP_Hummingbird.paa"
            }, "" },
            { "Sheriff", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa"
            }, "" },
            { "Civ Blue", "civ", {
                "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa"
            }, "" },
            { "Civ Red", "civ", {
                "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa"
            }, "" },
            { "Blueline", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueline_co.paa"
            }, "" },
            { "Elliptical", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa"
            }, "" },
            { "Furious", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa"
            }, "" },
            { "Jeans Blue", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa"
            }, "" },
            { "Speedy Redline", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa"
            }, "" },
            { "Sunset", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa"
            }, "" },
            { "Vrana", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa"
            }, "" },
            { "Waves Blue", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa"
            }, "" },
            { "Rebel Digital", "reb", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_digital_co.paa"
            }, "" },
            { "Digi Green", "reb", {
                "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_indp_co.paa"
            }, "" },
            { "EMS", "med", {
                "textures\MEDIC_Vehicles\MEDIC_m900.jpg"
            }, "" },
            { "SEK", "swat", {
                "textures\COP_Vehicles\SEK_Humming.paa"
            }, "" },
            { "ZIVIL", "swat", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueline_co.paa"
            }, "" }
        };
    };

    class C_Heli_Light_01_civil_F : B_Heli_Light_01_F {
        vItemSpace = 125;
        conditions = "license_civ_pilot || {!(playerSide isEqualTo civilian)}";
        price = 350000;
        price_med = 100000;
        textures[] = {
            { "EMS", "med", {
                "textures\MEDIC_Vehicles\MEDIC_m900.jpg"
            }, "" },
            { "COP", "cop", {
                "textures\COP_Vehicles\COP_Hummingbird.paa"
            }, "" }
        };
    };

    class O_Heli_Light_02_unarmed_F {
        vItemSpace = 450;
        conditions = "license_civ_pilot || {license_med_mAir} || {(playerSide isEqualTo west)}";
        price = 2500000;
        price_med = 125000;
        textures[] = {
            { "COP", "cop", {
                "textures\COP_Vehicles\COP_Orca.paa"
            }, "" },
            { "White / Blue", "civ", {
                "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_civilian_co.paa"
            }, "" },
            { "Digi Green", "civ", {
                "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_indp_co.paa"
            }, "" },
            { "Desert Digi", "reb", {
                "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_opfor_co.paa"
            }, "" },
            { "EMS", "med", {
                "textures\MEDIC_Vehicles\MEDIC_orca.jpg"
            }, "" }
        };
    };

    class B_SDV_01_F {
        vItemSpace = 50;
        conditions = "license_civ_boat || {license_cop_cg} || {(playerSide isEqualTo independent)}";
        price = 150000;
        textures[] = {};
    };

    class C_Van_01_fuel_F {
        vItemSpace = 275;
        vFuelSpace = 100000;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 120000;
        textures[] = {
            { "White", "civ", {
                "\A3\soft_f_gamma\Van_01\data\van_01_ext_co.paa",
                "\A3\soft_f_gamma\Van_01\data\van_01_tank_co.paa"
            }, "" },
            { "Red", "civ", {
                "\A3\soft_f_gamma\Van_01\data\van_01_ext_red_co.paa",
                "\A3\soft_f_gamma\Van_01\data\van_01_tank_red_co.paa"
            }, "" }
        };
    };

    class I_Truck_02_fuel_F {
        vItemSpace = 40;
        vFuelSpace = 42000;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 200000;
        textures[] = {
            { "White", "civ", {
                "\A3\Soft_F_Beta\Truck_02\data\truck_02_kab_co.paa",
                "\A3\Soft_F_Beta\Truck_02\data\truck_02_fuel_co.paa"
            }, "" }
        };
    };

    class B_Truck_01_fuel_F {
        vItemSpace = 50;
        vFuelSpace = 50000;
        conditions = "license_civ_trucking || {!(playerSide isEqualTo civilian)}";
        price = 250000;
        textures[] = {};
    };
};
