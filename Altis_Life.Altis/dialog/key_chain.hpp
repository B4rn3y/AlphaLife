class Life_key_management {
    idd = 2700;
    name= "life_key_chain";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn life_fnc_keyMenu;";

    class controlsBackground {
        class TabletBCKGRND: life_RscPicture
        {
            idc = -1;
            text = "textures\zmenu\tablet.paa";
            x = -0.0203282;
            y = -0.104377;
            w = 1.08561;
            h = 1.18545;

        };
        class PictureClose: life_RscPicture
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
    };

    class controls {
        /*
        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = -1;
            text = "$STR_Keys_Title";
            x = 0.1;
            y = 0.2;
            w = 0.6;
            h = (1 / 25);
        };*/

        class KeyChainList: Life_RscListBox {
            idc = 2701;
            text = "";
            sizeEx = 0.040;

            x = 0.206023;
            y = 0.176514;
            w = 0.5625;
            h = 0.66;
        };

        class CloseButtonKey: life_RscButtonSilent {
            idc = -1;
            tooltip = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;[] call lhm_fnc_p_updateMenu";
            x = 0.094697;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
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

        class NearPlayers: Life_RscCombo {
            idc = 2702;
            x = 0.78025;
            y = 0.3328;
            w = 0.168939;
            h = 0.0416836;
        };

        class DropKey: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Keys_DropKey";
            onButtonClick = "[] call life_fnc_keyDrop";
            x = 0.778535;
            y = 0.78404;
            w = 0.171338;
            h = 0.053468;
        };

        class GiveKey: Life_RscButtonMenu {
            idc = 2703;
            text = "$STR_Keys_GiveKey";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_keyGive";
            x = 0.777273;
            y = 0.179596;
            w = 0.171338;
            h = 0.053468;
        };


        class GiveKeyGang : Life_RscButtonMenu {
            idc = 2704;
            text = "Gang Key";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_keyGiveGang";
            x = 0.777273;
            y = 0.259596;
            w = 0.171338;
            h = 0.053468;
        };
    };
};