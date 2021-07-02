
class Tuning_Conf {
    class Conf {

        material_cost = 1000000;
        horn_cost = 1500000;
        nitro_cost = 500000;
        oil_cost = 2000000;
        cost_lights = 5000000;

        nitro_amount = 5;
        oil_amount = 3;

        horns[] = {
            {"CarHorn", "Car Horn"},
            {"TruckHorn", "Truck Horn"},
            {"TruckHorn2", "Truck Horn 2"},
            {"TruckHorn3", "Truck Horn 3"},
            {"SportCarHorn", "Sport Car Horn"},
            {"MiniCarHorn", "Mini Car Horn"},
            {"PoliceHorn", "[ILLEGAL] Police Horn"}
        };


        materials[] =
        {
           {"material\blueShine.rvmat","Blue Shine"},
           {"material\blueUltimate.rvmat","Blue Ultimate"},
           {"material\crazyLasyShine.rvmat","Lasy Shine"},
           {"material\csgoFadeShine.rvmat","Fade Shine"},
           {"material\darkBlueGlow.rvmat","Dark Blue Glow"},
           {"material\darkGreenGlow.rvmat","Dark Green Glow"},
           {"material\fadeUltimate.rvmat","Fade"},
           {"material\firestormRedEditionShine.rvmat","Firestorm Red"},
           {"material\firestormYellowEditionShine.rvmat","Firestorm Yellow"},
           {"material\flipFlopGreenShine.rvmat","Flip Flop Green"},
           {"material\flipFlopYellowShine.rvmat","Flip Flop Yellow"},
           {"material\girlsClubShine.rvmat","Girls Club"},
           {"material\goldenRetrieverShine.rvmat","Golden Retriever"},
           {"material\goldShine.rvmat","Gold"},
           {"material\greenUltimate.rvmat","Green"},
           {"material\lavaShine.rvmat","Lava"},
           {"material\lemonGlow.rvmat","Lemon"},
           {"material\lightBlueGlow.rvmat","Light Blue"},
           {"material\lightGreenGlow.rvmat","Light Green"},
           {"material\lilaGlow.rvmat","Lila"},
           {"material\manderinGlow.rvmat","Manderin"},
           {"material\mirror.rvmat","Mirror"},
           {"material\oceanShine.rvmat","Ocean"},
           {"material\orangeGlow.rvmat","Orange"},
           {"material\pinkLadyGlow.rvmat","Pink"},
           {"material\redGlow.rvmat","Red"},
           {"material\redUltimate.rvmat","Red Ultimate"},
           {"material\reverse1Ultimate.rvmat","Reverse 1"},
           {"material\reverse2Ultimate.rvmat","Reverse 2"},
           {"material\reverse3Ultimate.rvmat","Reverse 3"},
           {"material\silentBlueGlow.rvmat","Silent Blue"},
           {"material\silentGreenGlow.rvmat","Silent Green"},
           {"material\stealthShine.rvmat","Stealth"},
           {"material\twinColoursShine.rvmat","Twin Color"},
           {"material\whiteBlueGlow.rvmat","White/Blue"},
           {"material\yellowGlow.rvmat","Yellow"}
        };


        light_color[] =
        {
            {"Blue", {0.1, 0.1, 20}},
            {"Red", {20, 0.1, 0.1}},
            {"Orange",{0.996,0.573,0}},
            {"Yellow",{0.875,0.996,0}},
            {"Green",{0.016,0.996,0}},
            {"Light Blue",{0,0.996,0.906}},
            {"Pink",{0.941,0,1}},
            {"Violet",{0.667,0,1}}
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
