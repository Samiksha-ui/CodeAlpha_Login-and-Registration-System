#include <iostream>
#include <fstream>
using namespace std;

void registerUser() {
    string username, password;

    cout << "\n--- Registration ---\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();

    cout << "Registration Successful!\n";
}

void loginUser() {
    string username, password, fileUser, filePass;

    cout << "\n--- Login ---\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream file(username + ".txt");

    if (!file) {
        cout << "User not found!\n";
        return;
    }

    getline(file, fileUser);
    getline(file, filePass);

    if (username == fileUser && password == filePass)
        cout << "Login Successful!\n";
    else
        cout << "Invalid Password!\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== Login System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
        }

    } while(choice != 3);

    return 0;
}