class life_spawn_selection {
    idd = 38500;
    movingEnable = 0;
    enableSimulation = 1;

    class controlsBackground {
        class life_RscTitleBackground: Life_RscText    {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            text = "$STR_Spawn_Title";
            x = 0.0390623 * safezoneW + safezoneX;
            y = 0.075 * safezoneH + safezoneY;
            w = 0.199688 * safezoneW;
            h = 0.0272221 * safezoneH;
        };

        class MainBackground: Life_RscText {
            colorBackground[] = {0,0,0,0.7};
            idc = -1;
            x = 0.0387894 * safezoneW + safezoneX;
            y = 0.100778 * safezoneH + safezoneY;
            w = 0.200078 * safezoneW;
            h = 0.629073 * safezoneH;
        };
    };

    class controls {
        class SpawnPointList: Life_RscListNBox {
            idc = 38510;
            text = "";
            sizeEx = 0.041;
            coloumns[] = {0,0,0.9};
            drawSideArrows = 0;
            idcLeft = -1;
            idcRight = -1;
            rowHeight = 0.050;
            x = 0.0402345 * safezoneW + safezoneX;
            y = 0.104629 * safezoneH + safezoneY;
            w = 0.196563 * safezoneW;
            h = 0.592963 * safezoneH;
            onLBSelChanged = "_this spawn life_fnc_spawnPointSelected;";
        };

        class spawnButton: Life_RscButtonMenu {
            idc = 7755;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            text = "$STR_Spawn_Spawn";
            onButtonClick = "[] call life_fnc_spawnConfirm";
            x = 0.040234 * safezoneW + safezoneX;
            y = 0.699074 * safezoneH + safezoneY;
            w = 0.196562 * safezoneW;
            h = 0.0281482 * safezoneH;
        };
    };
};





/* #Nuguma
$[
    1.063,
    ["t",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1000,"bckgrnd_left",[1,"",["0.0387894 * safezoneW + safezoneX","0.100778 * safezoneH + safezoneY","0.200078 * safezoneW","0.629073 * safezoneH"],[-1,-1,-1,-1],[0,0,1,0.7],[-1,-1,-1,-1],"","-1"],[]],
    [1500,"listbox_my_vehicles",[1,"",["0.0402345 * safezoneW + safezoneX","0.104629 * safezoneH + safezoneY","0.196563 * safezoneW","0.592963 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"unimpound",[1,"",["0.040234 * safezoneW + safezoneX","0.699074 * safezoneH + safezoneY","0.196562 * safezoneW","0.0281482 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"left_header",[1,"",["0.0390623 * safezoneW + safezoneX","0.075 * safezoneH + safezoneY","0.199688 * safezoneW","0.0272221 * safezoneH"],[-1,-1,-1,-1],[0,1,1,1],[-1,-1,-1,-1],"","-1"],[]]
]
*/



/*

////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Nuguma)
////////////////////////////////////////////////////////

class bckgrnd_left: RscText
{
    idc = 1000;
    x = 0.0387894 * safezoneW + safezoneX;
    y = 0.100778 * safezoneH + safezoneY;
    w = 0.200078 * safezoneW;
    h = 0.629073 * safezoneH;
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
class unimpound: RscButtonMenu
{
    idc = 2400;
    x = 0.040234 * safezoneW + safezoneX;
    y = 0.699074 * safezoneH + safezoneY;
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
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////


*/