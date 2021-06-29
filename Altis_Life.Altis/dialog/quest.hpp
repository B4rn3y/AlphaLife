class alpha_quest {
	idd = 5223;
	name= "alpha_quest";
	movingEnable = 0;
	enableSimulation = 1;
	onLoad = "";

	class controlsBackground {
		class tablet: life_RscPicture
		{
			idc = 1200;
			text = "textures\zmenu\tablet.paa";
			x = -0.0195705;
			y = -0.104647;
			w = 1.08561;
			h = 1.18714;
		};
		class PictureClose: life_RscPicture
		{
			idc = 1206;
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
		class ButtonClose : life_RscButtonSilent {
			idc = -1;
			//shortcuts[] = {0x00050000 + 2};
			tooltip = "$STR_Global_Close";
			onButtonClick = "closeDialog 0;";
			x = 0.094697;
			y = 0.715488;
			w = 0.0823233;
			h = 0.089899;
		};


		class quests: life_RscListbox
		{
			idc = 1500;
			sizeEx = 0.0450;
			onLBselChanged = "[] call life_fnc_questmenuEVH;";
			x = 0.215909;
			y = 0.243165;
			w = 0.291414;
			h = 0.558249;
		};
		class text_header: life_RscText
		{
			idc = 1000;
			text = "Quests:"; //--- ToDo: Localize;
			x = 0.227273;
			y = 0.190236;
			w = 0.192172;
			h = 0.0444444;
		};
		class str_text: life_RscStructuredText
		{
			idc = 1100;
			text = "";
			x = 0.524369;
			y = 0.318721;
			w = 0.40303;
			h = 0.468687;
		};
		class load_screen_bckgrnd: life_RscText
		{
			idc = -1;
			colorBackground[] = {0,0,0,0.7};
			x = 0.525253;
			y = 0.240741;
			w = 0.40303;
			h = 0.0562289;
		};

		class progress: life_RscProgress
		{
			idc = 38201;
			colorFrame[] = {1, 1, 1, 1};
            colorBar[] = {1,0.502,0,1};
			x = 0.525253;
			y = 0.240741;
			w = 0.40303;
			h = 0.0562289;
		};
		class str_text_loading: life_RscStructuredText
		{
			idc = 1101;
			text = "";
			x = 0.525253;
			y = 0.240741;
			w = 0.40303;
			h = 0.0562289;

		};


	};
};