#include <iostream>
#include <cmath>
using namespace std;

double function(double y, double t) {
    return (1 + pow(t, 2) * (1 - pow(y, 2)) - 2 * t) / (5 - pow(t, 2) * (1 + y));
}

int main() {
    double y, t;
    cout << "Enter y: ";
    cin >> y;

    cout << "Enter t: ";
    cin >> t;

    double result = function(y, t);
    cout << "Result: " << result << endl;

    return 0;
}
