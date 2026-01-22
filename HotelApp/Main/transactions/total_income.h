#pragma once
#include <iostream>
#include <string>
using namespace std;

/*income information is taken as an address because it needed to be equal to zero
for another user to enter data when we are done*/
int safe = 0;
int calculateTotalIncome(int& income) {
	safe += income;
	income = 0;
	return safe;
}