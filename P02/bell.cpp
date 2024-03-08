/*
Bell numbers 𝐵0,𝐵1,𝐵2,… count the possible partitions of a set, i.e., the number or partitions for a set with 𝑛≥0 elements is given by 𝐵𝑛, where 𝐵0=𝐵1=1 and for 𝑛≥2
𝐵𝑛=∑𝑛−1𝑘=0(𝑛−1𝑘)𝐵𝑘
Write a C++ function unsigned long bell(unsigned long n) to compute Bell numbers.
Hint: Note that binomial coefficients are used in the definition above. Reuse the code of the previous exercise to compute them.
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


unsigned long bell(unsigned long n){
    unsigned long result = 0;
    if (n==0 || n == 1){
        result = 1;
        return result;
    }
    else
        for (unsigned long k=0; k<=n-1;k++){
            result += bc(n-1, k)*bell(k);
        }
    return result;
}

int main(){
    cout << bell(4) << '\n';
    return 0;
}