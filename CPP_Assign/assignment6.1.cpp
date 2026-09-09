#include <iostream>
#include <string>

using namespace std;


class Product {
protected:
    int id;
    string title;
    double price;

public:
    Product(int id, string title, double price) {
        this->id = id;
        this->title = title;
        this->price = price;
    }

    virtual ~Product() {}

    
    virtual double getFinalPrice() = 0;

    virtual void display() {
        cout << "ID: " << id << " | Title: " << title << " | Original Price: $" << price;
    }
};

class Book : public Product {
private:
    string author;

public:
    Book(int id, string title, string author, double price) 
        : Product(id, title, price), author(author) {}

    double getFinalPrice() override {
        return price * 0.90; 
    }

    void display() override {
        Product::display();
        cout << " | Author: " << author << " | Final Price (10% off): $" << getFinalPrice() << endl;
    }
};


class Tape : public Product {
private:
    string artist;

public:
    Tape(int id, string title, string artist, double price) 
        : Product(id, title, price), artist(artist) {}

    
    double getFinalPrice() override {
        return price * 0.95; 
    }

    void display() override {
        Product::display();
        cout << " | Artist: " << artist << " | Final Price (5% off): $" << getFinalPrice() << endl;
    }
};

int main() {
    Product* arr[3] = {nullptr, nullptr, nullptr};
    int choice;
    double totalBill = 0.0;

    cout << "--- Welcome to the Shop ---" << endl;
    
    for (int i = 0; i < 3; i++) {
        cout << "\nSelect product " << (i + 1) << " to purchase:" << endl;
        cout << "1. Book\n2. Tape" << endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        int id;
        string title, extra; 
        double price;

        cout << "Enter ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Price: ";
        cin >> price;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter Author: ";
            getline(cin, extra);
            arr[i] = new Book(id, title, extra, price);
        } else if (choice == 2) {
            cout << "Enter Artist: ";
            getline(cin, extra);
            arr[i] = new Tape(id, title, extra, price);
        } else {
            cout << "Invalid choice! Defaulting to a standard empty item slot." << endl;
            i--; 
            continue;
        }
    }

    cout << "\n--- Final Bill Summary ---" << endl;
    for (int i = 0; i < 3; i++) {
        if (arr[i] != nullptr) {
            arr[i]->display();
            totalBill += arr[i]->getFinalPrice();
        }
    }
    cout << "Total Amount Payable: $" << totalBill << endl;

    
    for (int i = 0; i < 3; i++) {
        delete arr[i];
        arr[i] = nullptr;
    }

    return 0;
}
