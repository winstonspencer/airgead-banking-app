/**
 * @file Row.h
 * @author Winston Spencer
 * @brief The Airgead Banking Application Row Definition
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef AIRGEAD_BANKING_SRC_ROW_H_
#define AIRGEAD_BANKING_SRC_ROW_H_

#include <vector>
#include "Column.h"

// Use the standard namespance (std)
using namespace std;

/**
 * @brief The class Row used to display data in table format.
 * 
 */
class Row
{

  /**
   * @brief The Row class encapsulated class members and methods
   * 
   */
private:
  vector<Column> m_columns;

public:
  
  /**
   * @brief Construct a new Row object
   */
  Row();

  /**
   * @brief Destroy the Row object.
   * 
   */
  ~Row();

  /**
   * @brief Adds a column to the row
   * 
   * @param t_column the column to add to the row
   */
  void addColumn(Column t_column);

  /**
   * @brief Get the number of columns in the row
   * 
   * @return int the number of columns in the row
   */
  int getLength();

  /**
   * @brief Get the i-th Column in the row
   * 
   * @param i index of the column to retrieve
   * @return Column the i-th Column in the row
   */
  Column getColumn(int i);

  /**
   * @brief Get all Columns in the row
   * 
   * @return vector<Column> the row columns
   */
  Column * getColumns();

  /**
   * @brief Remove all columns in the row
   * 
   */
  void clear();
};

#endif