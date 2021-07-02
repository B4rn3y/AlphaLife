


class hud_veh {
    idd = -1;
    duration = 10e10;
    movingEnable = 0;
    fadein = 0;
    fadeout = 0;
    name = "hud_veh";
    onLoad = "uiNamespace setVariable ['hud_veh',_this select 0]";
    objects[] = {};

    class controlsBackground
    {

        class RscStructuredText_1103: life_RscStructuredText
        {
            idc = 1100;
            text = "";
            x = 0.83414 * safezoneW + safezoneX;
            y = 0.706333 * safezoneH + safezoneY;
            w = 0.112969 * safezoneW;
            h = 0.191111 * safezoneH;
        };
    };
};


/* #Jiruxy
$[
    1.063,
    ["Tablet",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1103,"",[1,"",["0.83414 * safezoneW + safezoneX","0.638481 * safezoneH + safezoneY","0.112969 * safezoneW","0.191111 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]




////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Jiruxy)
////////////////////////////////////////////////////////


class RscStructuredText_1103: RscStructuredText
{
    idc = 1103;
    x = 0.83414 * safezoneW + safezoneX;
    y = 0.638481 * safezoneH + safezoneY;
    w = 0.112969 * safezoneW;
    h = 0.191111 * safezoneH;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////

*/


