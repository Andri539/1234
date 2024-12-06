#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRec
{
	TEST_CLASS(UnitTestRec)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 4;
			int a[n] = { 1,2,6,18 };
			int expectation = CountEvenElementsTamplate<int>(a, n, 0, 0);
			int actual = 3;
			Assert::AreEqual(expectation, actual);
		}
	};
}
