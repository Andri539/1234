#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

double function(double y) {
    double t = 1 + pow(y, 2) / 2 - pow(y, 3) / 3;
    return (1 + pow(t, 2) * (1 - pow(y, 2)) - 2 * t) / (5 - pow(t, 2) * (1 + y));
}

void testFunction() {
    double y = 1.0;
    double expected = -0.585366;
    double result = function(y);
    assert(abs(result - expected) < 0.0001);
    cout << "Test passed!" << endl;
}

int main() {
    testFunction();
    return 0;
}
