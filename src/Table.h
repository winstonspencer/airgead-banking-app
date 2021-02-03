/**
 * @file Table.h
 * @author Winston Spencer
 * @brief The Airgead Banking Application Table Definition
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef AIRGEAD_BANKING_SRC_TABLE_H_
#define AIRGEAD_BANKING_SRC_TABLE_H_

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "Column.h"
#include "Row.h"

// Use the standard namespance (std)
using namespace std;

/**
 * @brief The class Table used to display data in table format.
 * 
 */
class Table
{

  /**
   * @brief The Table class encapsulated class members and methods
   * 
   */
private:
  int m_tableWidth;
  int m_columnWidth;
  int m_rowPrefixSize;
  int m_rowPostfixSize;
  char m_headerDivChar;
  char m_bodyDivChar;
  char m_columnSeperator;
  char m_filler;
  Row m_header;
  vector<Row> m_rows;
  
  /**
   * @brief Print the table row dividers
   * 
   * @param t_header true is the current row is a header row else false.
   */
  void printDiv(bool t_header);

  /**
   * @brief Prints the current row
   * 
   * @param t_header  true is the current row is a header row else false.
   * @param t_row the row to print.
   */
  void printRow(bool t_header, Row t_row);

  /**
   * @brief Prints the header row.
   * 
   */
  void printHeader();

  /**
   * @brief Prints the table body.
   * 
   */
  void printBody();

public:
  /**
   * @brief Construct a new Table object
   */
  Table();

  /**
   * @brief Destroy the Tableobject
   * 
   */
  ~Table();

  /**
   * @brief Added the table header
   * 
   * @param t_columns the table header columns
   */
  void addHeader(Column t_columns[]);

  /**
   * @brief Adds a row to the table
   * 
   * @param t_row the row to add to the table
   */
  void addRow(Row t_row);

  /**
   * @brief Creates a row with the specified columns then add the row to the table.
   * 
   * @param t_columns 
   */
  void addRow(Column *t_columns);

  /**
   * @brief Display the formatted table
   * 
   */
  void display();

  /**
   * @brief Removes all rows from the table.
   * 
   */
  void clear();
};

#endif