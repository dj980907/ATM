#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
using namespace std;
//this is the account number that will be assigned
int account = 1;
// int password = 12345;

//this is a transaction class that will store the time, type, and the amount of the transaction
class transaction {
public:
  string time;
  string type;
  int amount; 

  //this is a constructor that take in the parameter to create a transaction object
  transaction(string ty, int a, string t) {
    type = ty;
    amount = a;
    time = t;
  }
};

//this is the account object
//account object has account number that will be automatically generated, default password to 12345, and balance set at 5000
class Account {
public:
  int accountNumber;
  string passWord;
  int Balance;
  // arraylist that saves the list of transactions
  list<transaction> transactionArray = {};

  // non-parameter constructor (default constructor)
  //we will make 10 accounts and each account will have account number starting at 1
  //and each account will have password starting at 12345 and increment by 1 for simplicity
  Account() {
    accountNumber = account;
    passWord = "abcde";
    Balance = 5000;
    account++;
    // password++;
  }
  //we won't use this but just in case I made a constructor with parameter
  Account(string pw, int b) {
    accountNumber = account;
    passWord = pw;
    Balance = b;
  }
};

//method that shows the current balance
void showBalance(Account &a) {
  string enter;
  cout << "\nMain Window --> Show Balance" << endl;
  cout << "==============================================================="
       << endl;
  cout << "Your current balance is: $" << a.Balance << endl;
  cout << "---------------------------------------------------------------"
       << endl;
  cout << "Press enter to go back to the Main Window" << endl;

  if (cin.get() == '\n') {
    cin.ignore();
  }
}

//this is the method that does deposit
void deposit(Account &a) {
  int deposit;
  
  cout << "\nMain Window --> Deposit (Enter the following information)" << endl;
  cout << "==============================================================="
       << endl;
  cout << "The amount you want to deposit: $";
  //take in deposit from the user (standard input)
  cin >> deposit;
  cout << "---------------------------------------------------------------"
       << endl;

  if(deposit <= 0){
    cout << "We can't let you deposit " << deposit << "... smh"<< endl;
    cout << "Press enter to go back to the Main Window" << endl;
  
    if (cin.get() == '\n') {
      cin.ignore();
    }
  }
  else{
    //add the value given by the user to the balance 
    a.Balance += deposit;
  
    //making transaction object
    //this is time
    time_t t = time(0);
    string dt = ctime(&t);
    dt.erase(dt.length()-1);
    
    //creating transaction objects
    transaction tran("deposit", deposit, dt);
    
    //add the object to the arraylist 
    a.transactionArray.push_back(tran);
  
    cout << "Well done. This was added to your balance successfully... Press "
            "enter to go back to the Main Window"
         << endl;
  
    if (cin.get() == '\n') {
      cin.ignore();
    }
  }
}

//method for withdraw
void withdraw(Account &a) {
  int withdraw;
  
  cout << "\nMain Window --> Withdraw (Enter the following information)"
       << endl;
  cout << "==============================================================="
       << endl;
  cout << "The amount you want to withdraw: $";
  //get the withdraw amount from the user
  cin >> withdraw;
  cout << "---------------------------------------------------------------"
       << endl;
  //check and see if we can actually withdraw that amount
  //if not, we don't withdraw
  if (a.Balance < withdraw) {
    cout << "Not enough balance to take out $" << withdraw
         << ". Work harder homie. Press enter to go back to the Main Window"
         << endl;
    if (cin.get() == '\n') {
      cin.ignore();
    }
  }
  //if we have enough money, then we subtract that amount from the balance
  else {
    a.Balance -= withdraw;

    //creating transaction object
    //time
    time_t t = time(0);
    string dt = ctime(&t);
    dt.erase(dt.length()-1);
    
    //putting parameters in the transaction object
    transaction tran("withdraw", withdraw, dt);

    //putting transaction object into arraylist
    a.transactionArray.push_back(tran);

    cout << "Please take your money then... Press enter to go back to the Main "
            "Window"
         << endl;
    if (cin.get() == '\n') {
      cin.ignore();
    }
  }
}

//showing all the transactions
//basically reading the arraylist of the account object
void showAllTransactions(Account &a) {
  cout << "\nMain Window --> Show All Transactions" << endl;
  cout << "==============================================================="
       << endl;
  cout << endl;

  //show the account number
  cout << "Account no: " << a.accountNumber << endl;
  cout << "---------------------------------------------------------------"
       << endl;
  cout << left << setfill(' ') << setw(30) << "Date" << left << setfill(' ')
       << setw(22) << "| Type" << left << setfill(' ') << setw(10) << "| Amount"
       << endl;
  cout << "---------------------------------------------------------------"
       << endl;
  //going to iterate through the arraylist and print out time, type, and amount
  std::list<transaction>::iterator it;
  for (it = a.transactionArray.begin(); it != a.transactionArray.end(); ++it) {
    cout << setfill(' ') << setw(30) << it->time << "| ";
    cout << setfill(' ') << setw(20) << it->type << "| ";
    cout << setfill(' ') << setw(10) << it->amount << endl;
  }

  cout << "---------------------------------------------------------------"
       << endl;
  cout << "Press enter to go back to the Main Window" << endl;
  if (cin.get() == '\n') {
    cin.ignore();
  }
}

//this is a main window that shows the user the option
int mainWindow(Account &a) {
  int option;
  cout << "\nMain Window:" << endl;
  cout << "=============" << endl;
  cout << "Choose one of the following options:" << endl;
  cout << "(1) Show Balance" << endl;
  cout << "(2) Deposit" << endl;
  cout << "(3) Withdraw" << endl;
  cout << "(4) Show All Transactions" << endl;
  cout << "(5) Exit" << endl;
  cout << "Enter Your Choice: ";
  cin >> option;
  if (option == 1) {
    showBalance(a);
    return 0;
  } else if (option == 2) {
    deposit(a);
    return 0;
  } else if (option == 3) {
    withdraw(a);
    return 0;
  } else if (option == 4) {
    showAllTransactions(a);
    return 0;
  } else if (option == 5) {
    return 1;
  } else {
    cout << "invalid option. Enter again" << endl;
    return 0;
  }
}