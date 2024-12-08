#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void generateArray(std::vector<int>& array, int size, int minValue, int maxValue) {
    for (int i = 0; i < size; ++i) {
        array.push_back(minValue + rand() % (maxValue - minValue + 1));
    }
}

void findMinMaxIndices(const std::vector<int>& array, int& minIndex, int& maxIndex) {
    minIndex = 0;
    maxIndex = 0;
    for (size_t i = 1; i < array.size(); ++i) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }
}

void countAndSumByCriterion(const std::vector<int>& array, int& count, int& sum, int criterion) {
    count = 0;
    sum = 0;
    for (int value : array) {
        if (value > criterion) {
            ++count;
            sum += value;
        }
    }
}

void replaceByCriterion(std::vector<int>& array, int criterion) {
    for (int& value : array) {
        if (value > criterion) {
            value = 0;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int size = 10;
    int minValue = -50, maxValue = 50;
    int criterion = 0;

    std::vector<int> array;
    generateArray(array, size, minValue, maxValue);

    std::cout << "Generated array: ";
    for (int value : array) {
        std::cout << std::setw(4) << value;
    }
    std::cout << std::endl;

    int minIndex, maxIndex;
    findMinMaxIndices(array, minIndex, maxIndex);
    std::cout << "Index of min element: " << minIndex << ", Index of max element: " << maxIndex << std::endl;

    int count, sum;
    countAndSumByCriterion(array, count, sum, criterion);
    std::cout << "Count of elements > " << criterion << ": " << count << std::endl;
    std::cout << "Sum of elements > " << criterion << ": " << sum << std::endl;

    replaceByCriterion(array, criterion);

    std::cout << "Modified array:   ";
    for (int value : array) {
        std::cout << std::setw(4) << value;
    }
    std::cout << std::endl;

    return 0;
}
