#include <iostream>
#include <string>
#include "transactions/rooms.h"
#include "transactions/room_reservation.h"
#include "transactions/room_report.h"
#include "transactions/room_numbers.h"
#include "transactions/room_evacuation.h"
#include "transactions/total_income.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "English");
	/*The parameter (room, 300) in functions: 'room' is located in rooms.h.
	It holds room information and indirectly customer information (contains object from customer struct). 300 is the number of rooms.*/
	//Rooms created with assignRoomProperties() function defined in rooms.h
	assignRoomProperties(room);
	int choice;
	while (true) {
		cout << "---Welcome to GULER Hotel---" << endl << endl;

		cout << "Please Select the Operation You Want to Perform;" << endl;
		cout << "1-) Room Reservation\n2-) Room Report\n3-) Check Out Room\n4-) Room Statistics\n5-) Total Income\n0-) Exit\n";
		choice = validateInteger("Your Choice: ");//validateInteger() function is defined in rooms.h

		if (choice == 0) {
			cout << "Exiting Successfully..." << endl;
			break;
		}
		else if (choice == 1) {
			bookRoom(room, 300);//bookRoom() function is defined in room_reservation.h
		}
		else if (choice == 2) {
			getRoomReport(room, 300);//getRoomReport() function is defined in room_report.h
		}
		else if (choice == 3) {
			checkOutRoom(room, 300);//checkOutRoom() function is defined in room_evacuation.h
		}
		else if (choice == 4) {
			showRoomStatistics(room, 300);//showRoomStatistics() function is defined in room_numbers.h
		}
		else if (choice == 5) {
			cout << "\nTotal Income: " << calculateTotalIncome(currentIncome) << endl;//calculateTotalIncome() function is defined in total_income.h
		}
		else {
			cout << "\n* ERROR: Please Make a Valid Selection!" << endl << endl;
		}
	}
	return 0;
}