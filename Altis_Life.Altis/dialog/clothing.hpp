class Life_Clothing {
    idd = 3100;
    name= "Life_Clothing";
    movingEnable = 1;
    enableSimulation = 1;
    //onLoad = "[] execVM 'core\client\keychain\init.sqf'";

    class controlsBackground {
		
		#define ScaleX safezoneW + safezoneX
		#define ScaleY safezoneH + safezoneY
		
		#define START_X 0.08 * ScaleX
		#define START_Y 0.2 * ScaleY		
		
		#define GENERAL_GUI_WIDTH 0.13 * safezoneW
		#define BACKGROUND_HEIGHT 0.23 * safezoneH
		
        class Life_RscTitleBackground: Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = START_X;
            y = START_Y;
            w = GENERAL_GUI_WIDTH;
            h = BACKGROUND_HEIGHT/10;
        };

        class MainBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = START_X; //0.0822359 * ScaleX;
            y = START_Y + BACKGROUND_HEIGHT/8;
            w = GENERAL_GUI_WIDTH;
            h = BACKGROUND_HEIGHT;
        };
    };

    class controls {
        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = 3103;
            text = "TITLE";
            x = START_X;
            y = START_Y;
            w = GENERAL_GUI_WIDTH * 0.9;
            h = BACKGROUND_HEIGHT/10;
        };

        class ClothingList: Life_RscListBox {
            idc = 3101;
            text = "";
            sizeEx = 0.035;
            onLBSelChanged = "[_this] call life_fnc_changeClothes;";
            x = START_X + GENERAL_GUI_WIDTH/30;
            y = START_Y + BACKGROUND_HEIGHT/6.4;
            w = GENERAL_GUI_WIDTH - ((GENERAL_GUI_WIDTH/30)*2);
            h = BACKGROUND_HEIGHT * 0.825;
        };

        class PriceTag: Life_RscStructuredText {
            idc = 3102;
            text = "Price: 1.550.000";
            sizeEx = 0.035;
            x = START_X + (GENERAL_GUI_WIDTH/27);
            y = START_Y + BACKGROUND_HEIGHT;
            w = GENERAL_GUI_WIDTH/2;
            h = BACKGROUND_HEIGHT/5;
        };

        class TotalPrice: Life_RscStructuredText {
            idc = 3106;
            text = "Total: 1.500.000";
            sizeEx = 0.035;
            x = START_X + GENERAL_GUI_WIDTH/2;
            y = START_Y + BACKGROUND_HEIGHT;
            w = GENERAL_GUI_WIDTH/2;
            h = BACKGROUND_HEIGHT/5;
        };

        class FilterList: Life_RscCombo {
            idc = 3105;
            colorBackground[] = {0,0,0,0.7};
            onLBSelChanged  = "_this call life_fnc_clothingFilter";
            x = START_X;
            y = START_Y + BACKGROUND_HEIGHT*1.14;
            w = GENERAL_GUI_WIDTH;
            h = BACKGROUND_HEIGHT/12;
        };

        class CloseButtonKey: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Close";
            onButtonClick = "closeDialog 0; [] call life_fnc_playerSkins;";
            x = START_X + GENERAL_GUI_WIDTH/2 + (GENERAL_GUI_WIDTH/2 * 0.05);
            y = START_Y + BACKGROUND_HEIGHT*1.24;
            w = GENERAL_GUI_WIDTH/2 * 0.95;
            h = BACKGROUND_HEIGHT/10;
        };

        class BuyButtonKey: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Buy";
            onButtonClick = "[] call life_fnc_buyClothes;";
            x = START_X;
            y = START_Y + BACKGROUND_HEIGHT*1.24;
            w = GENERAL_GUI_WIDTH/2 * 0.95;
            h = BACKGROUND_HEIGHT/10;
        };

        class viewAngle: life_RscXSliderH {
            color[] = {1, 1, 1, 0.45};
            colorActive[] = {1, 1, 1, 0.65};
            idc = 3107;
            text = "";
            onSliderPosChanged = "[4,_this select 1] call life_fnc_s_onSliderChange;";
            tooltip = "";
            x = 0.25 * ScaleX;
            y = 0.93 * ScaleY;
            w = 0.5 * safezoneW;
            h = 0.02 * safezoneH;
        };
    };
};

/* TONIC ORIGINAL


class Life_Clothing {
    idd = 3100;
    name= "Life_Clothing";
    movingEnable = 1;
    enableSimulation = 1;
    //onLoad = "[] execVM 'core\client\keychain\init.sqf'";

    class controlsBackground {
        class Life_RscTitleBackground: Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = 0.0821059 * safezoneW + safezoneX;
            y = 0.212176 * safezoneH + safezoneY;
            w = 0.318;
            h = (1 / 25);
        };

        class MainBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.0822359 * safezoneW + safezoneX;
            y = 0.236099 * safezoneH + safezoneY;
            w = 0.318;
            h = 0.5 - (22 / 250);
        };
    };

    class controls {
        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = 3103;
            text = "";
            x = 0.0821059 * safezoneW + safezoneX;
            y = 0.212176 * safezoneH + safezoneY;
            w = 0.6;
            h = (1 / 25);
        };

        class ClothingList: Life_RscListBox {
            idc = 3101;
            text = "";
            sizeEx = 0.035;
            onLBSelChanged = "[_this] call life_fnc_changeClothes;";
            x = 0.0842977 * safezoneW + safezoneX;
            y = 0.240498 * safezoneH + safezoneY;
            w = 0.3;
            h = 0.35;
        };

        class PriceTag: Life_RscStructuredText {
            idc = 3102;
            text = "";
            sizeEx = 0.035;
            x = 0.0853304 * safezoneW + safezoneX;
            y = 0.439419 * safezoneH + safezoneY;
            w = 0.2;
            h = (1 / 25);
        };

        class TotalPrice: Life_RscStructuredText {
            idc = 3106;
            text = "";
            sizeEx = 0.035;
            x = 0.135 * safezoneW + safezoneX;
            y = 0.439419 * safezoneH + safezoneY;
            w = 0.2;
            h = (1 / 25);
        };

        class FilterList: Life_RscCombo {
            idc = 3105;
            colorBackground[] = {0,0,0,0.7};
            onLBSelChanged  = "_this call life_fnc_clothingFilter";
            x = 0.0822359 * safezoneW + safezoneX;
            y = 0.468 * safezoneH + safezoneY;
            w = 0.318;
            h = 0.035;
        };

        class CloseButtonKey: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Close";
            onButtonClick = "closeDialog 0; [] call life_fnc_playerSkins;";
            x = 0.149 * safezoneW + safezoneX;
            y = 0.489992 * safezoneH + safezoneY;
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class BuyButtonKey: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Buy";
            onButtonClick = "[] call life_fnc_buyClothes;";
            x = 0.0822359 * safezoneW + safezoneX;
            y = 0.489992 * safezoneH + safezoneY;
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class viewAngle: life_RscXSliderH {
            color[] = {1, 1, 1, 0.45};
            colorActive[] = {1, 1, 1, 0.65};
            idc = 3107;
            text = "";
            onSliderPosChanged = "[4,_this select 1] call life_fnc_s_onSliderChange;";
            tooltip = "";
            x = 0.25 * safezoneW + safezoneX;
            y = 0.93 * safezoneH + safezoneY;
            w = 0.5 * safezoneW;
            h = 0.02 * safezoneH;
        };
    };
};

*/

