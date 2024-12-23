// Name: Chris Williford
// Date: November 13, 2024
// Module Three: Clock Project

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Function to display the current time in both formats
void displayTime(const tm& currentTime) {
	// 12-hour format
	cout << "12-hour format: " << put_time(&currentTime, "%|:%M:%S %p") << " | 24-hour format: " << put_time(&currentTime, "%H:%M:%S") << endl;
}

// Function to add one hour
void addOneHour(tm& currentTime) {
	currentTime.tm_hour += 1;
	mktime(&currentTime); // Normalize the time structure
}

// Function to add one minute
void addOneMinute(tm& currentTime) {
	currentTime.tm_min += 1;
	mktime(&currentTime); // Normalize the time structure
}

// Function to add one second
void addOneSecond(tm& currentTime) {
	currentTime.tm_sec += 1;
	mktime(&currentTime); // Normalize the time structure
}

int main() {
	// Get the current time
	time_t now = time(0);
	tm currentTime;
	// Use localtime_s for safer conversion
	localtime_s(&currentTime, &now);
	while (true) {
		displayTime(currentTime);
		cout << "\n**************************" << endl;
		cout << "* 1-Add One Hour *" << endl;
		cout << "* 2-Add One Minute *" << endl;
		cout << "* 3-Add One Second *" << endl;
		cout << "* 4-Exit Program *" << endl;
		cout << "**************************" << endl;

		int choice;
		cout << "Select an option: ";
		cin >> choice;
		switch (choice) {
		case 1:
			addOneHour(currentTime);
			break;
		case 2:
			addOneMinute(currentTime);
			break;
		case 3:
			addOneSecond(currentTime);
			break;
		case 4:
			return 0; // Exit the program
		default:
			cout << "Invalid option. Please try again." << endl;
		}
	}
	return 0;
}
