#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.141592653589793;

void getA(const double x, const int n, double& a) {
    a = pow(x - 1, n + 1) / ((n + 1) * pow(x, n + 1));
}

void FindSum(const double x, const double eps, int& n, double& s) {
    n = 0;
    double a;
    s = 0.0;
    do {
        getA(x, n, a);
        double R = ((x - 1) / x) * (n / (n + 1));
        a *= R;
        s += a;
        n++;
    } while (fabs(a) >= eps);
}

int main() {
    double x0, xk, dx, eps, x, s = 0.0;
    int n = 0;

    cout << "Enter x0: "; cin >> x0;
    cout << "Enter xk: "; cin >> xk;
    cout << "Enter dx: "; cin >> dx;
    cout << "Enter eps: "; cin >> eps;

    cout << "-------------------------------------------------" << endl;
    cout << "|   x   |   ln(x)   |  ln(x) (ряд)  |   n   |" << endl;
    cout << "-------------------------------------------------" << endl;

    x = x0;
    while (x <= xk) {
        FindSum(x, eps, n, s);
        cout << "| " << setw(5) << setprecision(2) << x << " | "
            << setw(10) << setprecision(5) << log(x) << " | "
            << setw(13) << setprecision(5) << s << " | "
            << setw(5) << n << " |" << endl;

        x += dx;
    }

    cout << "-------------------------------------------------" << endl;

    return 0;
}
