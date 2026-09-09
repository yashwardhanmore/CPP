#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0.0) {}
    Employee(int id, double salary) : id(id), salary(salary) {}
    virtual ~Employee() {}

    void setId(int id) { this->id = id; }
    int getId() const { return id; }
    
    void setSalary(double salary) { this->salary = salary; }
    double getSalary() const { return salary; }

    virtual void accept() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Salary: $";
        cin >> salary;
    }

    virtual void display() const {
        cout << "ID: " << id << " | Base Salary: $" << salary;
    }
};

class Manager : virtual public Employee {
private:
    double bonus;

public:
    Manager() : Employee(), bonus(0.0) {}
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void setBonus(double bonus) { this->bonus = bonus; }
    double getBonus() const { return bonus; }

    void acceptManager() {
        cout << "Enter Manager Bonus: $";
        cin >> bonus;
    }

    void displayManager() const {
        cout << " | Bonus: $" << bonus;
    }

    void accept() override {
        Employee::accept();
        acceptManager();
    }

    void display() const override {
        Employee::display();
        displayManager();
        cout << " | Total: $" << (getSalary() + bonus) << endl;
    }
};

class Salesman : virtual public Employee {
private:
    double commission;

public:
    Salesman() : Employee(), commission(0.0) {}
    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}

    void setCommission(double commission) { this->commission = commission; }
    double getCommission() const { return commission; }

    void acceptSalesman() {
        cout << "Enter Salesman Commission: $";
        cin >> commission;
    }

    void displaySalesman() const {
        cout << " | Commission: $" << commission;
    }

    void accept() override {
        Employee::accept();
        acceptSalesman();
    }

    void display() const override {
        Employee::display();
        displaySalesman();
        cout << " | Total: $" << (getSalary() + commission) << endl;
    }
};

class SalesManager : public Manager, public Salesman {
public:
    SalesManager() : Employee(), Manager(), Salesman() {}
    SalesManager(int id, double salary, double bonus, double commission)
        : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commission) {}

    void accept() override {
        Employee::accept(); 
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }

    void display() const override {
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
        cout << " | Net Earnings: $" << (getSalary() + getBonus() + getCommission()) << endl;
    }
};

int main() {
    cout << "=== 1. Testing Employee Class ===" << endl;
    Employee emp(101, 50000.0);
    emp.display();
    cout << "\n" << endl;

    cout << "=== 2. Testing Manager Class ===" << endl;
    Manager mgr(201, 75000.0, 15000.0);
    mgr.display();
    cout << endl;

    cout << "=== 3. Testing Salesman Class ===" << endl;
    Salesman sm(301, 40000.0, 12000.0);
    sm.display();
    cout << endl;

    cout << "=== 4. Testing SalesManager Class (Parameterized Constructor) ===" << endl;
    SalesManager smgr(401, 90000.0, 20000.0, 15000.0);
    smgr.display();
    cout << endl;

    cout << "=== 5. Testing Interactive User Input (accept() & display()) ===" << endl;
    SalesManager interactiveSmgr;
    cout << "Enter details for the Sales Manager:" << endl;
    interactiveSmgr.accept();
    
    cout << "\nDisplayed Summary:" << endl;
    interactiveSmgr.display();

    return 0;
}
