#include "Account.h"
#include <iostream>

using namespace std;

int main() {

  cout << "the password for all the account is 'abcde'" << endl;
  // creating an array with 10 accounts
  Account *accountArray = new Account[10];

  int accountNumber;
  string passWord;
  bool keepGoing = true;

  while (keepGoing) {
    cout << "\nLogin Window:" << endl;
    cout << "=============" << endl;
    cout << "Enter Your Account no: ";
    // ask the user for the account number
    cin >> accountNumber;
    // ask the user for the password
    cout << "Enter Your Password: ";
    cin >> passWord;

    // if the password matches the one that we set it will stop the loop
    // for example, it will check what the password of the account user picked

    if (accountArray[accountNumber - 1].passWord == passWord) {
      keepGoing = false;
    }
    // tell the user that the password or account number is wrong
    else {
      cout << "Wrong password or account number homie" << endl;
    }
  }

  bool keepGoing2 = true;
  do {

    int option = mainWindow(accountArray[accountNumber - 1]);
    if (option == 1) {
      cout << "Good Bye!" << endl;
      keepGoing2 = false;
    }
  } while (keepGoing2);
}