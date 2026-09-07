#include <iostream>
#include <cmath>
using namespace std;

class Cylinder {
private:
    int radius;
    int height;
    int volume;
    static int cylindercount; 

public:
    
    Cylinder() {
        radius = 0;
        height = 0;
        volume = 0;
        cylindercount++; 
    }

    void getdata() {
        cout << "Enter radius of cylinder: " << endl;
        cin >> radius;
        cout << "Enter height of cylinder: " << endl;
        cin >> height;
    }

    void calculatevolume() {
        
        volume = 3.14 * radius * radius * height; 
        cout << "Volume of this cylinder: " << volume << endl;
    }

    static int getCount() {
        return cylindercount;
    }
};


int Cylinder::cylindercount = 0; 

int main() {
    Cylinder c1;
    c1.getdata();
    c1.calculatevolume();
    
    
    cout << "Total cylinders created: " << Cylinder::getCount() << endl;
    
    return 0;
}