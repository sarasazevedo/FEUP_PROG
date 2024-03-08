/*The value of 𝜋 can be approximated by the Gregory–Leibniz series:
4∑𝑘𝑛=0(−1)𝑛/(2𝑛+1)
Write a C++ program that given integers k and d prints the k-th approximation with d decimal places. You should make use of a value of type double for the approximation, and customise the print format using std::fixed and std::setprecision defined in header <iomanip>, i.e., for a value x of type double and d digits of precision, print x with d digits using std::cout << std::fixed << std::setprecision(d) << x ;*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    int k,d;
    cin >> k >> d;
    double result = 0;

    for (int i=0; i<=k; i++){
        result += 4 * (pow(-1, i) / (2.0 * i + 1));
    }
    
    cout << fixed << setprecision(d) << result;
    return 0;
}