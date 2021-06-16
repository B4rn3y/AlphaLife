class SettingsMenu {
    idd = 2900;
    name = "SettingsMenu";
    movingEnable = 1;
    enableSimulation = 1;

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

        class PlayerTagsHeader: Life_RscText {
            idc = -1;
            text = "$STR_SM_PlayerTags";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            x = 0.670454;
            y = 0.202021;
            w = 0.225;
            h = 0.0419866;
        };

        class BroacastHeader : PlayerTagsHeader {
            idc = -1;
            text = "$STR_SM_BCSW";

            x = 0.670455;
            y = 0.255892;
            w = 0.225;
            h = 0.0419866;

        };

        class RevealNearestHeader : PlayerTagsHeader {
            idc = -1;
            text = "$STR_SM_RNObj";
            x = 0.670454;
            y = 0.311448;
            w = 0.225;
            h = 0.0419866;
        };

/*
        class SideChatHeader : PlayerTagsHeader {
            idc = -1;
            text = "$STR_SM_SC";
            x = 0.670455;
            y = 0.36532;
            w = 0.225;
            h = 0.0419866;
        };
        */

/*
        class Title: Life_RscTitle {
            idc = -1;
            colorBackground[] = {0,0,0,0};
            text = "$STR_SM_Title";
            x = 0.102272;
            y = 0.136363;
            w = 0.276768;
            h = 0.0478114;
        };
        */


        class close_picture: life_RscPicture
        {
            idc = -1;
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
        class VDonFoot: Life_RscText {
            idc = -1;
            text = "$STR_SM_onFoot";
            x = 0.106;
            y = 0.2036;
            w = 0.111364;
            h = 0.0478114;
        };

        class VDinCar: Life_RscText {
            idc = -1;
            text = "$STR_SM_inCar";
            x = 0.105975;
            y = 0.264382;
            w = 0.111364;
            h = 0.0444444;
        };

        class VDinAir: Life_RscText {
            idc = -1;
            text = "$STR_SM_inAir";
            x = 0.10606;
            y = 0.324915;
            w = 0.111364;
            h = 0.0444444;
        };

        class VD_onfoot_slider: life_RscXSliderH {
            idc = 2901;
            text = "";
            onSliderPosChanged = "[0,_this select 1] call life_fnc_s_onSliderChange;";
            tooltip = "$STR_SM_ToolTip1";
            x = 0.231061;
            y = 0.210438;
            w = 0.294444;
            h = 0.0360269;
        };

        class VD_onfoot_value: Life_RscEdit {
            idc = 2902;
            text = "";
            onChar = "[_this select 0, _this select 1,'ground',false] call life_fnc_s_onChar;";
            onKeyUp = "[_this select 0, _this select 1,'ground',true] call life_fnc_s_onChar;";
            x = 0.542929;
            y = 0.20202;
            w = 0.10505;
            h = 0.0511785;
        };

        class VD_car_slider: life_RscXSliderH {
            idc = 2911;
            text = "";
            onSliderPosChanged = "[1,_this select 1] call life_fnc_s_onSliderChange;";
            tooltip = "$STR_SM_ToolTip2";
            x = 0.231061;
            y = 0.26936;
            w = 0.294444;
            h = 0.0360269;
        };

        class VD_car_value: Life_RscEdit {
            idc = 2912;
            text = "";
            onChar = "[_this select 0, _this select 1,'vehicle',false] call life_fnc_s_onChar;";
            onKeyUp = "[_this select 0, _this select 1,'vehicle',true] call life_fnc_s_onChar;";
            x = 0.542929;
            y = 0.262626;
            w = 0.10505;
            h = 0.0511785;
        };

        class VD_air_slider: life_RscXSliderH {
            idc = 2921;
            text = "";
            onSliderPosChanged = "[2,_this select 1] call life_fnc_s_onSliderChange;";
            tooltip = "$STR_SM_ToolTip3";
            x = 0.229798;
            y = 0.33165;
            w = 0.294444;
            h = 0.0360269;
        };

        class VD_air_value: Life_RscEdit {
            idc = 2922;
            text = "";
            onChar = "[_this select 0, _this select 1,'air',false] call life_fnc_s_onChar;";
            onKeyUp = "[_this select 0, _this select 1,'air',true] call life_fnc_s_onChar;";
            x = 0.542929;
            y = 0.323232;
            w = 0.10505;
            h = 0.0511785;
        };

        class PlayerTagsONOFF: Life_RscActiveText {
            tooltip = "$STR_GUI_PlayTags";
            idc = 2970;
            sizeEx = 0.04;
            // onCheckedChanged = "['tags',_this select 1] call life_fnc_s_onCheckedChange;";
            x = 0.909091;
            y = 0.20202;
            w = 0.0684345;
            h = 0.0436701;

        };

        class BroadcastONOFF: PlayerTagsONOFF {
            idc = 2973;
            tooltip = "$STR_GUI_BroadcastSwitch";
            // onCheckedChanged = "['sidechat',_this select 1] call life_fnc_s_onCheckedChange;";
            x = 0.909091;
            y = 0.255892;
            w = 0.0684345;
            h = 0.0436701;
        };

        class RevealONOFF : PlayerTagsONOFF {
            idc = 2972;
            tooltip = "$STR_GUI_PlayerReveal";
            //onCheckedChanged = "['objects',_this select 1] call life_fnc_s_onCheckedChange;";
            x = 0.909091;
            y = 0.311448;
            w = 0.0684345;
            h = 0.0436701;
        };
/*
        class SideChannelOnOFF : PlayerTagsONOFF {
            idc = 2971;
            tooltip = "$STR_GUI_SideSwitch";
            //onCheckedChanged = "['broadcast',_this select 1] call life_fnc_s_onCheckedChange;";
            x = 0.909091;
            y = 0.36532;
            w = 0.0684345;
            h = 0.0436701;
        };
*/
        class ButtonClose: life_RscButtonSilent {
            idc = -1;
            //shortcuts[] = {0x00050000 + 2};
            tooltip = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = 0.094697;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
        };

        class your_pid_header: life_RscText
        {
            idc = -1;
            text = "Deine PID:"; //--- ToDo: Localize;
            x = 0.10101;
            y = 0.405724;
            w = 0.190909;
            h = 0.039394;
        };
        class edit_your_pid: life_RscEdit
        {
            idc = 1780;
            text = "";
            tooltip = "Nutze diese PID für jede Anfrage an den Support. Kopieren mit STRG + A gefolgt von STRG + C";
            x = 0.106313;
            y = 0.457508;
            w = 0.27298;
            h = 0.0663299;
        };
    };
};



/* #Vijopo
$[
    1.063,
    ["Tablet",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1000,"header",[0,"Einstellungen:",[0.102272,0.136363,0.276768,0.0478114],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1200,"tablet",[0,"tablet.paa",[-0.0195705,-0.104647,1.08561,1.18714],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"",[0,"Zu FuÃŸ",[0.106,0.2036,0.111364,0.0478114],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1002,"",[0,"Im Auto",[0.105975,0.264382,0.111364,0.0444444],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1003,"",[0,"Im Himmel",[0.10606,0.324915,0.111364,0.0444444],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1900,"slider_fuss",[0,"",[0.231061,0.210438,0.294444,0.0360269],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1901,"slider_auto",[0,"",[0.231061,0.26936,0.294444,0.0360269],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1902,"slider_air",[0,"",[0.229798,0.33165,0.294444,0.0360269],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1401,"edit_car",[0,"",[0.542929,0.262626,0.10505,0.0511785],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1402,"edit_air",[0,"",[0.542929,0.323232,0.10505,0.0511785],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1400,"edit_foot",[0,"",[0.542929,0.20202,0.10505,0.0511785],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1004,"player_name_header",[0,"Spielernamen:",[0.670454,0.202021,0.225,0.0419866],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1005,"sidechat_header",[0,"Sidechat umschalten:",[0.670455,0.255892,0.225,0.0419866],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1006,"near_objects_header",[0,"Nahe Objekte anzeigen:",[0.670454,0.311448,0.225,0.0419866],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1007,"broadcast_header",[0,"Broadcast umschalten:",[0.670455,0.36532,0.225,0.0419866],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1008,"on_OFF_playername",[0,"OFF",[0.909091,0.20202,0.0684345,0.0436701],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1009,"on_off_sidechat",[0,"OFF",[0.909091,0.255892,0.0684345,0.0436701],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1010,"on_off_objects",[0,"OFF",[0.909091,0.311448,0.0684345,0.0436701],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1011,"on_off_broadcast",[0,"OFF",[0.909091,0.36532,0.0684345,0.0436701],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1012,"your_pid_header",[0,"Deine PID:",[0.10101,0.405724,0.190909,0.039394],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1403,"edit_your_pid",[0,"",[0.106313,0.457508,0.27298,0.0663299],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1201,"",[0,"tablet\close.paa",[0.0823232,0.724849,0.0785353,0.0932661],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]


////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Vijopo)
////////////////////////////////////////////////////////

class header: RscText
{
    idc = 1000;
    text = "Einstellungen:"; //--- ToDo: Localize;
    x = 0.102272;
    y = 0.136363;
    w = 0.276768;
    h = 0.0478114;
};
class tablet: RscPicture
{
    idc = 1200;
    text = "tablet.paa";
    x = -0.0195705;
    y = -0.104647;
    w = 1.08561;
    h = 1.18714;
};
class RscText_1001: RscText
{
    idc = 1001;
    text = "Zu FuÃŸ"; //--- ToDo: Localize;
    x = 0.106;
    y = 0.2036;
    w = 0.111364;
    h = 0.0478114;
    colorBackground[] = {0,0,0,0.5};
};
class RscText_1002: RscText
{
    idc = 1002;
    text = "Im Auto"; //--- ToDo: Localize;
    x = 0.105975;
    y = 0.264382;
    w = 0.111364;
    h = 0.0444444;
    colorBackground[] = {0,0,0,0.5};
};
class RscText_1003: RscText
{
    idc = 1003;
    text = "Im Himmel"; //--- ToDo: Localize;
    x = 0.10606;
    y = 0.324915;
    w = 0.111364;
    h = 0.0444444;
    colorBackground[] = {0,0,0,0.5};
};
class slider_fuss: RscSlider
{
    idc = 1900;
    x = 0.231061;
    y = 0.210438;
    w = 0.294444;
    h = 0.0360269;
    colorBackground[] = {0,0,0,0.5};
};
class slider_auto: RscSlider
{
    idc = 1901;
    x = 0.231061;
    y = 0.26936;
    w = 0.294444;
    h = 0.0360269;
};
class slider_air: RscSlider
{
    idc = 1902;
    x = 0.229798;
    y = 0.33165;
    w = 0.294444;
    h = 0.0360269;
};
class edit_car: RscEdit
{
    idc = 1401;
    x = 0.542929;
    y = 0.262626;
    w = 0.10505;
    h = 0.0511785;
    colorBackground[] = {0,0,0,0.5};
};
class edit_air: RscEdit
{
    idc = 1402;
    x = 0.542929;
    y = 0.323232;
    w = 0.10505;
    h = 0.0511785;
    colorBackground[] = {0,0,0,0.5};
};
class edit_foot: RscEdit
{
    idc = 1400;
    x = 0.542929;
    y = 0.20202;
    w = 0.10505;
    h = 0.0511785;
    colorBackground[] = {0,0,0,0.5};
};
class player_name_header: RscText
{
    idc = 1004;
    text = "Spielernamen:"; //--- ToDo: Localize;
    x = 0.670454;
    y = 0.202021;
    w = 0.225;
    h = 0.0419866;
    colorBackground[] = {0,0,0,0.5};
};
class sidechat_header: RscText
{
    idc = 1005;
    text = "Sidechat umschalten:"; //--- ToDo: Localize;
    x = 0.670455;
    y = 0.255892;
    w = 0.225;
    h = 0.0419866;
    colorBackground[] = {0,0,0,0.5};
};
class near_objects_header: RscText
{
    idc = 1006;
    text = "Nahe Objekte anzeigen:"; //--- ToDo: Localize;
    x = 0.670454;
    y = 0.311448;
    w = 0.225;
    h = 0.0419866;
    colorBackground[] = {0,0,0,0.5};
};
class broadcast_header: RscText
{
    idc = 1007;
    text = "Broadcast umschalten:"; //--- ToDo: Localize;
    x = 0.670455;
    y = 0.36532;
    w = 0.225;
    h = 0.0419866;
    colorBackground[] = {0,0,0,0.5};
};
class on_OFF_playername: RscText
{
    idc = 1008;
    text = "OFF"; //--- ToDo: Localize;
    x = 0.909091;
    y = 0.20202;
    w = 0.0684345;
    h = 0.0436701;
    colorBackground[] = {0,0,0,0.5};
};
class on_off_sidechat: RscText
{
    idc = 1009;
    text = "OFF"; //--- ToDo: Localize;
    x = 0.909091;
    y = 0.255892;
    w = 0.0684345;
    h = 0.0436701;
    colorBackground[] = {0,0,0,0.5};
};
class on_off_objects: RscText
{
    idc = 1010;
    text = "OFF"; //--- ToDo: Localize;
    x = 0.909091;
    y = 0.311448;
    w = 0.0684345;
    h = 0.0436701;
    colorBackground[] = {0,0,0,0.5};
};
class on_off_broadcast: RscText
{
    idc = 1011;
    text = "OFF"; //--- ToDo: Localize;
    x = 0.909091;
    y = 0.36532;
    w = 0.0684345;
    h = 0.0436701;
    colorBackground[] = {0,0,0,0.5};
};
class your_pid_header: RscText
{
    idc = 1012;
    text = "Deine PID:"; //--- ToDo: Localize;
    x = 0.10101;
    y = 0.405724;
    w = 0.190909;
    h = 0.039394;
};
class edit_your_pid: RscEdit
{
    idc = 1403;
    x = 0.106313;
    y = 0.457508;
    w = 0.27298;
    h = 0.0663299;
    colorBackground[] = {0,0,0,0.5};
};
class RscPicture_1201: RscPicture
{
    idc = 1201;
    text = "tablet\close.paa";
    x = 0.0823232;
    y = 0.724849;
    w = 0.0785353;
    h = 0.0932661;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////

*/
