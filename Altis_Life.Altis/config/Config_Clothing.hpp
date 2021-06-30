/*
*    ARRAY FORMAT:
*        0: STRING (Classname)
*        1: STRING (Display Name, leave as "" for default)
*        2: SCALAR (Price)
*        3: STRING (Conditions) - Must return boolean :
*            String can contain any amount of conditions, aslong as the entire
*            string returns a boolean. This allows you to check any levels, licenses etc,
*            in any combination. For example:
*                "call life_coplevel && license_civ_someLicense"
*            This will also let you call any other function.
*
*   Clothing classnames can be found here: https://community.bistudio.com/wiki/Arma_3_CfgWeapons_Equipment
*   Backpacks/remaining classnames can be found here (TIP: Search page for "pack"): https://community.bistudio.com/wiki/Arma_3_CfgVehicles_EMPTY
*
*/
class Clothing {
    class bruce {
        title = "STR_Shops_C_Bruce";
        conditions = "";
        side = "civ";
        uniforms[] = {
            { "NONE", $STR_C_Remove_uniforms, 0, "" },
            { "U_C_Poloshirt_stripped", "", 10000, "" },
            { "U_C_Poloshirt_redwhite", "", 10000, "" },
            { "U_C_Poloshirt_salmon", "", 10000, "" },
            { "U_C_Poloshirt_blue", "", 10000, "" },
            { "U_C_Poloshirt_burgundy", "", 10000, "" },
            { "U_C_Poloshirt_tricolour", "", 10000, "" },
            { "U_C_Poor_2", "", 10000, "" },
            { "U_IG_Guerilla2_2", "", 10000, "" },
            { "U_IG_Guerilla3_1", "", 10000, "" },
            { "U_OrestesBody", "", 10000, "" },
            { "U_IG_Guerilla2_3", "", 10000, "" },
            { "U_C_HunterBody_grn", "", 10000, "" },
            { "U_C_WorkerCoveralls", "", 10000, "" },
            { "U_NikosBody", "", 10000, "" },
            { "U_NikosAgedBody", $STR_C_Civ_Niko, 10000, "" },
            { "U_C_Man_casual_1_F", "", 10000, "" }, //Apex DLC
            { "U_C_Man_casual_2_F", "", 10000, "" }, //Apex DLC
            { "U_C_Man_casual_3_F", "", 10000, "" }, //Apex DLC
            { "U_C_Man_casual_4_F", "", 10000, "" }, //Apex DLC
            { "U_C_Man_casual_5_F", "", 10000, "" }, //Apex DLC
            { "U_C_Man_casual_6_F", "", 10000, "" }, //Apex DLC
            { "U_C_man_sport_1_F", "", 10000, "" }, //Apex DLC
            { "U_C_man_sport_2_F", "", 10000, "" }, //Apex DLC
            { "U_C_man_sport_3_F", "", 10000, "" },
            { "U_C_CBRN_Suit_01_Blue_F", "HAZARD SUIT", 50000, "" },
            { "U_C_Scientist", "HAZARD SUIT", 50000, "" },
            { "U_C_IDAP_Man_shorts_F", "", 10000, "" },
            { "U_C_FormalSuit_01_blue_F", "", 50000, "" },
            { "U_C_FormalSuit_01_gray_F", "", 50000, "" },
            { "U_C_FormalSuit_01_khaki_F", "", 50000, "" },
            { "U_C_FormalSuit_01_black_F", "", 50000, "" },
            { "U_C_FormalSuit_01_tshirt_gray_F", "", 50000, "" },
            { "U_C_FormalSuit_01_tshirt_black_F", "", 50000, "" },
            { "U_C_Journalist", "", 10000, "" },
            { "U_Marshal", "", 10000, "" },
            { "U_C_Uniform_Scientist_01_formal_F", "", 10000, "" },
            { "U_C_Uniform_Scientist_01_F", "", 10000, "" },
            { "U_C_Uniform_Scientist_02_F", "", 10000, "" },
            { "U_C_ArtTShirt_01_v1_F", "", 10000, "" },
            { "U_C_ArtTShirt_01_v6_F", "", 10000, "" }
        };
        headgear[] = {
            { "NONE", $STR_C_Remove_headgear, 0, "" },
            { "H_Bandanna_camo", "", 120, "" },
            { "H_Bandanna_surfer", "", 130, "" },
            { "H_Bandanna_khk", "", 145, "" },
            { "H_Cap_blu", "", 150, "" },
            { "H_Cap_grn", "", 150, "" },
            { "H_Cap_grn_BI", "", 150, "" },
            { "H_Cap_oli", "", 150, "" },
            { "H_Cap_red", "", 150, "" },
            { "H_Cap_tan", "", 150, "" },
            { "H_Helmet_Skate", "", 150, "" }, //Apex DLC
            { "H_Bandanna_gry", "", 150, "" },
            { "H_Bandanna_sgg", "", 160, "" },
            { "H_Bandanna_cbr", "", 165, "" },
            { "H_StrawHat", "", 225, "" },
            { "H_Hat_tan", "", 265, "" },
            { "H_Hat_brown", "", 276, "" },
            { "H_Hat_grey", "", 280, "" },
            { "H_BandMask_blk", $STR_C_Civ_BandMask, 300, "" },
            { "H_Hat_blue", "", 310, "" },
            { "H_Hat_checker", "", 340, "" },
            { "H_Booniehat_tan", "", 425, "" },
            { "H_Booniehat_grn", "", 425, "" },
            { "H_Hat_Tinfoil_F", "", 10000, "" },
            { "H_Booniehat_khk_hs", "", 10000, "" },
            { "H_Booniehat_taiga", "", 10000, "" },
            { "H_HeadSet_yellow_F", "", 10000, "" },
            { "H_Cap_press", "", 10000, "" },
            { "H_Cap_blu", "", 10000, "" },
            { "H_Cap_surfer", "", 10000, "" },
            { "H_Cap_usblack", "", 10000, "" },
            { "H_Cap_brn_SPECOPS", "", 10000, "" },
            { "H_Hat_Safari_olive_F", "", 10000, "" },
            { "H_Hat_Safari_sand_F", "", 10000, "" },
            { "H_PASGT_basic_blue_press_F", "", 10000, "" },
            { "H_Construction_earprot_yellow_F", "", 10000, "" },
            { "H_Construction_earprot_vrana_F", "", 10000, "" },
            { "H_Construction_earprot_orange_F", "", 10000, "" },
            { "H_Helmet_Skate", "", 10000, "" }
        };
        goggles[] = {
            { "NONE", $STR_C_Remove_goggles, 0, "" },
            { "G_Shades_Black", "", 20, "" },
            { "G_Shades_Blue", "", 20, "" },
            { "G_Shades_Green", "", 20, "" },
            { "G_Shades_Red", "", 20, "" },
            { "G_Sport_Blackred", "", 25, "" },
            { "G_Sport_BlackWhite", "", 25, "" },
            { "G_Sport_Blackyellow", "", 25, "" },
            { "G_Sport_Checkered", "", 25, "" },
            { "G_Sport_Greenblack", "", 25, "" },
            { "G_Sport_Red", "", 25, "" },
            { "G_Lowprofile", "", 30, "" },
            { "G_Squares", "", 50, "" },
            { "G_Aviator", "", 100, "" },
            { "G_Combat", "", 125, "" },
            { "G_Lady_Mirror", "", 150, "" },
            { "G_Lady_Dark", "", 150, "" },
            { "G_Lady_Blue", "", 150, "" },
            {"G_AirPurifyingRespirator_02_black_F","",10000,""},
            {"G_Respirator_white_F","",10000,""},
            {"G_RegulatorMask_F","",10000,""},
            {"G_Blindfold_01_white_F","",10000,""},,
            {"G_Blindfold_01_black_F","",10000,""},
            {"G_Goggles_VR","",10000,""},
            {"G_EyeProtectors_F","",10000,""}
        };
        vests[] = {
            { "NONE", $STR_C_Remove_vests, 0, "" },
            { "V_Safety_blue_F", "", 10000, "" },
            { "V_Safety_yellow_F", "", 10000, "" },
            { "V_Safety_orange_F", "", 10000, "" },
            { "V_Press_F", "", 25000, "" }
        };
        backpacks[] = {
            { "NONE", $STR_C_Remove_backpacks, 0, "" },
            { "B_OutdoorPack_blk", "", 20000, "" },
            { "B_AssaultPack_khk", "", 20000, "" },
            { "B_AssaultPack_dgtl", "", 20000, "" },
            { "B_AssaultPack_rgr", "", 20000, "" },
            { "B_AssaultPack_sgg", "", 20000, "" },
            { "B_AssaultPack_blk", "", 20000, "" },
            { "B_AssaultPack_cbr", "", 20000, "" },
            { "B_AssaultPack_mcamo", "", 20000, "" },
            { "B_AssaultPack_tna_f", "", 20000, "" }, //Apex DLC
            { "B_TacticalPack_oli", "", 20000, "" },
            { "B_Kitbag_mcamo", "", 20000, "" },
            { "B_Kitbag_sgg", "", 20000, "" },
            { "B_Kitbag_cbr", "", 20000, "" },
            { "B_FieldPack_blk", "", 20000, "" },
            { "B_FieldPack_ocamo", "", 20000, "" },
            { "B_FieldPack_oucamo", "", 20000, "" },
            { "B_FieldPack_ghex_f", "", 20000, "" }, //Apex DLC
            { "B_Bergen_sgg", "", 20000, "" },
            { "B_Bergen_mcamo", "", 20000, "" },
            { "B_Bergen_rgr", "", 20000, "" },
            { "B_Bergen_blk", "", 20000, "" },
            { "B_Carryall_ocamo", "", 25000, "" },
            { "B_Carryall_oucamo", "", 25000, "" },
            { "B_Carryall_mcamo", "", 25000, "" },
            { "B_Carryall_oli", "", 25000, "" },
            { "B_Carryall_khk", "", 25000, "" },
            { "B_Carryall_cbr", "", 25000, "" },
            { "B_Carryall_ghex_f", "", 50000, "" }, //Apex DLC
            { "B_Bergen_dgtl_f", "", 50000, "" },
            { "B_Bergen_tna_f", "", 50000, "" },
            { "B_Messenger_IDAP_F", "", 20000, "" },
            { "B_Messenger_Black_F", "", 20000, "" }
        };
    };

    class cop {
        title = "STR_Shops_C_Police";
        conditions = "";
        side = "cop";
        uniforms[] = {
            { "NONE", $STR_C_Remove_uniforms, 0, "" },
            { "U_BG_Guerrilla_6_1", "COP Uniform", 500, "call life_coplevel >= 1" },
            { "U_I_CombatUniform", "SEK Uniform", 350, "call life_swatlevel >= 1" },
            { "U_B_GEN_Commander_F", "SEK Uniform 2", 350, "call life_swatlevel >= 1" },
            { "U_I_ParadeUniform_01_AAF_decorated_F", "COP CHEF Uniform", 500, "call life_coplevel > 7" },
            { "U_I_GhillieSuit", "Zivil Ghillie", 500, "call life_swatlevel >= 1" },
            { "U_O_GhillieSuit", "Zivil Ghillie", 500, "call life_swatlevel >= 1" },
            { "U_O_T_FullGhillie_tna_F", "Zivil Ghillie", 500, "call life_swatlevel >= 1" },
            { "U_I_FullGhillie_lsh", "Zivil Ghillie", 500, "call life_swatlevel >= 1" },
            { "U_O_FullGhillie_ard", "Zivil Ghillie", 500, "call life_swatlevel >= 1" },
            { "U_BG_Guerilla1_1", "Zivil Kleidung", 500, "call life_swatlevel >= 1" },
            { "U_I_G_Story_Protagonist_F", "Zivil Kleidung", 500, "call life_swatlevel >= 1" },
            { "U_C_Poloshirt_stripped", "Zivil Kleidung", 500, "call life_swatlevel >= 1" },
            { "U_C_Poloshirt_blue", "Zivil Kleidung", 500, "call life_swatlevel >= 1" }
        };
        headgear[] = {
            { "NONE", $STR_C_Remove_headgear, 0, "" },
            { "H_Cap_police", "", 25, "" },
            { "H_Booniehat_mcamo", "", 120, "call life_coplevel >= 1" },
            { "H_HelmetB_plain_mcamo", "", 75, "call life_coplevel >= 1" },
            { "H_HelmetB_Enh_tna_F", "", 80, "call life_coplevel >= 1" }, //Apex DLC
            { "H_Beret_blk_POLICE", "", 50, "call life_coplevel >= 2" },
            { "H_MilCap_mcamo", "", 100, "call life_coplevel >= 2" },
            { "H_MilCap_gen_F", "", 1200, "call life_coplevel >= 2" }, //Apex DLC
            { "H_MilCap_tna_F", "", 1200, "call life_coplevel >= 2" }, //Apex DLC
            { "H_MilCap_oucamo", "", 1200, "call life_coplevel >= 2" },
            { "H_Cap_blk", "" , 500, "call life_coplevel >= 1" },
            {"H_Beret_Colonel", "" , 500, "call life_coplevel >= 7"},
            {"H_Beret_02", "" , 500, "call life_coplevel >= 5"},
            { "H_ParadeDressCap_01_AAF_F", "COP CHEF HUT", 500, "call life_coplevel > 7" },
            { "H_Cap_blk_CMMG", "", 500, "call life_swatlevel >= 1" },
            { "H_Cap_usblack", "", 500, "call life_swatlevel >= 1" },
            { "H_Shemag_olive", "", 500, "call life_swatlevel >= 1" },
            { "H_Booniehat_tna_F", "", 500, "call life_swatlevel >= 1" },
            { "H_Booniehat_tan", "", 500, "call life_swatlevel >= 1" }
        };
        goggles[] = {
            { "NONE", $STR_C_Remove_goggles, 0, "" },
            { "G_Squares", "", 10, "" },
            { "G_Shades_Blue", "", 20, "" },
            { "G_Sport_Blackred", "", 20, "" },
            { "G_Sport_Checkered", "", 20, "" },
            { "G_Sport_Blackyellow", "", 20, "" },
            { "G_Sport_BlackWhite", "", 20, "" },
            { "G_Shades_Black", "", 25, "" },
            { "G_Lowprofile", "", 30, "" },
            { "G_Combat", "", 55, "" },
            { "G_Aviator", "", 100, "" },
            { "G_Lady_Mirror", "", 150, "" },
            { "G_Lady_Dark", "", 150, "" },
            { "G_Lady_Blue", "", 150, "" },
            { "G_Balaclava_blk", "", 150, "call life_swatlevel >= 1" },
            { "G_Balaclava_oli", "", 150, "call life_swatlevel >= 1" },
            { "G_Balaclava_combat", "", 150, "call life_swatlevel >= 1" },
            { "G_Balaclava_lowprofile", "", 150, "call life_swatlevel >= 1" },
            { "G_Balaclava_TI_blk_F", "", 150, "call life_swatlevel >= 1" },
            { "G_Balaclava_TI_G_blk_F", "", 150, "call life_swatlevel >= 1" },
            { "G_Bandanna_beast", "", 150, "call life_swatlevel >= 1" },
            { "G_Bandanna_aviator", "", 150, "call life_swatlevel >= 1" },
            { "G_Balaclava_TI_G_tna_F", "", 150, "call life_swatlevel >= 1" }
        };
        vests[] = {
            { "NONE", $STR_C_Remove_vests, 0, "" },
            { "V_Rangemaster_belt", "", 800, "" },
            { "V_TacVest_blk_POLICE", "", 1000, "call life_coplevel >= 1" },
            { "V_PlateCarrier2_blk", "", 1500, "call life_coplevel >= 2" },
            { "V_PlateCarrier2_rgr", "", 1500, "call life_swatlevel > 0" }
        };
        backpacks[] = {
            { "NONE", $STR_C_Remove_backpacks, 0, "" },
            { "B_FieldPack_cbr", "", 500, "" },
            { "B_AssaultPack_cbr", "", 700, "" },
            { "B_Kitbag_cbr", "", 800, "" },
            { "B_Bergen_sgg", "", 2500, "" },
            { "B_Carryall_cbr", "", 3500, "" }
        };
    };

    class dive {
        title = "STR_Shops_C_Diving";
        conditions = "license_civ_dive";
        side = "civ";
        uniforms[] = {
            { "NONE", $STR_C_Remove_uniforms, 0, "" },
            { "U_B_Wetsuit", "", 2000, "" },
            { "U_O_Wetsuit", "", 2000, "" }
        };
        headgear[] = {
            { "NONE", $STR_C_Remove_headgear, 0, "" }
        };
        goggles[] = {
            { "NONE", $STR_C_Remove_goggles, 0, "" },
            { "G_Diving", "", 500, "" }
        };
        vests[] = {
            { "NONE", $STR_C_Remove_vests, 0, "" },
            { "V_RebreatherB", "", 5000, "" },
            { "V_RebreatherIR", "", 5000, "" }
        };
        backpacks[] = {
            { "NONE", $STR_C_Remove_backpacks, 0, "" }
        };
    };

    class gun_clothing {
        title = "STR_Shops_C_Gun";
        conditions = "license_civ_gun";
        side = "civ";
        uniforms[] = {
            { "NONE", $STR_C_Remove_uniforms, 0, "" }
        };
        headgear[] = {
            { "NONE", $STR_C_Remove_headgear, 0, "" }
        };
        goggles[] = {
            { "NONE", $STR_C_Remove_goggles, 0, "" }
        };
        vests[] = {
            { "NONE", $STR_C_Remove_vests, 0, "" },
            { "V_Rangemaster_belt", "", 4900, "" }
        };
        backpacks[] = {
            { "NONE", $STR_C_Remove_backpacks, 0, "" }
        };
    };

    class gang_clothing {
        title = "STR_Shops_C_Gang";
        conditions = "";
        side = "civ";
        uniforms[] = {
            { "NONE", $STR_C_Remove_uniforms, 0, "" }
        };
        headgear[] = {
            { "NONE", $STR_C_Remove_headgear, 0, "" }
        };
        goggles[] = {
            { "NONE", $STR_C_Remove_goggles, 0, "" }
        };
        vests[] = {
            { "NONE", $STR_C_Remove_vests, 0, "" },
            { "V_Rangemaster_belt", "", 1900, "" }
        };
        backpacks[] = {
            { "NONE", $STR_C_Remove_backpacks, 0, "" }
        };
    };

    class med_clothing {
        title = "STR_MAR_EMS_Clothing_Shop";
        conditions = "";
        side = "med";
        uniforms[] = {
            { "NONE", $STR_C_Remove_uniforms, 0, "" },
            { "U_I_CombatUniform", $STR_C_EMS_uniforms, 50, "" },
            { "U_B_Wetsuit", "", 250, "" },
            { "U_C_CBRN_Suit_01_Blue_F", "HAZARD SUIT", 5000, "" },
            { "U_C_Scientist", "HAZARD SUIT", 5000, "" }
        };
        headgear[] = {
            { "NONE", $STR_C_Remove_headgear, 0, "" },
            { "H_Cap_blu", "", 10, "" },
            { "H_Beret_CSAT_01_F", "", 10, "call life_mediclevel > 4" },
            { "H_CrewHelmetHeli_B", "", 30, "" },
            { "H_Cap_red", "", 10, "" }
        };
        goggles[] = {
            { "NONE", $STR_C_Remove_goggles, 0, "" },
            { "G_Shades_Blue", "", 10, "" },
            {"G_AirPurifyingRespirator_02_black_F", "", 10, "" },
            {"G_Respirator_white_F", "", 10, "" },
            {"G_Squares", "", 10, "" },
            {"G_Aviator", "", 10, "" },
            {"G_Spectacles", "", 10, "" },
            {"G_Diving", "", 10, "" }
        };
        vests[] = {
            { "NONE", $STR_C_Remove_vests, 0, "" },
            {"V_RebreatherB", "", 7500, "" }
        };
        backpacks[] = {
            { "NONE", $STR_C_Remove_backpacks, 0, "" },
            { "B_FieldPack_oli", $STR_C_EMS_backpacks, 3000, "" }
        };
    };

    class reb {
        title = "STR_Shops_C_Rebel";
        conditions = "license_civ_rebel";
        side = "civ";
        uniforms[] = {
            { "NONE", $STR_C_Remove_uniforms, 0, "" },
            { "U_IG_Guerilla1_1", "", 45000, "" },
            { "U_I_G_Story_Protagonist_F", "", 45000, "" },
            { "U_I_G_resistanceLeader_F", "", 45000, "" },
            { "U_IG_leader", "", 45000, "" },
            { "U_O_PilotCoveralls", "", 45000, "" },
            { "U_O_SpecopsUniform_ocamo", "", 45000, "" },
            { "U_B_T_Soldier_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_1_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_2_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_3_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_4_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_5_F", "", 45000, "" }, //Apex DLC
            { "U_I_GhillieSuit", "", 100000, "" },
            { "U_O_GhillieSuit", "", 100000, "" },
            { "U_B_GhillieSuit", "", 100000, "" },
            { "U_O_T_Sniper_F", "", 100000, "" },
            { "U_B_T_Sniper_F", "", 100000, "" },
            { "U_O_FullGhillie_lsh", "", 100000, "" },
            { "U_O_FullGhillie_sard", "", 100000, "" },
            { "U_O_FullGhillie_ard", "", 100000, "" },
            { "U_O_T_FullGhillie_tna_F", "", 100000, "" },
            { "U_B_T_FullGhillie_tna_F", "", 100000, "" },
            { "U_I_C_Soldier_Para_1_F", "", 45000, "" },
            { "U_I_C_Soldier_Para_5_F", "", 45000, "" },
            { "U_I_C_Soldier_Camo_F", "", 45000, "" },
            { "U_O_T_Soldier_F", "", 45000, "" },
            { "U_I_L_Uniform_01_camo_F", "", 45000, "" },
            { "U_I_E_Uniform_01_shortsleeve_F", "", 45000, "" },
            { "U_B_CombatUniform_mcam_wdl_f", "", 45000, "" },
            { "U_I_L_Uniform_01_tshirt_olive_F", "", 45000, "" },
            { "U_BG_Guerilla1_2_F", "", 45000, "" },
            { "U_B_CombatUniform_mcam", "", 45000, "" },
            { "U_B_CombatUniform_mcam_tshirt", "", 45000, "" },
            { "U_I_CombatUniform", "", 45000, "" },
            { "U_O_CombatUniform_ocamo", "", 45000, "" },
            { "U_O_CombatUniform_oucamo", "", 45000, "" },
            { "U_B_survival_uniform", "", 45000, "" },
            { "U_B_CTRG_Soldier_urb_1_F", "", 45000, "" },
            { "U_B_CTRG_Soldier_F", "", 45000, "" },
            { "U_B_CTRG_Soldier_Arid_F", "", 45000, "" },
            { "U_I_L_Uniform_01_deserter_F", "", 45000, "" },
            { "U_BG_Guerrilla_6_1", "", 45000, "" },
            { "U_O_R_Gorka_01_brown_F", "", 45000, "" },
            { "U_O_R_Gorka_01_camo_F", "", 45000, "" },
            { "U_I_E_Uniform_01_tanktop_F", "", 45000, "" },
            { "U_C_E_LooterJacket_01_F", "", 45000, "" }
        };
        headgear[] = {
            { "NONE", $STR_C_Remove_headgear, 0, "" },
            { "H_Bandanna_camo", "", 10000, "" },
            { "H_ShemagOpen_khk", "", 10000, "" },
            { "H_ShemagOpen_tan", "", 10000, "" },
            { "H_Shemag_olive", "", 10000, "" },
            { "H_HelmetO_ocamo", "", 25000, "" },
            { "H_HelmetCrew_O_ghex_F", "", 25000, "" },
            { "H_CrewHelmetHeli_I_E", "", 25000, "" },
            { "H_CrewHelmetHeli_I", "", 25000, "" },
            { "H_PilotHelmetFighter_O", "", 25000, "" },
            { "H_HelmetB_camo", "", 25000, "" },
            { "H_HelmetB_light", "", 25000, "" },
            { "H_Cap_marshal", "", 10000, "" },
            { "H_MilCap_ocamo", "", 10000, "" },
            { "H_MilCap_wdl", "", 10000, "" },
            { "H_Cap_headphones", "", 10000, "" },
            { "H_HelmetB_TI_tna_F", "", 150000, "" },
            { "H_HelmetB_TI_arid_F", "", 150000, "" },
            { "H_HelmetSpecB_wdl", "", 25000, "" }
        };
        goggles[] = {
            { "NONE", $STR_C_Remove_goggles, 0, "" },
            { "G_Shades_Black", "", 20, "" },
            { "G_Shades_Blue", "", 20, "" },
            { "G_Sport_Blackred", "", 25, "" },
            { "G_Sport_Checkered", "", 25, "" },
            { "G_Sport_Blackyellow", "", 25, "" },
            { "G_Sport_BlackWhite", "", 25, "" },
            { "G_Lowprofile", "", 30, "" },
            { "G_Squares", "", 50, "" },
            { "G_Combat", "", 125, "" },
            { "G_Balaclava_blk", "", 150, "" },
            { "G_Balaclava_combat", "", 150, "" },
            { "G_Balaclava_lowprofile", "", 150, "" },
            { "G_Balaclava_oli", "", 150, "" },
            { "G_Bandanna_aviator", "", 150, "" },
            { "G_Bandanna_beast", "", 150, "" },
            { "G_Bandanna_blk", "", 150, "" },
            { "G_Bandanna_khk", "", 150, "" },
            { "G_Bandanna_oli", "", 150, "" },
            { "G_Bandanna_shades", "", 150, "" },
            { "G_Bandanna_sport", "", 150, "" },
            { "G_Bandanna_tan", "", 150, "" },
            { "G_Balaclava_TI_G_tna_F", "", 150, "" },
            { "G_Balaclava_TI_tna_F", "", 150, "" }
        };
        vests[] = {
            { "NONE", $STR_C_Remove_vests, 0, "" },
            { "V_BandollierB_cbr", "", 10000, "" },
            { "V_HarnessO_brn", "", 10000, "" },
            { "V_TacVest_khk", "", 15000, "" },
            { "V_TacChestrig_grn_F", "", 10000, "" }, //Apex DLC
            { "V_PlateCarrier1_rgr", "", 75000, "" },
            { "V_TacVest_brn", "", 15000, "" },
            { "V_TacVest_khk", "", 15000, "" },
            { "V_TacVest_oli", "", 15000, "" },
            { "V_I_G_resistanceLeader_F", "", 15000, "" },
            { "V_PlateCarrier_Kerry", "", 75000, "" },
            { "V_PlateCarrier2_tna_F", "", 150000, "" },
            { "V_PlateCarrier1_tna_F", "", 75000, "" },
            { "V_PlateCarrier1_wdl", "", 75000, "" },
            { "V_CarrierRigKBT_01_light_EAF_F", "", 75000, "" },
            { "V_PlateCarrier2_wdl", "", 150000, "" }
        };
        backpacks[] = {
            { "NONE", $STR_C_Remove_backpacks, 0, "" },
            { "B_OutdoorPack_blk", "", 20000, "" },
            { "B_AssaultPack_khk", "", 20000, "" },
            { "B_AssaultPack_dgtl", "", 20000, "" },
            { "B_AssaultPack_rgr", "", 20000, "" },
            { "B_AssaultPack_sgg", "", 20000, "" },
            { "B_AssaultPack_blk", "", 20000, "" },
            { "B_AssaultPack_cbr", "", 20000, "" },
            { "B_AssaultPack_mcamo", "", 20000, "" },
            { "B_AssaultPack_tna_f", "", 20000, "" }, //Apex DLC
            { "B_TacticalPack_oli", "", 20000, "" },
            { "B_Kitbag_mcamo", "", 20000, "" },
            { "B_Kitbag_sgg", "", 20000, "" },
            { "B_Kitbag_cbr", "", 20000, "" },
            { "B_FieldPack_blk", "", 20000, "" },
            { "B_FieldPack_ocamo", "", 20000, "" },
            { "B_FieldPack_oucamo", "", 20000, "" },
            { "B_FieldPack_ghex_f", "", 20000, "" }, //Apex DLC
            { "B_Bergen_sgg", "", 20000, "" },
            { "B_Bergen_mcamo", "", 20000, "" },
            { "B_Bergen_rgr", "", 20000, "" },
            { "B_Bergen_blk", "", 20000, "" },
            { "B_Carryall_ocamo", "", 25000, "" },
            { "B_Carryall_oucamo", "", 25000, "" },
            { "B_Carryall_mcamo", "", 25000, "" },
            { "B_Carryall_oli", "", 25000, "" },
            { "B_Carryall_khk", "", 25000, "" },
            { "B_Carryall_cbr", "", 25000, "" },
            { "B_Carryall_ghex_f", "", 50000, "" }, //Apex DLC
            { "B_Bergen_dgtl_f", "", 50000, "" },
            { "B_Bergen_tna_f", "", 50000, "" },
            { "B_Messenger_IDAP_F", "", 20000, "" },
            { "B_Messenger_Black_F", "", 20000, "" },
            { "B_ViperHarness_ghex_F", "", 45000, "" },
            { "B_ViperHarness_khk_F", "", 45000, "" },
            { "B_ViperHarness_oli_F", "", 45000, "" },
            { "B_ViperHarness_blk_F", "", 45000, "" },
            { "B_ViperHarness_hex_F", "", 45000, "" }
        };
    };

    class mercenary {
        title = "Mercenary";
        conditions = "license_civ_mercenary";
        side = "civ";
        uniforms[] = {
            { "NONE", $STR_C_Remove_uniforms, 0, "" },
            { "U_IG_Guerilla1_1", "", 45000, "" },
            { "U_I_G_Story_Protagonist_F", "", 45000, "" },
            { "U_I_G_resistanceLeader_F", "", 45000, "" },
            { "U_IG_leader", "", 45000, "" },
            { "U_O_PilotCoveralls", "", 45000, "" },
            { "U_O_SpecopsUniform_ocamo", "", 45000, "" },
            { "U_B_T_Soldier_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_1_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_2_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_3_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_4_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_5_F", "", 45000, "" }, //Apex DLC
            { "U_I_GhillieSuit", "", 100000, "" },
            { "U_O_GhillieSuit", "", 100000, "" },
            { "U_B_GhillieSuit", "", 100000, "" },
            { "U_O_T_Sniper_F", "", 100000, "" },
            { "U_B_T_Sniper_F", "", 100000, "" },
            { "U_O_FullGhillie_lsh", "", 100000, "" },
            { "U_O_FullGhillie_sard", "", 100000, "" },
            { "U_O_FullGhillie_ard", "", 100000, "" },
            { "U_O_T_FullGhillie_tna_F", "", 100000, "" },
            { "U_B_T_FullGhillie_tna_F", "", 100000, "" },
            { "U_I_C_Soldier_Para_1_F", "", 45000, "" },
            { "U_I_C_Soldier_Para_5_F", "", 45000, "" },
            { "U_I_C_Soldier_Camo_F", "", 45000, "" },
            { "U_O_T_Soldier_F", "", 45000, "" },
            { "U_I_L_Uniform_01_camo_F", "", 45000, "" },
            { "U_I_E_Uniform_01_shortsleeve_F", "", 45000, "" },
            { "U_B_CombatUniform_mcam_wdl_f", "", 45000, "" },
            { "U_I_L_Uniform_01_tshirt_olive_F", "", 45000, "" },
            { "U_BG_Guerilla1_2_F", "", 45000, "" },
            { "U_B_CombatUniform_mcam", "", 45000, "" },
            { "U_B_CombatUniform_mcam_tshirt", "", 45000, "" },
            { "U_I_CombatUniform", "", 45000, "" },
            { "U_O_CombatUniform_ocamo", "", 45000, "" },
            { "U_O_CombatUniform_oucamo", "", 45000, "" },
            { "U_B_survival_uniform", "", 45000, "" },
            { "U_B_CTRG_Soldier_urb_1_F", "", 45000, "" },
            { "U_B_CTRG_Soldier_F", "", 45000, "" },
            { "U_B_CTRG_Soldier_Arid_F", "", 45000, "" },
            { "U_I_L_Uniform_01_deserter_F", "", 45000, "" },
            { "U_BG_Guerrilla_6_1", "", 45000, "" },
            { "U_O_R_Gorka_01_brown_F", "", 45000, "" },
            { "U_O_R_Gorka_01_camo_F", "", 45000, "" },
            { "U_I_E_Uniform_01_tanktop_F", "", 45000, "" },
            { "U_C_E_LooterJacket_01_F", "", 45000, "" }
        };
        headgear[] = {
            { "NONE", $STR_C_Remove_headgear, 0, "" },
            { "H_Bandanna_camo", "", 10000, "" },
            { "H_ShemagOpen_khk", "", 10000, "" },
            { "H_ShemagOpen_tan", "", 10000, "" },
            { "H_Shemag_olive", "", 10000, "" },
            { "H_HelmetO_ocamo", "", 25000, "" },
            { "H_HelmetCrew_O_ghex_F", "", 25000, "" },
            { "H_CrewHelmetHeli_I_E", "", 25000, "" },
            { "H_CrewHelmetHeli_I", "", 25000, "" },
            { "H_PilotHelmetFighter_O", "", 25000, "" },
            { "H_HelmetB_camo", "", 25000, "" },
            { "H_HelmetB_light", "", 25000, "" },
            { "H_Cap_marshal", "", 10000, "" },
            { "H_MilCap_ocamo", "", 10000, "" },
            { "H_MilCap_wdl", "", 10000, "" },
            { "H_Cap_headphones", "", 10000, "" },
            { "H_HelmetB_TI_tna_F", "", 150000, "" },
            { "H_HelmetB_TI_arid_F", "", 150000, "" },
            { "H_HelmetSpecB_wdl", "", 25000, "" }
        };
        goggles[] = {
            { "NONE", $STR_C_Remove_goggles, 0, "" },
            { "G_Shades_Black", "", 20, "" },
            { "G_Shades_Blue", "", 20, "" },
            { "G_Sport_Blackred", "", 25, "" },
            { "G_Sport_Checkered", "", 25, "" },
            { "G_Sport_Blackyellow", "", 25, "" },
            { "G_Sport_BlackWhite", "", 25, "" },
            { "G_Lowprofile", "", 30, "" },
            { "G_Squares", "", 50, "" },
            { "G_Combat", "", 125, "" },
            { "G_Balaclava_blk", "", 150, "" },
            { "G_Balaclava_combat", "", 150, "" },
            { "G_Balaclava_lowprofile", "", 150, "" },
            { "G_Balaclava_oli", "", 150, "" },
            { "G_Bandanna_aviator", "", 150, "" },
            { "G_Bandanna_beast", "", 150, "" },
            { "G_Bandanna_blk", "", 150, "" },
            { "G_Bandanna_khk", "", 150, "" },
            { "G_Bandanna_oli", "", 150, "" },
            { "G_Bandanna_shades", "", 150, "" },
            { "G_Bandanna_sport", "", 150, "" },
            { "G_Bandanna_tan", "", 150, "" },
            { "G_Balaclava_TI_G_tna_F", "", 150, "" },
            { "G_Balaclava_TI_tna_F", "", 150, "" }
        };
        vests[] = {
            { "NONE", $STR_C_Remove_vests, 0, "" },
            { "V_BandollierB_cbr", "", 10000, "" },
            { "V_HarnessO_brn", "", 10000, "" },
            { "V_TacVest_khk", "", 15000, "" },
            { "V_TacChestrig_grn_F", "", 10000, "" }, //Apex DLC
            { "V_PlateCarrier1_rgr", "", 75000, "" },
            { "V_TacVest_brn", "", 15000, "" },
            { "V_TacVest_khk", "", 15000, "" },
            { "V_TacVest_oli", "", 15000, "" },
            { "V_I_G_resistanceLeader_F", "", 15000, "" },
            { "V_PlateCarrier_Kerry", "", 75000, "" },
            { "V_PlateCarrier2_tna_F", "", 150000, "" },
            { "V_PlateCarrier1_tna_F", "", 75000, "" },
            { "V_PlateCarrier1_wdl", "", 75000, "" },
            { "V_CarrierRigKBT_01_light_EAF_F", "", 75000, "" },
            { "V_PlateCarrier2_wdl", "", 150000, "" }
        };
        backpacks[] = {
            { "NONE", $STR_C_Remove_backpacks, 0, "" },
            { "B_OutdoorPack_blk", "", 20000, "" },
            { "B_AssaultPack_khk", "", 20000, "" },
            { "B_AssaultPack_dgtl", "", 20000, "" },
            { "B_AssaultPack_rgr", "", 20000, "" },
            { "B_AssaultPack_sgg", "", 20000, "" },
            { "B_AssaultPack_blk", "", 20000, "" },
            { "B_AssaultPack_cbr", "", 20000, "" },
            { "B_AssaultPack_mcamo", "", 20000, "" },
            { "B_AssaultPack_tna_f", "", 20000, "" }, //Apex DLC
            { "B_TacticalPack_oli", "", 20000, "" },
            { "B_Kitbag_mcamo", "", 20000, "" },
            { "B_Kitbag_sgg", "", 20000, "" },
            { "B_Kitbag_cbr", "", 20000, "" },
            { "B_FieldPack_blk", "", 20000, "" },
            { "B_FieldPack_ocamo", "", 20000, "" },
            { "B_FieldPack_oucamo", "", 20000, "" },
            { "B_FieldPack_ghex_f", "", 20000, "" }, //Apex DLC
            { "B_Bergen_sgg", "", 20000, "" },
            { "B_Bergen_mcamo", "", 20000, "" },
            { "B_Bergen_rgr", "", 20000, "" },
            { "B_Bergen_blk", "", 20000, "" },
            { "B_Carryall_ocamo", "", 25000, "" },
            { "B_Carryall_oucamo", "", 25000, "" },
            { "B_Carryall_mcamo", "", 25000, "" },
            { "B_Carryall_oli", "", 25000, "" },
            { "B_Carryall_khk", "", 25000, "" },
            { "B_Carryall_cbr", "", 25000, "" },
            { "B_Carryall_ghex_f", "", 50000, "" }, //Apex DLC
            { "B_Bergen_dgtl_f", "", 50000, "" },
            { "B_Bergen_tna_f", "", 50000, "" },
            { "B_Messenger_IDAP_F", "", 20000, "" },
            { "B_Messenger_Black_F", "", 20000, "" },
            { "B_ViperHarness_ghex_F", "", 45000, "" },
            { "B_ViperHarness_khk_F", "", 45000, "" },
            { "B_ViperHarness_oli_F", "", 45000, "" },
            { "B_ViperHarness_blk_F", "", 45000, "" },
            { "B_ViperHarness_hex_F", "", 45000, "" }
        };
    };

    class alpha {
        title = "Alpha";
        conditions = "license_civ_alpha";
        side = "civ";
        uniforms[] = {
            { "NONE", $STR_C_Remove_uniforms, 0, "" },
            { "U_IG_Guerilla1_1", "", 45000, "" },
            { "U_I_G_Story_Protagonist_F", "", 45000, "" },
            { "U_I_G_resistanceLeader_F", "", 45000, "" },
            { "U_IG_leader", "", 45000, "" },
            { "U_O_PilotCoveralls", "", 45000, "" },
            { "U_O_SpecopsUniform_ocamo", "", 45000, "" },
            { "U_B_T_Soldier_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_1_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_2_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_3_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_4_F", "", 45000, "" }, //Apex DLC
            { "U_I_C_Soldier_Bandit_5_F", "", 45000, "" }, //Apex DLC
            { "U_I_GhillieSuit", "", 100000, "" },
            { "U_O_GhillieSuit", "", 100000, "" },
            { "U_B_GhillieSuit", "", 100000, "" },
            { "U_O_T_Sniper_F", "", 100000, "" },
            { "U_B_T_Sniper_F", "", 100000, "" },
            { "U_O_FullGhillie_lsh", "", 100000, "" },
            { "U_O_FullGhillie_sard", "", 100000, "" },
            { "U_O_FullGhillie_ard", "", 100000, "" },
            { "U_O_T_FullGhillie_tna_F", "", 100000, "" },
            { "U_B_T_FullGhillie_tna_F", "", 100000, "" },
            { "U_I_C_Soldier_Para_1_F", "", 45000, "" },
            { "U_I_C_Soldier_Para_5_F", "", 45000, "" },
            { "U_I_C_Soldier_Camo_F", "", 45000, "" },
            { "U_O_T_Soldier_F", "", 45000, "" },
            { "U_I_L_Uniform_01_camo_F", "", 45000, "" },
            { "U_I_E_Uniform_01_shortsleeve_F", "", 45000, "" },
            { "U_B_CombatUniform_mcam_wdl_f", "", 45000, "" },
            { "U_I_L_Uniform_01_tshirt_olive_F", "", 45000, "" },
            { "U_BG_Guerilla1_2_F", "", 45000, "" },
            { "U_B_CombatUniform_mcam", "", 45000, "" },
            { "U_B_CombatUniform_mcam_tshirt", "", 45000, "" },
            { "U_I_CombatUniform", "", 45000, "" },
            { "U_O_CombatUniform_ocamo", "", 45000, "" },
            { "U_O_CombatUniform_oucamo", "", 45000, "" },
            { "U_B_survival_uniform", "", 45000, "" },
            { "U_B_CTRG_Soldier_urb_1_F", "", 45000, "" },
            { "U_B_CTRG_Soldier_F", "", 45000, "" },
            { "U_B_CTRG_Soldier_Arid_F", "", 45000, "" },
            { "U_I_L_Uniform_01_deserter_F", "", 45000, "" },
            { "U_BG_Guerrilla_6_1", "", 45000, "" },
            { "U_O_R_Gorka_01_brown_F", "", 45000, "" },
            { "U_O_R_Gorka_01_camo_F", "", 45000, "" },
            { "U_I_E_Uniform_01_tanktop_F", "", 45000, "" },
            { "U_C_E_LooterJacket_01_F", "", 45000, "" },
            { "U_O_R_Gorka_01_black_F", "", 45000, "" }
        };
        headgear[] = {
            { "NONE", $STR_C_Remove_headgear, 0, "" },
            { "H_Bandanna_camo", "", 10000, "" },
            { "H_ShemagOpen_khk", "", 10000, "" },
            { "H_ShemagOpen_tan", "", 10000, "" },
            { "H_Shemag_olive", "", 10000, "" },
            { "H_HelmetO_ocamo", "", 25000, "" },
            { "H_HelmetCrew_O_ghex_F", "", 25000, "" },
            { "H_CrewHelmetHeli_I_E", "", 25000, "" },
            { "H_CrewHelmetHeli_I", "", 25000, "" },
            { "H_PilotHelmetFighter_O", "", 25000, "" },
            { "H_HelmetB_camo", "", 25000, "" },
            { "H_HelmetB_light", "", 25000, "" },
            { "H_Cap_marshal", "", 10000, "" },
            { "H_MilCap_ocamo", "", 10000, "" },
            { "H_MilCap_wdl", "", 10000, "" },
            { "H_Cap_headphones", "", 10000, "" },
            { "H_HelmetB_TI_tna_F", "", 150000, "" },
            { "H_HelmetB_TI_arid_F", "", 150000, "" },
            { "H_HelmetSpecB_wdl", "", 25000, "" }
        };
        goggles[] = {
            { "NONE", $STR_C_Remove_goggles, 0, "" },
            { "G_Shades_Black", "", 20, "" },
            { "G_Shades_Blue", "", 20, "" },
            { "G_Sport_Blackred", "", 25, "" },
            { "G_Sport_Checkered", "", 25, "" },
            { "G_Sport_Blackyellow", "", 25, "" },
            { "G_Sport_BlackWhite", "", 25, "" },
            { "G_Lowprofile", "", 30, "" },
            { "G_Squares", "", 50, "" },
            { "G_Combat", "", 125, "" },
            { "G_Balaclava_blk", "", 150, "" },
            { "G_Balaclava_combat", "", 150, "" },
            { "G_Balaclava_lowprofile", "", 150, "" },
            { "G_Balaclava_oli", "", 150, "" },
            { "G_Bandanna_aviator", "", 150, "" },
            { "G_Bandanna_beast", "", 150, "" },
            { "G_Bandanna_blk", "", 150, "" },
            { "G_Bandanna_khk", "", 150, "" },
            { "G_Bandanna_oli", "", 150, "" },
            { "G_Bandanna_shades", "", 150, "" },
            { "G_Bandanna_sport", "", 150, "" },
            { "G_Bandanna_tan", "", 150, "" },
            { "G_Balaclava_TI_G_tna_F", "", 150, "" },
            { "G_Balaclava_TI_tna_F", "", 150, "" }
        };
        vests[] = {
            { "NONE", $STR_C_Remove_vests, 0, "" },
            { "V_BandollierB_cbr", "", 10000, "" },
            { "V_HarnessO_brn", "", 10000, "" },
            { "V_TacVest_khk", "", 15000, "" },
            { "V_TacChestrig_grn_F", "", 10000, "" }, //Apex DLC
            { "V_PlateCarrier1_rgr", "", 75000, "" },
            { "V_TacVest_brn", "", 15000, "" },
            { "V_TacVest_khk", "", 15000, "" },
            { "V_TacVest_oli", "", 15000, "" },
            { "V_I_G_resistanceLeader_F", "", 15000, "" },
            { "V_PlateCarrier_Kerry", "", 75000, "" },
            { "V_PlateCarrier2_tna_F", "", 150000, "" },
            { "V_PlateCarrier1_tna_F", "", 75000, "" },
            { "V_PlateCarrier1_wdl", "", 75000, "" },
            { "V_CarrierRigKBT_01_light_EAF_F", "", 75000, "" },
            { "V_PlateCarrier2_wdl", "", 150000, "" },
            { "V_PlateCarrier2_blk", "", 450000, "" }
        };
        backpacks[] = {
            { "NONE", $STR_C_Remove_backpacks, 0, "" },
            { "B_OutdoorPack_blk", "", 20000, "" },
            { "B_AssaultPack_khk", "", 20000, "" },
            { "B_AssaultPack_dgtl", "", 20000, "" },
            { "B_AssaultPack_rgr", "", 20000, "" },
            { "B_AssaultPack_sgg", "", 20000, "" },
            { "B_AssaultPack_blk", "", 20000, "" },
            { "B_AssaultPack_cbr", "", 20000, "" },
            { "B_AssaultPack_mcamo", "", 20000, "" },
            { "B_AssaultPack_tna_f", "", 20000, "" }, //Apex DLC
            { "B_TacticalPack_oli", "", 20000, "" },
            { "B_Kitbag_mcamo", "", 20000, "" },
            { "B_Kitbag_sgg", "", 20000, "" },
            { "B_Kitbag_cbr", "", 20000, "" },
            { "B_FieldPack_blk", "", 20000, "" },
            { "B_FieldPack_ocamo", "", 20000, "" },
            { "B_FieldPack_oucamo", "", 20000, "" },
            { "B_FieldPack_ghex_f", "", 20000, "" }, //Apex DLC
            { "B_Bergen_sgg", "", 20000, "" },
            { "B_Bergen_mcamo", "", 20000, "" },
            { "B_Bergen_rgr", "", 20000, "" },
            { "B_Bergen_blk", "", 20000, "" },
            { "B_Carryall_ocamo", "", 25000, "" },
            { "B_Carryall_oucamo", "", 25000, "" },
            { "B_Carryall_mcamo", "", 25000, "" },
            { "B_Carryall_oli", "", 25000, "" },
            { "B_Carryall_khk", "", 25000, "" },
            { "B_Carryall_cbr", "", 25000, "" },
            { "B_Carryall_ghex_f", "", 50000, "" }, //Apex DLC
            { "B_Bergen_dgtl_f", "", 50000, "" },
            { "B_Bergen_tna_f", "", 50000, "" },
            { "B_Messenger_IDAP_F", "", 20000, "" },
            { "B_Messenger_Black_F", "", 20000, "" },
            { "B_ViperHarness_ghex_F", "", 45000, "" },
            { "B_ViperHarness_khk_F", "", 45000, "" },
            { "B_ViperHarness_oli_F", "", 45000, "" },
            { "B_ViperHarness_blk_F", "", 45000, "" },
            { "B_ViperHarness_hex_F", "", 45000, "" }
        };
    };

    class kart {
        title = "STR_Shops_C_Kart";
        conditions = "";
        side = "civ";
        uniforms[] = {
            { "NONE", $STR_C_Remove_uniforms, 0, "" },
            { "U_C_Driver_1_black", "", 1500, "" },
            { "U_C_Driver_1_blue", "", 1500, "" },
            { "U_C_Driver_1_red", "", 1500, "" },
            { "U_C_Driver_1_orange", "", 1500, "" },
            { "U_C_Driver_1_green", "", 1500, "" },
            { "U_C_Driver_1_white", "", 1500, "" },
            { "U_C_Driver_1_yellow", "", 1500, "" },
            { "U_C_Driver_2", "", 3500, "" },
            { "U_C_Driver_1", "", 3600, "" },
            { "U_C_Driver_3", "", 3700, "" },
            { "U_C_Driver_4", "", 3700, "" }
        };
        headgear[] = {
            { "NONE", $STR_C_Remove_headgear, 0, "" },
            { "H_RacingHelmet_1_black_F", "", 1000, "" },
            { "H_RacingHelmet_1_red_F", "", 1000, "" },
            { "H_RacingHelmet_1_white_F", "", 1000, "" },
            { "H_RacingHelmet_1_blue_F", "", 1000, "" },
            { "H_RacingHelmet_1_yellow_F", "", 1000, "" },
            { "H_RacingHelmet_1_green_F", "", 1000, "" },
            { "H_RacingHelmet_1_F", "", 2500, "" },
            { "H_RacingHelmet_2_F", "", 2500, "" },
            { "H_RacingHelmet_3_F", "", 2500, "" },
            { "H_RacingHelmet_4_F", "", 2500, "" }
        };
        goggles[] = {
            { "NONE", $STR_C_Remove_goggles, 0, "" }
        };
        vests[] = {
            { "NONE", $STR_C_Remove_vests, 0, "" }
        };
        backpacks[] = {
            { "NONE", $STR_C_Remove_backpacks, 0, "" }
        };
    };
};
