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
  this->m_tableWidth = 69;
  this->m_columnWidth = 20;
  this->m_rowPrefixSize = 2;
  this->m_rowPostfixSize = 2;
  this->m_headerDivChar = '=';
  this->m_bodyDivChar = '-';
  this->m_columnSeperator = '|';
  this->m_filler = ' ';
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
  this->m_filler = ' ';
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

  for (int i = 0; i < columnLen; ++i)
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
  this->printDiv(true);
  this->printHeader();
  this->printDiv(false);
  this->printBody();
  this->printDiv(false);
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
  if (header)
  {
    cout << left << setw(this->m_tableWidth) << setfill(this->m_headerDivChar) << this->m_headerDivChar << endl;
  }
  else
  {
    cout << left << setw(this->m_tableWidth) << setfill(this->m_bodyDivChar) << this->m_bodyDivChar << endl;
  }

  return;
}

void Table::printRow(bool t_header, Row t_row)
{
  Column column;
  cout << left << setw(2) << setfill(' ') << this->m_columnSeperator;

  for (int i = 0; i < t_row.getLength(); ++i)
  {
    column = t_row.getColumn(i);
    cout << left << setw(this->m_columnWidth) << setfill(this->m_filler) << column.getValue();

    if (i < (t_row.getLength() - 1))
    {
      cout << left << setw(2) << setfill(' ') << this->m_columnSeperator;
    }
  }

  cout << right << setw(3) << setfill(' ') << this->m_columnSeperator;
  cout << endl;

  return;
}

void Table::printHeader()
{

  this->printRow(true, this->m_header);
}

void Table::printBody()
{
  for (int i = 0; i < this->m_rows.size(); ++i)
  {
    this->printRow(false, this->m_rows.at(i));
  }
}
