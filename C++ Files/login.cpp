#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

string hashPassword(const string& password) {
    hash<string> hasher;
    size_t hashed = hasher(password);
    return to_string(hashed);
}

unordered_map<string, string> loadUsers() {
    unordered_map<string, string> users;
    ifstream infile("users.txt");
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string username, passwordHash;
        ss >> username >> passwordHash;
        users[username] = passwordHash;
    }
    infile.close();
    return users;
}

void saveUser(const string& username, const string& passwordHash) {
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << passwordHash << endl;
    outfile.close();
}

void registerUser() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    unordered_map<string, string> users = loadUsers();

    if (users.find(username) != users.end()) {
        cout << "Username already exists. Try another one.\n";
        return;
    }

    string passwordHash = hashPassword(password);
    saveUser(username, passwordHash);
    cout << "Registration successful.\n";
}

void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    unordered_map<string, string> users = loadUsers();

    string passwordHash = hashPassword(password);
    if (users.find(username) != users.end() && users[username] == passwordHash) {
        cout << "Login successful. Welcome, " << username << "!\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
