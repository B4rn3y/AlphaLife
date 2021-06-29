private ["_ret","_unique_ID","_perc","_count_all_quests","_count_done_quests","_quest_config"];
_ret = "ERROR";
_unique_ID = param[0,-1,[-1]];
_perc = param[1,false,[false]];

if(_perc) exitWith {
    if(isnil "alpha_quests") exitWith {_ret};

    _count_all_quests = 0;
    _count_done_quests = 0;
    _quest_config = getArray (missionConfigFile >> "cfgQuests" >> "Quests" >> "Quests");
    {
        {
            _count_all_quests = _count_all_quests + 1;
            if((_x select 0) in alpha_quests) then {
                _count_done_quests = _count_done_quests + 1;
            };


        } foreach (_x select 1);


    } foreach _quest_config;

    [_count_all_quests,_count_done_quests]
};


if(_unique_ID isEqualTo -1) exitWith {_ret};


_quest_config = getArray (missionConfigFile >> "cfgQuests" >> "Quests" >> "Quests");


{
    {
        if((_x select 0) isEqualTo _unique_ID) then {
            _ret = _x;

        };


    } foreach (_x select 1);


} foreach _quest_config;


_ret;