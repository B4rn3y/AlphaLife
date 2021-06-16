
private ["_path","_uniform","_coplevel","_swat","_mediclevel"];

_path = "";
_uniform = uniform player;
switch (playerSide) do
{
    case west:
    {
        _path = "textures\uniforms\cop\";
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
                        _path = _path + "cop_president.jpg";
                    };

                    case 7:
                    {
                        _path = _path + "cop_president.jpg";
                    };

                    default
                    {
                        _path = _path + "cop_normal.jpg";
                    };
                };
            };

            case "U_I_CombatUniform":
            {
                if(_swat) then {
                    _path = _path + "cop_swat.jpg";
                };
            };
        };
    };

    case independent:
    {
        _path = "textures\uniforms\medic\";
        _mediclevel = call life_mediclevel;
        switch (_uniform) do
        {
            case "U_I_CombatUniform":
            {
                switch (_mediclevel) do
                {
                    default
                    {
                        _path = _path + "medic_normal.jpg";
                    };
                };
            };
        };
    };
};

if!(_path isEqualTo "") then {
    player setObjectTextureGlobal[0,_path];
    if(playerside in [west,independent]) then {
        (unitBackpack player) setObjectTextureGlobal [0, ""];
    };
};