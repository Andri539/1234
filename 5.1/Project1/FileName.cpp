#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double y;
    cout << "Enter y: ";
    cin >> y; 

    double t = 1 + pow(y, 2) / 2 - pow(y, 3) / 3;
    double result = (1 + pow(t, 2) * (1 - pow(y, 2)) - 2 * t) / (5 - pow(t, 2) * (1 + y));

    cout << "Result: " << result << endl;

    return 0; 
}
