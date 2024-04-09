#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string hashPassword(const string& password) {
    return string(password.rbegin(), password.rend());
}

bool fileExists(const string& name) {
    ifstream f(name.c_str());
    return f.good();
}

void registerUser() {
    string username, password;

    cout << "Select a username: "; cin >> username;
    cout << "Select a password: "; cin >> password;

    string filename = "C:\login" + username + ".txt";

    if (fileExists(filename)) {
        cout << "User already exists." << endl;
        return;
    }

    ofstream file(filename);
    file << username << endl << hashPassword(password);
    file.close();

    cout << "Registration successful." << endl;
}

bool isLoggedIn() {
    string username, password, storedUser, storedHash;

    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read("C:\login" + username + ".txt");
    getline(read, storedUser);
    getline(read, storedHash);

    if (storedUser == username && storedHash == hashPassword(password)) {
        return true;
    }
    else {
        return false;
    }
}

void loginUser() {
    bool status = isLoggedIn();

    if (!status) {
        cout << "Login Failed!" << endl;
    }
    else {
        cout << "Successfully logged in!" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "1: Register\n2: Login\n3: Exit\nYour choice: "; cin >> choice;
        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
