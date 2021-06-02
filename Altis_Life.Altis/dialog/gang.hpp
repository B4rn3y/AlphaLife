class Life_My_Gang_Diag {
    idd = 2620;
    name= "life_my_gang_menu";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "";

    class controlsBackground {
        class TabletBCKGRND: life_RscPicture
        {
            idc = -1;
            text = "textures\zmenu\tablet.paa";
            x = -0.0195705;
            y = -0.104647;
            w = 1.08561;
            h = 1.18714;

        };
        class Picture_close: life_RscPicture
        {
            idc = 1206;
            text = "textures\zmenu\close.paa";
            x = 0.094697;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
        };

        class PlayersName: Life_RscTitle  {
            idc = 2009;
            style = 1;
            text = "";
            x = 0.653535;
            y = 0.126734;
            w = 0.167045;
            h = 0.026532;
        };


        class TimeText: life_RscText
        {
            idc = 7858;
            SizeEx = 0.027;
            text = "";
            x = 0.930556;
            y = 0.127946;
            w = 0.0534085;
            h = 0.033266;
        };
    };

    class controls {
        class gang_name: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = 2629;
            text = "";
            x = 0.104798;
            y = 0.227273;
            w = 0.606313;
            h = 0.0444444;
        };

        class GangMemberList: Life_RscListBox
        {
            idc = 2621;
            text = "";
            sizeEx = 0.035;
            x = 0.100934;
            y = 0.281312;
            w = 0.615151;
            h = 0.423232;
        };

        class CloseLoadMenu: life_RscButtonSilent {
            idc = -1;
            tooltip = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;[] call life_fnc_p_updateMenu";
            x = 0.094697;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
        };

        class GangLeave: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Gang_Leave";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_gangLeave";
            x = 0.72601;
            y = 0.279461;
            w = 0.250253;
            h = 0.056229;
        };

        class GangLock: Life_RscButtonMenu {
            idc = 2622;
            text = "$STR_Gang_UpgradeSlots";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] spawn life_fnc_gangUpgrade";
            x = 0.72601;
            y = 0.343434;
            w = 0.250253;
            h = 0.056229;
        };

        class GangKick: Life_RscButtonMenu {
            idc = 2624;
            text = "$STR_Gang_Kick";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_gangKick";
            x = 0.72601;
            y = 0.407407;
            w = 0.250253;
            h = 0.056229;
        };

        class GangLeader: Life_RscButtonMenu {
            idc = 2625;
            text = "$STR_Gang_SetLeader";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] spawn life_fnc_gangNewLeader";
            x = 0.72601;
            y = 0.469697;
            w = 0.250253;
            h = 0.056229;
        };

        class InviteMember: GangLeader {
            idc = 2630;
            text = "$STR_Gang_Invite_Player";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] spawn life_fnc_gangInvitePlayer";
            x = 0.72601;
            y = 0.592593;
            w = 0.250253;
            h = 0.056229;
        };

        class DisbandGang: InviteMember    {
            idc = 2631;
            text = "$STR_Gang_Disband_Gang";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] spawn life_fnc_gangDisband";
            x = 0.72601;
            y = 0.531986;
            w = 0.250253;
            h = 0.056229;
        };

        class ColorList: Life_RscCombo {
            idc = 2632;
            x = 0.72601;
            y = 0.656566;
            w = 0.24899;
            h = 0.0427609;
        };

        class GangBank: life_RscText {
            idc = 601;
            style = 1;
            text = "";
            x = 0.728535;
            y = 0.227273;
            w = 0.243939;
            h = 0.042761;
        };
    };
};

class Life_Create_Gang_Diag {
    idd = 2520;
    name= "life_my_gang_menu_create";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn {waitUntil {!isNull (findDisplay 2520)};((findDisplay 2520) displayCtrl 7858) ctrlsettext format[""%1:%2"",systemtime select 3,systemtime select 4];ctrlSetText[2009,format [""%1 / %2"", life_carryWeight, life_maxWeight]]; ((findDisplay 2520) displayCtrl 2523) ctrlSetText format [localize ""STR_Gang_PriceTxt"",[(getNumber(missionConfigFile >> 'Life_Settings' >> 'gang_price'))] call life_fnc_numberText]};";

    class controlsBackground {
        class TabletBCKGRND: life_RscPicture
        {
            idc = -1;
            text = "textures\zmenu\tablet.paa";
            x = -0.0195705;
            y = -0.104647;
            w = 1.08561;
            h = 1.18714;

        };
        class Picture_close: life_RscPicture
        {
            idc = 1206;
            text = "textures\zmenu\close.paa";
            x = 0.094697;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
        };

        class PlayersName: Life_RscTitle  {
            idc = 2009;
            style = 1;
            text = "";
            x = 0.653535;
            y = 0.126734;
            w = 0.167045;
            h = 0.026532;
        };


        class TimeText: life_RscText
        {
            idc = 7858;
            SizeEx = 0.027;
            text = "";
            x = 0.930556;
            y = 0.127946;
            w = 0.0534085;
            h = 0.033266;
        };
    };

    class controls {
        class InfoMsg: Life_RscStructuredText {
            idc = 2523;
            sizeEx = 0.020;
            text = "";
            x = 0.330808;
            y = 0.328283;
            w = 0.37399;
            h = 0.113468;
        };

/*
        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = -1;
            text = "$STR_Gang_Title";
            x = 0.1;
            y = 0.2;
            w = 0.5;
            h = (1 / 25);
        };
*/
        class CloseLoadMenu: life_RscButtonSilent {
            idc = -1;
            tooltip = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;[] call life_fnc_p_updateMenu;";
            x = 0.094697;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
        };

        class GangCreateField: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Gang_Create";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_createGang";
            x = 0.421717;
            y = 0.510101;
            w = 0.180808;
            h = 0.0545455;
        };

        class CreateGangText: Life_RscEdit {
            idc = 2522;
            text = "$STR_Gang_YGN";
            x = 0.330975;
            y = 0.451253;
            w = 0.375253;
            h = 0.0545452;
        };
    };
};





/* #Qojuze
$[
    1.063,
    ["Tablet",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1200,"tablet",[0,"tablet.paa",[-0.0195705,-0.104647,1.08561,1.18714],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1201,"",[0,"tablet\close.paa",[0.094697,0.715488,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"TimeText",[0,"",[0.926768,0.126263,0.0445701,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1003,"Weight",[0,"",[0.653535,0.126734,0.167045,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1500,"gang_members",[0,"",[0.100934,0.281312,0.615151,0.423232],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1000,"gang_name",[0,"Gang name hier eingeben",[0.104798,0.227273,0.606313,0.0444444],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"btn_leave",[0,"Verlassen",[0.72601,0.279461,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2401,"btn_slots",[0,"Slots erhÃ¶hen",[0.72601,0.343434,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2402,"btn_kick",[0,"Kicken",[0.72601,0.407407,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2403,"btn_new_leader",[0,"Neuer AnfÃ¼hrer",[0.72601,0.469697,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2404,"btn_disband_gang",[0,"Gang AuflÃ¶sen",[0.72601,0.531986,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2405,"btn_invite",[0,"Spieler einladen",[0.72601,0.592593,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2100,"combo_players",[0,"",[0.72601,0.656566,0.24899,0.0427609],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1002,"money",[0,"",[0.728535,0.227273,0.243939,0.042761],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]









////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Pehuly)
////////////////////////////////////////////////////////

class tablet: RscPicture
{
    idc = 1200;
    text = "tablet.paa";
    x = -0.0195705;
    y = -0.104647;
    w = 1.08561;
    h = 1.18714;
};
class RscPicture_1201: RscPicture
{
    idc = 1201;
    text = "tablet\close.paa";
    x = 0.094697;
    y = 0.715488;
    w = 0.0823233;
    h = 0.089899;
};
class TimeText: RscText
{
    idc = 1001;
    x = 0.926768;
    y = 0.126263;
    w = 0.0445701;
    h = 0.026532;
};
class Weight: RscText
{
    idc = 1003;
    x = 0.653535;
    y = 0.126734;
    w = 0.167045;
    h = 0.026532;
};
class gang_members: RscListbox
{
    idc = 1500;
    x = 0.100934;
    y = 0.281312;
    w = 0.615151;
    h = 0.423232;
};
class gang_name: RscText
{
    idc = 1000;
    text = "Gang name hier eingeben"; //--- ToDo: Localize;
    x = 0.104798;
    y = 0.227273;
    w = 0.606313;
    h = 0.0444444;
};
class btn_leave: RscButtonMenu
{
    idc = 2400;
    text = "Verlassen"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.279461;
    w = 0.250253;
    h = 0.056229;
};
class btn_slots: RscButtonMenu
{
    idc = 2401;
    text = "Slots erhÃ¶hen"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.343434;
    w = 0.250253;
    h = 0.056229;
};
class btn_kick: RscButtonMenu
{
    idc = 2402;
    text = "Kicken"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.407407;
    w = 0.250253;
    h = 0.056229;
};
class btn_new_leader: RscButtonMenu
{
    idc = 2403;
    text = "Neuer AnfÃ¼hrer"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.469697;
    w = 0.250253;
    h = 0.056229;
};
class btn_disband_gang: RscButtonMenu
{
    idc = 2404;
    text = "Gang AuflÃ¶sen"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.531986;
    w = 0.250253;
    h = 0.056229;
};
class btn_invite: RscButtonMenu
{
    idc = 2405;
    text = "Spieler einladen"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.592593;
    w = 0.250253;
    h = 0.056229;
};
class combo_players: RscCombo
{
    idc = 2100;
    x = 0.72601;
    y = 0.656566;
    w = 0.24899;
    h = 0.0427609;
};
class money: RscText
{
    idc = 1002;
    x = 0.728535;
    y = 0.227273;
    w = 0.243939;
    h = 0.042761;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////





/* #Vasadu
$[
    1.063,
    ["Tablet",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1200,"tablet",[0,"tablet.paa",[-0.0195705,-0.104647,1.08561,1.18714],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1201,"",[0,"tablet\close.paa",[0.094697,0.715488,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"TimeText",[0,"",[0.926768,0.126263,0.0445701,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1003,"Weight",[0,"",[0.653535,0.126734,0.167045,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1400,"",[0,"",[0.330975,0.451253,0.375253,0.0545452],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"btn_create_gang",[0,"Erstellen",[0.421717,0.510101,0.180808,0.0545455],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1100,"",[0,"",[0.330808,0.328283,0.37399,0.113468],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]


////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Mewije)
////////////////////////////////////////////////////////

class tablet: RscPicture
{
    idc = 1200;
    text = "tablet.paa";
    x = -0.0195705;
    y = -0.104647;
    w = 1.08561;
    h = 1.18714;
};
class RscPicture_1201: RscPicture
{
    idc = 1201;
    text = "tablet\close.paa";
    x = 0.094697;
    y = 0.715488;
    w = 0.0823233;
    h = 0.089899;
};
class TimeText: RscText
{
    idc = 1001;
    x = 0.926768;
    y = 0.126263;
    w = 0.0445701;
    h = 0.026532;
};
class Weight: RscText
{
    idc = 1003;
    x = 0.653535;
    y = 0.126734;
    w = 0.167045;
    h = 0.026532;
};
class RscEdit_1400: RscEdit
{
    idc = 1400;
    x = 0.330975;
    y = 0.451253;
    w = 0.375253;
    h = 0.0545452;
};
class btn_create_gang: RscButtonMenu
{
    idc = 2400;
    text = "Erstellen"; //--- ToDo: Localize;
    x = 0.421717;
    y = 0.510101;
    w = 0.180808;
    h = 0.0545455;
};
class RscStructuredText_1100: RscStructuredText
{
    idc = 1100;
    x = 0.330808;
    y = 0.328283;
    w = 0.37399;
    h = 0.113468;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////



*/







