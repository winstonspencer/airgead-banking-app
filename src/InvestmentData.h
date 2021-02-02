/**
 * @file InvestmentData.h
 * @author Winston Spencer
 * @brief The Airgead Banking Application Investment Data Class Definition
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef AIRGEAD_BANKING_SRC_INVESTMENT_DATA_H_
#define AIRGEAD_BANKING_SRC_INVESTMENT_DATA_H_

/**
 * @brief The immutable class InvestmentData holds the investment data provided by the user.
 * 
 */
class InvestmentData
{

  /**
   * @brief The InvestmentData encapsulated class members and methods
   * 
   */
private:
  /**
   * @brief The intial investment amount provided by the user
   * 
   */
  double m_initailInvestmentAmount;

  /**
   * @brief The monthly deposit amount provided by the user
   * 
   */
  double m_monthlyDeplositAmount;

  /**
   * @brief The annual interest provided by the user
   * 
   */
  double m_annualInterest;

  /**
   * @brief The number of years the investment will be gaining interest provided by the user
   * 
   */
  int m_years;

  /**
   * @brief Calaculates the monthly interest rate.
   *        The rate is calculated as: (Interest Rate/100)/12
   * 
   * @return double 
   */
  double calculateMonthlyInterestRate();

  /**
   * @brief The InvestmentData public class members & methods
   * 
   */
public:

  /**
   * @brief Construct a new Investment Data object
   * 
   * @param t_initailInvestmentAmount The intiail investment amount
   * @param t_monthlyDeplositAmount The monthly deplosit mount
   * @param t_annualInterest The annual interest
   * @param t_years The number of years interest will applied to the investment 
   */
  InvestmentData(double t_initailInvestmentAmount, double t_monthlyDeplositAmount, double t_annualInterest, int t_years);

  /**
   * @brief Destroy the Investment Data object
   * 
   */
  ~InvestmentData();

  /**
   * @brief Get the Initial Investment Amount
   * 
   * @return double 
   */
  double getInitialInvestmentAmount();

  /**
   * @brief Get the Monthly Deposit Amount
   * 
   * @return double 
   */
  double getMonthlyDepositAmount();

  /**
   * @brief Get the Annual Interest
   * 
   * @return double 
   */
  double getAnnualInterest();

  /**
   * @brief Get the number of Years
   * 
   * @return int 
   */
  int getYears();

  /**
   * @brief Calaculates the monthly balance The rate is calculated as: 
   *          (Opening Amount + Deposited Amount) * calculateMonthlyInterestRate()
   * 
   * @param t_useMonthlyAmount Determines if the monthly amount should be used when 
   *                           calculating the balance
   * @return double 
   */
  double calculateMonthlyBalance(bool t_useMonthlyAmount);

};

#endif AIRGEAD_BANKING_SRC_INVESTMENT_DATA_H_