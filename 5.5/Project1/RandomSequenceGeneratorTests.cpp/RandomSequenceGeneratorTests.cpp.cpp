#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(RandomSequenceGeneratorTests)
    {
    public:

        TEST_METHOD(InitialValuesTest)
        {
            RandomSequenceGenerator gen(2, 3, 5, 100);
            std::vector<int> sequence = gen.getSequence();

            Assert::AreEqual(2, (int)sequence.size());

            Assert::IsTrue(sequence[0] >= 0 && sequence[0] < 100);
            Assert::IsTrue(sequence[1] >= 0 && sequence[1] < 100);
        }

        TEST_METHOD(SequenceGenerationTest)
        {
            RandomSequenceGenerator gen(2, 3, 5, 100);

            gen.next();
            gen.next();
            gen.next();

            std::vector<int> sequence = gen.getSequence();

            Assert::IsTrue(sequence.size() >= 5);

            int expected = (2 * sequence[sequence.size() - 2] + 3 * sequence[sequence.size() - 3] + 5) % 100;
            Assert::AreEqual(expected, sequence[sequence.size() - 1]);
        }

        TEST_METHOD(DifferentParametersTest)
        {
            RandomSequenceGenerator gen(1, 1, 1, 50);

            gen.next();
            gen.next();
            gen.next();
            gen.next();

            std::vector<int> sequence = gen.getSequence();

            Assert::IsTrue(sequence.size() >= 5);

            int expected = (sequence[sequence.size() - 2] + sequence[sequence.size() - 3] + 1) % 50;
            Assert::AreEqual(expected, sequence[sequence.size() - 1]);
        }
    };
}
