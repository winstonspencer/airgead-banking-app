/**
 * @file Menu.h
 * @author Winston Spencer
 * @brief The Airgead Banking Application Menu
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Include class dependencies
#include <cmath>
#include <string>
#include <iomanip>
#include <iostream>
#include <exception>
#include "Menu.h"
#include "Table.h"
#include "Formatter.h"

// Use the standard namespance (std)
using namespace std;

/**
 * @brief Collects the user input and converts it to a double
 *        the method returns 1 for invalid results.
 * 
 */
void Menu::collectUserInput(string userPrompt, int &value)
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
void Menu::collectUserInput(string userPrompt, double &value)
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

/**
 * @brief Collects the investment data from the user
 * 
 * @param investmentData The investment data to populate
 */
void Menu::collectInvestmentData(InvestmentData &investmentData)
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
    collectUserInput("** Enter Initial Investment Amount: $", initialInvestmentAmount);
    collectUserInput("** Enter Monthly Deposit Amount: $", monthlyDepositAmount);
    collectUserInput("** Enter Initial Annual Interest: %", annualInterest);
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

  // Display the continue screen
  this->displayContinueMenu();
  return;
}

/**
 * @brief Displays the main menu
 * 
 * @return int 
 */
int Menu::displayMainMenu()
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

/**
 * @brief Display the investment reports.
 * 
 * @param investmentData 
 * @param t_useMonthlyDeposit 
 */
void Menu::displayReport(InvestmentData &investmentData, bool t_useMonthlyDeposit)
{
  // Declare and initialize function variables
  double totalBalance = 0.0;
  double totalInterest = 0.0;
  Table table;

  try
  {

    table.addHeader(new Column("YEAR"));
    table.addHeader(new Column("BALANCE"));
    table.addHeader(new Column("EARNED INTEREST"));

    // Set the balance to the initial investment amount
    totalBalance = investmentData.getInitialInvestmentAmount();

    for (int i = 0; i < investmentData.getYears(); ++i)
    {
      investmentData.calculateYearlyBalance(totalInterest, totalBalance, t_useMonthlyDeposit);

      // Create a new row
      Row row;

      // Add the year to the first column.
      row.addColumn(Column(i + 1));

      // Add the balance to the row
      row.addColumn(Column("$" + toString(fabs(totalBalance))));

      // Add the interest to the row
      row.addColumn(Column("$" + toString(fabs(totalInterest))));

      // Add the row to the table
      table.addRow(row);
    }

    // Display the table
    table.display();

    // Display the continue screen
    this->displayContinueMenu();
  }
  catch (exception &e)
  {
    cout << "Error printing our monthly investment report." << e.what() << endl;
  }

  return;
}

/**
   * @brief Display the continue menu.
   * 
   */
void Menu::displayContinueMenu()
{

  // Declare the user input variable.
  string userInput;

  cout << " Please press any key to continue: " << endl;

  // Get the user input within the try
  getline(cin, userInput);
}

/**
   * @brief Display the exit screen
   * 
   */
void Menu::displayExitScreen()
{
  cout << "Goodbye!" << endl;
}
