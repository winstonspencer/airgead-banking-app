/**
 * @file main.cpp
 * @author Winston Spencer
 * @brief The Airgead Banking Application entry point
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Import required libraries
#include <exception>
#include <iostream>

// Use the standard namespance (std)
using namespace std;

int displayMainMenu()
{

  int menuOption = 0;

  cout << "**********************************************************" << endl;
  cout << "***************** Airgead Banking App ********************" << endl;
  cout << "**********************************************************" << endl;
  cout << "** 1 - Enter Investment Data                            **" << endl;
  cout << "** 2 - View Investment Report without Monthly Deposit.  **" << endl;
  cout << "** 3 - View Investment Report with Monthly Deposit.     **" << endl;
  cout << "** 4 - Exit                                             **" << endl;
  cout << "**********************************************************" << endl;

  try
  {

    // Get the user input within the trycatch
    cin >> menuOption;
  }
  catch (exception &e)
  {
    cout << "Invalid input: " << e.what() << endl;
  }

  return menuOption;
}

void collectInvestmentData()
{
}

void displayMonthyReport(bool t_useMonthlyDeposit)
{
}

/**
 * @brief The application entry point
 * 
 * @return int 0 = success.  Any other value indicates the application exited with ane rror.
 */
int main()
{

  // Decleare the option variable
  int option;

  // While the option is not 1 - 4 display the menu
  do
  {

    // Get the user option from the main menu
    option = displayMainMenu();

  } while (option > 0 && option < 5);

  return 0;
}