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
 * @brief The class InvestmentData holds the investment data provided by the user.
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
   * @brief The annual interest rate provided by the user
   * 
   */
  double m_annualInterestRate;

  /**
   * @brief The number of years the investment will be gaining interest provided by the user
   * 
   */
  int m_years;

  /**
   * @brief Calaculates the monthly interest rate.
   *        The rate is calculated as: (m_annualInterestRate/100)/12
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
   */
  InvestmentData();

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
   * @brief Get the Annual Interest Rate
   * 
   * @return double 
   */
  double getAnnualInterestRate();

  /**
   * @brief Get the number of Years
   * 
   * @return int 
   */
  int getYears();

  /**
   * @brief Set the Initial Investment Amount object
   * 
   * @param t_initialInvestmentAmount the initial investment amount
   */
  void setInitialInvestmentAmount(double t_initialInvestmentAmount);

  /**
   * @brief Set the Monthly Deposit Amount object
   * 
   * @param t_monthlyDeplositAmount the Monthly Deposit Amount object
   */
  void setMonthlyDepositAmount(double t_monthlyDeplositAmount);

  /**
   * @brief Set the Annual Interest Rate
   * 
   * @param t_annualInterestRate the Annual Interest rate
   */
  void setAnnualInterestRate(double t_annualInterestRate);

  /**
   * @brief Set the Years
   * 
   * @param years the Years
   */
  void setYears(int years);

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
  double calculateMonthlyBalance(double t_openingBalance, bool t_useMonthlyAmount);
};

#endif