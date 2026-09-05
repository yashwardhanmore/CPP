#include <iostream>
#include <iomanip>

class Date {
private:
    int day, month, year;

public:
    void initDate()          { day=1; month=1; year=2000; }
    void printDateOnConsole() const
    {
        std::cout<<"Current date: "
                 <<std::setw(2)<<std::setfill('0')<<day<<'/'
                 <<std::setw(2)<<std::setfill('0')<<month<<'/'
                 <<std::setw(4)<<std::setfill('0')<<year<<"\n";
    }
    void acceptDateFromConsole()
    {
        int d,m,y; bool ok=false;
        do{
            std::cout<<"Enter day (1‑31): ";
            if(!(std::cin>>d)) { std::cin.clear(); std::cin.ignore(1000,'\n'); continue; }
            std::cout<<"Enter month (1‑12): ";
            if(!(std::cin>>m)) { std::cin.clear(); std::cin.ignore(1000,'\n'); continue; }
            std::cout<<"Enter year (>=1900): ";
            if(!(std::cin>>y)) { std::cin.clear(); std::cin.ignore(1000,'\n'); continue; }

            ok = (d>=1 && d<=31 && m>=1 && m<=12 && y>=1900);
            if(!ok) std::cout<<"Invalid date. Try again.\n";
        }while(!ok);

        day=d; month=m; year=y;
    }
    bool isLeapYear() const
    {
        return (year%400==0) || (year%4==0 && year%100!=0);
    }
};

int main()
{
    Date dt;
    bool init=false, exit=false;
    int choice;

    do{
        std::cout<<"\n--- Date Manager (class) ---\n"
                  <<"1. Initialise date\n"
                  <<"2. Accept date from console\n"
                  <<"3. Print date on console\n"
                  <<"4. Check leap year\n"
                  <<"5. Exit\n"
                  <<"Enter choice: ";
        if(!(std::cin>>choice)) { std::cin.clear(); std::cin.ignore(1000,'\n'); continue; }

        switch(choice){
            case 1: dt.initDate(); init=true;
                    std::cout<<"Date initialised to 01/01/2000\n"; break;
            case 2: if(!init){ dt.initDate(); init=true; }
                    dt.acceptDateFromConsole();
                    std::cout<<"Date accepted.\n"; break;
            case 3: if(init) dt.printDateOnConsole();
                    else std::cout<<"Date not initialised yet.\n"; break;
            case 4: if(init)
                        std::cout<<(dt.isLeapYear()?"Leap year":"Not a leap year")<<"\n";
                    else std::cout<<"Date not initialised yet.\n"; break;
            case 5: exit=true; break;
            default: std::cout<<"Unknown option.\n";
        }
    }while(!exit);

    return 0;
}
