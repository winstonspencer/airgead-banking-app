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
#include "Column.h"

/**
   * @brief Construct a new Column object
   */
Column::Column()
{
  this->m_width = 0;
  this->m_value = "";
}

/**
 * @brief Construct a new Column object
 * 
 * @param t_value  the column value
 */
Column::Column(string t_value)
{
  this->m_width = 0;
  this->m_value = t_value;
}

/**
 * @brief Construct a new Column object
 * 
 * @param t_width  the column width
 * @param t_value  the column value
 */
Column::Column(int t_width, string t_value)
{
  this->m_width = t_width;
  this->m_value = t_value;
}

/**
 * @brief Destroy the Column object.
 * 
 */
Column::~Column()
{
  this->m_width = 0;
  this->m_value = "";
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
 * @brief Set the column width
 * 
 * @param t_width the column width
 */
void Column::setWidth(int t_width)
{
  this->m_width = t_width;
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

/**
 * @brief Get the column width
 * 
 * @return int the column width
 */
int Column::getWidth()
{
  return this->m_width;
}