class player_inv_market
{
	idd = 9001;
	name="player_inv_market";
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

        class Picture_close: life_RscButtonSilent
        {
            idc = -1;
            tooltip = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = 0.094697;
			y = 0.715488;
			w = 0.0823233;
			h = 0.089899;
        };

		class items_listbox: life_RscListbox
		{
			idc = 1500;
			onLBSelChanged = "0 call life_fnc_p_market_menu_EVH;";
			sizeEx = 0.04;
			x = 0.102272;
			y = 0.210438;
			w = 0.260353;
			h = 0.50404;
		};
		class items_header: life_RscText
		{
			idc = 1000;
			text = "Items:"; //--- ToDo: Localize;
			x = 0.108585;
			y = 0.16835;
			w = 0.270455;
			h = 0.0343434;
		};
		class str_text: life_RscStructuredText
		{
			idc = 1100;
			text = "";
			x = 0.36995;
			y = 0.171717;
			w = 0.602525;
			h = 0.663973;
		};

	};
};





/* #Taxuwe
$[
	1.063,
	["Tablet",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[1200,"tablet",[0,"tablet.paa",[-0.0195705,-0.104647,1.08561,1.18714],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1003,"Weight",[0,"",[0.653535,0.126734,0.167045,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1001,"TimeText",[0,"",[0.926768,0.126263,0.0445701,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1206,"Picture_close",[0,"tablet\close.paa",[0.094697,0.715488,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1500,"items",[0,"",[0.102272,0.210438,0.260353,0.50404],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1000,"items_header",[0,"Items",[0.108585,0.16835,0.270455,0.0343434],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1100,"str_text",[0,"",[0.36995,0.171717,0.602525,0.663973],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]






////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Taxuwe)
////////////////////////////////////////////////////////

class tablet: RscPicture
{
	idc = 1200;
	text = "tablet.paa";
	x = -0.0195705;
	y = -0.104647;
	w = 1.08561;
	h = 1.18714;
};
class Weight: RscText
{
	idc = 1003;
	x = 0.653535;
	y = 0.126734;
	w = 0.167045;
	h = 0.026532;
};
class TimeText: RscText
{
	idc = 1001;
	x = 0.926768;
	y = 0.126263;
	w = 0.0445701;
	h = 0.026532;
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
class items: RscListbox
{
	idc = 1500;
	x = 0.102272;
	y = 0.210438;
	w = 0.260353;
	h = 0.50404;
};
class items_header: RscText
{
	idc = 1000;
	text = "Items"; //--- ToDo: Localize;
	x = 0.108585;
	y = 0.16835;
	w = 0.270455;
	h = 0.0343434;
};
class str_text: RscStructuredText
{
	idc = 1100;
	x = 0.36995;
	y = 0.171717;
	w = 0.602525;
	h = 0.663973;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////






*/

