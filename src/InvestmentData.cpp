/**
 * @file InvestmentData.cpp
 * @author Winston Spencer
 * @brief The Airgead Banking Application Investment Data Class Implementation
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Import required libraries
#include <iostream>
#include <math.h>
#include "InvestmentData.h"

/**
   * @brief Construct a new Investment Data object
   *
   */
InvestmentData::InvestmentData()
{
  this->m_initailInvestmentAmount = 0.0;
  this->m_monthlyDeplositAmount = 0.0;
  this->m_annualInterestRate = 0.0;
  this->m_years = 0;
}

/**
   * @brief Destroy the Investment Data object
   * 
   */
InvestmentData::~InvestmentData()
{
  this->m_initailInvestmentAmount = 0.0;
  this->m_monthlyDeplositAmount = 0.0;
  this->m_annualInterestRate = 0.0;
  this->m_years = 0;
}

/**
   * @brief Get the Initial Investment Amount
   * 
   * @return double 
   */
double InvestmentData::getInitialInvestmentAmount()
{
  return this->m_initailInvestmentAmount;
}

/**
   * @brief Get the Monthly Deposit Amount
   * 
   * @return double 
   */
double InvestmentData::getMonthlyDepositAmount()
{
  return this->m_monthlyDeplositAmount;
}

/**
   * @brief Get the Annual Interest
   * 
   * @return double 
   */
double InvestmentData::getAnnualInterestRate()
{
  return this->m_annualInterestRate;
}

/**
   * @brief Get the number of Years
   * 
   * @return int 
   */
int InvestmentData::getYears()
{
  return this->m_years;
}

/**
 * @brief Sets the initial investment amount.
 * 
 * @param t_initialInvestmentAmount the initial investment amount.
 */
void InvestmentData::setInitialInvestmentAmount(double t_initialInvestmentAmount)
{
  this->m_initailInvestmentAmount = t_initialInvestmentAmount;
}

/**
 * @brief Sets the monthly deposit amount
 * 
 * @param t_monthlyDepositAmount the monthly deposit amount
 */
void InvestmentData::setMonthlyDepositAmount(double t_monthlyDepositAmount)
{
  this->m_monthlyDeplositAmount = t_monthlyDepositAmount;
}

/**
 * @brief Sets the annual interest rate
 * 
 * @param t_annualInterestRate the annual interest rate
 */
void InvestmentData::setAnnualInterestRate(double t_annualInterestRate)
{
  this->m_annualInterestRate = t_annualInterestRate;
}

/**
 * @brief Sets the number of years
 * 
 * @param t_years the number of years
 */
void InvestmentData::setYears(int t_years)
{
  this->m_years = t_years;
}

/**
 * @brief Calaculates the monthly interest rate.
 *        The rate is calculated as: (m_annualInterestRate/100)/12
 * 
 * @param t_openingBalance 
 * @return double 
 */
double InvestmentData::calculateMonthlyInterest(double t_openingBalance)
{
  // Declare and Initialize the monthlyInterestAmount variable
  double monthlyInterestAmount = 0.0;

  //  Only calculate the interest IFF the interest rate is > 0% else return 0.
  if (fabs(this->m_annualInterestRate) > 0.0001)
  {
    // Calculate the monthly interest rate.
    monthlyInterestAmount = t_openingBalance * ((this->m_annualInterestRate / 100.0) / 12.0);
  }

  // Return the calculated monthly interest amount.
  return monthlyInterestAmount;
}

/**
 * @brief Calculates the yearly interest and total investment balance.
 * 
 * @param t_yearlyInterestAmount The yearly interest
 * @param t_openingBalance the opening balance
 * @param t_useMonthlyDeposit flag to determine if the monthly deposito value should be used.
 */
void InvestmentData::calculateYearlyBalance(double &t_yearlyInterestAmount, double & t_openingBalance, bool t_useMonthlyDeposit)
{
  // Declare function variables
  double monthlyInterest;

  // Initialze the total interest to 0 at the beginning of each year.
  t_yearlyInterestAmount = 0.0;

  // Loop through all the months in the year to calculate
  // the monthly interest and balance.
  for (int currentMonth = 0; currentMonth < 12; ++currentMonth)
  {

    // Get the starting balance.
    if (t_useMonthlyDeposit)
    {
      t_openingBalance += this->getMonthlyDepositAmount();
    }

    // Calculate the monthly interest amount
    monthlyInterest = this->calculateMonthlyInterest(t_openingBalance);

    // Calculate the year to date interest
    t_yearlyInterestAmount += monthlyInterest;

    // Calculate the year to date balance
    t_openingBalance += monthlyInterest;
  }

  return;
}