/*
*    FORMAT:
*        STRING (Conditions) - Must return boolean :
*            String can contain any amount of conditions, aslong as the entire
*            string returns a boolean. This allows you to check any levels, licenses etc,
*            in any combination. For example:
*                "call life_coplevel && license_civ_someLicense"
*            This will also let you call any other function.
*
*
*    ARRAY FORMAT:
*        0: STRING (Classname): Item Classname
*        1: STRING (Nickname): Nickname that will appear purely in the shop dialog
*        2: SCALAR (Buy price)
*        3: SCALAR (Sell price): To disable selling, this should be -1
*        4: STRING (Conditions): Same as above conditions string
*
*    Weapon classnames can be found here: https://community.bistudio.com/wiki/Arma_3_CfgWeapons_Weapons
*    Item classnames can be found here: https://community.bistudio.com/wiki/Arma_3_CfgWeapons_Items
*
*/
class WeaponShops {
    //Armory Shops
    class gun {
        name = "Billy Joe's Firearms";
        side = "civ";
        conditions = "license_civ_gun";
        items[] = {
            {"hgun_Pistol_heavy_01_F","", 50000,25000,""}, // 4-five
            {"hgun_Pistol_heavy_02_F","",60000,30000,""}, // Zubr
            {"hgun_PDW2000_F","",100000,50000,""},        // pdw
            {"SMG_05_F","",100000,50000,""},              // protector
            {"arifle_SDAR_F","",150000,75000,""}          //sdar
        };
        mags[] = {
            {"11Rnd_45ACP_Mag","",100,50,""}, // 4-five mag
            {"6Rnd_45ACP_Cylinder","",200,100,""}, // zubr mag
            {"30Rnd_9x21_Mag","",500,250,""},  //pdw mag
            {"30Rnd_9x21_Mag_SMG_02","",500,250,""}, // protector mag
            {"20Rnd_556x45_UW_mag","",25000,12500,""}   // sdar mag
        };
        accs[] = {
            { "acc_flashlight_pistol", "", 1000, 500, "" },//Pistol Flashlight
            { "optic_ACO_grn_smg", "", 2500, 1250, "" }
        };
    };

    class rebel {
        name = "Mohammed's Jihadi Shop";
        side = "civ";
        conditions = "license_civ_rebel";
        items[] = {
            { "Binocular", "", 2500, 75, "" },
            { "Rangefinder", "", 5000, 75, "" },
            { "ItemGPS", "", 2500, 50, "" },
            { "FirstAidKit", "", 2500, 75, "" },
            { "NVGoggles", "", 5000, 1000, "" },
            {"arifle_AKS_F","",150000,75000,""},  // aks 74 u
            {"arifle_AKM_F","",300000,150000,""},   // AKM
            {"arifle_Mk20_plain_F","",200000,100000,""}, // MK20
            {"arifle_Mk20_F","",200000,100000,""}, // MK20 Tarnfleck
            {"arifle_TRG21_F","",200000,100000,""}, // TRG21
            {"arifle_SPAR_01_blk_F","",200000,100000,""}, // Spar 16 black
            {"arifle_SPAR_01_khk_F","",200000,100000,""}, // Spar 16 khaki
            {"arifle_SPAR_01_snd_F","",200000,100000,""}, // Spar 16 sand
            {"arifle_SPAR_02_blk_F","",400000,200000,""}, // SPAR 16S BLACK
            {"arifle_SPAR_02_khk_F","",400000,200000,""}, // SPAR 16S khaki
            {"arifle_SPAR_02_snd_F","",400000,200000,""}, // SPAR 16S sand
            {"arifle_Katiba_F","",350000,175000,""},      // katiba
            {"arifle_CTARS_blk_F","",400000,200000,""},   // CAR 95 1 black
            {"arifle_CTARS_ghex_F","",400000,200000,""},   // CAR 95 1 ghex
            {"arifle_CTARS_hex_F","",400000,200000,""},   // CAR 95 1 hex
            {"arifle_MXC_Black_F","",300000,150000,""},    // MXC black
            {"arifle_MXC_F","",300000,150000,""},          // MXC sand
            {"arifle_MXC_khk_F","",300000,150000,""},    // MXC khaki
            {"arifle_MX_Black_F","",350000,175000,""},   // MX black
            {"arifle_MX_F","",350000,175000,""},   // MX sand
            {"arifle_MX_khk_F","",350000,175000,""},   // MX black
            {"arifle_MXM_Black_F","",350000,175000,""},  // MXM black
            {"arifle_MXM_F","",350000,175000,""},  // MXM sand
            {"arifle_MXM_khk_F","",350000,175000,""},  // MXM khaki
            {"arifle_MX_SW_Black_F","",450000,225000,""},  // MXSW black
            {"arifle_MX_SW_F","",450000,225000,""},  // MXSW sand
            {"arifle_MX_SW_khk_F","",450000,225000,""}  // MXSW khaki
        };
        mags[] = {
            {"30Rnd_545x39_Mag_F","",15000,7500,""}, //aks 74 u mag
            {"30Rnd_762x39_Mag_F","",15000,7500,""},  // akm 30rnd mag
            {"75Rnd_762x39_Mag_F","",35000,17500,""}, // akm 75 rnd mag
            {"30Rnd_556x45_Stanag","",15000,7500,""}, // MK20 Mag / TRG21 MAG / spar 16 mag
            {"150Rnd_556x45_Drum_Mag_F","",35000,17500,""}, // SPAR 16 Trommelmag // spar16s
            {"30Rnd_65x39_caseless_green","",15000,7500,""}, // katiba mag
            {"100Rnd_580x42_Mag_F","",35000,17500,""},        // CAR 95 1 100mag
            {"30Rnd_580x42_Mag_F","",15000,7500,""},          // CAR 95 1 30mag
            {"30Rnd_65x39_caseless_black_mag","",15000,7500,""},  // MXC 30rnd mag
            {"100Rnd_65x39_caseless_black_mag","",35000,17500,""}, // MXC 100rnd MAG
            {"150Rnd_556x45_Drum_Sand_Mag_F","",35000,17500,""},     // spar 16s trommel
            {"150Rnd_556x45_Drum_Mag_F","",35000,17500,""},     // spar 16s trommel
            {"30Rnd_556x45_Stanag_Sand_red","",15000,7500,""},     // spar 16s
            {"30Rnd_65x39_caseless_mag","",15000,7500,""},     // mx SW
            {"100Rnd_65x39_caseless_black_mag","",35000,17500,""},     // mx SW trommel
            {"30Rnd_580x42_Mag_F","",15000,7500,""},                   // car mag
            {"100Rnd_580x42_Mag_F","",35000,17500,""}                   // car mag 100 rnd
        };
        accs[] = {
            { "muzzle_snds_H", "", 50000, 25000, "" },
            {"muzzle_snds_M","",50000,25000,""},
            {"muzzle_snds_58_blk_F","",50000,25000,""},
            { "optic_Hamr", "", 50000, 25000, "" },
            { "optic_ERCO_blk_F", "", 50000, 25000, "" },
            { "optic_DMS", "", 50000, 25000, "" },
            { "optic_AMS", "", 50000, 25000, "" },
            { "optic_Arco_blk_F", "", 50000, 25000, "" },
            { "optic_SOS", "", 50000, 25000, "" }
        };
    };

    class mercenary {
        name = "Mercenary Store";
        side = "civ";
        conditions = "";
        items[] = {
            { "Binocular", "", 2500, 75, "" },
            { "Rangefinder", "", 5000, 75, "" },
            { "ItemGPS", "", 2500, 50, "" },
            { "FirstAidKit", "", 2500, 75, "" },
            { "NVGoggles", "", 5000, 1000, "" },
            {"arifle_ARX_blk_F","",400000,200000,""},   // typ 115 black
            {"arifle_ARX_ghex_F","",400000,200000,""},   // typ 115 ghex
            {"arifle_ARX_hex_F","",400000,200000,""},   // typ 115 hex
            {"arifle_AK12_F","",450000,225000,""},    // ak12 black
            {"arifle_AK12_arid_F","",450000,225000,""},    // ak12 arid
            {"arifle_AK12_lush_F","",450000,225000,""},    // ak12 lush
            {"srifle_DMR_03_F","",500000,250000,""},       // MK1 EMR black
            {"srifle_DMR_03_multicam_F","",500000,250000,""},       // MK1 EMR multicam
            {"srifle_DMR_03_khaki_F","",500000,250000,""},       // MK1 EMR khaki
            {"srifle_DMR_03_tan_F","",500000,250000,""},       // MK1 EMR sand
            {"srifle_DMR_03_woodland_F","",500000,250000,""},       // MK1 EMR woodland
            {"srifle_DMR_06_olive_F","",450000,225000,""},           // mk14
            {"srifle_DMR_06_hunter_F","",450000,225000,""},           // mk14 hunter
            {"srifle_DMR_06_camo_F","",450000,225000,""},           // mk14 camo
            {"srifle_EBR_F","",500000,250000,""},                   // MK18 abr
            {"arifle_SPAR_03_blk_F","",450000,225000,""},             // spar 17 black
            {"arifle_SPAR_03_khk_F","",450000,225000,""},             // spar 17 khaki
            {"arifle_SPAR_03_snd_F","",450000,225000,""},             // spar 17 sand
            {"arifle_RPK12_F","",450000,225000,""},                      // rpk black
            {"arifle_RPK12_arid_F","",450000,225000,""},                      // rpk sand
            {"arifle_RPK12_lush_F","",450000,225000,""},                       // rpk green
            {"srifle_DMR_01_F","",450000,225000,""}                   // rahim
        };
        mags[] = {
            {"30Rnd_65x39_caseless_green","",15000,7500,""},  // typ115 normal mag
            {"10Rnd_50BW_Mag_F","",40000,20000,""},           // typ115 .50cal
            {"30Rnd_762x39_AK12_Mag_F","",15000,7500,""},     // ak12 mag
            {"75Rnd_762x39_Mag_F","",35000,17500,""},     // ak12 75rnd mag
            {"20Rnd_762x51_Mag","",15000,7500,""},         // mk1 emr/Mk14 /spar 17 mag
            {"10Rnd_Mk14_762x51_Mag","",15000,7500,""},         // Mk14 mag
            {"75rnd_762x39_AK12_Mag_F","",35000,17500,""},     // rpk mag 75rnd
            {"10Rnd_762x54_Mag","",15000,7500,""}               //rahim mag
        };
        accs[] = {
            { "muzzle_snds_H", "", 50000, 25000, "" },
            {"muzzle_snds_M","",50000,25000,""},
            {"muzzle_snds_58_blk_F","",50000,25000,""},
            {"muzzle_snds_B","",50000,25000,""},
            { "optic_Hamr", "", 50000, 25000, "" },
            { "optic_ERCO_blk_F", "", 50000, 25000, "" },
            { "optic_DMS", "", 50000, 25000, "" },
            { "optic_AMS", "", 50000, 25000, "" },
            { "optic_Arco_blk_F", "", 50000, 25000, "" },
            { "optic_SOS", "", 50000, 25000, "" }
        };
    };

    class alpha {
        name = "Alpha Store";
        side = "civ";
        conditions = "";
        items[] = {
            { "Binocular", "", 2500, 75, "" },
            { "Rangefinder", "", 5000, 75, "" },
            { "ItemGPS", "", 2500, 50, "" },
            { "FirstAidKit", "", 2500, 75, "" },
            { "NVGoggles", "", 5000, 1000, "" },
            {"srifle_DMR_04_F","",1250000,625000,""},   // asp black
            {"srifle_DMR_04_Tan_F","",1250000,625000,""},   // asp tan
            {"srifle_DMR_02_F","",1500000,750000,""},   //mar 10 black
            {"srifle_DMR_02_camo_F","",1500000,750000,""},   //mar 10 flecktarn
            {"srifle_DMR_02_sniper_F","",1500000,750000,""},   //mar 10 sand
            {"srifle_DMR_05_blk_F","",1500000,750000,""},     // cyrus black
            {"srifle_DMR_05_tan_f","",1500000,750000,""},     // cyrus brown
            {"srifle_DMR_05_hex_F","",1500000,750000,""},     // cyrus hex
            {"LMG_Zafir_F","",3000000,1500000,""},  // zafir
            {"srifle_LRR_F","",2500000,1250000,""}, // LRR black
            {"srifle_LRR_camo_F","",2500000,1250000,""}, // LRR camo
            {"srifle_LRR_tna_F","",2500000,1250000,""}, // LRR tan
            {"srifle_GM6_F","",3500000,1750000,""}, // lynx black
            {"srifle_GM6_camo_F","",3500000,1750000,""}, // lynx camo
            {"srifle_GM6_ghex_F","",3500000,1750000,""}, // lynx tan
            {"LMG_03_F","",1000000,500000,""}, // lim 85
            {"LMG_Mk200_F","",1500000,750000,""}, //mk200 tan
            {"LMG_Mk200_black_F","",1500000,750000,""} //mk200 black
        };
        mags[] = {
            {"10Rnd_127x54_Mag","",15000,7500,""},  // asp mag
            {"10Rnd_338_Mag","",15000,7500,""}, //mar10 mag
            {"10Rnd_93x64_DMR_05_Mag","",15000,7500,""}, // cyrus mag
            {"150Rnd_762x54_Box","",75000,32500,""},  // zafir mag
            {"7Rnd_408_Mag","",15000,7500,""}, // LRR mag
            {"5Rnd_127x108_Mag","",15000,7500,""}, // lynx mag
            {"200Rnd_556x45_Box_F","",75000,32500,""}, // lim 85 mag
            {"200Rnd_65x39_cased_Box","",75000,32500,""}  //mk200 mag
        };
        accs[] = {
            { "muzzle_snds_H", "", 150000, 25000, "" },
            {"muzzle_snds_M","",150000,25000,""},
            {"muzzle_snds_58_blk_F","",150000,25000,""},
            {"muzzle_snds_B","",150000,25000,""},
            {"muzzle_snds_338_black","",150000,25000,""},
            {"muzzle_snds_93mmg","",150000,25000,""},
            { "optic_Hamr", "", 50000, 25000, "" },
            { "optic_ERCO_blk_F", "", 50000, 25000, "" },
            { "optic_DMS", "", 50000, 25000, "" },
            { "optic_AMS", "", 50000, 25000, "" },
            { "optic_Arco_blk_F", "", 50000, 25000, "" },
            { "optic_SOS", "", 50000, 25000, "" }
        };
    };

    class gang {
        name = "Hideout Armament";
        side = "civ";
        conditions = "";
        items[] = {
            {"hgun_Pistol_heavy_01_F","", 50000,25000,""}, // 4-five
            {"hgun_Pistol_heavy_02_F","",60000,30000,""}, // Zubr
            {"hgun_PDW2000_F","",100000,50000,""},        // pdw
            {"SMG_05_F","",100000,50000,""},              // protector
            {"arifle_SDAR_F","",150000,75000,""}          //sdar
        };
        mags[] = {
            {"11Rnd_45ACP_Mag","",100,50,""}, // 4-five mag
            {"6Rnd_45ACP_Cylinder","",200,100,""}, // zubr mag
            {"30Rnd_9x21_Mag","",500,250,""},  //pdw mag
            {"30Rnd_9x21_Mag_SMG_02","",500,250,""}, // protector mag
            {"20Rnd_556x45_UW_mag","",25000,12500,""}   // sdar mag
        };
        accs[] = {
            { "acc_flashlight_pistol", "", 1000, 500, "" },//Pistol Flashlight
            { "optic_ACO_grn_smg", "", 2500, 1250, "" }
        };
    };

    //Basic Shops
    class genstore {
        name = "Altis General Store";
        side = "civ";
        conditions = "";
        items[] = {
            { "Binocular", "", 150, 75, "" },
            { "ItemGPS", "", 5000, 2500, "" },
            { "ItemMap", "", 5000, 2500, "" },
            { "ItemCompass", "", 5000, 2500, "" },
            { "ItemWatch", "", 50, 25, "" },
            { "FirstAidKit", "", 10000, 5000, "" },
            { "NVGoggles", "", 10000, 5000, "" },
            { "Chemlight_red", "", 300, 150, "" },
            { "Chemlight_yellow", "", 300, 150, "" },
            { "Chemlight_green", "", 300, 150, "" },
            { "Chemlight_blue", "", 300, 150, "" }
        };
        mags[] = {};
        accs[] = {};
    };

    class f_station_store {
        name = "Altis Fuel Station Store";
        side = "";
        conditions = "";
        items[] = {
            { "Binocular", "", 150, 75, "" },
            { "ItemGPS", "", 5000, 2500, "" },
            { "ItemMap", "", 5000, 2500, "" },
            { "ItemCompass", "", 5000, 2500, "" },
            { "ItemWatch", "", 50, 25, "" },
            { "FirstAidKit", "", 10000, 5000, "" },
            { "NVGoggles", "", 10000, 5000, "" },
            { "Chemlight_red", "", 300, 150, "" },
            { "Chemlight_yellow", "", 300, 150, "" },
            { "Chemlight_green", "", 300, 150, "" },
            { "Chemlight_blue", "", 300, 150, "" }
        };
        mags[] = {};
        accs[] = {};
    };

    //Cop Shops
    class cop_basic {
        name = "Altis Cop Shop";
        side = "cop";
        conditions = "call life_coplevel > 0";
        items[] = {
            { "Binocular", "", 150, 75, "" },
            { "Rangefinder", "", 5000, 75, "call life_coplevel > 1" },
            { "ItemGPS", "", 100, 50, "" },
            { "FirstAidKit", "", 150, 75, "" },
            { "NVGoggles", "", 2000, 1000, "" },
            { "HandGrenade_Stone", $STR_W_items_Flashbang, 1700, 850, "" },
            { "hgun_P07_snds_F", $STR_W_items_StunPistol, 5000, 1000, "" },
            { "arifle_SDAR_F", "", 10000, 5000, "" },
            { "arifle_SPAR_01_blk_F", "", 40000, 20000, "" },    // spar 16
            { "arifle_SPAR_02_blk_F", "", 50000, 25000, "call life_coplevel > 1" },    // spar 16S
            { "arifle_MXC_Black_F", "", 30000, 15000, "call life_coplevel > 1" },    // MXC
            { "arifle_MX_Black_F", "", 50000, 25000, "call life_coplevel > 1" },    // MX
            { "arifle_MSBS65_black_F", "", 45000, 22500, "call life_coplevel > 1" },    // promet
            { "arifle_MXM_Black_F", "", 65000, 32500, "call life_coplevel > 2" },    // MXM
            { "arifle_MX_SW_Black_F", "", 65000, 32500, "call life_coplevel > 2" },    // MXSW
            { "arifle_ARX_blk_F", "", 70000, 35000, "" },    // type115
            { "arifle_SPAR_03_blk_F", "", 100000, 50000, "call life_coplevel > 3" },    // spar 17
            { "srifle_EBR_F", "", 150000, 75000, "call life_coplevel > 3" },    // mk18
            { "srifle_DMR_03_F", "", 150000, 75000, "call life_coplevel > 3" },    // mk18
            { "LMG_03_F", "", 250000, 125000, "call life_coplevel > 4" },    // lim85
            { "LMG_Mk200_black_F", "", 350000, 175000, "call life_coplevel > 4" },    // mk200
            { "LMG_Zafir_F", "", 450000, 225000, "call life_coplevel > 5" }    // zafir
        };
        mags[] = {
            { "16Rnd_9x21_Mag", "", 125, 60, "" },
            { "20Rnd_556x45_UW_mag", "", 125, 60, "" },
            { "30Rnd_556x45_Stanag", "", 125, 60, "" },    // spar 16 mag
            { "150Rnd_556x45_Drum_Mag_F", "", 250, 60, "" },     //spar 16s mag
            { "30Rnd_65x39_caseless_black_mag", "", 125, 60, "" },    // MXC mag
            { "30Rnd_65x39_caseless_msbs_mag", "", 125, 60, "" },    // promet mag
            { "100Rnd_65x39_caseless_black_mag", "", 250, 125, "" },    // MXSW mag
            { "30Rnd_65x39_caseless_green", "", 125, 60, "" },    // type115 mag
            { "20Rnd_762x51_Mag", "", 125, 60, "" },    // spar17/mk18 mag
            { "200Rnd_556x45_Box_F", "", 250, 120, "" },    // lim85 mag
            { "200Rnd_65x39_cased_Box", "", 250, 120, "" },    // mk200 mag
            { "150Rnd_762x54_Box", "", 250, 120, "" }    // zafir mag
        };
        accs[] = {
            { "optic_AMS", "", 15000, 7500, "" },
            { "optic_DMS", "", 15000, 7500, "" },
            { "optic_Arco_blk_F", "", 15000, 7500, "" },
            { "optic_ERCO_blk_F", "", 15000, 7500, "" },
            { "optic_KHS_blk", "", 15000, 7500, "" },
            { "optic_LRPS", "", 15000, 7500, "" },
            { "optic_Hamr", "", 15000, 7500, "" },
            { "optic_SOS", "", 15000, 7500, "" },
            { "optic_MRCO", "", 15000, 7500, "" },
            { "acc_flashlight", "", 10000, 5000, "" },
            { "acc_pointer_IR", "", 10000, 5000, "" },
            { "muzzle_snds_H", "", 25000, 12500, "" },
            { "muzzle_snds_M", "", 25000, 12500, "" },
            { "muzzle_snds_B", "", 25000, 12500, "" },
            { "bipod_01_F_blk", "", 10000, 5000, "" }
        };
    };

    //Swat Shops
    class cop_swat {
        name = "Altis SEK Shop";
        side = "cop";
        conditions = "call life_swatlevel > 0";
        items[] = {
            { "Binocular", "", 150, 75, "" },
            { "ItemGPS", "", 100, 50, "" },
            { "FirstAidKit", "", 150, 75, "" },
            { "NVGoggles", "", 2000, 1000, "" },
            { "HandGrenade_Stone", $STR_W_items_Flashbang, 1700, 850, "" },
            { "hgun_P07_snds_F", $STR_W_items_StunPistol, 5000, 1000, "" },
            { "arifle_SDAR_F", "", 10000, 5000, "" },
            { "arifle_SPAR_01_blk_F", "", 40000, 20000, "" },    // spar 16
            { "arifle_SPAR_02_blk_F", "", 50000, 25000, "" },    // spar 16S
            { "arifle_MXC_Black_F", "", 30000, 15000, "" },    // MXC
            { "arifle_MX_Black_F", "", 50000, 25000, "" },    // MX
            { "arifle_MSBS65_black_F", "", 45000, 22500, "" },    // promet
            { "arifle_MXM_Black_F", "", 65000, 32500, "" },    // MXM
            { "arifle_MX_SW_Black_F", "", 65000, 32500, "" },    // MXSW
            { "arifle_ARX_blk_F", "", 70000, 35000, "" },    // type115
            { "arifle_SPAR_03_blk_F", "", 100000, 50000, "" },    // spar 17
            { "srifle_EBR_F", "", 150000, 75000, "" },    // mk18
            { "srifle_DMR_03_F", "", 150000, 75000, "" },    // mk18
            { "LMG_03_F", "", 250000, 125000, "" },    // lim85
            { "LMG_Mk200_black_F", "", 350000, 175000, "" },    // mk200
            { "LMG_Zafir_F", "", 450000, 225000, "" },    // zafir
            { "srifle_DMR_04_F", "", 300000, 150000, "" },    // asp
            { "srifle_DMR_02_F", "", 350000, 175000, "" },    // mar10
            { "srifle_DMR_05_blk_F", "", 400000, 200000, "" },    // cyrus
            { "srifle_LRR_F", "", 400000, 200000, "" },    // m320
            { "srifle_GM6_F", "", 450000, 225000, "" }   // m320
        };
        mags[] = {
            { "16Rnd_9x21_Mag", "", 125, 60, "" },
            { "20Rnd_556x45_UW_mag", "", 125, 60, "" },
            { "30Rnd_556x45_Stanag", "", 125, 60, "" },    // spar 16 mag
            { "150Rnd_556x45_Drum_Mag_F", "", 250, 60, "" },     //spar 16s mag
            { "30Rnd_65x39_caseless_black_mag", "", 125, 60, "" },    // MXC mag
            { "30Rnd_65x39_caseless_msbs_mag", "", 125, 60, "" },    // promet mag
            { "100Rnd_65x39_caseless_black_mag", "", 250, 125, "" },    // MXSW mag
            { "30Rnd_65x39_caseless_green", "", 125, 60, "" },    // type115 mag
            { "20Rnd_762x51_Mag", "", 125, 60, "" },    // spar17/mk18 mag
            { "200Rnd_556x45_Box_F", "", 250, 120, "" },    // lim85 mag
            { "200Rnd_65x39_cased_Box", "", 250, 120, "" },    // mk200 mag
            { "150Rnd_762x54_Box", "", 250, 120, "" },    // zafir mag
            { "10Rnd_127x54_Mag", "", 125, 60, "" },    // sp mag
            { "10Rnd_338_Mag", "", 125, 60, "" },    // mar10 mag
            { "10Rnd_93x64_DMR_05_Mag", "", 125, 60, "" },    // cyrus mag
            { "7Rnd_408_Mag", "", 125, 60, "" },    // m320 mag
            { "5Rnd_127x108_Mag", "", 125, 60, "" }    // lynx mag
        };
        accs[] = {
            { "optic_AMS", "", 15000, 7500, "" },
            { "optic_DMS", "", 15000, 7500, "" },
            { "optic_Arco_blk_F", "", 15000, 7500, "" },
            { "optic_ERCO_blk_F", "", 15000, 7500, "" },
            { "optic_KHS_blk", "", 15000, 7500, "" },
            { "optic_LRPS", "", 15000, 7500, "" },
            { "optic_Hamr", "", 15000, 7500, "" },
            { "optic_SOS", "", 15000, 7500, "" },
            { "optic_MRCO", "", 15000, 7500, "" },
            { "acc_flashlight", "", 10000, 5000, "" },
            { "acc_pointer_IR", "", 10000, 5000, "" },
            { "muzzle_snds_H", "", 25000, 12500, "" },
            { "muzzle_snds_M", "", 25000, 12500, "" },
            { "muzzle_snds_B", "", 25000, 12500, "" },
            { "muzzle_snds_338_black", "", 25000, 12500, "" },
            { "muzzle_snds_93mmg", "", 25000, 12500, "" },
            { "bipod_01_F_blk", "", 10000, 5000, "" }
        };
    };

    //Medic Shops
    class med_basic {
        name = "store";
        side = "med";
        conditions = "";
        items[] = {
            { "ItemGPS", "", 100, 50, "" },
            { "Binocular", "", 150, 75, "" },
            { "FirstAidKit", "", 150, 75, "" },
            { "NVGoggles", "", 1200, 600, "" }
        };
        mags[] = {};
        accs[] = {};
    };
};
