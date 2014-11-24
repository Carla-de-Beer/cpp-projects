// Carla de Beer
// C++ code employing the Newton Raphson approximation method to generate the root of a polynomial of the form:
// ax^6 + bx^5 + cx^4+ dx^3+ ex^2 + fx + g
// Date created: 20/10/2014

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

  // Polynomial values:
  int a = 0;
  int b = 1;
  int c = -3;
  int d = 1;
  int e = -1;
  int f = -1;  
  int g = 6;

int main(){
  
  double x = 0.0;
  double x1 = 0.0;
  double tol = 0.0000000001;
  int iter = 0;
  int maxIter = 1000;
  double err = tol + 1;
  
  while(err > tol && iter < maxIter){
    
    double top = (a*pow(x,6) + b*pow(x,5) + c*pow(x,4) + d*pow(x,3) + e*pow(x,2) + f*x + g);
    double bottom = (6*a*pow(x,5) + 5*b*pow(x,4) + 4*c*pow(x,3) + 3*d*pow(x,2) + 2*e*x + f);
    
    x1 = x - (top/bottom);
    err = fabs(x1 - x);
    x = x1;
    ++iter;    
  }
  
  if(err <= tol){
    cout << "The root is: " << setprecision(11) << x << endl;
    }
    else{
      cout << "Error: no convergence." << endl;
    } 
  
 return 0; 
}
