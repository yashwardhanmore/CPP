#include <iostream>

class TollBooth {
private:
    unsigned int totalCars;
    unsigned int payingCars;
    double cashCollected;
public:
    TollBooth() : totalCars(0), payingCars(0), cashCollected(0.0) {}
    void payingCar() {
        ++totalCars;
        ++payingCars;
        cashCollected += 0.50;
    }
    void nopayCar() {
        ++totalCars;
    }
    void printOnConsole() const {
        unsigned int nonPayingCars = totalCars - payingCars;
        std::cout << "Total cars:          " << totalCars << '\n';
        std::cout << "Paying cars:         " << payingCars << '\n';
        std::cout << "Non‑paying cars:    " << nonPayingCars << '\n';
        std::cout << "Cash collected: $   " << cashCollected << "\n";
    }
};

int main() {
    TollBooth booth;
    booth.payingCar();
    booth.nopayCar();
    booth.payingCar();
    booth.nopayCar();
    booth.payingCar();
    booth.printOnConsole();
    return 0;
}
