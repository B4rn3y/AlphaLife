class Socket_Reciever {
    tag = "SOCK";
    class SQL_Socket {
        file = "core\session";
        class dataQuery {};
        class insertPlayerInfo {};
        class requestReceived {};
        class syncData {};
        class updatePartial {};
        class updateRequest {};
    };
};

class Life_Client_Core {
    tag = "life";

    class Master_Directory {
        file = "core";
        class initCiv {};
        class initCop {};
        class initMedic {};
        class setupActions {};
        class setupEVH {};
        class survival {};
        class initSafezones {};
    };

    class Actions {
        file = "core\actions";
        class arrestAction {};
        class buyLicense {};
        class captureHideout {};
        class catchFish {};
        class dpFinish {};
        class dropFishingNet {};
        class escortAction {};
        class gather {};
        class getDPMission {};
        class gutAnimal {};
        class healHospital {};
        class impoundAction {};
        class mine {};
        class newsBroadcast {};
        class packupSpikes {};
        class pickupItem {};
        class pickupMoney {};
        class postBail {};
        class processAction {};
        class pulloutAction {};
        class putInCar {};
        class removeContainer {};
        class repairTruck {};
        class restrainAction {};
        class robAction {};
        class searchAction {};
        class searchVehAction {};
        class seizePlayerAction {};
        class serviceChopper {};
        class stopEscorting {};
        class storeVehicle {};
        class surrender {};
        class ticketAction {};
        class unrestrain {};
    };

    class Admin {
        file = "core\admin";
        class adminCompensate {};
        class adminDebugCon {};
        class adminFreeze {};
        class admingetID {};
        class adminGodMode {};
        class adminid {};
        class admininfo {};
        class adminMarkers {};
        class adminMenu {};
        class adminQuery {};
        class adminSpectate {};
        class adminTpHere {};
        class adminTpTo {};
        class teleesp {};
        class invis {};
        class addMoney {};
        class BA_admin_menu_open_dialog {};
        class BA_admin_menu_execute_code {};
    };

    class Civilian {
        file = "core\civilian";
        class civMarkers {};
        class demoChargeTimer {};
        class freezePlayer {};
        class jail {};
        class jailMe {};
        class knockedOut {};
        class knockoutAction {};
        class removeLicenses {};
        class robPerson {};
        class robReceive {};
        class tazed {};
        class Frogtrap {};
        class robGasStation {};
        class robsmallbank {};
    };

    class Config {
        file = "core\config";
        class houseConfig {};
        class itemWeight {};
        class vehicleAnimate {};
        class vehicleWeightCfg {};
    };

    class Cop {
        file = "core\cop";
        class bountyReceive {};
        class containerInvSearch {};
        class copInteractionMenu {};
        class copLights {};
        class copMarkers {};
        class copSearch {};
        class copSiren {};
        class doorAnimate {};
        class fedCamDisplay {};
        class licenseCheck {};
        class licensesRead {};
        class questionDealer {};
        class radar {};
        class repairDoor {};
        class restrain {};
        class searchClient {};
        class seizeClient {};
        class sirenLights {};
        class spikeStripEffect {};
        class ticketGive {};
        class ticketPaid {};
        class ticketPay {};
        class ticketPrompt {};
        class vehInvSearch {};
        class wantedGrab {};
        class gateAct {};
        class copcallmanagement {};
        class CopOptionsMenu {};
        class placeablesMenu {};
        class placeablesRemoveAll {};
        class placeablePlace {};
        class placeableCancel {};
        class placeablesPlaceComplete {};
        class copLightPosition {};
        class unlockVeh {};
        class bankSiren {};
        class remove_horn {};
    };

    class Dialog_Controls {
        file = "dialog\function";
        class bankDeposit {};
        class bankTransfer {};
        class bankWithdraw {};
        class displayHandler {};
        class gangBankResponse {};
        class garageLBChange {};
        class impoundMenu {};
        class progressBar {};
        class safeFix {};
        class safeInventory {};
        class safeOpen {};
        class safeTake {};
        class sellGarage {};
        class setMapPosition {};
        class spawnConfirm {};
        class spawnMenu {};
        class spawnPointCfg {};
        class spawnPointSelected {};
        class unimpound {};
        class useGangBank {};
        class vehicleGarage {};
        class wireTransfer {};
        class show_name_message {};
        class insurecar {};
        class garageComboChange {};
        class garage_set_gang {};
    };

    class exclusion_zone {
        file = "core\exclusion_zone";
        class sz_add {};
        class sz_del {};
        class sz_find {};
        class sz_hideGUI {};
        class sz_msg_add {};
        class sz_msg_del {};
        class init_exclusion_zones {};
    };

    class Functions {
        file = "core\functions";
        class AAN {};
        class accType {};
        class actionKeyHandler {};
        class animSync {};
        class calWeightDiff {};
        class checkMap {};
        class clearVehicleAmmo {};
        class dropItems {};
        class escInterupt {};
        class fetchCfgDetails {};
        class fetchDeadGear {};
        class fetchVehInfo {};
        class isDamaged {};
        class giveDiff {};
        class handleDamage {};
        class handleInv {};
        class handleItem {};
        class hideObj {};
        class hudSetup {};
        class hudUpdate {};
        class inventoryClosed {};
        class inventoryOpened {};
        class isUIDActive {};
        class keyHandler {};
        class loadDeadGear {};
        class loadGear {};
        class nearATM {};
        class nearestDoor {};
        class nearUnits {};
        class numberText {};
        class onFired {};
        class onTakeItem {};
        class playerSkins {};
        class playerTags {};
        class postNewsBroadcast {};
        class pullOutVeh {};
        class pushObject {};
        class receiveItem {};
        class receiveMoney {};
        class receiveMoney_admin {};
        class revealObjects {};
        class saveGear {};
        class simDisable {};
        class startLoadout {};
        class stripDownPlayer {};
        class teleport {};
        class whereAmI {};
        class moveIn {};
        class exp_hint {};
        class nearestObjects {};
        class showInvInfo {};
        class processEVH {};
        class centerMsg {};
        class fadeSound {};
        class radiation {};
        class mapMarkerplayer {};
        class rpNameCheck {};
        class nearplayers {};
        class findPlayerOfPID {};
    };

    class FSM {
        file = "core\fsm";
        class LightsLoop {ext = ".fsm";};
        class circleCamera3D {ext = ".fsm";};
    };

    class Gangs {
        file = "core\gangs";
        class createGang {};
        class gangCreated {};
        class gangDisband {};
        class gangDisbanded {};
        class gangInvite {};
        class gangInvitePlayer {};
        class gangKick {};
        class gangLeave {};
        class gangMenu {};
        class gangNewLeader {};
        class gangUpgrade {};
        class initGang {};
        class gang_find_member_entry {};
        class gangUpdate_client {};
        class gangJoin {};
        class gang_allie_menu {};
        class gang_invite_allie {};
        class gang_invite_allie_received {};
        class gang_invite_allie_resp_received {};
        class gang_remove_allie {};
        class gang_set_taxes {};
        class gang_rights_dialog_EVH {};
        class gang_rights_dialog {};
        class gang_public {};
    };

    class Gang_Area {
        file = "core\gang_area";
        class capture_area {};
        class gang_area_receive_money {};
    };

    class Housing {
        file = "core\housing";
        class buyHouse {};
        class buyHouseGarage {};
        class containerMenu {};
        class copBreakDoor {};
        class copHouseOwner {};
        class garageRefund {};
        class getBuildingPositions {};
        class houseMenu {};
        class initHouses {};
        class lightHouse {};
        class lightHouseAction {};
        class lockHouse {};
        class lockupHouse {};
        class placeContainer {};
        class PlayerInBuilding {};
        class raidHouse {};
        class sellHouse {};
        class sellHouseGarage {};
    };

    class Items {
        file = "core\items";
        class blastingCharge {};
        class boltcutter {};
        class defuseKit {};
        class flashbang {};
        class jerrycanRefuel {};
        class jerryRefuel {};
        class lockpick {};
        class placestorage {};
        class spikeStrip {};
        class storageBox {};
        class painkiller {};
    };

    class Medical_System {
        file = "core\medical";
        class deathScreen {};
        class medicLights {};
        class medicMarkers {};
        class medicRequest {};
        class medicSiren {};
        class medicSirenLights {};
        class onPlayerKilled {};
        class onPlayerRespawn {};
        class requestMedic {};
        class respawned {};
        class revived {};
        class revivePlayer {};
        class medcallmanagement {};
        class medInteractionMenu {};
    };

    class Network {
        file = "core\functions\network";
        class broadcast {};
        class corpse {};
        class jumpFnc {};
        class say3D {};
        class setFuel {};
        class soundDevice {};
    };

    class Player_Menu {
        file = "core\pmenu";
        class cellphone {};
        class giveItem {};
        class giveMoney {};
        class keyDrop {};
        class keyGive {};
        class keyMenu {};
        class p_openMenu {};
        class p_updateMenu {};
        class pardon {};
        class removeItem {};
        class s_onChar {};
        class s_onCheckedChange {};
        class s_onSliderChange {};
        class settingsMenu {};
        class updateViewDistance {};
        class useItem {};
        class wantedAddP {};
        class wantedInfo {};
        class wantedList {};
        class wantedMenu {};
        class keyGiveGang {};
        class licenseMenu {};
        class p_market_menu {};
        class p_market_menu_EVH {};
    };

    class Quests {
        file = "core\quests";
        class check_quests {};
        class quest_achieved {};
        class quest_config_index {};
        class questmenuEVH {};
        class questmenuopen {};
    };

    class Shops {
        file = "core\shops";
        class 3dPreviewDisplay {};
        class 3dPreviewExit {};
        class 3dPreviewInit {};
        class atmMenu {};
        class buyClothes {};
        class changeClothes {};
        class chopShopMenu {};
        class chopShopSelection {};
        class chopShopSell {};
        class chopShopSold {};
        class clothingFilter {};
        class clothingMenu {};
        class fuelLBchange {};
        class fuelStatOpen {};
        class levelCheck {};
        class vehicleShopBuy {};
        class vehicleShopLBChange {};
        class vehicleShopMenu {};
        class virt_buy {};
        class virt_menu {};
        class virt_sell {};
        class virt_update {};
        class weaponShopAccs {};
        class weaponShopBuySell {};
        class weaponShopFilter {};
        class weaponShopMags {};
        class weaponShopMenu {};
        class weaponShopSelection {};
    };

    class skills {
        file = "core\skills";
        class calculate_level {};
        class addexp {};
        class skill_menu_TreeSelChanged {};
        class open_skill_menu {};
        class init_skills {};
    };

    class tuning {
        file = "core\tuning";
        class create_tuning_shop {};
        class open_tuning_shop {};
        class tuning_shop_combo_EVH {};
        class tuning_shop_lb_EVH {};
        class tuning_shop_buy {};
        class GetInEVH {};
        class GetOutEVH {};
        class oilspill_fire {};
        class oilspill_receive {};
        class nitro {};
        class update_vehicle_hud {};
        class car_light {};
        class car_light_receive {};
    };

    class Vehicle {
        file = "core\vehicle";
        class addVehicle2Chain {};
        class colorVehicle {};
        class deviceMine {};
        class FuelRefuelcar {};
        class fuelStore {};
        class fuelSupply {};
        class lockVehicle {};
        class openInventory {};
        class vehiclecolor3DRefresh {};
        class vehicleOwners {};
        class vehicleWeight {};
        class vehInventory {};
        class vehStoreItem {};
        class vehTakeItem {};
        class vInteractionMenu {};
        class lightConfig {};
        class light_switch {};
    };
};
