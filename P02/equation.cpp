/* 
A quadratic equation of the form 𝑎𝑥2+𝑏𝑥+𝑐=0 in the domain of real numbers is known to have 0, 1, or 2 solutions according to the value of Δ=𝑏2−4𝑎𝑐:
no solutions if Δ<0
1 solution 𝑥1=−𝑏2𝑎 f Δ=0
2 solutions 𝑥1=−𝑏−Δ‾‾√2𝑎
and 𝑥2=−𝑏+Δ‾‾√2𝑎 when Δ>0
Write a C++ function to solve the quadratic equation for the case where 𝑎, 𝑏, 𝑐are integer coefficients, with 𝑎≠0:
int solve_eq(int a, int b, int c, double& x1, double& x2)
The function should return the number of solutions for the equation (0, 1, or 2) and, in the case there are solutions, assign the corresponding values to x1 and x2 as described above. x1 and x2 should be set to NAN defined in header cmath when there are no corresponding solutions (x2 = NAN when Δ=0
; and x1 = x2 = NAN when Δ<0).
To perform the square root computation, you should use the function std::sqrt, defined in header cmath.
Note: the test cases illustrate solutions with a precision of 7 decimal digits.
*/

#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2){
    int delta = pow(b, 2)- 4*a*c; 
    if(delta < 0){
        x1=NAN;
        x2=NAN;
        return 0;
    }
    else if(delta==0){
        x1=(-b)/(2.0*a);
        x2=NAN;
        return 1;
    }
    else {
        x1=(-b-sqrt(delta))/(2*a);
        x2=(-b+sqrt(delta))/(2*a);
        return 2;
    }   
}

int main(){
    double x1, x2; 
    int r = solve_eq(1, -2, 1, x1, x2); 
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';
    return 0;
}