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
  int m_width;
  string m_value;

public:
  /**
   * @brief Construct a new Column object
   */
  Column();

  /**
   * @brief Construct a new Column object
   * 
   * @param t_value  the column value
   */
  Column(string t_value);

  /**
   * @brief Construct a new Column object
   * 
   * @param t_width  the column width
   * @param t_value  the column value
   */
  Column(int t_width, string t_value);

  /**
   * @brief Destroy the Column object.
   * 
   */
  ~Column();

  /**
   * @brief Set the column value
   * 
   * @param t_value 
   */
  void setValue(string t_value);

  /**
   * @brief Set the column width
   * 
   * @param t_width the column width
   */
  void setWidth(int t_width);

  /**
   * @brief Get the column value
   * 
   * @return string the column value
   */
  string getValue();

  /**
   * @brief Get the column width
   * 
   * @return int the column width
   */
  int getWidth();
};

#endif
