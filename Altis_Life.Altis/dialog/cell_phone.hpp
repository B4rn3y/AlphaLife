class Life_cell_phone {
    idd = 3000;
    name= "life_cell_phone";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn life_fnc_cellphone";

    class controlsBackground {
        class PhoneBCKGRND: life_RscPicture
        {
            idc = -1;
            text = "textures\zmenu\phone.paa";
            x = -0.0315654;
            y = -0.139731;
            w = 1.04318;
            h = 1.32034;

        };
    };

    class controls {

        class textEdit: Life_RscEdit {
            idc = 3003;
            text = "";
            sizeEx = 0.030;
            x = 0.251262;
            y = 0.56734;
            w = 0.305808;
            h = 0.0595961;
        };

        class TextMsgButton: Life_RscButtonMenu {
            idc = 3015;
            text = "$STR_CELL_TextMSGBtn";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_textmsg";
            x = 0.561869;
            y = 0.563973;
            w = 0.106313;
            h = 0.0646465;
        };

        class PlayerList: Life_RscCombo {
            idc = 3004;
            x = 0.248737;
            y = 0.631313;
            w = 0.308334;
            h = 0.0461279;
        };

        class TextCopButton: Life_RscButtonMenu {
            idc = 3016;
            text = "$STR_CELL_TextPolice";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_textcop";
            x = 0.464646;
            y = 0.685185;
            w = 0.208586;
            h = 0.0494949;
        };

        class TextAdminButton: Life_RscButtonMenu {
            idc = 3017;
            text = "$STR_CELL_TextAdmins";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_textadmin";
            x = 0.248737;
            y = 0.737374;
            w = 0.208586;
            h = 0.0494949;
        };

        class AdminMsgButton: Life_RscButtonMenu {
            idc = 3020;
            text = "$STR_CELL_AdminMsg";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_adminmsg";
            x = 0.367424;
            y = 0.920875;
            w = 0.308333;
            h = 0.052862;
        };

        class AdminMsgAllButton: Life_RscButtonMenu {
            idc = 3021;
            text = "$STR_CELL_AdminMSGAll";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_adminmsgall";
            x = 0.367424;
            y = 0.87037;
            w = 0.308333;
            h = 0.0478115;
        };

        class EMSRequest: Life_RscButtonMenu {
            idc = 3022;
            text = "$STR_CELL_EMSRequest";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_emsrequest";
            x = 0.248737;
            y = 0.685185;
            w = 0.208586;
            h = 0.0494949;
        };

        class CloseButtonKey: life_RscButtonSilent {
            idc = -1;
            tooltip = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = 0.429293;
            y = 0.989898;
            w = 0.0684343;
            h = 0.0814814;
        };
    };
};






/* #Nuceci
$[
    1.063,
    ["phone",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1200,"bckgrnd",[0,"tablet\phone.paa",[-0.0315654,-0.139731,1.04318,1.32034],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1400,"edit_text_to_send",[0,"",[0.251262,0.56734,0.305808,0.0595961],[-1,-1,-1,-1],[0,0,1,1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"btn_send",[0,"Senden",[0.561869,0.563973,0.106313,0.0646465],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2100,"combo_players",[0,"",[0.248737,0.631313,0.308334,0.0461279],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2401,"",[0,"An die SanitÃ¤ter",[0.248737,0.685185,0.208586,0.0494949],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2404,"admin_send_message_one",[0,"Adminnachricht",[0.367424,0.920875,0.308333,0.052862],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2402,"cops",[0,"An die Ploizei",[0.464646,0.685185,0.208586,0.0494949],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2403,"Send_to_admins",[0,"An die Admins",[0.248737,0.737374,0.208586,0.0494949],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2405,"admin_msg_all",[0,"Adminnachricht",[0.367424,0.87037,0.308333,0.0478115],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1000,"",[0,"",[0.429293,0.989898,0.0684343,0.0814814],[0,0,1,0.5],[0,0,1,0.5],[-1,-1,-1,-1],"","-1"],[]]
]




////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Nuceci)
////////////////////////////////////////////////////////

class bckgrnd: RscPicture
{
    idc = 1200;
    text = "tablet\phone.paa";
    x = -0.0315654;
    y = -0.139731;
    w = 1.04318;
    h = 1.32034;
};
class edit_text_to_send: RscEdit
{
    idc = 1400;
    x = 0.251262;
    y = 0.56734;
    w = 0.305808;
    h = 0.0595961;
    colorBackground[] = {0,0,1,1};
};
class btn_send: RscButtonMenu
{
    idc = 2400;
    text = "Senden"; //--- ToDo: Localize;
    x = 0.561869;
    y = 0.563973;
    w = 0.106313;
    h = 0.0646465;
};
class combo_players: RscCombo
{
    idc = 2100;
    x = 0.248737;
    y = 0.631313;
    w = 0.308334;
    h = 0.0461279;
};
class RscButtonMenu_2401: RscButtonMenu
{
    idc = 2401;
    text = "An die SanitÃ¤ter"; //--- ToDo: Localize;
    x = 0.248737;
    y = 0.685185;
    w = 0.208586;
    h = 0.0494949;
};
class admin_send_message_one: RscButtonMenu
{
    idc = 2404;
    text = "Adminnachricht"; //--- ToDo: Localize;
    x = 0.367424;
    y = 0.920875;
    w = 0.308333;
    h = 0.052862;
};
class cops: RscButtonMenu
{
    idc = 2402;
    text = "An die Ploizei"; //--- ToDo: Localize;
    x = 0.464646;
    y = 0.685185;
    w = 0.208586;
    h = 0.0494949;
};
class Send_to_admins: RscButtonMenu
{
    idc = 2403;
    text = "An die Admins"; //--- ToDo: Localize;
    x = 0.248737;
    y = 0.737374;
    w = 0.208586;
    h = 0.0494949;
};
class admin_msg_all: RscButtonMenu
{
    idc = 2405;
    text = "Adminnachricht"; //--- ToDo: Localize;
    x = 0.367424;
    y = 0.87037;
    w = 0.308333;
    h = 0.0478115;
};
class close_btn: RscText
{
    idc = 1000;
    x = 0.429293;
    y = 0.989898;
    w = 0.0684343;
    h = 0.0814814;
    colorText[] = {0,0,1,0.5};
    colorBackground[] = {0,0,1,0.5};
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////



*/













/*
class Life_cell_phone {
    idd = 3000;
    name= "life_cell_phone";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn life_fnc_cellphone";

    class controlsBackground {
        class Life_RscTitleBackground: Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = 0.1;
            y = 0.2;
            w = 0.64;
            h = (1 / 25);
        };

        class MainBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.64;
            h = 0.3 - (5 / 250);
        };
    };

    class controls {
        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = 3001;
            text = "$STR_CELL_Title";
            x = 0.1;
            y = 0.2;
            w = 0.6;
            h = (1 / 25);
        };

        class TextToSend: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = 3002;
            text = "$STR_CELL_TextToSend";
            x = 0.1;
            y = 0.25;
            w = 0.6;
            h = (1 / 25);
        };

        class textEdit: Life_RscEdit {
            idc = 3003;
            text = "";
            sizeEx = 0.030;
            x = 0.11;
            y = 0.3;
            w = 0.62;
            h = 0.03;
        };

        class TextMsgButton: Life_RscButtonMenu {
            idc = 3015;
            text = "$STR_CELL_TextMSGBtn";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_textmsg";
            x = 0.11;
            y = 0.35;
            w = 0.2;
            h = (1 / 25);
        };

        class PlayerList: Life_RscCombo {
            idc = 3004;
            x = 0.11;
            y = 0.4;
            w = 0.2;
            h = (1 / 25);
        };

        class TextCopButton: Life_RscButtonMenu {
            idc = 3016;
            text = "$STR_CELL_TextPolice";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_textcop";
            x = 0.32;
            y = 0.35;
            w = 0.2;
            h = (1 / 25);
        };

        class TextAdminButton: Life_RscButtonMenu {
            idc = 3017;
            text = "$STR_CELL_TextAdmins";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_textadmin";
            x = 0.53;
            y = 0.35;
            w = 0.2;
            h = (1 / 25);
        };

        class AdminMsgButton: Life_RscButtonMenu {
            idc = 3020;
            text = "$STR_CELL_AdminMsg";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_adminmsg";
            x = 0.32;
            y = 0.4;
            w = 0.2;
            h = (1 / 25);
        };

        class AdminMsgAllButton: Life_RscButtonMenu {
            idc = 3021;
            text = "$STR_CELL_AdminMSGAll";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_adminmsgall";
            x = 0.53;
            y = 0.4;
            w = 0.2;
            h = (1 / 25);
        };

        class EMSRequest: Life_RscButtonMenu {
            idc = 3022;
            text = "$STR_CELL_EMSRequest";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call TON_fnc_cell_emsrequest";
            x = 0.11;
            y = 0.45;
            w = 0.2;
            h = (1 / 25);
        };

        class CloseButtonKey: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = -0.06 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.51 + (1 / 50);
            w = (6.25 / 40);
            h = (1 / 25);
        };
    };
};
*/