
class Tuning_Conf {
    class Conf {

        nitro_cost = 500000;
        oil_cost = 2000000;

        nitro_amount = 5;
        oil_amount = 3;

        horns[] = {
            {"CarHorn", "Car Horn",1500000},
            {"TruckHorn", "Truck Horn",1500000},
            {"TruckHorn2", "Truck Horn 2",1500000},
            {"TruckHorn3", "Truck Horn 3",1500000},
            {"SportCarHorn", "Sport Car Horn",1500000},
            {"MiniCarHorn", "Mini Car Horn",1500000},
            {"PoliceHorn", "[ILLEGAL] Police Horn",10000000}
        };


        materials[] =
        {
           {"material\blueShine.rvmat","Blue Shine",5000000},
           {"material\blueUltimate.rvmat","Blue Ultimate",5000000},
           {"material\crazyLasyShine.rvmat","Lasy Shine",5000000},
           {"material\csgoFadeShine.rvmat","Fade Shine",5000000},
           {"material\darkBlueGlow.rvmat","Dark Blue Glow",5000000},
           {"material\darkGreenGlow.rvmat","Dark Green Glow",5000000},
           {"material\fadeUltimate.rvmat","Fade",5000000},
           {"material\firestormRedEditionShine.rvmat","Firestorm Red",5000000},
           {"material\firestormYellowEditionShine.rvmat","Firestorm Yellow",5000000},
           {"material\flipFlopGreenShine.rvmat","Flip Flop Green",5000000},
           {"material\flipFlopYellowShine.rvmat","Flip Flop Yellow",5000000},
           {"material\girlsClubShine.rvmat","Girls Club",5000000},
           {"material\goldenRetrieverShine.rvmat","Golden Retriever",5000000},
           {"material\goldShine.rvmat","Gold",5000000},
           {"material\greenUltimate.rvmat","Green",5000000},
           {"material\lavaShine.rvmat","Lava",5000000},
           {"material\lemonGlow.rvmat","Lemon",5000000},
           {"material\lightBlueGlow.rvmat","Light Blue",5000000},
           {"material\lightGreenGlow.rvmat","Light Green",5000000},
           {"material\lilaGlow.rvmat","Lila",5000000},
           {"material\manderinGlow.rvmat","Manderin",5000000},
           {"material\mirror.rvmat","Mirror",5000000},
           {"material\oceanShine.rvmat","Ocean",5000000},
           {"material\orangeGlow.rvmat","Orange",5000000},
           {"material\pinkLadyGlow.rvmat","Pink",5000000},
           {"material\redGlow.rvmat","Red",5000000},
           {"material\redUltimate.rvmat","Red Ultimate",5000000},
           {"material\reverse1Ultimate.rvmat","Reverse 1",5000000},
           {"material\reverse2Ultimate.rvmat","Reverse 2",5000000},
           {"material\reverse3Ultimate.rvmat","Reverse 3",5000000},
           {"material\silentBlueGlow.rvmat","Silent Blue",5000000},
           {"material\silentGreenGlow.rvmat","Silent Green",5000000},
           {"material\stealthShine.rvmat","Stealth",5000000},
           {"material\twinColoursShine.rvmat","Twin Color",5000000},
           {"material\whiteBlueGlow.rvmat","White/Blue",5000000},
           {"material\yellowGlow.rvmat","Yellow",5000000}
        };


        light_color[] =
        {
            {"Blue", {0.1, 0.1, 1},10000000},
            {"Red", {1, 0.1, 0.1},10000000},
            {"Orange",{0.996,0.573,0},10000000},
            {"Yellow",{0.875,0.996,0},10000000},
            {"Green",{0.016,0.996,0},10000000},
            {"Light Blue",{0,0.996,0.906},10000000},
            {"Pink",{0.941,0,1},10000000},
            {"Violet",{0.667,0,1},10000000}
        };


        vehicle_light_pos[] =
        {
            {"B_MRAP_01_F",{0,-1.5,-1}},   // hunter
            {"I_MRAP_03_F",{0,-0.4,-1.0}},   // strider
            {"O_MRAP_02_F",{0,-1.6,-1.0}},  // ifrit
            {"C_Offroad_01_F",{0,-0.3,-1}},   // offroad   light lightAttachObject[car,[0,-0.3,-1]]
            {"C_SUV_01_F",{0,-0.3,-1.0}},    // SUV
            {"C_Offroad_02_unarmed_F",{0,0.2,-0.9}},    // Offroader Apex
            {"C_Hatchback_01_sport_F",{0,-0.1,-1}},    // sport limo
            {"B_LSV_01_unarmed_F",{0,0,-1.5}},           // prowler
            {"O_T_LSV_02_unarmed_F",{0,0,-1.2}}        // quilin
        };

    };


};
