/**
 * @file Menu.h
 * @author Winston Spencer
 * @brief The Airgead Banking Application Menu Class Definition
 * @version 0.1
 * @date 2021-02-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef AIRGEAD_BANKING_SRC_MENU_H_
#define AIRGEAD_BANKING_SRC_MENU_H_

// Include class dependencies
#include <string>
#include "InvestmentData.h"

// Use the standard namespance (std)
using namespace std;

class Menu
{

private:
  /**
   * @brief Collects the user input and converts it to a double
   *        the method returns 1 for invalid results.
   * 
   */
  void collectUserInput(string userPrompt, int &value);

  /**
   * @brief Collects the user input and converts it to a double
   *        the method returns 0.0 for invalid results.
   * 
   */
  void collectUserInput(string userPrompt, double &value);

  /**
   * @brief Display the continue menu.
   * 
   */
  void displayContinueMenu();

public:
  /**
   * @brief Displays the main menu
   * 
   * @return int 
   */
  int displayMainMenu();

  /**
   * @brief Display the investment reports.
   * 
   * @param investmentData 
   * @param t_useMonthlyDeposit 
   */
  void displayReport(InvestmentData &investmentData, bool t_useMonthlyDeposit);

  /**
   * @brief Display the exit screen
   * 
   */
  void displayExitScreen();

  /**
   * @brief Collects the investment data from the user
   * 
   * @param investmentData The investment data to populate
   */
  void collectInvestmentData(InvestmentData &investmentData);
};

#endif