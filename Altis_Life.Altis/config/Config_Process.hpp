/*
*   class:
*       MaterialsReq (Needed to process) = Array - Format -> {{"ITEM CLASS",HOWMANY}}
*       MaterialsGive (Returned items) = Array - Format -> {{"ITEM CLASS",HOWMANY}}
*       Text (Progess Bar Text) = Localised String
*       NoLicenseCost (Cost to process w/o license) = Scalar
*
*   Example for multiprocess:
*
*   class Example {
*       MaterialsReq[] = {{"cocaine_processed",1},{"heroin_processed",1}};
*       MaterialsGive[] = {{"diamond_cut",1}};
*       Text = "STR_Process_Example";
*       //ScrollText = "Process Example";
*       NoLicenseCost = 4000;
*   };
*/

class ProcessAction {
    class oil {
        MaterialsReq[] = {{"oil_unprocessed",1}};
        MaterialsGive[] = {{"oil_processed",1}};
        Text = "STR_Process_Oil";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class shell {
        MaterialsReq[] = {{"shell",1}};
        MaterialsGive[] = {{"pearl",1}};
        Text = "STR_Process_Shell";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class jewellry {
        MaterialsReq[] = {{"diamond_cut",1},{"iron_refined",2}};
        MaterialsGive[] = {{"jewellry",1}};
        Text = "STR_Process_Jewellry";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class lsd {
        MaterialsReq[] = {{"frog",1}};
        MaterialsGive[] = {{"lsd",1}};
        Text = "STR_Process_lsd";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class snake {
        MaterialsReq[] = {{"snake",1}};
        MaterialsGive[] = {{"snake_venom",1}};
        Text = "STR_Process_Snake";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class coal {
        MaterialsReq[] = {{"coal_ore",1}};
        MaterialsGive[] = {{"coal",1}};
        Text = "STR_Process_Coal";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class black_powder {
        MaterialsReq[] = {{"coal",1}};
        MaterialsGive[] = {{"black_powder",1}};
        Text = "STR_Process_Black_Powder";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class washed_uran {
        MaterialsReq[] = {{"unwashed_uran",1}};
        MaterialsGive[] = {{"washed_uran",1}};
        Text = "STR_Process_Washed_Uran";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class grenade {
        MaterialsReq[] = {{"iron_refined",2},{"black_powder",1}};
        MaterialsGive[] = {{"grenade",1}};
        Text = "STR_Process_Grenade";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class dried_uran {
        MaterialsReq[] = {{"washed_uran",1}};
        MaterialsGive[] = {{"dried_uran",1}};
        Text = "STR_Process_Dried_Uran";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class uran {
        MaterialsReq[] = {{"dried_uran",1}};
        MaterialsGive[] = {{"uran",1}};
        Text = "STR_Process_Uran";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class whiskey {
        MaterialsReq[] = {{"glass",2}};
        MaterialsGive[] = {{"whiskey",1}};
        Text = "STR_Process_Whiskey";
        //ScrollText = "Process Oil";
        NoLicenseCost = 1200;
    };

    class diamond {
        MaterialsReq[] = {{"diamond_uncut",1}};
        MaterialsGive[] = {{"diamond_cut",1}};
        Text = "STR_Process_Diamond";
        //ScrollText = "Cut Diamonds";
        NoLicenseCost = 1350;
    };

    class heroin {
        MaterialsReq[] = {{"heroin_unprocessed",1}};
        MaterialsGive[] = {{"heroin_processed",1}};
        Text = "STR_Process_Heroin";
        //ScrollText = "Process Heroin";
        NoLicenseCost = 1750;
    };

    class copper {
        MaterialsReq[] = {{"copper_unrefined",1}};
        MaterialsGive[] = {{"copper_refined",1}};
        Text = "STR_Process_Copper";
        //ScrollText = "Refine Copper";
        NoLicenseCost = 750;
    };

    class iron {
        MaterialsReq[] = {{"iron_unrefined",1}};
        MaterialsGive[] = {{"iron_refined",1}};
        Text = "STR_Process_Iron";
        //ScrollText = "Refine Iron";
        NoLicenseCost = 1120;
    };

    class sand {
        MaterialsReq[] = {{"sand",1}};
        MaterialsGive[] = {{"glass",1}};
        Text = "STR_Process_Sand";
        //ScrollText = "Melt Sand into Glass";
        NoLicenseCost = 650;
    };

    class cocaine {
        MaterialsReq[] = {{"cocaine_unprocessed",1}};
        MaterialsGive[] = {{"cocaine_processed",1}};
        Text = "STR_Process_Cocaine";
        //ScrollText = "Process Cocaine";
        NoLicenseCost = 1500;
    };

    class marijuana {
        MaterialsReq[] = {{"cannabis",1}};
        MaterialsGive[] = {{"marijuana",1}};
        Text = "STR_Process_Marijuana";
        //ScrollText = "Harvest Marijuana";
        NoLicenseCost = 500;
    };

    class cement {
        MaterialsReq[] = {{"rock",1}};
        MaterialsGive[] = {{"cement",1}};
        Text = "STR_Process_Cement";
        //ScrollText = "Mix Cement";
        NoLicenseCost = 350;
    };
};
