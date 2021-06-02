class welcome_server {
    idd = 9002;
    name= "welcome_server";
    movingEnable = false;
    enableSimulation = true;
    //onLoad = "[] spawn life_fnc_wantedadd2;";

    class controlsBackground {
        class Life_RscTitleBackground: Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            text="Alpha Life";
            idc = -1;
            x = -0.07575;
            y = -0.0084;
            w = 1.14419;
            h = 0.0343433;
        };

        class MainBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = -0.07575;
            y = 0.0272;
            w = 1.14419;
            h = 0.945116;
        };
    };

    class controls {
        class RscStructuredText_1100: life_RscStructuredText
        {
            idc = 1100;
            text="";
            x = -0.06825;
            y = 0.032;
            w = 1.1303;
            h = 0.928284;
        };
        class btn_ok: life_RscButtonMenu
        {
            idc = 2400;
            text = "Einverstanden"; //--- ToDo: Localize;
            x = 0.869949;
            y = 0.973064;
            w = 0.198485;
            h = 0.0427609;
        };
        class btn_no: life_RscButtonMenu
        {
            idc = 2401;
            text = "Zurueck zur Lobby"; //--- ToDo: Localize;
            x = -0.0757576;
            y = 0.973064;
            w = 0.256566;
            h = 0.039394;
        };
    };
};



/* #Vykuju
$[
    1.063,
    ["welcome",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1000,"main_bckgrnd",[0,"",[-0.07575,0.0272,1.14419,0.945116],[-1,-1,-1,-1],[0,0,0,0.5],[-1,-1,-1,-1],"","-1"],[]],
    [1001,"header",[0,"",[-0.07575,-0.0084,1.14419,0.0343433],[-1,-1,-1,-1],[0,1,0,1],[-1,-1,-1,-1],"","-1"],[]],
    [1100,"",[0,"",[-0.06825,0.032,1.1303,0.928284],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"btn_ok",[0,"Einverstanden",[0.869949,0.973064,0.198485,0.0427609],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2401,"btn_no",[0,"ZurÃ¼ck zur Lobby",[-0.0757576,0.973064,0.256566,0.039394],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]


////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Vykuju)
////////////////////////////////////////////////////////

class main_bckgrnd: RscText
{
    idc = 1000;
    x = -0.07575;
    y = 0.0272;
    w = 1.14419;
    h = 0.945116;
    colorBackground[] = {0,0,0,0.5};
};
class header: RscText
{
    idc = 1001;
    x = -0.07575;
    y = -0.0084;
    w = 1.14419;
    h = 0.0343433;
    colorBackground[] = {0,1,0,1};
};
class RscStructuredText_1100: RscStructuredText
{
    idc = 1100;
    x = -0.06825;
    y = 0.032;
    w = 1.1303;
    h = 0.928284;
};
class btn_ok: RscButtonMenu
{
    idc = 2400;
    text = "Einverstanden"; //--- ToDo: Localize;
    x = 0.869949;
    y = 0.973064;
    w = 0.198485;
    h = 0.0427609;
};
class btn_no: RscButtonMenu
{
    idc = 2401;
    text = "ZurÃ¼ck zur Lobby"; //--- ToDo: Localize;
    x = -0.0757576;
    y = 0.973064;
    w = 0.256566;
    h = 0.039394;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////


*/
