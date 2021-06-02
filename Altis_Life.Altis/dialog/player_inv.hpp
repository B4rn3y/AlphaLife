#include "player_sys.sqf"




class playerSettings {
    idd = playersys_DIALOG;
    movingEnable = 1;
    enableSimulation = 1;

    class controlsBackground {


        class TabletBCKGRND: life_RscPicture
        {
            idc = -1;
            text = "textures\zmenu\tablet.paa";
            x = -0.0195705;
            y = -0.104647;
            w = 1.08561;
            h = 1.18714;

        };

        class Picture_message: life_RscPicture
        {
            idc = 1201;
            text = "textures\zmenu\sms.paa";
            x = 0.194445;
            y = 0.195287;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_settings: life_RscPicture
        {
            idc = 1202;
            text = "textures\zmenu\config.paa";
            x = 0.296717;
            y = 0.195287;
            w = 0.0823233;
            h = 0.089899;
        };
        class picture_keys: life_RscPicture
        {
            idc = 1203;
            text = "textures\zmenu\key.paa";
            x = 0.0972225;
            y = 0.195287;
            w = 0.0823233;
            h = 0.089899;
        };
        class picture_gang: life_RscPicture
        {
            idc = 1204;
            text = "textures\zmenu\gang.paa";
            x = 0.0959597;
            y = 0.316498;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_lizenzen: life_RscPicture
        {
            idc = 1205;
            text = "textures\zmenu\lizenzen.paa";
            x = 0.396465;
            y = 0.195287;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_close: life_RscPicture
        {
            idc = 1206;
            text = "textures\zmenu\close.paa";
            x = 0.094697;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_markt: life_RscPicture
        {
            idc = 1207;
            text = "textures\zmenu\markt.paa";
            x = 0.497475;
            y = 0.195287;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_admin: life_RscPicture
        {
            idc = 1208;
            text = "textures\zmenu\admin.paa";
            x = 0.4975;
            y = 0.596;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_sync_data: life_RscPicture
        {
            idc = 1209;
            text = "textures\zmenu\sync.paa";
            x = 0.49495;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
        };

        class moneyStatusInfo: Life_RscStructuredText {
            idc = 2015;
            sizeEx = 0.020;
            text = "";
            x = 0.676263;
            y = 0.609495;
            w = 0.273737;
            h = 0.106734;
        };

        class PlayersName: Life_RscTitle  {
            idc = carry_weight;
            style = 1;
            text = "";
            x = 0.653535;
            y = 0.126734;
            w = 0.167045;
            h = 0.026532;
        };



        class TimeText: life_RscText
        {
            idc = 8888;
            SizeEx = 0.027;
            text = "";
            x = 0.930556;
            y = 0.127946;
            w = 0.0534085;
            h = 0.033266;
        };
    };

    class controls {
        class itemHeader: Life_RscText {
            idc = -1;
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            text = "$STR_PM_cItems";
            sizeEx = 0.04;
            x = 0.684343;
            y = 0.166667;
            w = 0.263131;
            h = 0.0265319;
        };

/*
        class licenseHeader: Life_RscText {
            idc = -1;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            text = "$STR_PM_Licenses";
            sizeEx = 0.04;
            x = 0.336;
            y = 0.26;
            w = 0.275;
            h = 0.04;
        };
*/

        class moneySHeader: Life_RscText {
            idc = -1;
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            text = "$STR_PM_MoneyStats";
            sizeEx = 0.04;
            x = 0.680682;
            y = 0.577508;
            w = 0.264141;
            h = 0.0242425;
        };

        class itemList: Life_RscListBox {
            idc = item_list;
            sizeEx = 0.030;
            x = 0.678788;
            y = 0.201482;
            w = 0.271212;
            h = 0.204848;
        };

        class moneyEdit: Life_RscEdit {
            idc = 2018;
            text = "1";
            sizeEx = 0.030;
            x = 0.682071;
            y = 0.725724;
            w = 0.263384;
            h = 0.0298991;
        };

        class NearPlayers: Life_RscCombo {
            idc = 2022;
            x = 0.680808;
            y = 0.763838;
            w = 0.266035;
            h = 0.029899;
        };

        class moneyDrop: Life_RscButtonMenu {
            idc = 2001;
            text = "$STR_Global_Give";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_giveMoney";
            sizeEx = 0.025;
            x = 0.751137;
            y = 0.799192;
            w = 0.1125;
            h = 0.04;
        };

        class itemEdit: Life_RscEdit {
            idc = item_edit;
            text = "1";
            sizeEx = 0.030;
            x = 0.682324;
            y = 0.410774;
            w = 0.268687;
            h = 0.0332658;

        };

        class iNearPlayers: Life_RscCombo {
            idc = 2023;
            x = 0.683459;
            y = 0.445253;
            w = 0.266667;
            h = 0.0343433;
        };

        class DropButton: Life_RscButtonMenu {
            idc = 2002;
            text = "$STR_Global_Give";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_giveItem;";
            x = 0.820833;
            y = 0.482627;
            w = 0.125;
            h = 0.04;
        };

        class UseButton: Life_RscButtonMenu {
            text = "$STR_Global_Use";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_useItem;";
            x = 0.681818;
            y = 0.483164;
            w = 0.125;
            h = 0.04;
        };

        class RemoveButton: Life_RscButtonMenu {
            text = "$STR_Global_Remove";
            //colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_removeItem;";
            x = 0.756314;
            y = 0.525253;
            w = 0.125;
            h = 0.04;
        };

        class Picture_message: life_RscButtonSilent
        {
            idc = 3001;
            tooltip = "$STR_PM_CellPhone";
            onButtonClick = "createDialog ""Life_cell_phone"";";
            x = 0.194445;
            y = 0.195287;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_settings: life_RscButtonSilent
        {
            idc = 3002;
            tooltip = "$STR_Global_Settings";
            onButtonClick = "[] call life_fnc_settingsMenu;";
            x = 0.296717;
            y = 0.195287;
            w = 0.0823233;
            h = 0.089899;
        };
        class picture_keys: life_RscButtonSilent
        {
            idc = 3003;
            tooltip = "$STR_PM_KeyChain";
            onButtonClick = "createDialog ""Life_key_management"";";
            x = 0.0972225;
            y = 0.195287;
            w = 0.0823233;
            h = 0.089899;
        };
        class picture_gang: life_RscButtonSilent
        {
            idc = 3004;
            tooltip = "$STR_PM_MyGang";
            onButtonClick = "if (isNil ""life_action_gangInUse"") then {if (isNil {(group player) getVariable ""gang_owner""}) then {createDialog ""Life_Create_Gang_Diag"";} else {[] spawn life_fnc_gangMenu;};};";
            x = 0.0959597;
            y = 0.316498;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_lizenzen: life_RscButtonSilent
        {
            idc = 3005;
            tooltip = "$STR_PM_Licenses";
            onButtonClick = "[] spawn life_fnc_licenseMenu;";
            x = 0.396465;
            y = 0.195287;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_close: life_RscButtonSilent
        {
            idc = 3006;
            tooltip = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = 0.094697;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_markt: life_RscButtonSilent
        {
            idc = 3007;
            tooltip = "$STR_PM_Market";
            onButtonClick = "0 spawn life_fnc_p_market_menu;";
            x = 0.497475;
            y = 0.195287;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_admin: life_RscButtonSilent
        {
            idc = 3008;
            tooltip = "$STR_PM_AdminMenu";
            onButtonClick = "closeDialog 0; [] spawn life_fnc_BA_admin_menu_open_dialog;";
            x = 0.4975;
            y = 0.596;
            w = 0.0823233;
            h = 0.089899;
        };
        class Picture_sync_data: life_RscButtonSilent
        {
            idc = 3009;
            tooltip = "$STR_PM_SyncData";
            onButtonClick = "[] call SOCK_fnc_syncData;";
            x = 0.49495;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
        };

        /*
        class ButtonClose: Life_RscButtonMenu {
            idc = -1;
            //shortcuts[] = {0x00050000 + 2};
            text = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = 0.1;
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonSettings: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Settings";
            onButtonClick = "[] call life_fnc_settingsMenu;";
            x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonMyGang: Life_RscButtonMenu {
            idc = 2011;
            text = "$STR_PM_MyGang";
            onButtonClick = "if (isNil ""life_action_gangInUse"") then {if (isNil {(group player) getVariable ""gang_owner""}) then {createDialog ""Life_Create_Gang_Diag"";} else {[] spawn life_fnc_gangMenu;};};";
            x = 0.1 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class Licenses_Menu : Life_RscControlsGroup {
            idc = -1;
            w = 0.28;
            h = 0.38;
            x = 0.34;
            y = 0.30;

            class Controls {
                class Life_Licenses: Life_RscStructuredText {
                    idc = 2014;
                    sizeEx = 0.020;
                    text = "";
                    x = 0;
                    y = 0;
                    w = 0.27;
                    h = 0.65;
                };
            };
        };

        class ButtonGangList: Life_RscButtonMenu {
            idc = 2012;
            text = "$STR_PM_WantedList";
            onButtonClick = "[] call life_fnc_wantedMenu";
            x = 0.1 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonKeys: Life_RscButtonMenu {
            idc = 2013;
            text = "$STR_PM_KeyChain";
            onButtonClick = "createDialog ""Life_key_management"";";
            x = 0.26 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonCell: Life_RscButtonMenu {
            idc = 2014;
            text = "$STR_PM_CellPhone";
            onButtonClick = "createDialog ""Life_cell_phone"";";
            x = 0.42 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonAdminMenu: Life_RscButtonMenu {
            idc = 2021;
            text = "$STR_PM_AdminMenu";
            onButtonClick = "closeDialog 0; [] spawn life_fnc_BA_admin_menu_open_dialog;";
            x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.805;
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonSyncData: Life_RscButtonMenu {
            idc = -1;
            //shortcuts[] = {0x00050000 + 2};
            text = "$STR_PM_SyncData";
            onButtonClick = "[] call SOCK_fnc_syncData;";
            x = 0.1;
            y = 0.805;
            w = (6.25 / 40);
            h = (1 / 25);
        };
        */
    };
};











/*


class playerSettings {
    idd = playersys_DIALOG;
    movingEnable = 1;
    enableSimulation = 1;

    class controlsBackground {
        class Life_RscTitleBackground: Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };

        class MainBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.8;
            h = 0.6 - (22 / 250);
        };

        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = -1;
            text = "$STR_PM_Title";
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };

        class moneyStatusInfo: Life_RscStructuredText {
            idc = 2015;
            sizeEx = 0.020;
            text = "";
            x = 0.105;
            y = 0.30;
            w = 0.3;
            h = 0.6;
        };

        class PlayersName: Title {
            idc = carry_weight;
            style = 1;
            text = "";
        };
    };

    class controls {
        class itemHeader: Life_RscText {
            idc = -1;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            text = "$STR_PM_cItems";
            sizeEx = 0.04;
            x = 0.62;
            y = 0.26;
            w = 0.275;
            h = 0.04;
        };

        class licenseHeader: Life_RscText {
            idc = -1;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            text = "$STR_PM_Licenses";
            sizeEx = 0.04;
            x = 0.336;
            y = 0.26;
            w = 0.275;
            h = 0.04;
        };

        class moneySHeader: Life_RscText {
            idc = -1;
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            text = "$STR_PM_MoneyStats";
            sizeEx = 0.04;
            x = 0.11;
            y = 0.26;
            w = 0.219;
            h = 0.04;
        };

        class itemList: Life_RscListBox {
            idc = item_list;
            sizeEx = 0.030;
            x = 0.62;
            y = 0.30;
            w = 0.275;
            h = 0.3;
        };

        class moneyEdit: Life_RscEdit {
            idc = 2018;
            text = "1";
            sizeEx = 0.030;
            x = 0.12;
            y = 0.42;
            w = 0.18;
            h = 0.03;
        };

        class NearPlayers: Life_RscCombo {
            idc = 2022;
            x = 0.12;
            y = 0.46;
            w = 0.18;
            h = 0.03;
        };

        class moneyDrop: Life_RscButtonMenu {
            idc = 2001;
            text = "$STR_Global_Give";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_giveMoney";
            sizeEx = 0.025;
            x = 0.135;
            y = 0.50;
            w = 0.13;
            h = 0.036;
        };

        class itemEdit: Life_RscEdit {
            idc = item_edit;
            text = "1";
            sizeEx = 0.030;
            x = 0.62;
            y = 0.61;
            w = 0.275;
            h = 0.03;

        };

        class iNearPlayers: Life_RscCombo {
            idc = 2023;
            x = 0.62;
            y = 0.65;
            w = 0.275;
            h = 0.03;
        };

        class DropButton: Life_RscButtonMenu {
            idc = 2002;
            text = "$STR_Global_Give";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_giveItem;";
            x = 0.765;
            y = 0.70;
            w = (5.25 / 40);
            h = (1 / 25);
        };

        class UseButton: Life_RscButtonMenu {
            text = "$STR_Global_Use";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_useItem;";
            x = 0.62;
            y = 0.70;
            w = (5.25 / 40);
            h = (1 / 25);
        };

        class RemoveButton: Life_RscButtonMenu {
            text = "$STR_Global_Remove";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "[] call life_fnc_removeItem;";
            x = 0.475;
            y = 0.70;
            w = (5.25 / 40);
            h = (1 / 25);
        };

        class ButtonClose: Life_RscButtonMenu {
            idc = -1;
            //shortcuts[] = {0x00050000 + 2};
            text = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = 0.1;
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonSettings: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Settings";
            onButtonClick = "[] call life_fnc_settingsMenu;";
            x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonMyGang: Life_RscButtonMenu {
            idc = 2011;
            text = "$STR_PM_MyGang";
            onButtonClick = "if (isNil ""life_action_gangInUse"") then {if (isNil {(group player) getVariable ""gang_owner""}) then {createDialog ""Life_Create_Gang_Diag"";} else {[] spawn life_fnc_gangMenu;};};";
            x = 0.1 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class Licenses_Menu : Life_RscControlsGroup {
            idc = -1;
            w = 0.28;
            h = 0.38;
            x = 0.34;
            y = 0.30;

            class Controls {
                class Life_Licenses: Life_RscStructuredText {
                    idc = 2014;
                    sizeEx = 0.020;
                    text = "";
                    x = 0;
                    y = 0;
                    w = 0.27;
                    h = 0.65;
                };
            };
        };

        class ButtonGangList: Life_RscButtonMenu {
            idc = 2012;
            text = "$STR_PM_WantedList";
            onButtonClick = "[] call life_fnc_wantedMenu";
            x = 0.1 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonKeys: Life_RscButtonMenu {
            idc = 2013;
            text = "$STR_PM_KeyChain";
            onButtonClick = "createDialog ""Life_key_management"";";
            x = 0.26 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonCell: Life_RscButtonMenu {
            idc = 2014;
            text = "$STR_PM_CellPhone";
            onButtonClick = "createDialog ""Life_cell_phone"";";
            x = 0.42 + (6.25 / 19.8) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.8 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonAdminMenu: Life_RscButtonMenu {
            idc = 2021;
            text = "$STR_PM_AdminMenu";
            onButtonClick = "closeDialog 0; [] spawn life_fnc_BA_admin_menu_open_dialog;";
            x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.805;
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class ButtonSyncData: Life_RscButtonMenu {
            idc = -1;
            //shortcuts[] = {0x00050000 + 2};
            text = "$STR_PM_SyncData";
            onButtonClick = "[] call SOCK_fnc_syncData;";
            x = 0.1;
            y = 0.805;
            w = (6.25 / 40);
            h = (1 / 25);
        };
    };
};

*/

/*
$[
    1.063,
    ["Tablet",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1100,"Moneystatus",[0,"",[0.676263,0.609495,0.273737,0.106734],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1200,"tablet",[0,"tablet.paa",[-0.0195705,-0.104647,1.08561,1.18714],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2100,"ComboMoney",[0,"",[0.680808,0.763838,0.266035,0.029899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1400,"EDitMoney",[0,"",[0.682071,0.725724,0.263384,0.0298991],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1000,"MoneyHeader",[0,"",[0.680682,0.577508,0.264141,0.0242425],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"MoneyBTNGive",[0,"",[0.751137,0.799192,0.1125,0.04],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1002,"ItemsHeader",[0,"",[0.684343,0.166667,0.263131,0.0265319],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1500,"ItemsListbox",[0,"",[0.678788,0.201482,0.271212,0.204848],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1401,"EditItems",[0,"",[0.682324,0.410774,0.268687,0.0332658],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1600,"BTNgive",[0,"",[0.820833,0.482627,0.125,0.04],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1601,"BTNuse",[0,"",[0.681818,0.483164,0.125,0.04],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1602,"BTNremove",[0,"",[0.756314,0.525253,0.125,0.04],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1003,"Weight",[0,"",[0.653535,0.126734,0.167045,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2101,"ItemCombo",[0,"",[0.683459,0.445253,0.266667,0.0343433],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"TimeText",[0,"",[0.926768,0.126263,0.0445701,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1201,"Picture_message",[0,"tablet\sms.paa",[0.194445,0.195287,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1202,"Picture_settings",[0,"tablet\config.paa",[0.296717,0.195287,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1203,"picture_keys",[0,"tablet\key.paa",[0.0972225,0.195287,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1204,"picture_gang",[0,"tablet\gang.paa",[0.497475,0.195287,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1205,"Picture_lizenzen",[0,"tablet\lizenzen.paa",[0.396465,0.195287,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1206,"Picture_close",[0,"tablet\close.paa",[0.094697,0.715488,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1207,"Picture_markt",[0,"tablet\markt.paa",[0.0959597,0.316498,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1208,"Picture_admin",[0,"tablet\admin.paa",[0.4975,0.596,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1209,"Picture_sync_data",[0,"tablet\sync.paa",[0.49495,0.715488,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]


////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Guzyre)
////////////////////////////////////////////////////////

class Moneystatus: RscStructuredText
{
    idc = 1100;
    x = 0.676263;
    y = 0.609495;
    w = 0.273737;
    h = 0.106734;
};
class tablet: RscPicture
{
    idc = 1200;
    text = "tablet.paa";
    x = -0.0195705;
    y = -0.104647;
    w = 1.08561;
    h = 1.18714;
};
class ComboMoney: RscCombo
{
    idc = 2100;
    x = 0.680808;
    y = 0.763838;
    w = 0.266035;
    h = 0.029899;
};
class EDitMoney: RscEdit
{
    idc = 1400;
    x = 0.682071;
    y = 0.725724;
    w = 0.263384;
    h = 0.0298991;
};
class MoneyHeader: RscText
{
    idc = 1000;
    x = 0.680682;
    y = 0.577508;
    w = 0.264141;
    h = 0.0242425;
};
class MoneyBTNGive: RscButtonMenu
{
    idc = 2400;
    x = 0.751137;
    y = 0.799192;
    w = 0.1125;
    h = 0.04;
};
class ItemsHeader: RscText
{
    idc = 1002;
    x = 0.684343;
    y = 0.166667;
    w = 0.263131;
    h = 0.0265319;
};
class ItemsListbox: RscListbox
{
    idc = 1500;
    x = 0.678788;
    y = 0.201482;
    w = 0.271212;
    h = 0.204848;
};
class EditItems: RscEdit
{
    idc = 1401;
    x = 0.682324;
    y = 0.410774;
    w = 0.268687;
    h = 0.0332658;
};
class BTNgive: RscButton
{
    idc = 1600;
    x = 0.820833;
    y = 0.482627;
    w = 0.125;
    h = 0.04;
};
class BTNuse: RscButton
{
    idc = 1601;
    x = 0.681818;
    y = 0.483164;
    w = 0.125;
    h = 0.04;
};
class BTNremove: RscButton
{
    idc = 1602;
    x = 0.756314;
    y = 0.525253;
    w = 0.125;
    h = 0.04;
};
class Weight: RscText
{
    idc = 1003;
    x = 0.653535;
    y = 0.126734;
    w = 0.167045;
    h = 0.026532;
};
class ItemCombo: RscCombo
{
    idc = 2101;
    x = 0.683459;
    y = 0.445253;
    w = 0.266667;
    h = 0.0343433;
};
class TimeText: RscText
{
    idc = 1001;
    x = 0.926768;
    y = 0.126263;
    w = 0.0445701;
    h = 0.026532;
};
class Picture_message: RscPicture
{
    idc = 1201;
    text = "tablet\sms.paa";
    x = 0.194445;
    y = 0.195287;
    w = 0.0823233;
    h = 0.089899;
};
class Picture_settings: RscPicture
{
    idc = 1202;
    text = "tablet\config.paa";
    x = 0.296717;
    y = 0.195287;
    w = 0.0823233;
    h = 0.089899;
};
class picture_keys: RscPicture
{
    idc = 1203;
    text = "tablet\key.paa";
    x = 0.0972225;
    y = 0.195287;
    w = 0.0823233;
    h = 0.089899;
};
class picture_gang: RscPicture
{
    idc = 1204;
    text = "tablet\gang.paa";
    x = 0.497475;
    y = 0.195287;
    w = 0.0823233;
    h = 0.089899;
};
class Picture_lizenzen: RscPicture
{
    idc = 1205;
    text = "tablet\lizenzen.paa";
    x = 0.396465;
    y = 0.195287;
    w = 0.0823233;
    h = 0.089899;
};
class Picture_close: RscPicture
{
    idc = 1206;
    text = "tablet\close.paa";
    x = 0.094697;
    y = 0.715488;
    w = 0.0823233;
    h = 0.089899;
};
class Picture_markt: RscPicture
{
    idc = 1207;
    text = "tablet\markt.paa";
    x = 0.0959597;
    y = 0.316498;
    w = 0.0823233;
    h = 0.089899;
};
class Picture_admin: RscPicture
{
    idc = 1208;
    text = "tablet\admin.paa";
    x = 0.4975;
    y = 0.596;
    w = 0.0823233;
    h = 0.089899;
};
class Picture_sync_data: RscPicture
{
    idc = 1209;
    text = "tablet\sync.paa";
    x = 0.49495;
    y = 0.715488;
    w = 0.0823233;
    h = 0.089899;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////


*/