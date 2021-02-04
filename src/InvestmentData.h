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
   * @brief Calaculates the monthly interest rate.
   *        The rate is calculated as: (m_annualInterestRate/100)/12
   * 
   * @return double 
   */
  double calculateMonthlyInterest(double t_openingBalance);

  /**
   * @brief Calculates the yearly interest and total investment balance.
   * 
   * @param t_yearlyInterestAmount The yearly interest
   * @param t_openingBalance the opening balance
   * @param t_useMonthlyDeposit flag to determine if the monthly deposito value should be used.
   */
  void calculateYearlyBalance(double & t_yearlyInterestAmount, double & t_openingBalance, bool t_useMonthlyDeposit);
};

#endif