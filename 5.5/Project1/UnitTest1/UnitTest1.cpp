#include "pch.h"
#include "CppUnitTest.h"
#include "../YourProject/Source.cpp"  // Підключаємо ваш головний файл Source.cpp

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

            // Перевірка, що 2 початкових значення були згенеровані
            Assert::AreEqual(2, (int)sequence.size());

            // Перевірка, що ці значення знаходяться в діапазоні [0, 100)
            Assert::IsTrue(sequence[0] >= 0 && sequence[0] < 100);
            Assert::IsTrue(sequence[1] >= 0 && sequence[1] < 100);
        }

        TEST_METHOD(SequenceGenerationTest)
        {
            RandomSequenceGenerator gen(2, 3, 5, 100);

            // Генерація значень
            gen.next();
            gen.next();
            gen.next();

            std::vector<int> sequence = gen.getSequence();

            // Перевірка, що згенеровано мінімум 5 значень
            Assert::IsTrue(sequence.size() >= 5);

            // Перевірка рекурентної формули для останнього значення
            int expected = (2 * sequence[sequence.size() - 2] + 3 * sequence[sequence.size() - 3] + 5) % 100;
            Assert::AreEqual(expected, sequence[sequence.size() - 1]);
        }

        TEST_METHOD(DifferentParametersTest)
        {
            RandomSequenceGenerator gen(1, 1, 1, 50);

            // Генерація кількох значень
            gen.next();
            gen.next();
            gen.next();
            gen.next();

            std::vector<int> sequence = gen.getSequence();

            // Перевірка, що згенеровано хоча б 5 значень
            Assert::IsTrue(sequence.size() >= 5);

            // Перевірка рекурентного обчислення для останнього значення
            int expected = (sequence[sequence.size() - 2] + sequence[sequence.size() - 3] + 1) % 50;
            Assert::AreEqual(expected, sequence[sequence.size() - 1]);
        }
    };
}
