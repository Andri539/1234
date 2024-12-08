#include <iostream>
#include <cassert>
#include <vector>
#include "../Project1/Source.cpp"

// ���-���� ��� generateArray
void testGenerateArray() {
    std::vector<int> array;
    generateArray(array, 10, 1, 100);
    assert(array.size() == 10); // �������� ������� ��������
    for (int val : array) {
        assert(val >= 1 && val <= 100); // �������� �������� �������
    }
    std::cout << "testGenerateArray passed" << std::endl;
}

// ���-���� ��� findMinMaxIndices
void testFindMinMaxIndices() {
    std::vector<int> array = { 1, 5, -3, 7, 2 };
    int minIndex = 0, maxIndex = 0;
    findMinMaxIndices(array, minIndex, maxIndex);
    assert(minIndex == 2); // ̳�������� ������� �� ������ 2
    assert(maxIndex == 3); // ������������ ������� �� ������ 3
    std::cout << "testFindMinMaxIndices passed" << std::endl;
}

// ���-���� ��� countAndSumByCriterion
void testCountAndSumByCriterion() {
    std::vector<int> array = { 1, 5, -3, 7, 2 };
    int count = 0, sum = 0;
    countAndSumByCriterion(array, count, sum, 0); // �������: �������� > 0
    assert(count == 4); // 4 �������� ����� 0
    assert(sum == 15); // ����: 1 + 5 + 7 + 2 = 15
    std::cout << "testCountAndSumByCriterion passed" << std::endl;
}

// ���-���� ��� replaceByCriterion
void testReplaceByCriterion() {
    std::vector<int> array = { 1, 5, -3, 7, 2 };
    replaceByCriterion(array, 0); // ����� �������� > 0 �� 0
    assert(array[0] == 0);
    assert(array[1] == 0);
    assert(array[3] == 0);
    assert(array[4] == 0);
    std::cout << "testReplaceByCriterion passed" << std::endl;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // ����������� ���������� ���������� �����

    // ������ ���-�����
    testGenerateArray();
    testFindMinMaxIndices();
    testCountAndSumByCriterion();
    testReplaceByCriterion();

    // ������� ����� ��������
    int size = 10;
    int minValue = -50, maxValue = 50;
    int criterion = 0; // �������: �������� ����� �� 0

    // ��������� ������
    std::vector<int> array;
    generateArray(array, size, minValue, maxValue);

    // ��������� ����������� ������
    std::cout << "Generated array: ";
    printArray(array);

    // ����� ������� ���������� �� ������������� ��������
    int minIndex = 0, maxIndex = 0;
    findMinMaxIndices(array, minIndex, maxIndex);
    std::cout << "Index of min element: " << minIndex << ", Index of max element: " << maxIndex << std::endl;

    // ���������� ������� �� ���� �������� �� �������
    int count = 0, sum = 0;
    countAndSumByCriterion(array, count, sum, criterion);
    std::cout << "Count of elements > " << criterion << ": " << count << std::endl;
    std::cout << "Sum of elements > " << criterion << ": " << sum << std::endl;

    // ����� �������� �� ���
    replaceByCriterion(array, criterion);

    // ��������� �������������� ������
    std::cout << "Modified array:   ";
    printArray(array);

    return 0;
}
