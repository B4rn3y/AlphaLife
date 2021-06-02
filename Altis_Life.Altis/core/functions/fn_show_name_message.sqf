

private ["_display","_str_text","_text"];
0 cutText["","BLACK FADED",99999999];
disableSerialization;
createDialog "welcome_server";

_display = findDisplay 9002;
if(isNull _display) exitWith {};

_str_text = _display displayCtrl 1100;


_text = "<t align='center' size='6' shadow='0'>Alpha Life</t><br /><br />";
_text = _text + format["Willkommen auf Alpha Life,<br /><br />solltest du fortfahren wird dein Datenbankeintrag mit dem Namen '%1' fest verknüpft werden und du kannst in Zukunft nur noch mit diesem Namen auf diesem Server spielen.<br /><br />Eine Änderung des Names kann NUR der Support vornehmen. Du hast jedoch jetzt nochmal die Möglichkeit im Arma 3 Hauptmenü deinen Namen zu ändern. Solltest du das nicht wollen, drücke bitte auf 'Einverstanden'.<br /><br />Viel Spaß auf dem Server.",profileName];