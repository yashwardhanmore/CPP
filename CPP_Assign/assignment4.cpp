#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSeconds() { return second; }

    void setHour(int h) { hour = h; }
    void setMinute(int m) { minute = m; }
    void setSeconds(int s) { second = s; }

    void printTime() {
        if (hour < 10) cout << "0"; cout << hour << ":";
        if (minute < 10) cout << "0"; cout << minute << ":";
        if (second < 10) cout << "0"; cout << second << endl;
    }
};

int main() {
    int maxCapacity;
    cout << "Enter maximum capacity for storing time objects: ";
    cin >> maxCapacity;

    Time** timeArray = new Time*[maxCapacity];
    int currentCount = 0;
    int choice;

    do {
        cout << "\n=== TIME TRACKER MENU ===" << endl;
        cout << "1. Add Time" << endl;
        cout << "2. Display All Time" << endl;
        cout << "3. Display only hrs of all time objects" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (currentCount >= maxCapacity) {
                    cout << "Error: Array is full!" << endl;
                } else {
                    int h, m, s;
                    cout << "Enter Hours (0-23): ";
                    cin >> h;
                    cout << "Enter Minutes (0-59): ";
                    cin >> m;
                    cout << "Enter Seconds (0-59): ";
                    cin >> s;

                    timeArray[currentCount] = new Time(h, m, s);
                    currentCount++;
                    cout << "Time added successfully!" << endl;
                }
                break;
            }
            case 2: {
                if (currentCount == 0) {
                    cout << "No time data recorded yet." << endl;
                } else {
                    cout << "\n--- Recorded Times ---" << endl;
                    for (int i = 0; i < currentCount; i++) {
                        cout << "Time " << (i + 1) << ": ";
                        timeArray[i]->printTime();
                    }
                }
                break;
            }
            case 3: {
                if (currentCount == 0) {
                    cout << "No time data recorded yet." << endl;
                } else {
                    cout << "\n--- Hours Only ---" << endl;
                    for (int i = 0; i < currentCount; i++) {
                        cout << "Object " << (i + 1) << " Hour component: " << timeArray[i]->getHour() << " hrs" << endl;
                    }
                }
                break;
            }
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please select between 1 and 4." << endl;
        }
    } while (choice != 4);

    for (int i = 0; i < currentCount; i++) {
        delete timeArray[i];
    }
    delete[] timeArray;
    timeArray = nullptr;

    return 0;
}
