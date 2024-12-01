#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, R, y;

    cout << "R = ";
    cin >> R;
    cout << "x = ";
    cin >> x;

    if (x <= -1 - R) {
        y = 1;
    }
    else if (x > -1 - R && x <= -1) {
        y = -sqrt(pow(R, 2) - pow(x + 1, 2));
    }
    else if (x >= 0 && x <= 2 * R) {
        y = (R + x * (-3 - R)) / (2 * R);
    }
    else if (x > 2 * R) {
        y = x - 3 * R;
    }

    cout << "y = " << y << endl;

    return 0;
}
