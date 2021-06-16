#define ST_CENTER         0x02


class playerHUD {
    idd = -1;
    duration = 10e10;
    movingEnable = 0;
    fadein = 0;
    fadeout = 0;
    name = "playerHUD";
    onLoad = "uiNamespace setVariable ['playerHUD',_this select 0]";
    objects[] = {};

    class controlsBackground
    {

        class LIFE_BAR_Speaker: Life_RscPicture
        {
            idc = 3000;
            text = "textures\HUD\earplugs.paa";
            x = 0.952292 * safezoneW + safezoneX;
            y = 0.640333 * safezoneH + safezoneY;
            w = 0.0331042 * safezoneW;
            h = 0.0589743 * safezoneH;
        };

        class LIFE_BAR_HEALTH_RING: Life_RscProgress
        {
            idc = 3200;
            text = "";
            texture = "textures\HUD\health_full.paa";
            style = 1;
            colorFrame[] = {0, 0, 0, 0};
            colorBar[] = {1,1,1,1};
            x = 0.952292 * safezoneW + safezoneX;
            y = 0.706333 * safezoneH + safezoneY;
            w = 0.0331042 * safezoneW;
            h = 0.0589743 * safezoneH;
        };
        class LIFE_BAR_HEALTH_RING_empty: Life_RscProgress
        {
            idc = 3201;
            text = "";
            texture = "textures\HUD\health_empty.paa";
            style = 1;
            colorFrame[] = {0, 0, 0, 0};
            colorBar[] = {1,1,1,1};
            x = 0.952292 * safezoneW + safezoneX;
            y = 0.706333 * safezoneH + safezoneY;
            w = 0.0331042 * safezoneW;
            h = 0.0589743 * safezoneH;
        };
        class LIFE_BAR_FOOD_RING: Life_RscProgress
        {
            idc = 3202;
            text = "";
            colorFrame[] = {0, 0, 0, 0};
            colorBar[] = {1,1,1,1};
            texture = "textures\HUD\food_full.paa";
            style = 1;
            x = 0.952292 * safezoneW + safezoneX;
            y = 0.772333 * safezoneH + safezoneY;
            w = 0.0331042 * safezoneW;
            h = 0.0589743 * safezoneH;
        };

        class LIFE_BAR_FOOD_RING_empty: Life_RscProgress
        {
            idc = 3203;
            text = "";
            colorFrame[] = {0, 0, 0, 0};
            colorBar[] = {1,1,1,1};
            texture = "textures\HUD\food_empty.paa";
            style = 1;
            x = 0.952292 * safezoneW + safezoneX;
            y = 0.772333 * safezoneH + safezoneY;
            w = 0.0331042 * safezoneW;
            h = 0.0589743 * safezoneH;
        };
        class LIFE_BAR_WATER_RING: Life_RscProgress
        {
            idc = 3204;
            text = "";
            colorFrame[] = {0, 0, 0, 0};
            colorBar[] = {1,1,1,1};
            texture = "textures\HUD\water_full.paa";
            style = 1;
            x = 0.952292 * safezoneW + safezoneX;
            y = 0.838333 * safezoneH + safezoneY;
            w = 0.0331042 * safezoneW;
            h = 0.0589743 * safezoneH;
        };
        class LIFE_BAR_WATER_RING_empty: Life_RscProgress
        {
            idc = 3205;
            text = "";
            colorFrame[] = {0, 0, 0, 0};
            colorBar[] = {1,1,1,1};
            texture = "textures\HUD\water_empty.paa";
            style = 1;
            x = 0.952292 * safezoneW + safezoneX;
            y = 0.838333 * safezoneH + safezoneY;
            w = 0.0331042 * safezoneW;
            h = 0.0589743 * safezoneH;
        };

        class uptime_pic: life_RscPicture
        {
            idc = 1200;
            text = "textures\HUD\serveruptime.paa";
            x = 0.958984 * safezoneW + safezoneX;
            y = 0.970371 * safezoneH + safezoneY;
            w = 0.0110156 * safezoneW;
            h = 0.0235186 * safezoneH;
        };

        class uptime_text: life_RscStructuredText
        {
            idc = 1101;
            text = ""; //--- ToDo: Localize;
            x = 0.973047 * safezoneW + safezoneX;
            y = 0.972222 * safezoneH + safezoneY;
            w = 0.0223439 * safezoneW;
            h = 0.0198148 * safezoneH;
        };
    };
};



/* #Kucume
/* #Sokypo
$[
    1.063,
    ["Tablet",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1100,"earplugs",[1,"earplugs.paa",["0.952291 * safezoneW + safezoneX","0.640333 * safezoneH + safezoneY","0.0331041 * safezoneW","0.0589743 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1102,"blah",[1,"earplugs.paa",["0.952292 * safezoneW + safezoneX","0.772333 * safezoneH + safezoneY","0.0331042 * safezoneW","0.0589743 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1200,"uptime_pic",[1,"serveruptime.paa",["0.958984 * safezoneW + safezoneX","0.970371 * safezoneH + safezoneY","0.0110156 * safezoneW","0.0235186 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1101,"uptime_text",[1,"5:26",["0.973047 * safezoneW + safezoneX","0.972222 * safezoneH + safezoneY","0.0223439 * safezoneW","0.0198148 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]


////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Sokypo)
////////////////////////////////////////////////////////

class earplugs: RscStructuredText
{
    idc = 1100;
    text = "earplugs.paa"; //--- ToDo: Localize;
    x = 0.952291 * safezoneW + safezoneX;
    y = 0.640333 * safezoneH + safezoneY;
    w = 0.0331041 * safezoneW;
    h = 0.0589743 * safezoneH;
};
class blah: RscStructuredText
{
    idc = 1102;
    text = "earplugs.paa"; //--- ToDo: Localize;
    x = 0.952292 * safezoneW + safezoneX;
    y = 0.772333 * safezoneH + safezoneY;
    w = 0.0331042 * safezoneW;
    h = 0.0589743 * safezoneH;
};
class uptime_pic: RscPicture
{
    idc = 1200;
    text = "serveruptime.paa";
    x = 0.958984 * safezoneW + safezoneX;
    y = 0.970371 * safezoneH + safezoneY;
    w = 0.0110156 * safezoneW;
    h = 0.0235186 * safezoneH;
};
class uptime_text: RscStructuredText
{
    idc = 1101;
    text = "5:26"; //--- ToDo: Localize;
    x = 0.973047 * safezoneW + safezoneX;
    y = 0.972222 * safezoneH + safezoneY;
    w = 0.0223439 * safezoneW;
    h = 0.0198148 * safezoneH;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////



*/
