#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {
        day = 1;
        month = 1;
        year = 2000;
    }

    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void displayDate() {
        if (day < 10) cout << "0"; cout << day << "/";
        if (month < 10) cout << "0"; cout << month << "/";
        cout << year;
    }
};

class Person {
private:
    string name;
    string address;
    Date birthdate; 

public:
    Person() {
        name = "Unknown";
        address = "Not Available";
    }

    Person(string n, string addr, Date dob) {
        name = n;
        address = addr;
        birthdate = dob; 
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: ";
        birthdate.displayDate();
        cout << endl;
    }
};

class Student {
private:
    int id;
    double marks;
    string course;
    Date joiningDate; 
    Date endDate;     

public:
    Student() {
        id = 0;
        marks = 0.0;
        course = "Undecided";
    }

    Student(int sId, double mks, string crs, Date joinDt, Date endDt) {
        id = sId;
        marks = mks;
        course = crs;
        joiningDate = joinDt;
        endDate = endDt;
    }

    void displayStudent() {
        cout << "Student ID: " << id << endl;
        cout << "Marks: " << marks << endl;
        cout << "Course: " << course << endl;
        cout << "Joining Date: ";
        joiningDate.displayDate();
        cout << "\nEnd Date: ";
        endDate.displayDate();
        cout << endl;
    }
};

int main() {
    cout << "--- Testing Person Object ---" << endl;
    Date dob(15, 8, 2004);
    Person p1("Pratik", "Pune, India", dob);
    p1.displayPerson();

    cout << "\n--- Testing Student Object ---" << endl;
    Date join(1, 8, 2023);
    Date end(30, 6, 2027);
    Student s1(101, 88.5, "Computer Engineering", join, end);
    s1.displayStudent();

    return 0;
}
