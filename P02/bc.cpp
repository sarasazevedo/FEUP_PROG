/*
Binomial coefficients occur in many areas of mathematics. A possible formulation of binomial coefficients is as follows for 𝑛>=0 and 0≤𝑘≤𝑛:
(𝑛𝑘)=𝑛×(𝑛−1)×…×(𝑛−𝑘+1)𝑘×(𝑘−1)×…×1
Write a C++ function unsigned long bc(unsigned long n, unsigned long k) to compute binomial coefficients.
Hint: be careful to use only unsigned long variables to avoid numerical overflows.
*/

#include <iostream>
using namespace std;

unsigned long bc(unsigned long n, unsigned long k){
    unsigned long result = 1;

    if(k == 0 || k == n) return 1;
    if(k==1) return n;

    for(unsigned long i=0;i<k;i++){
        result*=n-i;
    }

    for(unsigned long i=1;i<=k;i++){
        result/= i;
    }

    return result;
}

int main(){
    cout << bc(5, 0) << '\n';
    cout << bc(5, 1) << '\n';
    cout << bc(5, 5) << '\n';
    cout << bc(5, 2) << '\n';
    cout << bc(12, 7) << '\n';
    cout << bc(20, 10) << '\n'; 
    return 0;
}
