class gang_taxes {
    idd = 84785;
    name= "gang_taxes";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "";

    class controlsBackground {
        class bckgrnd: life_RscText
        {
            idc = 1000;
            x = 0.311869;
            y = 0.462963;
            w = 0.435859;
            h = 0.0713806;
            colorBackground[] = {0,0,0,0.7};
        };
    };

    class controls {
        class RscEdit_1400: life_RscEdit
        {
            idc = 1400;
            text = "0-50%";
            tooltip = "Steuern gehen direkt auf das Gang-Konto und werden nur beim Verkauf von Z-Items erhoben";
            onSetFocus = "params [""_control""];_control ctrlSetText """";";
            x = 0.315657;
            y = 0.469697;
            w = 0.27298;
            h = 0.0579124;
        };
        class RscButtonMenu_2400: life_RscButtonMenu
        {
            idc = 2400;
            text = "Einstellen"; //--- ToDo: Localize;
            OnButtonClick="[] spawn life_fnc_gang_set_taxes;";
            x = 0.590909;
            y = 0.469697;
            w = 0.15303;
            h = 0.0562289;
        };
    };
};






/* #Bofeqa
$[
    1.063,
    ["s",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
    [1000,"bckgrnd",[0,"",[0.311869,0.462963,0.435859,0.0713806],[-1,-1,-1,-1],[0,0,0,0.7],[-1,-1,-1,-1],"","-1"],[]],
    [1400,"",[0,"",[0.315657,0.469697,0.27298,0.0579124],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [2400,"",[0,"Einstellen",[0.590909,0.469697,0.15303,0.0562289],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/
/*

////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Barney, v1.063, #Bofeqa)
////////////////////////////////////////////////////////

class bckgrnd: RscText
{
    idc = 1000;
    x = 0.311869;
    y = 0.462963;
    w = 0.435859;
    h = 0.0713806;
    colorBackground[] = {0,0,0,0.7};
};
class RscEdit_1400: RscEdit
{
    idc = 1400;
    x = 0.315657;
    y = 0.469697;
    w = 0.27298;
    h = 0.0579124;
};
class RscButtonMenu_2400: RscButtonMenu
{
    idc = 2400;
    text = "Einstellen"; //--- ToDo: Localize;
    x = 0.590909;
    y = 0.469697;
    w = 0.15303;
    h = 0.0562289;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////


*/