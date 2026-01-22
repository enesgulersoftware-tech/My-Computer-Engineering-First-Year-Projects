#pragma once
#include <iostream>
#include <string>
#include "rooms.h"
using namespace std;


//Error checks and comments performed




//This module ensures total and occupied room counts are printed to the screen along with their types
void showRoomStatistics(rooms room[], int size) {

	struct room_stats_struct {
		int single_bed = 0;
		int single_bed_full = 0;

		int double_bed = 0;
		int double_bed_full = 0;

		int quad_bed = 0;
		int quad_bed_full = 0;
	}room_stats[3];



	for (int i = 0; i < size; i++) {
		/*We converted the enum data specifying room types defined in rooms.h to integer and assigned it to j.
		The reason was to calculate STANDARD, DELUXE, and EXECUTIVE types separately. It allowed us to index the room_stats object*/
		int j = static_cast<int>(room[i].type);
		//First, it finds the total room count, then if it meets the second condition, it calculates the occupied room count
		if (room[i].number_of_beds == 1) {
			room_stats[j].single_bed++;
			if (room[i].full) {
				room_stats[j].single_bed_full++;
			}
		}
		else if (room[i].number_of_beds == 2) {
			room_stats[j].double_bed++;
			if (room[i].full) {
				room_stats[j].double_bed_full++;
			}

		}
		else if (room[i].number_of_beds == 4) {
			room_stats[j].quad_bed++;
			if (room[i].full) {
				room_stats[j].quad_bed_full++;
			}
		}


	}
	//convertRoomTypeToString function is defined in rooms.h module
	for (int i = 0; i < 3; i++) {
		cout << "\n---" << convertRoomTypeToString(static_cast<room_type>(i)) << "---" << endl;
		cout << "1-Person Room Count: " << room_stats[i].single_bed << endl;
		cout << "1-Person Occupied Room Count: " << room_stats[i].single_bed_full << endl;
		cout << "2-Person Room Count: " << room_stats[i].double_bed << endl;
		cout << "2-Person Occupied Room Count: " << room_stats[i].double_bed_full << endl;
		cout << "4-Person Room Count: " << room_stats[i].quad_bed << endl;
		cout << "4-Person Occupied Room Count: " << room_stats[i].quad_bed_full << endl;
		cout << endl;
	}

}