#pragma once
#include <iostream>
#include <string>
#include "rooms.h"
using namespace std;

void getRoomReport(rooms room[], int size) {
	//Room number was obtained from the user using two functions defined in rooms.h
	globalRoomNumber = validateRoomNumber(validateInteger("\nEnter the Room Number to Check Status: "), room, size);
	for (int i = 0; i < size; i++) {
		if (room[i].number == globalRoomNumber) {
			//Room information is printed first, then customer information is printed
			cout << "\n---Room Information---" << endl;
			cout << "Room Type : " << convertRoomTypeToString(room[i].type) << endl;
			cout << "Number of Beds : " << room[i].number_of_beds << endl;
			cout << "Occupancy: " << ((room[i].full == true) ? "FULL" : "EMPTY") << endl;
			cout << "Nightly Cost: " << room[i].cost << endl;
			if (room[i].full == true) {
				cout << "---Customer Information---" << endl;
				for (int j = 0; j < room[i].number_of_beds; j++) {
					cout << "-----------------" << endl;
					cout << "Customer Name: " << room[i].customers[j].name << endl;
					cout << "Customer Surname: " << room[i].customers[j].surname << endl;
					cout << "Customer TC ID Number: " << room[i].customers[j].tc_id_number << endl;
					cout << "Customer Phone Number: " << room[i].customers[j].phone_number << endl;
					cout << "Customer Stay Duration (Days): " << room[i].customers[j].day << endl;



				}
			}
		}
	}
	cout << endl;
}