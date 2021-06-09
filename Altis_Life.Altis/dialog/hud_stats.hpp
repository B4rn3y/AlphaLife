#define ST_CENTER         0x02
/*
    Author: Daniel Stuart

    File: hud_stats.hpp
*/


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
    };
};







/*
class playerHUD {
    idd = -1;
    duration = 10e10;
    movingEnable = 0;
    fadein = 0;
    fadeout = 0;
    name = "playerHUD";
    onLoad = "uiNamespace setVariable ['playerHUD',_this select 0]";
    objects[] = {};
    controls[] = {
        Life_RscBackground_HUD,
        Life_RscProgress_HUDFood,
        Life_RscProgress_HUDHealth,
        Life_RscProgress_HUDWater,
        Life_RscText_HUDFood,
        Life_RscText_HUDHealth,
        Life_RscText_HUDWater
    };

    class Life_RscBackground_HUD: Life_RscBackground {
        colorBackground[] = {0,0,0,0.35};
        x = 0.414815 * safezoneW + safezoneX;
        y = 0.966667 * safezoneH + safezoneY;
        w = 0.170371 * safezoneW;
        h = 0.0333333 * safezoneH;
    };

    class LIFE_RscProgress_HUDCommon: Life_RscProgress {
        colorFrame[] = {0, 0, 0, 0.8};
        y = 0.972223 * safezoneH + safezoneY;
        w = 0.0462964 * safezoneW;
        h = 0.0222222 * safezoneH;
    };

    class Life_RscProgress_HUDFood: LIFE_RscProgress_HUDCommon {
        idc = 2200;
        colorBar[] = {0,0.50,0,0.65};
        x = 0.418981 * safezoneW + safezoneX;
    };

    class Life_RscProgress_HUDHealth: LIFE_RscProgress_HUDCommon {
        idc = 2201;
        colorBar[] = {0.85,0.05,0,0.65};
        x = 0.476852 * safezoneW + safezoneX;
    };

    class Life_RscProgress_HUDWater: LIFE_RscProgress_HUDCommon {
        idc = 2202;
        colorBar[] = {0,0.25,0.65,0.65};
        x = 0.534723 * safezoneW + safezoneX;
    };

    class Life_RscText_HUDCommon: Life_RscText {
        SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
        style = ST_CENTER;
        y = 0.972223 * safezoneH + safezoneY;
        w = 0.0462964 * safezoneW;
        h = 0.0222222 * safezoneH;
    };

    class Life_RscText_HUDFood: Life_RscText_HUDCommon {
        idc = 1200;
        text = "$STR_HUD_Food";
        x = 0.418981 * safezoneW + safezoneX;
    };

    class Life_RscText_HUDHealth: Life_RscText_HUDCommon {
        idc = 1201;
        text = "$STR_HUD_Health";
        x = 0.476852 * safezoneW + safezoneX;
    };

    class Life_RscText_HUDWater: Life_RscText_HUDCommon {
        idc = 1202;
        text = "$STR_HUD_Water";
        x = 0.534723 * safezoneW + safezoneX;
    };
};
*/