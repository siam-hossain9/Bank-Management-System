#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Account.h"

using namespace std;

vector<Account> accounts;

void loadAccounts() {
    ifstream fin("database.txt");
    if (!fin) return;

    int count;
    fin >> count;
    fin.ignore();

    for (int i = 0; i < count; ++i) {
        Account acc;
        int id;
        fin >> id;
        fin.ignore();
        acc.loadFromFile(fin);
        accounts.push_back(acc);
    }
    fin.close();
}

void saveAccounts() {
    ofstream fout("database.txt");
    fout << accounts.size() << endl;
    for (auto &acc : accounts) {
        fout << acc.getID() << endl;
        acc.saveToFile(fout);
    }
    fout.close();
}

Account* findAccount(int id) {
    for (auto &acc : accounts)
        if (acc.getID() == id)
            return &acc;
    return nullptr;
}

void menu() {
    int choice;
    do {
        cout << endl;
        cout << "====== Bank Management Menu ======" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. View Account" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Update Account" << endl;
        cout << "6. Delete Account" << endl;
        cout << "7. View All Accounts" << endl;
        cout << "8. Exit" << endl;
        cout << "Select Option: ";
        cin >> choice;
        cout << "You selected option [" << choice << "]: ";

        if (choice == 1) {
            cout << "Create Account" << endl;
            Account acc;
            acc.createAccount();
            accounts.push_back(acc);
        }
        else if (choice == 2) {
            cout << "View Account" << endl;
            int id;
            cout << "Enter ID: ";
            cin >> id;
            Account* acc = findAccount(id);
            if (acc) acc->displayAccount();
            else cout << "Not found." << endl;
        }
        else if (choice == 3) {
            cout << "Deposit" << endl;
            int id;
            double amt;
            cout << "Enter ID and amount to deposit: ";
            cin >> id >> amt;
            Account* acc = findAccount(id);
            if (acc) acc->deposit(amt);
            else cout << "Not found." << endl;
        }
        else if (choice == 4) {
            cout << "Withdraw" << endl;
            int id;
            double amt;
            cout << "Enter ID and amount to withdraw: ";
            cin >> id >> amt;
            Account* acc = findAccount(id);
            if (acc) acc->withdraw(amt);
            else cout << "Not found." << endl;
        }
        else if (choice == 5) {
            cout << "Update Account" << endl;
            int id;
            cout << "Enter ID to update: ";
            cin >> id;
            Account* acc = findAccount(id);
            if (acc) acc->updateAccount();
            else cout << "Not found." << endl;
        }
        else if (choice == 6) {
            cout << "Delete Account" << endl;
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            auto it = remove_if(accounts.begin(), accounts.end(),
                [id](Account& acc) { return acc.getID() == id; });
            if (it != accounts.end()) {
                accounts.erase(it, accounts.end());
                cout << "Account deleted." << endl;
            } else {
                cout << "Not found." << endl;
            }
        }
        else if (choice == 7) {
            cout << "View All Accounts" << endl;
            if (accounts.empty()) {
                cout << "No accounts to show." << endl;
            } else {
                for (const auto& acc : accounts) {
                    acc.displayAccount();
                    cout << "--------------------------" << endl;
                }
            }
        }
        else if (choice == 8) {
            cout << "Exit" << endl;
        }
        else {
            cout << "Invalid option!" << endl;
        }

    } while (choice != 8);

    saveAccounts();
    cout << "Data saved. Exiting..." << endl;
}




int main() {
    loadAccounts();
    menu();
    return 0;
}
