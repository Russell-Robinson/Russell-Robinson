// Corner Grocer.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <limits>
#include <string>
#include "GroceryTracker.h"

using namespace std;

void DisplayMenu() {
    cout << "================================" << endl;
    cout << "        Corner Grocer Menu      " << endl;
    cout << "================================" << endl;
    cout << "1 - Search for an Item" << endl;
    cout << "2 - Display Frequency List" << endl;
    cout << "3 - Display Histogram" << endl;
    cout << "4 - Exit Program" << endl;
    cout << "================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    GroceryTracker tracker;
    int menuChoice = 0;

    while (menuChoice != 4) {
        DisplayMenu();

        // Validate numeric input
        while (!(cin >> menuChoice)) {
            cout << "Invalid input. Enter a number from 1 to 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (menuChoice) {
        case 1: {
            string searchItem;
            cout << "\nEnter item to search: ";
            cin >> searchItem;

            int frequency = tracker.SearchItem(searchItem);
            cout << searchItem << " was purchased "
                << frequency << " time(s).\n" << endl;
            break;
        }

        case 2:
            tracker.PrintAllFrequencies();
            break;

        case 3:
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "\nThank you for using Corner Grocer." << endl;
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "\nInvalid menu option." << endl;
            cout << "Please select 1 through 4.\n" << endl;
            break;
        }
    }

    return 0;
}