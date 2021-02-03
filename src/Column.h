/**
 * @file Column.h
 * @author Winston Spencer
 * @brief The Airgead Banking Application Column Definition
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef AIRGEAD_BANKING_SRC_COLUMN_H_
#define AIRGEAD_BANKING_SRC_COLUMN_H_

#include <string>

// Use the standard namespance (std)
using namespace std;

/**
 * @brief The class Column used to display data in table format.
 * 
 */
class Column
{

  /**
   * @brief The Column class encapsulated class members and methods
   * 
   */
private:
  string m_value;

public:
  /**
   * @brief Construct a new Column object
   */
  Column();

  /**
   * @brief Construct a new Column object
   * 
   * @param t_value  the column int value
   */
  Column(int t_value);

  /**
   * @brief Construct a new Column object
   * 
   * @param t_value  the column double value
   */
  Column(double t_value);

  /**
   * @brief Construct a new Column object
   * 
   * @param t_value  the column string value
   */
  Column(string t_value);

  /**
   * @brief Destroy the Column object.
   * 
   */
  ~Column();

  /**
   * @brief Set the column int value
   * 
   * @param t_value 
   */
  void setValue(int t_value);

  /**
   * @brief Set the column double value
   * 
   * @param t_value 
   */
  void setValue(double t_value);

  /**
   * @brief Set the column string value
   * 
   * @param t_value 
   */
  void setValue(string t_value);

  /**
   * @brief Get the column value
   * 
   * @return string the column value
   */
  string getValue();
};

#endif
