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
    };
};



