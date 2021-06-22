
class Admin_Conf {
    class Conf {

        Scripts[] = {
            {"--==Standard Functions==--"},
            { "Give Money (myself)", "[] spawn life_fnc_addMoney", 2},
            { "Give Money (Selected Player)", "[lbdata[1501,(lbcursel 1501)]] spawn life_fnc_addMoney", 2},
            { "Tele/ESP", "[] spawn life_fnc_teleesp", 1},
            { "Spectate (Select Player), ", "[] spawn life_fnc_adminSpectate",1},
            { "TP Player to me", "[] spawn life_fnc_adminTpHere", 1},
            { "TP me to Player", "[] spawn life_fnc_adminTpTo", 1},
            { "GODMODE", "[] spawn life_fnc_adminGodMode", 1},
            { "Freeze/Unfreeze Player", "[] spawn life_fnc_adminFreeze", 1},
            { "Invisibility ON/OFF", "[] spawn life_fnc_invis", 1},
            {"--==Event Functions==--"}
        };
    };


};
