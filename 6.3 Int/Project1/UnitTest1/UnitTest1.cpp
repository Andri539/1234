#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIter
{
	TEST_CLASS(UnitTestIter)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			int a[n] = { 1,2,6, 14, 18 };
			int expectation = CountEvenElements(a, n);
			int actual = 4;
			Assert::AreEqual(expectation, actual);
		}
	};
}
