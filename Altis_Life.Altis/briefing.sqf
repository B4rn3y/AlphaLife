waitUntil {!isServer && {!isNull player} && {player isEqualTo player}};
if (player diarySubjectExists "controls") exitWith {};

player createDiarySubject ["INFO","INFO"];

/*  Example
    player createDiaryRecord ["", //Container
        [
            "", //Subsection
                "
TEXT HERE<br/><br/>
                "
        ]
    ];
*/

    player createDiaryRecord ["INFO",
        [
            "INFO",
             "Alle Infos zum Server findest du im Discord. <br/>Den Link zum Discord findest du im Teamspeak<br/><br/>Teamspeak: alphalife"
        ]
    ];

    player createDiaryRecord ["INFO",
        [
            "Tastaturbelegung",
             "- Ohrenstöpsel : SHIFT + O <br/>- Niederschlagen: STRG+ G <br/>- Fesseln (Kabelbinder benötigt): SHIFT+ R <br/>- Interagieren: Windowstaste <br/>- GPS: STRG (rechts) + M <br/>"
        ]
    ];
