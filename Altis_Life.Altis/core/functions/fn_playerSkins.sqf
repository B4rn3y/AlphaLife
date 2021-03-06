

private ["_path","_uniform","_root_path","_coplevel","_swat","_mediclevel"];

_path = "";
_uniform = uniform player;
switch (playerSide) do
{
    case west:
    {
        _root_path = "textures\uniforms\cop\";
        _coplevel = call life_coplevel;
        _swat = if(call life_swatlevel > 0) then {true} else {false};
        switch (_uniform) do
        {
            case "U_BG_Guerrilla_6_1":
            {
                switch (_coplevel) do
                {
                    case 8:
                    {
                        _path = _root_path + "cop_president.jpg";
                    };

                    case 7:
                    {
                        _path = _root_path + "cop_president.jpg";
                    };

                    default
                    {
                        _path = _root_path + "cop_normal.jpg";
                    };
                };
            };

            case "U_I_CombatUniform":
            {
                if(_swat) then {
                    _path = _root_path + "cop_swat.jpg";
                };
            };

            case "U_B_GEN_Commander_F":
            {
                if(_swat) then {
                    _path = _root_path + "cop_swat2.jpg";
                };
            };
        };
    };

    case independent:
    {
        _root_path = "textures\uniforms\medic\";
        _mediclevel = call life_mediclevel;
        switch (_uniform) do
        {
            case "U_I_CombatUniform":
            {
                switch (_mediclevel) do
                {
                    default
                    {
                        _path = _root_path + "medic_normal.jpg";
                    };
                };
            };
        };
    };

    case civilian:
    {
        _root_path = "textures\uniforms\gangs\";
        switch (_uniform) do
        {
            case "U_B_CombatUniform_mcam":
            {
                if(missionNamespace getvariable["license_civ_gang_anonym_alcoholic",false]) then {
                    _path = _root_path + "anonymen_alkoholiker.jpg";
                };

            };

            case "U_I_CombatUniform":
            {

                if(((group player) getvariable["gang_id",-1]) isEqualTo 51) then {
                    _path = _root_path + "mobiles_einsatzkommando_uniform.jpg";
                };

                if(((group player) getvariable["gang_id",-1]) isEqualTo 21) then {
                    _path = _root_path + "enemiesNightmare.jpg";
                };
            };

            case "U_B_CTRG_1":
            {
                if(((group player) getvariable["gang_id",-1]) isEqualTo 23) then {
                    _path = _root_path + "alits_nation_guard_uniform.jpg";
                };

            };
        };

        switch (backpack player) do
        {
            case "B_ViperHarness_blk_F":
            {
                if(((group player) getvariable["gang_id",-1]) isEqualTo 51) then {
                    (unitBackpack player) setObjectTextureGlobal[0,(_root_path + "mobiles_einsatzkommando_backpack.jpg")];
                };

                if(((group player) getvariable["gang_id",-1]) isEqualTo 23) then {
                    (unitBackpack player) setObjectTextureGlobal[0,(_root_path + "altis_nation_guard_backpack.jpg")];
                };

            };
        };
    };
};

if!(_path isEqualTo "") then {
    player setObjectTextureGlobal[0,_path];
};

if(playerside in [west,independent]) then {
    (unitBackpack player) setObjectTextureGlobal [0, ""];
};