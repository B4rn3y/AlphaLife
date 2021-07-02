class tuning {
    idd = 57742;
    name= "tuning";
    movingEnable = 1;
    enableSimulation = 1;

    class controlsBackground {

        class bckgrnd: Life_RscText
        {
            idc = 1000;
            colorBackground[] = {0, 0, 0, 0.7};
            x = 0.0387894 * safezoneW + safezoneX;
            y = 0.100778 * safezoneH + safezoneY;
            w = 0.200078 * safezoneW;
            h = 0.687407 * safezoneH;
        };

        class header: Life_RscText
        {
            idc = 1001;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            x = 0.0390623 * safezoneW + safezoneX;
            y = 0.075 * safezoneH + safezoneY;
            w = 0.199688 * safezoneW;
            h = 0.0272221 * safezoneH;
        };
    };

    class controls {

        class RscListbox_1500: life_RscListbox
        {
            idc = 1500;
            sizeEx = 0.035;
            onLBSelChanged = "[_this] call life_fnc_tuning_shop_lb_EVH;";
            x = 0.0402345 * safezoneW + safezoneX;
            y = 0.104629 * safezoneH + safezoneY;
            w = 0.196563 * safezoneW;
            h = 0.592963 * safezoneH;
        };
        class RscCombo_2100: life_RscCombo
        {
            idc = 2100;
            onLBSelChanged = "[_this] call life_fnc_tuning_shop_combo_EVH;";
            x = 0.040234 * safezoneW + safezoneX;
            y = 0.699074 * safezoneH + safezoneY;
            w = 0.196563 * safezoneW;
            h = 0.0272222 * safezoneH;
        };
        class buy: life_RscButtonMenu
        {
            idc = 2400;
            text = "Kaufen";
            onButtonClick="[] spawn life_fnc_tuning_shop_buy;";
            x = 0.040234 * safezoneW + safezoneX;
            y = 0.726852 * safezoneH + safezoneY;
            w = 0.196562 * safezoneW;
            h = 0.0281482 * safezoneH;
        };
        class RscButtonMenu_2401: life_RscButtonMenu
        {
            idc = 2401;
            text = "Close";
            onButtonClick = "closeDialog 0; ";
            x = 0.0402345 * safezoneW + safezoneX;
            y = 0.755556 * safezoneH + safezoneY;
            w = 0.196562 * safezoneW;
            h = 0.0281482 * safezoneH;
        };

    };
};



/* #Jikigy
$[
    1.063,
    ["t",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1000,"bckgrnd",[1,"",["0.0387894 * safezoneW + safezoneX","0.100778 * safezoneH + safezoneY","0.200078 * safezoneW","0.687407 * safezoneH"],[-1,-1,-1,-1],[0,0,1,0.7],[-1,-1,-1,-1],"","-1"],[]],
    [1500,"",[1,"",["0.0402345 * safezoneW + safezoneX","0.104629 * safezoneH + safezoneY","0.196563 * safezoneW","0.592963 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2100,"",[1,"",["0.040234 * safezoneW + safezoneX","0.699074 * safezoneH + safezoneY","0.196563 * safezoneW","0.0272222 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"buy",[1,"",["0.040234 * safezoneW + safezoneX","0.726852 * safezoneH + safezoneY","0.196562 * safezoneW","0.0281482 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2401,"",[1,"",["0.0402345 * safezoneW + safezoneX","0.755556 * safezoneH + safezoneY","0.196562 * safezoneW","0.0281482 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"header",[1,"",["0.0390623 * safezoneW + safezoneX","0.075 * safezoneH + safezoneY","0.199688 * safezoneW","0.0272221 * safezoneH"],[-1,-1,-1,-1],[0,1,1,1],[-1,-1,-1,-1],"","-1"],[]]
]




////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Jikigy)
////////////////////////////////////////////////////////

class bckgrnd: RscText
{
    idc = 1000;
    x = 0.0387894 * safezoneW + safezoneX;
    y = 0.100778 * safezoneH + safezoneY;
    w = 0.200078 * safezoneW;
    h = 0.687407 * safezoneH;
    colorBackground[] = {0,0,1,0.7};
};

class header: RscText
{
    idc = 1001;
    x = 0.0390623 * safezoneW + safezoneX;
    y = 0.075 * safezoneH + safezoneY;
    w = 0.199688 * safezoneW;
    h = 0.0272221 * safezoneH;
    colorBackground[] = {0,1,1,1};
};
class RscListbox_1500: RscListbox
{
    idc = 1500;
    x = 0.0402345 * safezoneW + safezoneX;
    y = 0.104629 * safezoneH + safezoneY;
    w = 0.196563 * safezoneW;
    h = 0.592963 * safezoneH;
};
class RscCombo_2100: RscCombo
{
    idc = 2100;
    x = 0.040234 * safezoneW + safezoneX;
    y = 0.699074 * safezoneH + safezoneY;
    w = 0.196563 * safezoneW;
    h = 0.0272222 * safezoneH;
};
class buy: RscButtonMenu
{
    idc = 2400;
    x = 0.040234 * safezoneW + safezoneX;
    y = 0.726852 * safezoneH + safezoneY;
    w = 0.196562 * safezoneW;
    h = 0.0281482 * safezoneH;
};
class RscButtonMenu_2401: RscButtonMenu
{
    idc = 2401;
    x = 0.0402345 * safezoneW + safezoneX;
    y = 0.755556 * safezoneH + safezoneY;
    w = 0.196562 * safezoneW;
    h = 0.0281482 * safezoneH;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////




*/

