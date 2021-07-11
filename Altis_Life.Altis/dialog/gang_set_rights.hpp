class gang_set_rights {
    idd = 23541;
    name= "gang_set_rights";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "";

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
        class Picture_close: life_RscPicture
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

    class controls {


        class CloseLoadMenu: life_RscButtonSilent {
            idc = -1;
            tooltip = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = 0.094697;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
        };

        class possible_rights: life_RscListbox
        {
            idc = 1500;
            sizeEx = 0.035;
            onLBDblClick="[] spawn life_fnc_gang_rights_dialog_EVH;";
            x = 0.0996714;
            y = 0.239224;
            w = 0.625252;
            h = 0.46532;
        };
        class RscStructuredText_1100: life_RscStructuredText
        {
            idc = 1100;
            x = 0.732323;
            y = 0.237373;
            w = 0.237627;
            h = 0.463637;
        };
        class RscText_1000: life_RscStructuredText
        {
            idc = 1000;
            text = "Rechte:"; //--- ToDo: Localize;
            x = 0.104707;
            y = 0.170149;
            w = 0.280555;
            h = 0.0612796;
        };
    };
};



/* #Kilibi
$[
    1.063,
    ["Tablet",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1200,"tablet",[0,"tablet.paa",[-0.0195705,-0.104647,1.08561,1.18714],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1201,"",[0,"tablet\close.paa",[0.094697,0.715488,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"TimeText",[0,"",[0.926768,0.126263,0.0445701,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1003,"Weight",[0,"",[0.653535,0.126734,0.167045,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1500,"gang_members",[0,"",[0.0996714,0.239224,0.625252,0.46532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1100,"",[0,"",[0.732323,0.237373,0.237627,0.463637],[-1,-1,-1,-1],[1,0,1,1],[-1,-1,-1,-1],"","-1"],[]],
    [1000,"",[0,"Rechte:",[0.104707,0.170149,0.280555,0.0612796],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/

/*

////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Nawiky)
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
class RscPicture_1201: RscPicture
{
    idc = 1201;
    text = "tablet\close.paa";
    x = 0.094697;
    y = 0.715488;
    w = 0.0823233;
    h = 0.089899;
};
class possible_rights: RscListbox
{
    idc = 1500;
    x = 0.0996714;
    y = 0.239224;
    w = 0.625252;
    h = 0.46532;
};
class RscStructuredText_1100: RscStructuredText
{
    idc = 1100;
    x = 0.732323;
    y = 0.237373;
    w = 0.237627;
    h = 0.463637;
    colorBackground[] = {1,0,1,1};
};
class RscText_1000: RscText
{
    idc = 1000;
    text = "Rechte:"; //--- ToDo: Localize;
    x = 0.104707;
    y = 0.170149;
    w = 0.280555;
    h = 0.0612796;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////

*/