#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRecurtion
{
	TEST_CLASS(UnitTestRecurtion)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			int c[n] = { 12, 12, -2, 1, -6 };
			int expectation = SumElements(c, n, 0, 0);
			int actual = 17;
			Assert::AreEqual(expectation, actual);
		}
	};
}

