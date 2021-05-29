/*
    File: init.sqf
    Author: 
    
    Description:
    
*/
StartProgress = false;

if (hasInterface) then {
		[] execVM "briefing.sqf"; //<------Load Briefing
	};

[] execVM "core\kavala.sqf"; 

StartProgress = true;



