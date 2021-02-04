/**
 * @file main.cpp
 * @author Winston Spencer
 * @brief The Airgead Banking Application entry point
 * @version 0.1
 * @date 2021-02-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Import required libraries
#include <string>
#include <memory>
#include "Menu.h"

// Use the standard namespance (std)
using namespace std;

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
  Menu menu;


  // While the option is not 1 - 4 display the menu
  do
  {
    // Get the user option from the main menu
    option = menu.displayMainMenu();

    if (option == 1)
    {
      menu.collectInvestmentData(*investmentData);
    }
    else if (option == 2)
    {
      menu.displayReport(*investmentData, false);
    }
    else if (option == 3)
    {
      menu.displayReport(*investmentData, true);
    }

    initialPass = false;

    // Exit the application when the option is 4.
  } while (option != 4);

  
  menu.displayExitScreen();
  return 0;
}