#include <iostream>
#include <cmath>

using namespace std;

double s(const double x) {
    if (abs(x) >= 1)
        return (sin(x) + x * cos(x)) / (pow(x, 2) + 1);
    else {
        double S = 0;
        int k = 0;
        double a = x;
        S = a;
        do {
            k++;
            double R = pow(x, 2) / (2 * k * (2 * k + 1));
            a *= R;
            S += a;
        } while (k < 4);
        return S;
    }
}

int main() {
    double tp, tk, res;
    int n;

    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = "; cin >> n;

    double dt = (tk - tp) / n;
    double t = tp;

    while (t <= tk) {
        res = s(pow(t, 2)) + 2 * s(t) + 1;
        cout << t << " " << res << endl;
        t += dt;
    }

    return 0;
}
