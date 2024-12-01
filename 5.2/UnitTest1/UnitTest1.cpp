#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void getA(const double x, const int n, double& a) {
    if (x == 0) {
        a = 0.0;
    }
    else {
        a = pow(x - 1, n + 1) / ((n + 1) * pow(x, n + 1));
    }
}

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(AllTests)
        {
            double a;
            double x = 0;
            int n = 0;

            getA(x, n, a);
            Assert::AreEqual(a, 0.0);
        }
    };
}
