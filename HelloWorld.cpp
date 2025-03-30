#include <iostream>
#include <string>
#include <fstream>

void registerUser() {
	std::cout << "Enter Username: ";
	std::string username{};
	std::cin >> username;

	std::cout << "\nEnter Password: ";
	std::string password{};
	std::cin >> password;

	//open file in append mode so new users wouldnt overwrite existing ones
	std::ofstream file("users.txt", std::ios::app);

	if (file.is_open()) {
		file << username << " " << password << '\n';
		file.close();
		std::cout << "User registered successfully!\n";
	} else {
		std::cout << "Error: Couldn't open the file.\n";
	}
}

bool logUser(const std::string& username, const std::string& password){
	std::ifstream file("users.txt");
	std::string storedUsername, storedPassword;

	if (!file.is_open()) {
		std::cout << "Error: Could not open file.\n";
		return false;
	}
	while (file >> storedUsername >> storedPassword) {
		if (storedUsername == username && storedPassword == password) {
			file.close();
			return true;
		}

	}
  file.close();
  return false;
}

void handleLogin() {
	std::string username, password;

	std::cout << "Enter Username: ";
	std::cin >> username;

	std::cout << "Enter Password: ";
	std::cin >> password;

	if(logUser(username, password)) { std::cout << "Login successful! Welcome, " << username << "!\n"; }
	else { std::cout << "Invalid username or password. Try again.\n"; }
}

void showMenu() {
	int choice;
	std::string username, password;

	while (true) {
		std::cout << "\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
		std::cin >> choice;

		if (choice == 1) { registerUser(); }
		else if (choice == 2) { handleLogin(); }
		else if (choice == 3) { std::cout << "Exiting program...\n"; break; }
		else { std::cout << "Invalid choice. please enter 1,2, or 3.\n"; }
	}
}

int main() {
	showMenu();
	return 0;
}