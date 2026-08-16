
#include <stdio.h>
#include <csv.h>
#include <iostream>


#include <cmath>
#include <tuple>

int main(int argc, char* argv[]){

  if (argc < 2){
    std::cerr << "You must include the file path to the CSV dataset" << std::endl;
    return 1;
  }

  //Load in the csv data
  std::string file_path = argv[1];
  std::ifstream file(file_path);

  if (!file.is_open()){
    std::cerr << "Couldn't open file" << std::endl;
  }

  CsvTable csv_data("classifier data", file);
  
  //Construct Guassians
  int num_features = csv_data._columns.size();
  int num_samples = csv_data._rows.size();
  
  std::tuple<std::tuple<double, double>> gaussian_tuples;
  std::vector<
      std::tuple<
          std::tuple<double, double>,
          std::tuple<double, double>
      >
  > _gauss_tuples;  
 
  _gauss_tuples.clear();    
  //std::cout <<  csv_data._rows[2][num_features-1].data << std::endl;
  // Find means and guassians
  for (int col = 0; col<num_features-1; col++){
  

   
    double mu_0 = 0; 
    double mu_1 = 0;

    double std_dev_0 = 0;
    double std_dev_1 = 0;
    
    for (int row = 0; row<num_samples; row++){
      
      bool _class = (csv_data._rows[row][num_features-1].data == 1); 
      if(!_class){
        mu_0 += csv_data._rows[row][col].data;
      } else{
          mu_1 += csv_data._rows[row][col].data;
      }
    }
    
    mu_0 = mu_0 / num_samples;
    mu_1 = mu_1 / num_samples;
    for (int row = 0; row<num_samples; row++){
   
      bool _class = (csv_data._rows[row][num_features-1].data == 1); 
      if (!_class){
        double diff = ( csv_data._rows[row][col].data)  - mu_0 ;
        int r2 = diff * diff; 
        std_dev_0 += r2;
        std_dev_0 = std_dev_0 / num_samples; 
        std_dev_0 = std::sqrt(std_dev_0);
      } else{
        double diff = ( csv_data._rows[row][col].data)  - mu_1 ;
        int r2 = diff * diff; 
        std_dev_1 += r2;  
        std_dev_1 = std_dev_1 / num_samples; 
        std_dev_1 = std::sqrt(std_dev_1);
        
        }
        }
 
        auto temp_0 = std::make_tuple(mu_0, std_dev_0);
        auto temp_1 = std::make_tuple(mu_1, std_dev_1);
        auto temp_full = std::make_tuple(temp_0, temp_1);
        _gauss_tuples.push_back(temp_full);    
}

      for (const auto& tups : _gauss_tuples) {
    const auto& [class0, class1] = tups;

    const auto& [mu0, stddev0] = class0;
    const auto& [mu1, stddev1] = class1;

    std::cout << mu0 << " " << stddev0 << std::endl;
    std::cout << mu1 << " " << stddev1 << std::endl;

  }  
}
