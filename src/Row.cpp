/**
 * @file Row.cpp
 * @author Winston Spencer
 * @brief The Airgead Banking Application Row Implementation
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Include class dependencies
#include "Row.h"

// Use the standard namespance (std)
using namespace std;

/**
 * @brief Construct a new Row object
 */
Row::Row(){
  this->m_columns.clear();
}

/**
 * @brief Destroy the Row object.
 * 
 */
Row::~Row()
{
  this->m_columns.clear();
}

/**
 * @brief Adds a column to the row
 * 
 * @param t_column the column to add to the row
 */
void Row::addColumn(Column t_column)
{
  this->m_columns.push_back(t_column);
}

/**
 * @brief Get the number of columns in the row
 * 
 * @return int the number of columns in the row
 */
int Row::getLength()
{
  return this->m_columns.size();
}

/**
 * @brief Get the i-th Column in the row
 * 
 * @param i index of the column to retrieve
 * @return Column the i-th Column in the row
 */
Column Row::getColumn(int i)
{
  Column c;

  if (i < this->m_columns.size())
  {
    c = this->m_columns.at(i);
  }

  return c;
}

/**
 * @brief Get all Columns in the row
 * 
 * @return vector<Column> the row columns
 */
Column *Row::getColumns()
{

  Column *columns = new Column[this->m_columns.size()];
  for (int i = 0; i < this->m_columns.size(); i++)
  {
    columns[i] = this->m_columns.at(i);
  }

  return columns;
}

/**
 * @brief Remove all columns in the row
 * 
 */
void Row::clear()
{

  for (int i = 0; i < this->m_columns.size(); i++)
  {
    this->m_columns.clear();
  }

  return;
}