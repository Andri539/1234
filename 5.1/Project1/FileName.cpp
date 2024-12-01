#include <iostream>
#include <cmath>
using namespace std;

double function(const double y) {
    double t = 1 + pow(y, 2) / 2 - pow(y, 3) / 3;
    return (1 + pow(t, 2) * (1 - pow(y, 2)) - 2 * t) / (5 - pow(t, 2) * (1 + y));
}

int main() {
    double y;
    cout << "Enter y: ";
    cin >> y;

    double result = function(y);
    cout << "Result = " << result << endl;

    return 0;
}
