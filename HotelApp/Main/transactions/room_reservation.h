#pragma once
#include <iostream>
#include <string>
#include "rooms.h"
using namespace std;



//Error checks and design of this module performed, comments written


void bookRoom(rooms room[], int size) {
	cout << "\n---Room Price List---\nSTANDARD\n* 1 Person: 1000 \n* 2 Person: 1200\n* 4 Person: 1400";
	cout << "\nDELUXE\n* 1 Person: 1500 \n* 2 Person: 1700\n* 4 Person: 1900";
	cout << "\nEXECUTIVE\n* 1 Person: 2000 \n* 2 Person: 2200\n* 4 Person: 2400\n";
	int comfort;
	int bed;
	//Room comfort type selected here
	cout << "\n---Select Room Comfort Type---\n1-) STANDARD  2-) DELUXE  3-) EXECUTIVE\n";
	//All incorrect data entries prevented with loops here. validateInteger function is defined in rooms.h module
	while (true) {
		comfort = validateInteger("(Enter Integer) Your Choice: ");
		if (comfort == 1 || comfort == 2 || comfort == 3) {
			break;
		}
		cout << "\n* ERROR: Please Enter a Valid Operation Number!" << endl << endl;
	}
	//Bed count selected here. Same error check logic applied as above loop
	cout << "\n---Select Number of Beds---\n*1 Person  *2 Person  *4 Person\n";
	while (true) {
		bed = validateInteger("(Enter Integer) Your Choice: ");
		if (bed == 1 || bed == 2 || bed == 4) {
			break;
		}
		cout << "\n* ERROR: Please Enter a Valid Operation Number!" << endl << endl;
	}
	cout << endl;
	//Room numbers meeting the conditions printed to screen here. Moves to next line after printing 5 side by side.
	//The purpose of 'counter' variable is to move to the next line after printing 5 items
	int counter = 1;
	for (int i = 0; i < size; i++) {
		if (room[i].type == (room_type)(comfort - 1) && room[i].number_of_beds == bed && room[i].full == false) {
			cout << room[i].number << " | ";
			if (counter % 5 == 0) {
				cout << endl;
			}
			counter++;
		}
	}
	/*Here the desired room number was subjected to two different tests. First tested if it is in room numbers range,
	if in range, tested again if it meets our desired conditions. If the entered number meets conditions,
	customer info is taken with a for loop*/
	bool isSuitable = false;
	while (true) {
		globalRoomNumber = validateRoomNumber(validateInteger("\nRoom Number You Want to Book: "), room, size);
		cout << endl;
		for (int i = 0; i < size; i++) {
			if (room[i].type == (room_type)(comfort - 1) && room[i].number_of_beds == bed && room[i].full == false && room[i].number == globalRoomNumber) {
				isSuitable = true;
				room[i].full = true;
				cin.ignore();
				for (int j = 0; j < room[i].number_of_beds; j++) {
					cout << "------------------------" << endl;
					cout << "Customer Name: ";
					getline(cin, room[i].customers[j].name);
					cout << "Customer Surname: ";
					getline(cin, room[i].customers[j].surname);
					//Customer TC ID and phone number info taken with function below. This function is defined in rooms.h module
					room[i].customers[j].tc_id_number = validatePhoneAndID("Customer TC ID Number: ", room, i, j, 1);
					room[i].customers[j].phone_number = validatePhoneAndID("Customer Phone Number: ", room, i, j, 2);
					//Here day info taken only for the first customer, others assigned from the first customer
					if (j == 0) {
						room[i].customers[j].day = validateInteger("Customer Stay Duration (Days): ");
						cin.ignore();
					}
					else {
						room[i].customers[j].day = room[i].customers[0].day;
					}
				}
				break;
			}

		}
		//Number checks performed here. While loop broken here
		if (isSuitable) {
			cout << endl;
			break;
		}
		else {
			cout << "* ERROR: Please Select from the Room Numbers Specified Above!" << endl;
		}
	}
}