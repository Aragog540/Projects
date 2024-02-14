#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Contact {
  string name;
  string phone;
  string email;
  string address;
};

vector<Contact> phonebook;

void addContact() {
  Contact newContact;
  cout << "Enter Name: ";
  getline(cin, newContact.name);
  cout << "Enter Phone Number: ";
  getline(cin, newContact.phone);
  cout << "Enter Email (optional): ";
  getline(cin, newContact.email);
  cout << "Enter Address (optional): ";
  getline(cin, newContact.address);
  phonebook.push_back(newContact);
  cout << "Contact added successfully!\n";
}

void listContacts() {
  if (phonebook.empty()) {
    cout << "Phonebook is empty!\n";
    return;
  }
  for (int i = 0; i < phonebook.size(); ++i) {
    cout << "Name: " << phonebook[i].name << endl;
    cout << "Phone: " << phonebook[i].phone << endl;
    if (!phonebook[i].email.empty()) {
      cout << "Email: " << phonebook[i].email << endl;
    }
    if (!phonebook[i].address.empty()) {
      cout << "Address: " << phonebook[i].address << endl;
    }
    cout << endl;
  }
}

void searchContact() {
  string searchTerm;
  cout << "Enter name or phone number to search: ";
  getline(cin, searchTerm);
  bool found = false;
  for (int i = 0; i < phonebook.size(); ++i) {
    if (phonebook[i].name.find(searchTerm) != string::npos ||
        phonebook[i].phone.find(searchTerm) != string::npos) {
      cout << "Name: " << phonebook[i].name << endl;
      cout << "Phone: " << phonebook[i].phone << endl;
      if (!phonebook[i].email.empty()) {
        cout << "Email: " << phonebook[i].email << endl;
      }
      if (!phonebook[i].address.empty()) {
        cout << "Address: " << phonebook[i].address << endl;
      }
      cout << endl;
      found = true;
    }
  }
  if (!found) {
    cout << "Contact not found!\n";
  }
}

int main() {
  int choice;
  do {
    cout << "\nPhonebook Menu:\n";
    cout << "1. Add Contact\n";
    cout << "2. List Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        addContact();
        break;
      case 2:
        listContacts();
        break;
      case 3:
        searchContact();
        break;
      case 4:
        cout << "Goodbye!\n";
        break;
      default:
        cout << "Invalid choice!\n";
    }
  } while (choice != 4);

  return 0;
}