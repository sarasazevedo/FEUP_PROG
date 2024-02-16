/*The Manhattan distance between 2 points (𝑥1,𝑦1) and (𝑥2,𝑦2) is given by |𝑥1−𝑥2|+|𝑦1−𝑦2.
Write a C++ program that reads an integer number n by user input followed by n pairs of integer numbers (𝑥1,𝑦1)…(𝑥𝑛,𝑦𝑛), each defining a point, and then prints the Manhattan distance associated with the path defined by the n points, i.e., the sum of Manhattan distances between successive points in the path.*/

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int distance = 0;
    int x1, y1;
    cin >> x1 >> y1;

     for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y; 
        distance += abs(x - x1) + abs(y - y1); 
        x1 = x;
        y1 = y;
    }

    cout << distance;

    return 0;
}