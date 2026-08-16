#include <iostream>
#include <cmath>
#include <guassian.hpp>



Gaussian::Gaussian(double& stddev, double& mu) : mu(mu), stddev(stddev){}


double Gaussian::probability(double& x){

  //Find Z score
  double Z = x - this->mu;
  Z = Z / this->stddev;
  
  double resp = 0.5 * (1+ std::erf(Z/std::sqrt(2)));
    
  return resp;
}
