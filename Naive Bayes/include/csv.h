
#pragma once
#include <string>
#include <fstream>
#include <vector>

struct CsvRow{
  int data;
  std::string column;
  int row;
};

class CsvTable{ 
  private:
    std::string file_path;
    std::ifstream& file;

    void parse_file(std::ifstream& file);
  
  public:
    CsvTable(const std::string& file_path, std::ifstream& file);
    std::vector< std::vector<CsvRow> > _rows;
    std::vector<std::string> _columns;
    

};
