#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	double x, y, R;

	cout << "R = ";
	cin >> R;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 7; i++) {
		cout << "¬вед≥ть координати:" << endl;
		cout << "x = "; cin >> x;
		cout << "y = "; cin >> y;

		if (pow(x, 2) + pow(y, 2) <= pow(R, 2) ||
			(y >= 0 && y <= R && x >= -R && x <= 0)) {
			cout << "(yes)" << endl;
		}
		else {
			cout << "(no)" << endl;
		}
	}

	cout << endl << fixed;

	for (int i = 0; i < 5; i++) {
		x = -R + static_cast<double>(rand()) / RAND_MAX * (2.5 * R);
		y = -R + static_cast<double>(rand()) / RAND_MAX * (2.5 * R);

		if (pow(x, 2) + pow(y, 2) <= pow(R, 2) ||
			(y >= 0 && y <= R && x >= -R && x <= 0)) {
			cout << setw(8) << setprecision(4) << x << " "
				<< setw(8) << setprecision(4) << y << " "
				<< "yes" << endl;
		}
		else {
			cout << setw(8) << setprecision(4) << x << " "
				<< setw(8) << setprecision(4) << y << " "
				<< "no" << endl;
		}
	}

	return 0;
}
