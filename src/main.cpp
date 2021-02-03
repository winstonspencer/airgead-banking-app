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
#include <cmath>
#include <string>
#include <memory>
#include <iomanip>
#include <iostream>
#include <exception>
#include "InvestmentData.h"
#include "Table.h"

// Use the standard namespance (std)
using namespace std;

/**
 * @brief Collects the user input and converts it to a double
 *        the method returns 1 for invalid results.
 * 
 */
void collectUserInput(string userPrompt, int &value)
{
  // Create the user input.
  string userInput;

  try
  {
    cout << userPrompt;

    // Get the user input within the trycatch
    getline(cin, userInput);
    value = stoi(userInput);
    cout << endl;
  }
  catch (exception &e)
  {
    value = 1;
  }
}

/**
 * @brief Collects the user input and converts it to a double
 *        the method returns 0.0 for invalid results.
 * 
 */
void collectUserInput(string userPrompt, double &value)
{
  // Create the user input.
  string userInput;

  try
  {
    cout << userPrompt;

    // Get the user input within the trycatch
    getline(cin, userInput);
    value = stod(userInput);
    cout << endl;
  }
  catch (exception &e)
  {
    value = 0.0;
  }
}

int displayMainMenu()
{
  // Declare and initialize the user option.
  int menuOption = 0;

  // Create the user input.
  string userInput;

  cout << "*************************************************************" << endl;
  cout << "**                Airgead Banking App                      **" << endl;
  cout << "*************************************************************" << endl;
  cout << "** 1 - Enter Investment Data                               **" << endl;
  cout << "** 2 - View Investment Report without Monthly Deposit.     **" << endl;
  cout << "** 3 - View Investment Report with Monthly Deposit.        **" << endl;
  cout << "** 4 - Exit                                                **" << endl;
  cout << "*************************************************************" << endl;
  cout << "User Selection: ";

  try
  {

    // Get the user input within the trycatch
    getline(cin, userInput);

    // Place a new line after the user input.
    cout << endl;

    // Validate and parse the user input.
    if (userInput.size() == 1 && isdigit(userInput.at(0)))
    {
      // substracting the asci value from 48 gives you the value entered by the user.
      menuOption = userInput.at(0) - 48;
    }
    else
    {
      cout << "Invalid user input input: [" << userInput << "]." << endl;
    }
  }
  catch (exception &e)
  {
    cout << "Unrecognized user input." << endl;
  }

  cout << "*************************************************************" << endl;
  return menuOption;
}

void collectInvestmentData(InvestmentData &investmentData)
{
  // Declare variables
  int years;
  string userInput;
  double annualInterest;
  double monthlyDepositAmount;
  double initialInvestmentAmount;

  try
  {

    cout << "*************************************************************" << endl;
    cout << "** Airgead Banking App: Investment Data                    **" << endl;
    cout << "*************************************************************" << endl;

    cout << "";

    // Get the user input within the trycatch
    collectUserInput("** Enter Initial Investment Amount: ", initialInvestmentAmount);
    collectUserInput("** Enter Monthly Deposit Amount: ", monthlyDepositAmount);
    collectUserInput("** Enter Initial Annual Interest: ", annualInterest);
    collectUserInput("** Enter Years: ", years);

    investmentData.setInitialInvestmentAmount(initialInvestmentAmount);
    investmentData.setMonthlyDepositAmount(monthlyDepositAmount);
    investmentData.setAnnualInterestRate(annualInterest);
    investmentData.setYears(years);

    cout << "*************************************************************" << endl;

    // Place a new line after the user input.
    cout << endl;
  }
  catch (exception &e)
  {
    cout << "Unrecognized user input." << endl;
  }

  cout << "*************************************************************" << endl;

  return;
}

void displayReport(InvestmentData &investmentData, bool t_useMonthlyDeposit)
{
  // Declare function variables
  double totalBalance;
  Table table;

  try
  {
    totalBalance = investmentData.getInitialInvestmentAmount();
    table.addHeader(new Column("YEAR"));
    table.addHeader(new Column("BALANCE"));
    table.addHeader(new Column("YEARLY INTEREST"));

    for (int i = 0; i < investmentData.getYears(); ++i)
    {
      Row row;
      row.addColumn(Column(i + 1));

      for (int i = 0; i < 12; i++)
      {
        totalBalance = investmentData.calculateMonthlyBalance(totalBalance, t_useMonthlyDeposit);
      }

      row.addColumn(Column(fabs(totalBalance)));
      row.addColumn(Column(fabs(investmentData.getAnnualInterestRate())));
      table.addRow(row);
    }

    table.display();
  }
  catch (exception &e)
  {
    cout << "Error printing our monthly investment report." << e.what() << endl;
  }

  return;
}

/**
 * @brief The application entry point
 * 
 * @return int 0 = success.  Any other value indicates the application exited with ane rror.
 */
int main()
{

  // Decleare all function variables.
  int option;
  bool initialPass = true;
  auto investmentData = make_unique<InvestmentData>();

  // While the option is not 1 - 4 display the menu
  do
  {
    // Get the user option from the main menu
    option = displayMainMenu();

    if (option == 1)
    {
      collectInvestmentData(*investmentData);
    }
    else if (option == 2)
    {
      displayReport(*investmentData, false);
    }
    else if (option == 3)
    {
      displayReport(*investmentData, true);
    }

    initialPass = false;

    // Exit the application when the option is 4.
  } while (option != 4);

  cout << "Goodbye!" << endl;

  return 0;
}