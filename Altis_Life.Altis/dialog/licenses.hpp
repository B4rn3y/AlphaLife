class licenses_new_menu
{
	idd = 9580;
	name="licenses_new_menu";
	movingEnabled = 0;
	enableSimulation = 1;
	//onLoad = "ctrlShow [2330,false];";

	class controlsBackground
	{
		class TabletBCKGRND: life_RscPicture
		{
			idc = -1;
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
			idc = 7858;
			SizeEx = 0.027;
			text = "";
			x = 0.930556;
			y = 0.127946;
			w = 0.0534085;
			h = 0.033266;
		};
	};

	class controls
	{
		class LicenseHeader: life_RscText
		{
			idc = 1001;
			text = "$STR_PM_Licenses";
			sizeEx = 0.04;
			x = 0.281187;
			y = 0.165925;
			w = 0.463763;
			h = 0.026734;
		};
		class Licenses_Menu: life_RscControlsGroup
		{
			idc = 2300;
			x = 0.281313;
			y = 0.206532;
			w = 0.4625;
			h = 0.60;
			class controls
			{
				class life_Licenses : life_RscStructuredText
					{
						idc = 2014;
						sizeEx = 0.020;
						text = "";
						x = 0;
						y = 0;
						w = 0.4625; h = 0.98;
					};
			};
		};
		class BTNClose: life_RscButtonSilent
		{
			idc = 1603;
			tooltip = "$STR_Global_Close";
			onButtonClick = "closeDialog 0; [] call lhm_fnc_p_openMenu;";
			x = 0.094697;
			y = 0.715488;
			w = 0.0823233;
			h = 0.089899;
		};
	};
};