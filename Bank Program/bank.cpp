#include <iostream> 
#include <string> 
using namespace std; 
class Account { 
protected: 
 string customerName; 
 int accountNumber; 
 double balance; 
public: 
 void initializeAccount(string name, int accNumber) {  customerName = name; 
 accountNumber = accNumber; 
 balance = 0.0; 
 } 
 void deposit(double amount) { 
 balance += amount; 
 cout << "Deposited: " << amount << endl;  } 
 void displayBalance() { 
 cout << "Account Number: " << accountNumber << endl;  cout << "Customer Name: " << customerName << endl;  cout << "Balance: " << balance << endl; 
 } 
}; 
class CurrAcct : public Account { 
public: 
 void withdraw(double amount) { 
 if (balance - amount >= 0) { 
 balance -= amount; 
 cout << "Withdrawn: " << amount << endl;  } 
 else { 
 cout << "Insufficient balance for withdrawal." << endl;
 } 
 } 
 void checkMinimumBalance() { 
 if (balance < 1000.0) { 
 cout << "Balance is below minimum. Service charge imposed." << endl;  balance -= 100; 
 } 
 } 
}; 
class SavAcct : public Account { 
public: 
 void computeAndDepositInterest(double rate) { 
 double interest = (balance * rate) / 100; 
 balance += interest; 
 cout << "Interest Added: $" << interest << endl; 
 } 
}; 
int main() { 
 int choice, accNumber; 
 string name; 
 CurrAcct currAccount; 
 SavAcct savAccount; 
 while (true) { 
 cout << "1. Create Current Account\n2. Create Savings Account\n3. Deposit\n4. Withdraw\n5.  Display Balance\n6. Compute and Deposit Interest\n7. Check Minimum Balance\n8. Exit\n"; 
 cout << "Enter your choice: "; 
 cin >> choice;
 switch (choice) { 
 case 1: 
 cout << "Enter customer name: "; 
 cin >> name; 
 cout << "Enter account number: "; 
 cin >> accNumber; 
 currAccount.initializeAccount(name, accNumber);  cout << "Current Account created successfully." << endl;  break; 
 case 2: 
 cout << "Enter customer name: "; 
 cin >> name; 
 cout << "Enter account number: "; 
 cin >> accNumber; 
 savAccount.initializeAccount(name, accNumber);  cout << "Savings Account created successfully." << endl;  break; 
 case 3: 
 double amount; 
 cout << "Enter the amount to deposit: $";  cin >> amount; 
 currAccount.deposit(amount); 
 break; 
 case 4: 
 cout << "Enter the amount to withdraw: $";  cin >> amount; 
 currAccount.withdraw(amount);
 break; 
 case 5: 
 cout << "Current Account Balance:\n"; 
 currAccount.displayBalance(); 
 cout << "Savings Account Balance:\n"; 
 savAccount.displayBalance(); 
 break; 
 case 6: 
 double rate; 
 cout << "Enter interest rate for the Savings Account: ";  cin >> rate; 
 savAccount.computeAndDepositInterest(rate);  break; 
 case 7: 
 currAccount.checkMinimumBalance(); 
 break; 
 case 8: 
 cout << "Exiting the program." << endl; 
 return 0; 
 default: 
 cout << "Invalid choice. Please enter a valid option." << endl;  } 
 } 
 return 0; 
}
