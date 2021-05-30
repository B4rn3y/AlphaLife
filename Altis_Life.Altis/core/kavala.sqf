private ["_objects","_object","_data"];
_data = [
	//Kavala Cop HQ Bäume
	["a3\plants_f\tree\t_broussonetiap1s_f.p3d", [3300.04,12488.3,7.81765], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_broussonetiap1s_f.p3d", [3309.1,12454.2,7.82475], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_broussonetiap1s_f.p3d", [3308.24,12437.3,7.35728], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_broussonetiap1s_f.p3d", [3260.28,12409.7,6.91611], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_broussonetiap1s_f.p3d", [3244.65,12415.7,7.6886], [[-0.674256,0.738498,0],[0,0,1]]],
	["a3\plants_f\tree\t_ficusb2s_f.p3d", [3251.28,12486.5,6.15131], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_ficusb2s_f.p3d", [3269.04,12491.4,6.86365], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_ficusb2s_f.p3d", [3285.11,12495.5,7.55737], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_ficusb2s_f.p3d", [3297.91,12425.9,7.50443], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_ficusb2s_f.p3d", [3236.62,12434.2,7.08582], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_ficusb2s_f.p3d", [3231.46,12450.8,6.56057], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_ficusb2s_f.p3d", [3226.93,12466.8,5.72832], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_fraxinusav2s_f.p3d", [3287.09,12455.3,7.10909], [[0,1,0],[0,0,1]]],
	["a3\plants_f\tree\t_fraxinusav2s_f.p3d", [3254.63,12446.8,6.82898], [[0,1,0],[0,0,1]]]
];
_objects = [];
{
	_object = createSimpleObject [(_x select 0), (ASLToAGL(_x select 1))];
	_object setVectorDirAndUp (_x select 2);
	_object setPosASL (_x select 1);
	_objects pushBack _object;
} forEach _data;
_objects;
