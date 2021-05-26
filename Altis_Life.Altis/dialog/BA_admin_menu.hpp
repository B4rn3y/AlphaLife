class BA_admin_menu {
    idd = 9000;
    name = "BA_admin_menu";
    movingEnable = 1;
    enableSimulation = 1;

    class controlsBackground {

        class main_background: Life_RscText
        {
            idc = 1000;
            x = -0.000780499 * safezoneW + safezoneX;
            //y = 0.00370417 * safezoneH + safezoneY;
            y = -0.000780499 * safezoneH + safezoneY;
            w = 0.504415 * safezoneW;
            h = 0.997293 * safezoneH;
            colorBackground[] = {0,0,0,0.7};
        };
    };

    class controls {
        class admin_options: Life_RscListbox
        {
            idc = 1500;
            onLBDblClick = "[_this] spawn life_fnc_BA_admin_menu_execute_code;";
            sizeEx = 0.05;
            x = 0.00624967 * safezoneW + safezoneX;
            y = 0.014815 * safezoneH + safezoneY;
            w = 0.171367 * safezoneW;
            h = 0.969038 * safezoneH;
        };
        class RscListbox_1501: Life_RscListbox
        {
            idc = 1501;
            onLBSelChanged = "[_this] spawn life_fnc_adminQuery";
            sizeEx = 0.05;
            x = 0.180079 * safezoneW + safezoneX;
            y = 0.0157411 * safezoneH + safezoneY;
            w = 0.172929 * safezoneW;
            h = 0.969038 * safezoneH;
        };
        class text_with_info: Life_RscStructuredText
        {
            idc = 1100;
            text = "";
            x = 0.353907 * safezoneW + safezoneX;
            y = 0.0166669 * safezoneH + safezoneY;
            w = 0.146562 * safezoneW;
            h = 0.968889 * safezoneH;
        };
    };
};
