/**
 * @file Table.cpp
 * @author Winston Spencer
 * @brief The Airgead Banking Application Table Implementation
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Include class dependencies
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "Table.h"
#include "Row.h"
#include "Column.h"

// Use the standard namespance (std)
using namespace std;

/**
 * @brief Construct a new Table object
 */
Table::Table()
{
  this->m_tableWidth = 72;
  this->m_columnWidth = 20;
  this->m_rowPrefixSize = 4;
  this->m_rowPostfixSize = 4;
  this->m_headerDivChar = '=';
  this->m_bodyDivChar = '-';
  this->m_columnSeperator = '|';
  this->m_header.clear();
  this->m_rows.clear();
}

/**
   * @brief Destroy the Tableobject
   * 
   */
Table::~Table()
{
  this->m_tableWidth = 0;
  this->m_columnWidth = 0;
  this->m_rowPrefixSize = 0;
  this->m_rowPostfixSize = 0;
  this->m_headerDivChar = ' ';
  this->m_bodyDivChar = ' ';
  this->m_columnSeperator = ' ';
  this->m_header.clear();
  this->m_rows.clear();
}

/**
 * @brief Added the table header
 * 
 * @param t_columns the table header columns
 */
void Table::addHeader(Column t_columns[])
{

  int columnLen = sizeof(*t_columns) / sizeof(Column);

  for (int i = 0; i < columnLen; i++)
  {
    this->m_header.addColumn(t_columns[i]);
  }

  return;
}

/**
   * @brief Adds a row to the table
   * 
   * @param t_row the row to add to the table
   */
void Table::addRow(Row t_row)
{
  this->m_rows.push_back(t_row);

  return;
}

/**
   * @brief Creates a row with the specified columns then add the row to the table.
   * 
   * @param t_columns 
   */
void Table::addRow(Column t_columns[])
{

  int columnLen = sizeof(*t_columns) / sizeof(Column);
  Row r;

  for (int i = 0; i < columnLen; i++)
  {
    r.addColumn(t_columns[i]);
  }

  return;
}

/**
   * @brief Display the formatted table
   * 
   */
void Table::display()
{
  this->printHeader();
  this->printBody();
}

/**
   * @brief Removes all rows from the table.
   * 
   */
void Table::clear()
{
  this->m_rows.clear();
}

void Table::printDiv(bool header)
{
  string *div;

  if (header)
  {
    cout << left << setw(this->m_tableWidth) << setfill(this->m_headerDivChar) << this->m_headerDivChar << endl;
  }
  else
  {
    cout << left << setw(this->m_tableWidth) << setfill(this->m_bodyDivChar) << this->m_bodyDivChar << endl;
  }

  cout << div << endl;
  
}

void Table::printRow(Row row)
{
}

void Table::printHeader()
{

  this->printDiv(true);
  for (int i = 0; i < this->m_header.getLength(); i++)
  {
    this->printRow(this->m_rows.at(i));
  }
  this->printDiv(true);
}

void Table::printBody()
{
  for (int i = 0; i < this->m_rows.size(); i++)
  {
    this->printRow(this->m_rows.at(i));
  }
}
