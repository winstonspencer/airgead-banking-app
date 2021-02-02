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
#include "InvestmentData.h"

/**
   * @brief Construct a new Investment Data object
   * 
   * @param t_initailInvestmentAmount The intiail investment amount
   * @param t_monthlyDeplositAmount The monthly deplosit mount
   * @param t_annualInterest The annual interest
   * @param t_years The number of years interest will applied to the investment 
   */
InvestmentData::InvestmentData(double t_initailInvestmentAmount, double t_monthlyDeplositAmount, double t_annualInterest, int t_years)
{
  this->m_initailInvestmentAmount = t_initailInvestmentAmount;
  this->m_monthlyDeplositAmount = t_monthlyDeplositAmount;
  this->m_annualInterest = t_annualInterest;
  this->m_years = t_years;
}

/**
   * @brief Destroy the Investment Data object
   * 
   */
InvestmentData::~InvestmentData()
{
  this->m_initailInvestmentAmount = 0.0;
  this->m_monthlyDeplositAmount = 0.0;
  this->m_annualInterest = 0.0;
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
double InvestmentData::getAnnualInterest()
{
  return this->m_annualInterest;
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
   * @brief Calaculates the monthly balance The rate is calculated as: 
   *          (Opening Amount + Deposited Amount) * calculateMonthlyInterestRate()
   * 
   * @param t_useMonthlyAmount Determines if the monthly amount should be used when 
   *                           calculating the balance
   * @return double 
   */
double InvestmentData::calculateMonthlyBalance(bool t_useMonthlyAmount)
{
  // Declare and Initialize the monthly balance variable
  double monethlyBalance = 0.0;

  // Calculate the monthly balance.
  monethlyBalance = ((this->m_annualInterest / 100.0) / 12.0);

  // Return the calculated monthly balance.
  return monethlyBalance;
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
  monthlyInterestRate = ((this->m_annualInterest / 100.0) / 12.0);

  // Return the calculated monthly interest rate.
  return monthlyInterestRate;
}
