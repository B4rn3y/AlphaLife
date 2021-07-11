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
/*
        class gang_name: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = 2629;
            text = "";
            x = 0.104798;
            y = 0.227273;
            w = 0.606313;
            h = 0.0444444;
        };
*/
        class GangMemberList: Life_RscListBox
        {
            idc = 2621;
            text = "";
            sizeEx = 0.035;
            x = 0.0996714;
            y = 0.321716;
            w = 0.621464;
            h = 0.392929;
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
            x = 0.726011;
            y = 0.20707;
            w = 0.250253;
            h = 0.056229;
        };

        class GangLock: Life_RscButtonMenu {
            idc = 2622;
            text = "$STR_Gang_UpgradeSlots";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] spawn life_fnc_gangUpgrade";
            x = 0.72601;
            y = 0.380472;
            w = 0.250253;
            h = 0.056229;
        };

        class GangKick: Life_RscButtonMenu {
            idc = 2624;
            text = "$STR_Gang_Kick";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] spawn life_fnc_gangKick";
            x = 0.72601;
            y = 0.43771;
            w = 0.250253;
            h = 0.056229;
        };

        class GangLeader: Life_RscButtonMenu {
            idc = 2625;
            text = "$STR_Gang_SetLeader";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] spawn life_fnc_gangNewLeader";
            x = 0.72601;
            y = 0.49495;
            w = 0.250253;
            h = 0.056229;
        };

        class InviteMember: GangLeader {
            idc = 2630;
            text = "$STR_Gang_Invite_Player";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] spawn life_fnc_gangInvitePlayer";
            x = 0.72601;
            y = 0.727273;
            w = 0.250253;
            h = 0.056229;
        };

        class DisbandGang: InviteMember    {
            idc = 2631;
            text = "$STR_Gang_Disband_Gang";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] spawn life_fnc_gangDisband";
            x = 0.72601;
            y = 0.552188;
            w = 0.250253;
            h = 0.056229;
        };

        class ColorList: Life_RscCombo {
            idc = 2632;
            x = 0.72601;
            y = 0.786196;
            w = 0.24899;
            h = 0.0427609;
        };

        class Gang_info: life_RscStructuredText {
            idc = 601;
            text = "";
            x = 0.10101;
            y = 0.170033;
            w = 0.61894;
            h = 0.147138;
        };

        class set_rights: Life_RscButtonMenu
        {
            idc = 2406;
            text = "$STR_Gang_setRights_Gang"; //--- ToDo: Localize;
            onButtonClick = "[] spawn life_fnc_gang_rights_dialog;";
            x = 0.72601;
            y = 0.66835;
            w = 0.250253;
            h = 0.056229;
        };
        class alliances: Life_RscButtonMenu
        {
            idc = 2407;
            text = "$STR_Gang_alliances_Gang"; //--- ToDo: Localize;
            onButtonClick="[] spawn life_fnc_gang_allie_menu;";
            x = 0.72601;
            y = 0.611111;
            w = 0.250253;
            h = 0.056229;
        };
        class tax_btn: Life_RscButtonMenu
        {
            idc = 2408;
            text = "$STR_Gang_taxes_Gang"; //--- ToDo: Localize;
            onButtonClick="createdialog ""gang_taxes"";";
            x = 0.72601;
            y = 0.323232;
            w = 0.250253;
            h = 0.056229;
        };

        class public_BTN: Life_RscButtonMenu
        {
            idc = 2409;
            text = "$STR_Gang_public_Gang"; //--- ToDo: Localize;
            onButtonClick="[] spawn life_fnc_gang_public;";
            x = 0.72601;
            y = 0.26431;
            w = 0.250253;
            h = 0.056229;
        };
    };
};

class Life_Create_Gang_Diag {
    idd = 2520;
    name= "life_my_gang_menu_create";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn {waitUntil {!isNull (findDisplay 2520)};((findDisplay 2520) displayCtrl 7858) ctrlsettext format[""%1:%2"",systemtime select 3,systemtime select 4];ctrlSetText[2009,format [""%1 / %2"", life_carryWeight, life_maxWeight]];((findDisplay 2520) displayCtrl 1101) ctrlsetstructuredtext parsetext format[""<t align='center'>%1</t>"",localize ""STR_Gang_JoinTxt""]; ((findDisplay 2520) displayCtrl 2523) ctrlsetstructuredtext parsetext format [""<t align='center'>%1%2</t>"",localize ""STR_Gang_PriceTxt"",[(getNumber(missionConfigFile >> 'Life_Settings' >> 'gang_price'))] call life_fnc_numberText]};";

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

        class str_text_join_gang: Life_RscStructuredText
        {
            idc = 1101;
            x = 0.171717;
            y = 0.49495;
            w = 0.651768;
            h = 0.0814814;

        };
        class InfoMsg: Life_RscStructuredText {
            idc = 2523;
            sizeEx = 0.020;
            text = "";
            x = 0.171716;
            y = 0.340067;
            w = 0.649243;
            h = 0.0865319;
        };
    };

    class controls {


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
            idc = 5555;
            text = "$STR_Gang_Create";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_createGang";
            x = 0.606061;
            y = 0.430977;
            w = 0.216162;
            h = 0.0579125;
        };

        class CreateGangText: Life_RscEdit {
            idc = 2522;
            text = "$STR_Gang_YGN";
            onSetFocus = "params [""_control""];_control ctrlSetText """";";
            x = 0.170427;
            y = 0.431116;
            w = 0.324748;
            h = 0.0579124;
        };


        class join_gang: life_RscButtonMenu
        {
            idc = 2401;
            text = "$STR_Gang_Join_public"; //--- ToDo: Localize;
            onButtonClick = "[true] spawn life_fnc_gang_allie_menu;";
            x = 0.368687;
            y = 0.579125;
            w = 0.216162;
            h = 0.0579125;
        };

        class tag: life_RscEdit
        {
            idc = 1401;
            text = "TAG";
            onSetFocus = "params [""_control""];_control ctrlSetText """";";
            x = 0.502526;
            y = 0.430976;
            w = 0.0987378;
            h = 0.0562289;
        };
    };
};




/* #Buluru
$[
    1.063,
    ["Tablet",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1200,"tablet",[0,"tablet.paa",[-0.0195705,-0.104647,1.08561,1.18714],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1201,"",[0,"tablet\close.paa",[0.094697,0.715488,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"TimeText",[0,"",[0.926768,0.126263,0.0445701,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1003,"Weight",[0,"",[0.653535,0.126734,0.167045,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1500,"gang_members",[0,"",[0.0996714,0.321716,0.621464,0.392929],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"btn_leave",[0,"Verlassen",[0.726011,0.20707,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2401,"btn_slots",[0,"Slots erhÃ¶hen",[0.72601,0.380472,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2402,"btn_kick",[0,"Kicken",[0.72601,0.43771,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2403,"btn_new_leader",[0,"Neuer AnfÃ¼hrer",[0.72601,0.49495,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2404,"btn_disband_gang",[0,"Gang AuflÃ¶sen",[0.72601,0.552188,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2405,"btn_invite",[0,"Spieler einladen",[0.72601,0.727273,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2100,"combo_players",[0,"",[0.72601,0.786196,0.24899,0.0427609],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1002,"money",[0,"",[0.723485,0.279462,0.243939,0.042761],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2406,"set_rights",[0,"Rechte setzen",[0.72601,0.66835,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2407,"alliances",[0,"Allianzen einst.",[0.72601,0.611111,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2408,"tax_btn",[0,"Steuern einst.",[0.72601,0.323232,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1100,"",[0,"",[0.10101,0.170033,0.61894,0.147138],[-1,-1,-1,-1],[1,0,1,1],[-1,-1,-1,-1],"","-1"],[]],
    [2409,"public",[0,"Ã¶ffentlich",[0.72601,0.26431,0.250253,0.056229],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/


/*
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Buluru)
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
    x = 0.0996714;
    y = 0.321716;
    w = 0.621464;
    h = 0.392929;
};
class btn_leave: RscButtonMenu
{
    idc = 2400;
    text = "Verlassen"; //--- ToDo: Localize;
    x = 0.726011;
    y = 0.20707;
    w = 0.250253;
    h = 0.056229;
};
class btn_slots: RscButtonMenu
{
    idc = 2401;
    text = "Slots erhÃ¶hen"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.380472;
    w = 0.250253;
    h = 0.056229;
};
class btn_kick: RscButtonMenu
{
    idc = 2402;
    text = "Kicken"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.43771;
    w = 0.250253;
    h = 0.056229;
};
class btn_new_leader: RscButtonMenu
{
    idc = 2403;
    text = "Neuer AnfÃ¼hrer"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.49495;
    w = 0.250253;
    h = 0.056229;
};
class btn_disband_gang: RscButtonMenu
{
    idc = 2404;
    text = "Gang AuflÃ¶sen"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.552188;
    w = 0.250253;
    h = 0.056229;
};
class btn_invite: RscButtonMenu
{
    idc = 2405;
    text = "Spieler einladen"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.727273;
    w = 0.250253;
    h = 0.056229;
};
class combo_players: RscCombo
{
    idc = 2100;
    x = 0.72601;
    y = 0.786196;
    w = 0.24899;
    h = 0.0427609;
};
class money: RscText
{
    idc = 1002;
    x = 0.723485;
    y = 0.279462;
    w = 0.243939;
    h = 0.042761;
};
class set_rights: RscButtonMenu
{
    idc = 2406;
    text = "Rechte setzen"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.66835;
    w = 0.250253;
    h = 0.056229;
};
class alliances: RscButtonMenu
{
    idc = 2407;
    text = "Allianzen einst."; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.611111;
    w = 0.250253;
    h = 0.056229;
};
class tax_btn: RscButtonMenu
{
    idc = 2408;
    text = "Steuern einst."; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.323232;
    w = 0.250253;
    h = 0.056229;
};
class RscStructuredText_1100: RscStructuredText
{
    idc = 1100;
    x = 0.10101;
    y = 0.170033;
    w = 0.61894;
    h = 0.147138;
    colorBackground[] = {1,0,1,1};
};
class public: RscButtonMenu
{
    idc = 2409;
    text = "Ã¶ffentlich"; //--- ToDo: Localize;
    x = 0.72601;
    y = 0.26431;
    w = 0.250253;
    h = 0.056229;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////


*/







////   CREATE GANG DIALOG

/* #Kymogi
$[
    1.063,
    ["Tablet",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1200,"tablet",[0,"tablet.paa",[-0.0195705,-0.104647,1.08561,1.18714],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1201,"",[0,"tablet\close.paa",[0.094697,0.715488,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"TimeText",[0,"",[0.926768,0.126263,0.0445701,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1003,"Weight",[0,"",[0.653535,0.126734,0.167045,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1002,"money",[0,"",[0.72601,0.247475,0.243939,0.042761],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1100,"gang_costs",[0,"",[0.171716,0.340067,0.649243,0.0865319],[-1,-1,-1,-1],[1,0,1,1],[-1,-1,-1,-1],"","-1"],[]],
    [1400,"",[0,"",[0.170427,0.431116,0.324748,0.0579124],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"create_gang",[0,"Gang erstellen",[0.606061,0.430977,0.216162,0.0579125],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1101,"str_text_join_gang",[0,"",[0.171717,0.49495,0.651768,0.0814814],[-1,-1,-1,-1],[1,0,1,1],[-1,-1,-1,-1],"","-1"],[]],
    [2401,"join_gang",[0,"Gang Beitreten",[0.368687,0.579125,0.216162,0.0579125],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1401,"",[0,"",[0.502526,0.430976,0.0987378,0.0562289],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/

////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Susama)
////////////////////////////////////////////////////////
/*
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Tirawi)
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
class money: RscText
{
    idc = 1002;
    x = 0.72601;
    y = 0.247475;
    w = 0.243939;
    h = 0.042761;
};
class gang_costs: RscStructuredText
{
    idc = 1100;
    x = 0.171716;
    y = 0.340067;
    w = 0.649243;
    h = 0.0865319;
    colorBackground[] = {1,0,1,1};
};
class RscEdit_1400: RscEdit
{
    idc = 1400;
    x = 0.170427;
    y = 0.431116;
    w = 0.324748;
    h = 0.0579124;
};
class create_gang: RscButtonMenu
{
    idc = 2400;
    text = "Gang erstellen"; //--- ToDo: Localize;
    x = 0.606061;
    y = 0.430977;
    w = 0.216162;
    h = 0.0579125;
};
class str_text_join_gang: RscStructuredText
{
    idc = 1101;
    x = 0.171717;
    y = 0.49495;
    w = 0.651768;
    h = 0.0814814;
    colorBackground[] = {1,0,1,1};
};
class join_gang: RscButtonMenu
{
    idc = 2401;
    text = "Gang Beitreten"; //--- ToDo: Localize;
    x = 0.368687;
    y = 0.579125;
    w = 0.216162;
    h = 0.0579125;
};
class tag: RscEdit
{
    idc = 1401;
    x = 0.502526;
    y = 0.430976;
    w = 0.0987378;
    h = 0.0562289;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////

*/