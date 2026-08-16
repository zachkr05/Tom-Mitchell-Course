

#include <iostream>
#include <stdio.h>
#include <csv.h>
#include <fstream>
#include <sstream>


void CsvTable::parse_file(std::ifstream& file){

  std::string column;
  std::string line;

  // Parse header
  if (std::getline(file, line)){

    std::stringstream ss(line);

    while(std::getline(ss, column, ',')){
      if (!column.empty() && column.back() == '\r') {
        column.pop_back();
      }

      this->_columns.push_back(column);
      std::cout << "Added " << column << " to columns\n" << std::endl;
    }

  }

  // Parse rows
  std::string rows;
  std::vector<CsvRow> curr_row;
  int index = 0;

  while(std::getline(file, line)){

    std::stringstream ss(line);
    int col = 0;

    while(std::getline(ss, rows, ',')){

      if (!rows.empty() && rows.back() == '\r'){
        rows.pop_back();
      }

      
      CsvRow row;

      row.data = std::stoi(rows);
      row.column = this->_columns[col];
      row.row = index;

      curr_row.push_back(row);

      std::cout
        << "Made row (data, column, row): "
        << row.data << " "
        << row.column << " "
        << row.row
        << std::endl;

      col++;
    }

    this->_rows.push_back(curr_row);
    curr_row.clear();

    std::cout << "Completed row " << index << std::endl;

    index++;
  }
}


CsvTable::CsvTable(const std::string& file_path, std::ifstream& file)
    : file_path(file_path), file(file)
{
    parse_file(file);
}
