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
   * @brief Calaculates the monthly balance as: 
   *          (Opening Balance + Deposited Amount) * calculateMonthlyInterestRate()
   * 
   * @param t_useMonthlyAmount Determines if the monthly amount should be used when 
   *                           calculating the balance
   * 
   * @param t_openingBalance The opening balance
   * 
   * @return double 
   */
double InvestmentData::calculateMonthlyBalance(double t_openingBalance, bool t_useMonthlyAmount)
{
  // Declare and Initialize the monthly balance variable
  double monthlyBalance = t_openingBalance;
  ;
  double interest = this->calculateMonthlyInterestRate();

  if (fabs(interest) > 0.0001)
  {
    if (t_useMonthlyAmount)
    {
      monthlyBalance = (monthlyBalance + this->m_monthlyDeplositAmount) + (monthlyBalance * this->calculateMonthlyInterestRate());
    }
    else
    {
      monthlyBalance = monthlyBalance + (monthlyBalance * this->calculateMonthlyInterestRate());
    }
  }

  // Return the calculated monthly balance.
  return monthlyBalance;
}

/**
   * @brief Calaculates the monthly interest rate.
   *        The rate is calculated as: (Interest Rate/100)/12
   * 
   * @return double 
   */
double InvestmentData::calculateMonthlyInterestRate()
{
  // Declare and Initialize the monthlyInterestRate variable
  double monthlyInterestRate = 0.0;

  // Calculate the monthly interest rate.
  monthlyInterestRate = ((this->m_annualInterestRate / 100.0) / 12.0);

  // Return the calculated monthly interest rate.
  return monthlyInterestRate;
}
