#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

double function(double y) {
    double t = 1 + std::pow(y, 2) / 2 - std::pow(y, 3) / 3;
    return (1 + std::pow(t, 2) * (1 - std::pow(y, 2)) - 2 * t) / (5 - std::pow(t, 2) * (1 + y));
}

namespace UnitTest {
    TEST_CLASS(UnitTest1) {
public:
    TEST_METHOD(TestMethod1) {
        double y = 1.0;
        double expected = -0.585366;
        double result = function(y);
        Assert::AreEqual(expected, result, 0.0001);
    }
    };
}
