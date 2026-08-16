#include <stdio.h>
#include <iostream>
#include <cmath>

class Gaussian {

  private:

    double stddev;
    double mu;
  
  public:



    Gaussian(double& stddev, double& mu);
    
    double probability(double& x);


};
