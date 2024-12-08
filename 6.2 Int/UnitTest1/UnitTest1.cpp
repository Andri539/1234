#include <iostream>
#include <cassert>
#include <vector>
#include "../Project1/Source.cpp"

// Юніт-тест для generateArray
void testGenerateArray() {
    std::vector<int> array;
    generateArray(array, 10, 1, 100);
    assert(array.size() == 10); // Перевірка кількості елементів
    for (int val : array) {
        assert(val >= 1 && val <= 100); // Перевірка діапазону значень
    }
    std::cout << "testGenerateArray passed" << std::endl;
}

// Юніт-тест для findMinMaxIndices
void testFindMinMaxIndices() {
    std::vector<int> array = { 1, 5, -3, 7, 2 };
    int minIndex = 0, maxIndex = 0;
    findMinMaxIndices(array, minIndex, maxIndex);
    assert(minIndex == 2); // Мінімальний елемент на індекс 2
    assert(maxIndex == 3); // Максимальний елемент на індекс 3
    std::cout << "testFindMinMaxIndices passed" << std::endl;
}

// Юніт-тест для countAndSumByCriterion
void testCountAndSumByCriterion() {
    std::vector<int> array = { 1, 5, -3, 7, 2 };
    int count = 0, sum = 0;
    countAndSumByCriterion(array, count, sum, 0); // Критерій: елементи > 0
    assert(count == 4); // 4 елементи більше 0
    assert(sum == 15); // Сума: 1 + 5 + 7 + 2 = 15
    std::cout << "testCountAndSumByCriterion passed" << std::endl;
}

// Юніт-тест для replaceByCriterion
void testReplaceByCriterion() {
    std::vector<int> array = { 1, 5, -3, 7, 2 };
    replaceByCriterion(array, 0); // Заміна елементів > 0 на 0
    assert(array[0] == 0);
    assert(array[1] == 0);
    assert(array[3] == 0);
    assert(array[4] == 0);
    std::cout << "testReplaceByCriterion passed" << std::endl;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Ініціалізація генератора випадкових чисел

    // Запуск юніт-тестів
    testGenerateArray();
    testFindMinMaxIndices();
    testCountAndSumByCriterion();
    testReplaceByCriterion();

    // Основна логіка програми
    int size = 10;
    int minValue = -50, maxValue = 50;
    int criterion = 0; // Критерій: значення більше за 0

    // Генерація масиву
    std::vector<int> array;
    generateArray(array, size, minValue, maxValue);

    // Виведення початкового масиву
    std::cout << "Generated array: ";
    printArray(array);

    // Пошук індексів мінімального та максимального елементів
    int minIndex = 0, maxIndex = 0;
    findMinMaxIndices(array, minIndex, maxIndex);
    std::cout << "Index of min element: " << minIndex << ", Index of max element: " << maxIndex << std::endl;

    // Обчислення кількості та суми елементів за критерієм
    int count = 0, sum = 0;
    countAndSumByCriterion(array, count, sum, criterion);
    std::cout << "Count of elements > " << criterion << ": " << count << std::endl;
    std::cout << "Sum of elements > " << criterion << ": " << sum << std::endl;

    // Заміна елементів на нулі
    replaceByCriterion(array, criterion);

    // Виведення модифікованого масиву
    std::cout << "Modified array:   ";
    printArray(array);

    return 0;
}
