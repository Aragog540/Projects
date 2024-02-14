#include<iostream>
#include<string>
#include<random>
#include<time.h>

using namespace std;

string generateRandomChar(bool lowercase, bool uppercase, bool numbers, bool symbols) {
  const string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
  const string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const string numberChars = "0123456789";
  const string symbolChars = "!@#$%^&*()_-+={}[];\'\\:|,<.>/?";

  string possibleChars = "";
  if (lowercase) possibleChars += lowercaseChars;
  if (uppercase) possibleChars += uppercaseChars;
  if (numbers) possibleChars += numberChars;
  if (symbols) possibleChars += symbolChars;

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distr(0, possibleChars.length() - 1);

  return string(1, possibleChars[distr(gen)]);
}

string generateStrongPassword(int length) {
  string password = "";
  bool hasLowercase = false;
  bool hasUppercase = false;
  bool hasNumber = false;
  bool hasSymbol = false;

  for (int i = 0; i < length; ++i) {
    while (!hasLowercase || !hasUppercase || !hasNumber || !hasSymbol) {
      string randomChar = generateRandomChar(!hasLowercase, !hasUppercase, !hasNumber, !hasSymbol);
      password += randomChar;
      hasLowercase |= islower(randomChar[0]);
      hasUppercase |= isupper(randomChar[0]);
      hasNumber |= isdigit(randomChar[0]);
      hasSymbol |= ispunct(randomChar[0]);
    }


    random_device rd;
    mt19937 g(rd());
    shuffle(password.begin(), password.end(), g);
  }

  return password;
}

int main() {
  int desiredLength;
  cout << "Enter desired password length (minimum 8): ";
  cin >> desiredLength;

  if (desiredLength < 8) {
    cout << "Password length must be at least 8 characters!\n";
    return 1;
  }

  cout << "Generated strong password: " << generateStrongPassword(desiredLength) << endl;

  return 0;
}