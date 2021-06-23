
private ["_actual_name","_display","_str_text","_ok_btn","_back_btn","_text"];

_actual_name = param[0,"",[""]];

0 cutText["","BLACK FADED",99999999];







disableSerialization;
createDialog "welcome_server";
waitUntil {!isnull(findDisplay 9002)};
_display = findDisplay 9002;
if(isNull _display) exitWith {};

_str_text = _display displayCtrl 1100;
_ok_btn = _display displayCtrl 2400;
_back_btn = _display displayCtrl 2401;
if(_actual_name isEqualTo "") then {
	_ret = profileName call life_fnc_rpNameCheck;

	_text = "<t align='center' size='6' shadow='0'>Alpha Life</t><br /><br /><br /><br />";
	_text = _text + "- Teamspeak: alphalife<br /><br />";

	if(_ret isEqualTo "") then {
		_text = _text + format["Willkommen auf Alpha Life,<br /><br />solltest du fortfahren wird dein Datenbankeintrag mit dem Namen '%1' fest verknüpft werden und du kannst in Zukunft nur noch mit diesem Namen auf diesem Server spielen.<br /><br />Eine Änderung des Names kann NUR der Support vornehmen. Du hast jedoch jetzt nochmal die Möglichkeit im Arma 3 Hauptmenü deinen Namen zu ändern. Solltest du das nicht wollen, drücke bitte auf 'Einverstanden'.<br /><br />Viel Spaß auf dem Server.",profileName];

		_str_text ctrlSetStructuredText parseText _text;
		_ok_btn buttonSetAction "closeDialog 0 ;0 call SOCK_fnc_insertPlayerInfo;";
		_back_btn buttonSetAction "closeDialog 0 ;[""WrongName"",false,true] call BIS_fnc_endMission;";
	} else {
		_ok_btn ctrlShow false;
		_text = _text + "Dein aktuller Name ist auf diesem Server so nicht erlaubt. GRUND:<br /><br />- ";
		_text = _text + _ret + "<br /><br />Bitte ändere deinen Namen in ein passendes Roleplay-Format im Arma 3 Hauptemnü und versuche es erneut.";
		_str_text ctrlSetStructuredText parseText _text;
		_back_btn buttonSetAction "closeDialog 0 ;[""WrongName_format"",false,true] call BIS_fnc_endMission;";
	};

} else {
	_ok_btn ctrlShow false;
	_back_btn buttonSetAction "closeDialog 0;";

	_text = "<t align='center' size='6' shadow='0' >Alpha Life</t><br /><br /><br /><br />";

	_text = _text + format["Dein aktueller Name %1 stimmt nicht mit dem in der Datenbank hinterlegten Namen '%2' überein.<br /><br />Gehe zurück in das Arma 3 Hauptmenü und ändere deinen Namen.<br /><br />",profileName, _actual_name];

	_text = _text + "Solltest du deinen Namen ändern wollen, so geht das nur über den Support.<br /><br />";

	_text = _text + "- Teamspeak: alphalife<br /><br />";

	_str_text ctrlSetStructuredText parseText _text;

	waitUntil {isnull(findDisplay 9002)};
	["WrongName",false,true] call BIS_fnc_endMission;
};