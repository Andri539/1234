#include <iostream>
#include <cmath>

using namespace std;

double IterSum(const int N, const int K) {
    double S = 0;
    for (int i = 1; i <= N; i++) {
        S += (1 + sqrt(1 + pow(i, 2))) / pow(i, 2);
    }
    return S;
}

double RecDownDec(const int N, const int K, int i, double t = 0) {
    if (i > N) {
        return t;
    }
    t += (1 + sqrt(1 + pow(i, 2))) / pow(i, 2);
    return RecDownDec(N, K, i + 1, t);
}

double RecDownInc(const int N, const int K, int i, double t = 0) {
    if (i < 1) {
        return t;
    }
    t += (1 + sqrt(1 + pow(i, 2))) / pow(i, 2);
    return RecDownInc(N, K, i - 1, t);
}

double RecUpDec(const int N, const int K, int i, double S = 0) {
    if (i < 1) {
        return S;
    }
    return RecUpDec(N, K, i - 1, S + (1 + sqrt(1 + pow(i, 2))) / pow(i, 2));
}

double RecUpInc(const int N, const int K, int i, double S = 0) {
    if (i > N) {
        return S;
    }
    return RecUpInc(N, K, i + 1, S + (1 + sqrt(1 + pow(i, 2))) / pow(i, 2));
}

int main() {
    int N, K;

    cout << "Enter N: ";
    cin >> N;
    cout << "Enter K: ";
    cin >> K;

    cout << "Inter: " << IterSum(N, K) << endl;
    cout << "Rec down --: " << RecDownDec(N, K, 1) << endl;
    cout << "Rec down ++: " << RecDownInc(N, K, N) << endl;
    cout << "Rec up --: " << RecUpDec(N, K, N) << endl;
    cout << "Rec up ++: " << RecUpInc(N, K, 1) << endl;

    return 0;
}
