#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
using namespace std;

class Account {
private:
    int id;
    string name;
    string address;
    string phone;
    double balance;

public:
    Account();
    void createAccount();
    void displayAccount() const;
    void deposit(double);
    void withdraw(double);
    void updateAccount();
    int getID() const;
    double getBalance() const;
    void saveToFile(ofstream &);
    void loadFromFile(ifstream &);
};

#endif
