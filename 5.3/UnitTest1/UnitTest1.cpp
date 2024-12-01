#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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

namespace UnitTest1 {
    TEST_CLASS(UnitTest1) {
public:
    TEST_METHOD(TestMethod1) {
        double t = -10;
        double result = s(pow(t, 2)) + 2 * s(t) + 1;
        Assert::AreEqual(result, 9.27501e+16, 1e+10);
    }
    };
}
