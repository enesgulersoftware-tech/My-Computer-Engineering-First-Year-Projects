#pragma once
#include <iostream>
#include <string>
#include "rooms.h"
#include "total_income.h"
using namespace std;


//Error checks performed, customer information deleted


//income variable holds revenue from only one room, we send this to total_income module to add to the safe
int currentIncome = 0;
void checkOutRoom(rooms room[], int size) {
	/*roomNumber obtained via validateInteger function (rooms.h). globalRoomNumber variable and validateRoomNumber function are also taken from rooms.h module.*/
	globalRoomNumber = validateRoomNumber(validateInteger("\nPlease Enter the Room Number to Check Out: "), room, size);
	for (int i = 0; i < size; i++) {

		if (room[i].number == globalRoomNumber) {
			if (room[i].full == false) {
				cout << "\nThis Room is Already Empty!" << endl << endl;
			}
			//Customer information in the room is deleted here
			else {
				currentIncome = (room[i].cost) * (room[i].customers[0].day);
				room[i].full = false;
				for (int j = 0; j < room[i].number_of_beds; j++) {
					room[i].customers[j].name.clear();
					room[i].customers[j].surname.clear();
					room[i].customers[j].tc_id_number.clear();
					room[i].customers[j].phone_number.clear();
					room[i].customers[j].day = 0;
				}
				cout << "\nRoom Number " << globalRoomNumber << " Checked Out Successfully!\nFee: " << currentIncome << endl << endl;
				//Income is entered into total_income function to be added to the main safe
				calculateTotalIncome(currentIncome);
			}
			break;
		}
	}
}