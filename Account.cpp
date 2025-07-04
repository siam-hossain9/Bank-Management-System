#include "Account.h"

Account::Account() {
    id = 0;
    balance = 0.0;
}

void Account::createAccount() {
    cout << "Enter Account ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Phone Number: ";
    getline(cin, phone);
    cout << "Enter Starting Balance: ";
    cin >> balance;
}

void Account::displayAccount() const {
    cout << "ID: " << id << "\nName: " << name
         << "\nAddress: " << address
         << "\nPhone: " << phone
         << "\nBalance: $" << balance << "\n";
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= balance)
        balance -= amount;
    else
        cout << "Insufficient Balance.\n";
}

void Account::updateAccount() {
    cin.ignore();
    cout << "Update Name: ";
    getline(cin, name);
    cout << "Update Address: ";
    getline(cin, address);
    cout << "Update Phone: ";
    getline(cin, phone);
}

int Account::getID() const {
    return id;
}

double Account::getBalance() const {
    return balance;
}

void Account::saveToFile(ofstream &out) {
    out << "ID: " << id << endl;
    out << "Name: " << name << endl;
    out << "Address: " << address << endl;
    out << "Phone: " << phone << endl;
    out << "Balance: " << balance << endl;
}


void Account::loadFromFile(ifstream &in) {
    string temp;
    getline(in, temp); // skip "ID: xxx"
    getline(in, temp); name = temp.substr(temp.find(": ") + 2);
    getline(in, temp); address = temp.substr(temp.find(": ") + 2);
    getline(in, temp); phone = temp.substr(temp.find(": ") + 2);
    getline(in, temp); balance = stod(temp.substr(temp.find(": ") + 2));
}

