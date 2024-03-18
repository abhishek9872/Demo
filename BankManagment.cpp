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

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter account number: ";
    cin >> acc_no;

    cout << "Enter Address: ";
    cin >> add;

    cout << "Enter mobile number: ";
    cin >> mo_no;

    users.emplace_back(name, acc_no, add, mo_no);

    outputFile << "Name is " << name << endl;
    outputFile << "Account number is " << acc_no << endl;
    outputFile << "Address is " << add << endl;
    outputFile << "Mobile number is " << mo_no << endl;
    outputFile.close();
}

void Customer::deposit(int am) {
    int amount1;
    cout << "Enter amount to deposit: ";
    cin >> amount1;
    am = amount1 + am;
    cout << "Amount deposited Successfully " << am << endl;
}

void Customer::withdraw(int am) {
    int amount2;
    cout << "Enter amount to withdraw: ";
    cin >> amount2;
    if (amount2 > 0) {
        am = amount2 - am;
        cout << "Amount Withdrawn Successfully " << am << endl;
    } else {
        cout << "Enter a positive number" << endl;
    }
}

void Customer::display() {
    cout << "Enter user to display" << endl;
    string name;
    cin >> name;
    bool found = false;
    for (const auto& user : users) {
        if (user.name == name) {
            cout << "Name: " << user.name << endl;
            cout << "Account Number: " << user.acc_no << endl;
            cout << "Address: " << user.add << endl;
            cout << "Mobile Number: " << user.mo_no << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "User with name " << name << " not found." << endl;
    }
}


class Account : public Customer {
    string name;
    int id;
    long balance;

public:
    static int totalbalance;

    void setname(string name) { this->name = name; }
    string getname() { return name; }
    void setid(int id) { this->id = id; }
    int getid() { return id; }
    void setbal(long balance) { this->balance = balance; }
    long getbal() { return balance; }

    static void Calculatetotalbalance(Account s1[20], int n) {
        totalbalance = 0;
        for (int i = 0; i < n; i++) {
            totalbalance += s1[i].balance;
        }
        cout << "Total balance is " << totalbalance << endl;
    }
};

class Loan : public Customer {
    double loanAmount;
    string name;
    string loanType;
    long p,r,t,SI,loan;
    public :
    void TakeLoan()
    {
        
    cout <<"Enter your name "<<endl;
    cin>>name;
    cout<<"Enter Principle amount"<<endl;
    cin>>p;
    cout<<"Enter rate "<<endl;
    cin>>r;
    cout<<"Enter periode"<<endl;
    cin>>t;
    loanAmount = p + (p * r * t) / 100;

        cout << "Loan amount is: " << loanAmount << endl;
        am += loanAmount;
        cout << "Loan taken successfully." << endl;
    }
};

int Account::totalbalance = 0;

int main() {
    Loan a1;

    int ch;
    do {
        cout << "1: Create Account" << endl;
        cout << "2: Withdraw money" << endl;
        cout << "3: Deposit" << endl;
        cout << "4: Take loan" << endl;
        cout << "5: Pay loan" << endl;
        cout << "6: Display user details" << endl;
        cout << "7: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                a1.create_account();
                break;
            case 2:
                a1.withdraw(a1.am);
                break;
            case 3:
                a1.deposit(a1.am);
                break;
            case 4:
                a1.TakeLoan();
            case 6:
                a1.display();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 7);

    return 0;
}