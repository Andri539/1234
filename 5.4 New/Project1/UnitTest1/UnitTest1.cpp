#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestIterSum)
        {
            int N = 2, K = 0;
            double expected = (1 + sqrt(2)) / 1 + (1 + sqrt(5)) / 4;
            double actual = IterSum(N, K);
            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(TestRecDownDec)
        {
            int N = 2, K = 0;
            double expected = (1 + sqrt(2)) / 1 + (1 + sqrt(5)) / 4;
            double actual = RecDownDec(N, K, 1);
            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(TestRecDownInc)
        {
            int N = 2, K = 0;
            double expected = (1 + sqrt(2)) / 1 + (1 + sqrt(5)) / 4;
            double actual = RecDownInc(N, K, N);
            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(TestRecUpDec)
        {
            int N = 2, K = 0;
            double expected = (1 + sqrt(2)) / 1 + (1 + sqrt(5)) / 4;
            double actual = RecUpDec(N, K, N);
            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(TestRecUpInc)
        {
            int N = 2, K = 0;
            double expected = (1 + sqrt(2)) / 1 + (1 + sqrt(5)) / 4;
            double actual = RecUpInc(N, K, 1);
            Assert::AreEqual(expected, actual, 0.0001);
        }
    };
}
