#include <iostream>
#include <iomanip>

struct Date {
    int day, month, year;
};

void initDate(Date *d)          { d->day = 1; d->month = 1; d->year = 2000; }
void printDateOnConsole(const Date *d)
{
    std::cout << "Current date: "
              << std::setw(2) << std::setfill('0') << d->day << '/'
              << std::setw(2) << std::setfill('0') << d->month << '/'
              << std::setw(4) << std::setfill('0') << d->year << '\n';
}
void acceptDateFromConsole(Date *d)
{
    int d1,m,y;
    bool ok=false;
    do {
        std::cout<<"Enter day (1‑31): ";
        if(!(std::cin>>d1)) { std::cin.clear(); std::cin.ignore(1000,'\n'); continue; }
        std::cout<<"Enter month (1‑12): ";
        if(!(std::cin>>m))   { std::cin.clear(); std::cin.ignore(1000,'\n'); continue; }
        std::cout<<"Enter year (>=1900): ";
        if(!(std::cin>>y))   { std::cin.clear(); std::cin.ignore(1000,'\n'); continue; }

        ok = (d1>=1 && d1<=31 && m>=1 && m<=12 && y>=1900);
        if(!ok) std::cout<<"Invalid date. Try again.\n";
    } while(!ok);

    d->day=d1; d->month=m; d->year=y;
}

int main()
{
    Date dt;
    bool init=false, exit=false;
    int choice;

    do {
        std::cout<<"\n--- Date Manager (struct) ---\n"
                  <<"1. Initialise date\n"
                  <<"2. Accept date from console\n"
                  <<"3. Print date on console\n"
                  <<"4. Exit\n"
                  <<"Enter choice: ";
        if(!(std::cin>>choice)) { std::cin.clear(); std::cin.ignore(1000,'\n'); continue; }

        switch(choice){
            case 1: initDate(&dt); init=true;
                    std::cout<<"Date initialised to "<<dt.day<<'/'<<dt.month<<'/'<<dt.year<<"\n";
                    break;
            case 2: if(!init){ initDate(&dt); init=true; }
                    acceptDateFromConsole(&dt);
                    std::cout<<"Date accepted.\n"; break;
            case 3: if(init) printDateOnConsole(&dt);
                    else std::cout<<"Date not initialised yet.\n"; break;
            case 4: exit=true; break;
            default: std::cout<<"Unknown option.\n";
        }
    } while(!exit);

    return 0;
}
