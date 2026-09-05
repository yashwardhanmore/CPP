#include <iostream>
#include <iomanip>   


struct Date {
    int day;
    int month;
    int year;
};


void initDate(Date *ptrDate);
void printDateOnConsole(const Date *ptrDate);
void acceptDateFromConsole(Date *ptrDate);


int main() {
    Date myDate;              
    bool isInitialised = false;
    int choice;

    do {
        std::cout << "\n--- Date Manager Menu ---\n"
                  << "1. Initialise date\n"
                  << "2. Accept date from console\n"
                  << "3. Print date on console\n"
                  << "4. Exit\n"
                  << "Enter choice: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();                 // reset fail flag
            std::cin.ignore(1000, '\n');      // discard bad input
            std::cout << "Invalid input – please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                initDate(&myDate);
                isInitialised = true;
                std::cout << "Date initialised to "
                          << std::setw(2) << std::setfill('0') << myDate.day
                          << '/' << std::setw(2) << std::setfill('0')
                          << myDate.month << '/'
                          << std::setw(4) << std::setfill('0')
                          << myDate.year << '\n';
                break;

            case 2:
            
                if (!isInitialised) {
                    initDate(&myDate);        // ensure structure exists
                    isInitialised = true;
                }
                acceptDateFromConsole(&myDate);
                std::cout << "Date accepted.\n";
                break;

            case 3:
                if (isInitialised)
                    printDateOnConsole(&myDate);
                else
                    std::cout << "Date not initialised yet.\n";
                break;

            case 4:
                std::cout << "Good‑bye!\n";
                break;

            default:
                std::cout << "Unknown option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}


void initDate(Date *ptrDate) {
    ptrDate->day   = 1;
    ptrDate->month = 1;
    ptrDate->year  = 2000;
}


void printDateOnConsole(const Date *ptrDate) {
    std::cout << "Current date: "
              << std::setw(2) << std::setfill('0') << ptrDate->day
              << '/' << std::setw(2) << std::setfill('0')
              << ptrDate->month << '/'
              << std::setw(4) << std::setfill('0')
              << ptrDate->year << '\n';
}


void acceptDateFromConsole(Date *ptrDate) {
    int d, m, y;
    bool ok = false;

    do {
        std::cout << "Enter day (1‑31): ";
        if (!(std::cin >> d)) { std::cin.clear(); std::cin.ignore(1000,'\n'); continue; }

        std::cout << "Enter month (1‑12): ";
        if (!(std::cin >> m)) { std::cin.clear(); std::cin.ignore(1000,'\n'); continue; }

        std::cout << "Enter year (>=1900): ";
        if (!(std::cin >> y)) { std::cin.clear(); std::cin.ignore(1000,'\n'); continue; }

        /* Very simple validation – can be extended */
        ok = (d >= 1 && d <= 31 &&
              m >= 1 && m <= 12 &&
              y >= 1900);
        if (!ok)
            std::cout << "Invalid date. Please try again.\n";
    } while (!ok);

    ptrDate->day   = d;
    ptrDate->month = m;
    ptrDate->year  = y;
}
