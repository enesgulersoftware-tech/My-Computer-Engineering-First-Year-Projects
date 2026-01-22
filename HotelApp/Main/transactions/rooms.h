#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <time.h>
using namespace std;


//Comment lines written

int globalRoomNumber;
//Room types defined with enum
enum room_type {
	STANDARD, DELUXE, EXECUTIVE
};
//Customer information collected in struct
struct customer {
	string name;
	string surname;
	string tc_id_number;
	string phone_number;
	int day = 0;
};
//Room information collected in struct
struct rooms {
	int number;
	room_type type;
	int number_of_beds;
	bool full;
	int cost;
	//Since max customers is 4, an array of 4 elements was created
	customer customers[4];

}room[300];//Number of rooms defined here

//This function converts enum types to string for printing
string convertRoomTypeToString(room_type type) {
	switch (type) {
	case STANDARD: return "STANDARD";
	case DELUXE: return "DELUXE";
	case EXECUTIVE: return "EXECUTIVE";
	}

}
//This is the number control function used in all modules. It tests for integer type.
int validateInteger(string message) {
	int input;
	while (true) {
		cout << message;
		cin >> input;
		try {
			if (cin.fail()) {
				throw string("* ERROR: Please Enter Integer Values!");
			}

			if (cin.peek() != '\n') {
				throw string("* ERROR: Please Enter Integer Values!");
			}

			return input;

		}
		catch (string error) {
			cout << endl << error << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}
/*Tests if the entered room number is valid. Also checks for integer input while taking parameters.
If the number is invalid, it sends it back to the function for re-validation*/
int validateRoomNumber(int number, rooms room[], int size) {
	while (true) {
		for (int i = 0; i < size; i++) {
			if (room[i].number == number) {
				return number;
			}
		}
		cout << endl << "* ERROR: Our Room Numbers are between 100 and 400. Please Enter Again!" << endl << endl;
		number = validateInteger("Room Number: ");
	}
}

/*This function takes TC ID and phone number to check for non-numeric values and length.
The 'operationNumber' parameter helps us understand if the incoming operation is a TC ID or a phone number.
'message' prints the operation message to the screen. 'i' and 'j' allow us to enter customer info for the specific room*/
string validatePhoneAndID(string message, rooms room[], int i, int j, int operationNumber) {
	bool hasError = false;//We keep track if the entered value is wrong with this variable
	if (operationNumber == 1) {
		while (true) {
			cout << message;
			getline(cin, room[i].customers[j].tc_id_number);
			for (int check = 0; check < room[i].customers[j].tc_id_number.size(); check++) {
				if (!isdigit(room[i].customers[j].tc_id_number[check]) || room[i].customers[j].tc_id_number.size() != 11) {
					cout << "\n* ERROR: Please Check the Entered TC ID Number!" << endl << endl;
					hasError = true;
					break;
				}
			}
			if (!hasError) {
				return room[i].customers[j].tc_id_number;
			}
			hasError = false;
		}
	}
	else if (operationNumber == 2) {
		while (true) {
			cout << message;
			getline(cin, room[i].customers[j].phone_number);
			for (int check = 0; check < room[i].customers[j].phone_number.size(); check++) {
				if (!isdigit(room[i].customers[j].phone_number[check]) || (room[i].customers[j].phone_number.size() != 10 && room[i].customers[j].phone_number.size() != 11)) {
					cout << "\n* ERROR: Please Check the Entered Phone Number!" << endl << endl;
					hasError = true;
					break;
				}
			}
			if (!hasError) {
				return room[i].customers[j].phone_number;
			}
			hasError = false;
		}
	}
}

//Room numbers and properties created here. Bed counts and types assigned randomly
void assignRoomProperties(rooms room[]) {
	srand(time(0));
	int bed[3] = { 1,2,4 };
	for (int i = 0; i < 300; i++) {
		room[i].number = 100 + i;
		int room_type_number = rand() % 3;
		room[i].type = (room_type)room_type_number;
		room[i].number_of_beds = bed[rand() % 3];
		room[i].full = false;

		if (room[i].type == STANDARD) {
			if (room[i].number_of_beds == 1)
				room[i].cost = 1000;
			else if (room[i].number_of_beds == 2)
				room[i].cost = 1200;
			else if (room[i].number_of_beds == 4)
				room[i].cost = 1400;
		}
		else if (room[i].type == DELUXE) {
			if (room[i].number_of_beds == 1)
				room[i].cost = 1500;
			else if (room[i].number_of_beds == 2)
				room[i].cost = 1700;
			else if (room[i].number_of_beds == 4)
				room[i].cost = 1900;
		}
		else if (room[i].type == EXECUTIVE) {
			if (room[i].number_of_beds == 1)
				room[i].cost = 2100;
			else if (room[i].number_of_beds == 2)
				room[i].cost = 2200;
			else if (room[i].number_of_beds == 4)
				room[i].cost = 2400;
		}
	}
}