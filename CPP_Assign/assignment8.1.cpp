#include <iostream>
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

    
    friend istream& operator>>(istream& input, Employee& emp) {
        cout << "Enter Employee ID: ";
        input >> emp.id;
        cout << "Enter Salary: ";
        input >> emp.salary;
        return input; 
    }

    
    friend ostream& operator<<(ostream& output, const Employee& emp) {
        output << "ID: " << emp.id << " | Salary: " << emp.salary;
        return output; 
    }
};

int main() {
    Employee emp1;

    
    cout << "--- Enter Details ---" << endl;
    cin >> emp1; 

    cout << "\n--- Employee Details ---" << endl;
    cout << emp1 << endl; 

    return 0;
}
