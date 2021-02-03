/**
 * @file Column.cpp
 * @author Winston Spencer
 * @brief The Airgead Banking Application Column Implementation
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Include class dependencies
#include <sstream>
#include <iomanip>
#include "Column.h"

// Use the standard namespance (std)
using namespace std;

/**
   * @brief Construct a new Column object
   */
Column::Column()
{
  this->m_value = "";
}

/**
 * @brief Construct a new Column object
 * 
 * @param t_value  the column int value
 */
Column::Column(int t_value)
{
  this->m_value = to_string(t_value);
}

/**
 * @brief Construct a new Column object
 * 
 * @param t_value  the column double value
 */
Column::Column(double t_value)
{
  this->setValue(t_value);
}

/**
 * @brief Construct a new Column object
 * 
 * @param t_value  the column value
 */
Column::Column(string t_value)
{
  this->m_value = t_value;
}

/**
 * @brief Destroy the Column object.
 * 
 */
Column::~Column()
{
  this->m_value = "";
}

/**
 * @brief Set the column int value
 * 
 * @param t_value 
 */
void Column::setValue(int t_value)
{
  this->m_value = to_string(t_value);
}

/**
 * @brief Set the column double value
 * 
 * @param t_value 
 */
void Column::setValue(double t_value)
{
  // Create an output string stream
  ostringstream streamObj;

  // Set Fixed -Point Notation
  streamObj << fixed;

  // Set precision to 2 digits
  streamObj << setprecision(2);

  //Add double to stream
  streamObj << t_value;

  // Get string from output string stream
  this->m_value = streamObj.str();
}

/**
 * @brief Set the column value
 * 
 * @param t_value 
 */
void Column::setValue(string t_value)
{
  this->m_value = t_value;
}

/**
 * @brief Get the column value
 * 
 * @return string the column value
 */
string Column::getValue()
{
  return this->m_value;
}