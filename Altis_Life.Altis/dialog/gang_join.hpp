class gang_join {
    idd = 518845;
    name= "gang_join";
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





        class gang_members: life_RscListNbox
        {
            idc = 1500;
            sizeEx = 0.035;
            columns[] = {0,0.6};
            x = 0.0996714;
            y = 0.242591;
            w = 0.693434;
            h = 0.472054;
        };
        class header_gangs: life_RscText
        {
            idc = 1000;
            text = "Verfuegbare Gangs:"; //--- ToDo: Localize;
            x = 0.10606;
            y = 0.188552;
            w = 0.319697;
            h = 0.0393939;
        };
        class btn_1: life_RscButtonMenu
        {
            idc = 2400;
            text = "Join"; //--- ToDo: Localize;
            x = 0.801768;
            y = 0.240741;
            w = 0.175758;
            h = 0.0494949;
        };
        class btn_2: life_RscButtonMenu
        {
            idc = 2401;
            text = "Delete allie"; //--- ToDo: Localize;
            x = 0.801768;
            y = 0.294613;
            w = 0.175758;
            h = 0.0494949;
        };

         class CloseLoadMenu: life_RscButtonSilent {
            idc = -1;
            tooltip = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = 0.094697;
            y = 0.715488;
            w = 0.0823233;
            h = 0.089899;
        };
    };
};





/* #Dizema
$[
    1.063,
    ["Tablet",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1200,"tablet",[0,"tablet.paa",[-0.0195705,-0.104647,1.08561,1.18714],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1201,"",[0,"tablet\close.paa",[0.094697,0.715488,0.0823233,0.089899],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"TimeText",[0,"",[0.926768,0.126263,0.0445701,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1003,"Weight",[0,"",[0.653535,0.126734,0.167045,0.026532],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1500,"gang_members",[0,"",[0.0996714,0.242591,0.693434,0.472054],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1000,"header_gangs",[0,"Verfuegbare Gangs:",[0.10606,0.188552,0.319697,0.0393939],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"btn_1",[0,"Join",[0.801768,0.240741,0.175758,0.0494949],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2401,"btn_2",[0,"remove allie",[0.801768,0.294613,0.175758,0.0494949],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/

/*

////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Ciliby)
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
class TimeText: RscText
{
    idc = 1001;
    x = 0.926768;
    y = 0.126263;
    w = 0.0445701;
    h = 0.026532;
};
class Weight: RscText
{
    idc = 1003;
    x = 0.653535;
    y = 0.126734;
    w = 0.167045;
    h = 0.026532;
};
class gang_members: RscListbox
{
    idc = 1500;
    x = 0.0996714;
    y = 0.242591;
    w = 0.693434;
    h = 0.472054;
};
class header_gangs: RscText
{
    idc = 1000;
    text = "Verfuegbare Gangs:"; //--- ToDo: Localize;
    x = 0.10606;
    y = 0.188552;
    w = 0.319697;
    h = 0.0393939;
};
class btn_1: RscButtonMenu
{
    idc = 2400;
    text = "Join"; //--- ToDo: Localize;
    x = 0.801768;
    y = 0.240741;
    w = 0.175758;
    h = 0.0494949;
};
class btn_2: RscButtonMenu
{
    idc = 2401;
    text = "remove allie"; //--- ToDo: Localize;
    x = 0.801768;
    y = 0.294613;
    w = 0.175758;
    h = 0.0494949;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////


*/