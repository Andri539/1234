#include "pch.h"
#include <CppUnitTest.h>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    double function(double y, double t) {
        return (1 + pow(t, 2) * (1 - pow(y, 2)) - 2 * t) / (5 - pow(t, 2) * (1 + y));
    }

    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestFunction)
        {
            double y = 1.0;
            double t = 1.0;
            double expected = -0.333333;
            double result = function(y, t);
            Assert::AreEqual(expected, result, 0.0001);
        }
    };
}
