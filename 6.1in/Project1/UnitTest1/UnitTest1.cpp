#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIteraction
{
	TEST_CLASS(UnitTestIteraction)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			int c[n] = { 4, 12, -2, 1, -7 };
			int expectation = CountElements(c, n);
			int actual = 5;
			Assert::AreEqual(expectation, actual);
		}
	};
}
