#include <iostream>
#include <string>

using namespace std;


class Employee {
private:
    int id;
    double salary;

public:
    Employee() {
        id = 0;
        salary = 0.0;
    }

    Employee(int id, double salary) {
        this->id = id;
        this->salary = salary;
    }

    void setId(int id) { this->id = id; }
    int getId() { return id; }

    void setSalary(double salary) { this->salary = salary; }
    double getSalary() { return salary; }

    
    virtual string getRole() {
        return "Employee";
    }

    virtual void accept() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void display() {
        cout << "ID: " << id << " | Salary: " << salary;
    }

    virtual ~Employee() {} 
};

class Manager : virtual public Employee {
private:
    double bonus;

public:
    Manager() {
        bonus = 0.0;
    }

    Manager(int id, double salary, double bonus) : Employee(id, salary) {
        this->bonus = bonus;
    }

    void setBonus(double bonus) { this->bonus = bonus; }
    double getBonus() { return bonus; }

    string getRole() override {
        return "Manager";
    }

    void accept() override {
        Employee::accept();
        acceptManager();
    }

    void display() override {
        Employee::display();
        displayManager();
    }

protected:
    void acceptManager() {
        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void displayManager() {
        cout << " | Bonus: " << bonus;
    }
};


class Salesman : virtual public Employee {
private:
    double commission;

public:
    Salesman() {
        commission = 0.0;
    }

    Salesman(int id, double salary, double commission) : Employee(id, salary) {
        this->commission = commission;
    }

    void setCommission(double commission) { this->commission = commission; }
    double getCommission() { return commission; }

    string getRole() override {
        return "Salesman";
    }

    void accept() override {
        Employee::accept(); 
        acceptSalesman();
    }

    void display() override {
        Employee::display(); 
        displaySalesman();
    }

protected:
    void acceptSalesman() {
        cout << "Enter Commission: ";
        cin >> commission;
    }

    void displaySalesman() {
        cout << " | Commission: " << commission;
    }
};


class SalesManager : public Manager, public Salesman {
public:
    SalesManager() {}

    SalesManager(int id, double salary, double bonus, double commission)
        : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commission) {}

    string getRole() override {
        return "SalesManager";
    }

    void accept() override {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display() override {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};


int main() {
   
    Employee* empList[100]; 
    int totalCount = 0; 
    int choice;

    do {
        cout << "\n================ MENU ================" << endl;
        cout << "1. Add Manager" << endl;
        cout << "2. Add Salesman" << endl;
        cout << "3. Add Salesmanager" << endl;
        cout << "4. Display Count By Designation" << endl;
        cout << "5. Display All Managers" << endl;
        cout << "6. Display All Salesmen" << endl;
        cout << "7. Display All SalesManagers" << endl;
        cout << "8. Exit" << endl;
        cout << "=======================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (totalCount < 100) {
                    Manager* m = new Manager();
                    m->accept();
                    empList[totalCount] = m;
                    totalCount++;
                    cout << "Manager added successfully!" << endl;
                } else {
                    cout << "Array is full!" << endl;
                }
                break;
            }
            case 2: {
                if (totalCount < 100) {
                    Salesman* s = new Salesman();
                    s->accept();
                    empList[totalCount] = s;
                    totalCount++;
                    cout << "Salesman added successfully!" << endl;
                } else {
                    cout << "Array is full!" << endl;
                }
                break;
            }
            case 3: {
                if (totalCount < 100) {
                    SalesManager* sm = new SalesManager();
                    sm->accept();
                    empList[totalCount] = sm;
                    totalCount++;
                    cout << "SalesManager added successfully!" << endl;
                } else {
                    cout << "Array is full!" << endl;
                }
                break;
            }
            case 4: {
                int mgrCount = 0, salesCount = 0, smCount = 0;
                
                
                for (int i = 0; i < totalCount; i++) {
                    if (empList[i]->getRole() == "Manager") mgrCount++;
                    else if (empList[i]->getRole() == "Salesman") salesCount++;
                    else if (empList[i]->getRole() == "SalesManager") smCount++;
                }
                cout << "\n--- Designation Counts ---" << endl;
                cout << "Managers: " << mgrCount << endl;
                cout << "Salesmen: " << salesCount << endl;
                cout << "SalesManagers: " << smCount << endl;
                break;
            }
            case 5:
                cout << "\n--- All Managers ---" << endl;
                for (int i = 0; i < totalCount; i++) {
                    if (empList[i]->getRole() == "Manager") {
                        empList[i]->display();
                        cout << endl;
                    }
                }
                break;

            case 6:
                cout << "\n--- All Salesmen ---" << endl;
                for (int i = 0; i < totalCount; i++) {
                    if (empList[i]->getRole() == "Salesman") {
                        empList[i]->display();
                        cout << endl;
                    }
                }
                break;

            case 7:
                cout << "\n--- All SalesManagers ---" << endl;
                for (int i = 0; i < totalCount; i++) {
                    if (empList[i]->getRole() == "SalesManager") {
                        empList[i]->display();
                        cout << endl;
                    }
                }
                break;

            case 8:
                cout << "Exiting application..." << endl;
                break;

            default:
                cout << "Invalid choice! Please choose between 1 and 8." << endl;
        }
    } while (choice != 8);

    
    for (int i = 0; i < totalCount; i++) {
        delete empList[i];
    }

    return 0;
}
