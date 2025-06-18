#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string phone;
    string email;
};

int main() {
    Student students[5];

    cout << "Enter information for 5 students:\n";

    for (int i = 0; i < 5; ++i) {
        cout << "\nStudent " << (i + 1) << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cin.ignore(); // Clears the input buffer

        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "Email: ";
        getline(cin, students[i].email);

        cout << "Phone Number: ";
        getline(cin, students[i].phone);
    }

    cout << "\nStudent Records:\n";
    cout << "--------------------------------------------\n";

    for (int i = 0; i < 5; ++i) {
        cout << "Student " << (i + 1) << ":\n";
        cout << "ID: " << students[i].id << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "Email: " << students[i].email << "\n";
        cout << "Contact: " << students[i].phone << "\n";
        cout << "--------------------------------------------\n";
    }

    return 0;
}
