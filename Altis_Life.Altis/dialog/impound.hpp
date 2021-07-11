class Life_impound_menu {
    idd = 2800;
    name="life_vehicle_shop";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "";

    class controlsBackground {

        class MainBackground_left: Life_RscText {
            colorBackground[] = {0,0,0,0.7};
            idc = -1;
            x = 0.0387894 * safezoneW + safezoneX;
            y = 0.100778 * safezoneH + safezoneY;
            w = 0.200078 * safezoneW;
            h = 0.744814 * safezoneH;
        };

        class VehicleTitleBox: Life_RscText {
            idc = -1;
            text = "$STR_GUI_YourVeh";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            x = 0.0390623 * safezoneW + safezoneX;
            y = 0.075 * safezoneH + safezoneY;
            w = 0.199688 * safezoneW;
            h = 0.0272221 * safezoneH;
        };

        class right_background: Life_RscText {
            colorBackground[] = {0,0,0,0.7};
            idc = 2810;
            x = 0.800389 * safezoneW + safezoneX;
            y = 0.0287037 * safezoneH + safezoneY;
            w = 0.199298 * safezoneW;
            h = 0.338333 * safezoneH;
        };

        class VehicleInfoHeader: Life_RscText {
            idc = 2830;
            text = "$STR_GUI_VehInfo";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            x = 0.80039 * safezoneW + safezoneX;
            y = 0.000925747 * safezoneH + safezoneY;
            w = 0.199688 * safezoneW;
            h = 0.0272221 * safezoneH;
        };

        class CloseBtn: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = 0.040234 * safezoneW + safezoneX;
            y = 0.812963 * safezoneH + safezoneY;
            w = 0.196562 * safezoneW;
            h = 0.0281482 * safezoneH;
        };

        class RetrieveCar: Life_RscButtonMenu {
            idc = 5213;
            text = "$STR_Global_Retrieve";
            onButtonClick = "[] call life_fnc_unimpound;";
            x = 0.040234 * safezoneW + safezoneX;
            y = 0.726852 * safezoneH + safezoneY;
            w = 0.196562 * safezoneW;
            h = 0.0281482 * safezoneH;
        };

        class SellCar: Life_RscButtonMenu {
            idc = 7845;
            text = "$STR_Global_Sell";
            onButtonClick = "[] call life_fnc_sellGarage; closeDialog 0;";
            x = 0.0402345 * safezoneW + safezoneX;
            y = 0.784259 * safezoneH + safezoneY;
            w = 0.196562 * safezoneW;
            h = 0.0281482 * safezoneH;
        };

        class InsureCar : life_RscButtonMenu
        {
            idc = 97480;
            text = "$STR_Global_Insure";
            onButtonClick = "[] spawn life_fnc_insureCar; ";
            x = 0.0402345 * safezoneW + safezoneX;
            y = 0.755556 * safezoneH + safezoneY;
            w = 0.196562 * safezoneW;
            h = 0.0281482 * safezoneH;
        };

        class gang: life_RscButtonMenu
        {
            idc = 2404;
            text = "$STR_gang_garage_add";
            x = 0.801953 * safezoneW + safezoneX;
            y = 0.336111 * safezoneH + safezoneY;
            w = 0.196562 * safezoneW;
            h = 0.0281482 * safezoneH;
        };


    };

    class controls {
        class VehicleList: Life_RscListBox {
            idc = 2802;
            text = "";
            sizeEx = 0.04;
            colorBackground[] = {0.1,0.1,0.1,0.9};
            onLBSelChanged = "_this spawn life_fnc_garageLBChange;";
            x = 0.0402345 * safezoneW + safezoneX;
            y = 0.104629 * safezoneH + safezoneY;
            w = 0.196563 * safezoneW;
            h = 0.592963 * safezoneH;
        };

        class combo_vehicles: life_RscCombo
        {
            idc = 2100;
            onLBSelChanged = "_this spawn life_fnc_garageComboChange;";
            x = 0.040234 * safezoneW + safezoneX;
            y = 0.699074 * safezoneH + safezoneY;
            w = 0.196563 * safezoneW;
            h = 0.0272222 * safezoneH;
        };

        class vehicleInfomationList: Life_RscStructuredText {
            idc = 2803;
            text = "";
            sizeEx = 0.035;
            x = 0.802734 * safezoneW + safezoneX;
            y = 0.0305552 * safezoneH + safezoneY;
            w = 0.195391 * safezoneW;
            h = 0.302222 * safezoneH;
        };
    };
};






/* #Gizuly
$[
    1.063,
    ["t",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1000,"bckgrnd_left",[1,"",["0.0387894 * safezoneW + safezoneX","0.100778 * safezoneH + safezoneY","0.200078 * safezoneW","0.744814 * safezoneH"],[-1,-1,-1,-1],[0,0,1,0.7],[-1,-1,-1,-1],"","-1"],[]],
    [1500,"listbox_my_vehicles",[1,"",["0.0402345 * safezoneW + safezoneX","0.104629 * safezoneH + safezoneY","0.196563 * safezoneW","0.592963 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2100,"combo_vehicles",[1,"",["0.040234 * safezoneW + safezoneX","0.699074 * safezoneH + safezoneY","0.196563 * safezoneW","0.0272222 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"unimpound",[1,"",["0.040234 * safezoneW + safezoneX","0.726852 * safezoneH + safezoneY","0.196562 * safezoneW","0.0281482 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2401,"insure",[1,"",["0.0402345 * safezoneW + safezoneX","0.755556 * safezoneH + safezoneY","0.196562 * safezoneW","0.0281482 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"left_header",[1,"",["0.0390623 * safezoneW + safezoneX","0.075 * safezoneH + safezoneY","0.199688 * safezoneW","0.0272221 * safezoneH"],[-1,-1,-1,-1],[0,1,1,1],[-1,-1,-1,-1],"","-1"],[]],
    [2402,"sell",[1,"",["0.0402345 * safezoneW + safezoneX","0.784259 * safezoneH + safezoneY","0.196562 * safezoneW","0.0281482 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2403,"close",[1,"",["0.040234 * safezoneW + safezoneX","0.812963 * safezoneH + safezoneY","0.196562 * safezoneW","0.0281482 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1002,"",[1,"",["0.800389 * safezoneW + safezoneX","0.0287037 * safezoneH + safezoneY","0.199298 * safezoneW","0.338333 * safezoneH"],[-1,-1,-1,-1],[0,0,1,0.7],[-1,-1,-1,-1],"","-1"],[]],
    [1100,"",[1,"",["0.802734 * safezoneW + safezoneX","0.0305552 * safezoneH + safezoneY","0.195391 * safezoneW","0.302222 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1003,"header_right",[1,"",["0.80039 * safezoneW + safezoneX","0.000925747 * safezoneH + safezoneY","0.199688 * safezoneW","0.0272221 * safezoneH"],[-1,-1,-1,-1],[0,1,1,1],[-1,-1,-1,-1],"","-1"],[]],
    [2404,"gang",[1,"",["0.801953 * safezoneW + safezoneX","0.336111 * safezoneH + safezoneY","0.196562 * safezoneW","0.0281482 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/


/*

////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Gizuly)
////////////////////////////////////////////////////////

class bckgrnd_left: RscText
{
    idc = 1000;
    x = 0.0387894 * safezoneW + safezoneX;
    y = 0.100778 * safezoneH + safezoneY;
    w = 0.200078 * safezoneW;
    h = 0.744814 * safezoneH;
    colorBackground[] = {0,0,1,0.7};
};
class listbox_my_vehicles: RscListbox
{
    idc = 1500;
    x = 0.0402345 * safezoneW + safezoneX;
    y = 0.104629 * safezoneH + safezoneY;
    w = 0.196563 * safezoneW;
    h = 0.592963 * safezoneH;
};
class combo_vehicles: RscCombo
{
    idc = 2100;
    x = 0.040234 * safezoneW + safezoneX;
    y = 0.699074 * safezoneH + safezoneY;
    w = 0.196563 * safezoneW;
    h = 0.0272222 * safezoneH;
};
class unimpound: RscButtonMenu
{
    idc = 2400;
    x = 0.040234 * safezoneW + safezoneX;
    y = 0.726852 * safezoneH + safezoneY;
    w = 0.196562 * safezoneW;
    h = 0.0281482 * safezoneH;
};
class insure: RscButtonMenu
{
    idc = 2401;
    x = 0.0402345 * safezoneW + safezoneX;
    y = 0.755556 * safezoneH + safezoneY;
    w = 0.196562 * safezoneW;
    h = 0.0281482 * safezoneH;
};
class left_header: RscText
{
    idc = 1001;
    x = 0.0390623 * safezoneW + safezoneX;
    y = 0.075 * safezoneH + safezoneY;
    w = 0.199688 * safezoneW;
    h = 0.0272221 * safezoneH;
    colorBackground[] = {0,1,1,1};
};
class sell: RscButtonMenu
{
    idc = 2402;
    x = 0.0402345 * safezoneW + safezoneX;
    y = 0.784259 * safezoneH + safezoneY;
    w = 0.196562 * safezoneW;
    h = 0.0281482 * safezoneH;
};
class close: RscButtonMenu
{
    idc = 2403;
    x = 0.040234 * safezoneW + safezoneX;
    y = 0.812963 * safezoneH + safezoneY;
    w = 0.196562 * safezoneW;
    h = 0.0281482 * safezoneH;
};
class RscText_1002: RscText
{
    idc = 1002;
    x = 0.800389 * safezoneW + safezoneX;
    y = 0.0287037 * safezoneH + safezoneY;
    w = 0.199298 * safezoneW;
    h = 0.338333 * safezoneH;
    colorBackground[] = {0,0,1,0.7};
};
class RscStructuredText_1100: RscStructuredText
{
    idc = 1100;
    x = 0.802734 * safezoneW + safezoneX;
    y = 0.0305552 * safezoneH + safezoneY;
    w = 0.195391 * safezoneW;
    h = 0.302222 * safezoneH;
};
class header_right: RscText
{
    idc = 1003;
    x = 0.80039 * safezoneW + safezoneX;
    y = 0.000925747 * safezoneH + safezoneY;
    w = 0.199688 * safezoneW;
    h = 0.0272221 * safezoneH;
    colorBackground[] = {0,1,1,1};
};
class gang: RscButtonMenu
{
    idc = 2404;
    x = 0.801953 * safezoneW + safezoneX;
    y = 0.336111 * safezoneH + safezoneY;
    w = 0.196562 * safezoneW;
    h = 0.0281482 * safezoneH;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////


*/