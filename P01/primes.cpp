#include <iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;

    for(int i=2; i<=n; i++){
        bool isPrime = false;
        for (int j=2; j*j<=i; j++){
            if (i % j == 0){
                isPrime = true;
            }
        }
        if (isPrime == false){
            cout << i << " ";
        }
    }
    return 0;
}
