

#include <iostream>

class Box {
private:
    double length;
    double breadth;
    double height;

public:
    
    Box() : length(1.0), breadth(1.0), height(1.0) {}

    
    Box(double dim) : length(dim), breadth(dim), height(dim) {}

    
    Box(double l, double b, double h) : length(l), breadth(b), height(h) {}

    double volume() const { return length * breadth * height; }
};

int main() {
    int choice;
    std::cout << "Menu:\n";
    std::cout << "1. Calculate Volume with default values\n";
    std::cout << "2. Calculate Volume with length, breadth and height with same value\n";
    std::cout << "3. Calculate Volume with different length, breadth and height values.\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1: {           
            Box box;         
            std::cout << "Volume (default 1x1x1): " << box.volume() << '\n';
            break;
        }
        case 2: {            
            double val;
            std::cout << "Enter the value for all dimensions: ";
            std::cin >> val;
            Box box(val);    
            std::cout << "Volume: " << box.volume() << '\n';
            break;
        }
        case 3: {            
            double l, b, h;
            std::cout << "Enter length: ";
            std::cin >> l;
            std::cout << "Enter breadth: ";
            std::cin >> b;
            std::cout << "Enter height: ";
            std::cin >> h;
            Box box(l, b, h); 
            std::cout << "Volume: " << box.volume() << '\n';
            break;
        }
        default:
            std::cout << "Invalid choice.\n";
    }

    return 0;
}
