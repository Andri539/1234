#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void generateArrayRecursive(std::vector<int>& array, int size, int minValue, int maxValue) {
    if (size <= 0) return;
    array.push_back(minValue + rand() % (maxValue - minValue + 1));
    generateArrayRecursive(array, size - 1, minValue, maxValue);
}

int findMinIndexRecursive(const std::vector<int>& array, int currentIndex, int minIndex) {
    if (currentIndex >= array.size()) return minIndex;
    if (array[currentIndex] < array[minIndex]) minIndex = currentIndex;
    return findMinIndexRecursive(array, currentIndex + 1, minIndex);
}

int findMaxIndexRecursive(const std::vector<int>& array, int currentIndex, int maxIndex) {
    if (currentIndex >= array.size()) return maxIndex;
    if (array[currentIndex] > array[maxIndex]) maxIndex = currentIndex;
    return findMaxIndexRecursive(array, currentIndex + 1, maxIndex);
}

void countAndSumByCriterionRecursive(const std::vector<int>& array, int currentIndex, int& count, int& sum, int criterion) {
    if (currentIndex >= array.size()) return;
    if (array[currentIndex] > criterion) {
        count++;
        sum += array[currentIndex];
    }
    countAndSumByCriterionRecursive(array, currentIndex + 1, count, sum, criterion);
}

void replaceByCriterionRecursive(std::vector<int>& array, int currentIndex, int criterion) {
    if (currentIndex >= array.size()) return;
    if (array[currentIndex] > criterion) array[currentIndex] = 0;
    replaceByCriterionRecursive(array, currentIndex + 1, criterion);
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int size = 10;
    int minValue = -50, maxValue = 50;
    int criterion = 0;

    std::vector<int> array;
    generateArrayRecursive(array, size, minValue, maxValue);

    std::cout << "Generated array: ";
    for (int value : array) {
        std::cout << std::setw(4) << value;
    }
    std::cout << std::endl;

    int minIndex = findMinIndexRecursive(array, 1, 0);
    int maxIndex = findMaxIndexRecursive(array, 1, 0);
    std::cout << "Index of min element: " << minIndex << ", Index of max element: " << maxIndex << std::endl;

    int count = 0, sum = 0;
    countAndSumByCriterionRecursive(array, 0, count, sum, criterion);
    std::cout << "Count of elements > " << criterion << ": " << count << std::endl;
    std::cout << "Sum of elements > " << criterion << ": " << sum << std::endl;

    replaceByCriterionRecursive(array, 0, criterion);

    std::cout << "Modified array:   ";
    for (int value : array) {
        std::cout << std::setw(4) << value;
    }
    std::cout << std::endl;

    return 0;
}
