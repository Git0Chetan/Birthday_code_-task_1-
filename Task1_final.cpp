#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Birthday {
    string name;
    int day;
    int month;
    int year;
};

vector<Birthday> birthdays;

void addBirthday() {
    Birthday b;
    cout << "Enter name: ";
    cin >> b.name;
    cout << "Enter day (1-31): ";
    cin >> b.day;
    cout << "Enter month (1-12): ";
    cin >> b.month;
    cout << "Enter year: ";
    cin >> b.year;
    birthdays.push_back(b);
    cout << "Added birthday for " << b.name << endl;
}

void searchBirthday() {
    string name;
    cout << "Enter name to search: ";
    cin >> name;
    vector<Birthday>::iterator it;
    for (it = birthdays.begin(); it != birthdays.end(); it++) {
        if (it->name == name) {
            cout << "Birthday found for " << name << ":" << endl;
            cout << "Day: " << it->day << endl;
            cout << "Month: " << it->month << endl;
            cout << "Year: " << it->year << endl;
            return;
        }
    }
    cout << "Birthday for " << name << " not found." << endl;
}

void editBirthday() {
    string name;
    cout << "Enter name to edit: ";
    cin >> name;
    vector<Birthday>::iterator it;
    for (it = birthdays.begin(); it != birthdays.end(); it++) {
        if (it->name == name) {
            cout << "Enter new day (1-31): ";
            cin >> it->day;
            cout << "Enter new month (1-12): ";
            cin >> it->month;
            cout << "Enter new year: ";
            cin >> it->year;
            cout << "Birthday updated for " << name << endl;
            return;
        }
    }
    cout << "Birthday for " << name << " not found." << endl;
}

void displayBirthdaysByMonth() {
    int month;
    cout << "Enter month (1-12) to display birthdays: ";
    cin >> month;
    vector<Birthday>::iterator it;
    bool found = false;
    for (it = birthdays.begin(); it != birthdays.end(); it++) {
        if (it->month == month) {
            if (!found) {
                cout << "Birthdays in month " << month << ":" << endl;
                found = true;
            }
            cout << it->name << " (Day: " << it->day << ")" << endl;
        }
    }
    if (!found) {
        cout << "No birthdays found in month " << month << endl;
    }
}

void runBirthdayManager() {
    int choice = 0;
    do {
        cout << "Birthday Manager" << endl;
        cout << "1. Add birthday" << endl;
        cout << "2. Search birthday" << endl;
        cout << "3. Edit birthday" << endl;
        cout << "4. Display birthdays by month" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter choice (1-5): ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBirthday();
                break;
            case 2:
                searchBirthday();
                break;
            case 3:
                editBirthday();
                break;
            case 4:
                displayBirthdaysByMonth();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
                break;
        }
    } while (choice != 5);
}

int main() {
    runBirthdayManager();
    return 0;
}
