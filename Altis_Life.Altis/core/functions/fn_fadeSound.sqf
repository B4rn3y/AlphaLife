

private ["_possibleFade","_fadeTo"];

_possibleFade = [1,0.5,0.25,0.1,0.01]; //Werte in %

life_fadeSound = (life_fadeSound + 1) % (count _possibleFade);

[] call life_fnc_hudUpdate;

_fadeTo = (_possibleFade select life_fadeSound);

1 fadeSound _fadeTo;

if (_fadeTo < 1) then
{
	titleText [format["Spielsound verringert auf %1%2 \n Strg + Umschalt + O für normalen Sound .",_fadeTo*100,"%"], "PLAIN DOWN",0.5];
}
else
{
	titleText ["Spielsound wieder normal.", "PLAIN DOWN",0.5];
};