#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class User {
public:
    string name;
    long acc_no;
    string add;
    long mo_no;
    User(string name, long acc_no, string add, long mo_no)
        : name(name), acc_no(acc_no), add(add), mo_no(mo_no) {}
};

class Customer {
public:
    long am;
    Customer() : am(0) {}

    void create_account();
    void deposit(int am);
    void withdraw(int am);
    void display();
};

vector<User> users;

void Customer::create_account() {
    string name;
    long acc_no;
    string add;
    long mo_no;
    ofstream outputFile("Bank.txt", ios::app);
    if (!outputFile.is_open()) {
        cout << "File is not open" << endl;
        return;
    }