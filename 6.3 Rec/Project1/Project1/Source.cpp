#include <iostream>
#include <iomanip>
using namespace std;


int CountEvenElements(int* a, const int size, int index);

template <typename T>
int CountEvenElementsTamplate(T* a, const int size, int index, int count);

void PrintArray(int* a, const int numberOfElements, int i);
template <typename T>
void PrintArray(T* a, const int numberOfElements, int i);

int main() {
    const int n = 11;

    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12 };

    cout << "Started Array:" << endl;
    PrintArray(a, n, 0);

    cout << "Started Array with Tamplate Print:" << endl;
    PrintArray<int>(a, n, 0);

    int evenCountRecurtion = CountEvenElements(a, n, 0);
    cout << "Number of even elements: " << evenCountRecurtion << endl;

    int evenCountTemplate = CountEvenElementsTamplate<int>(a, n, 0, 0);
    cout << "Number of even elements (template): " << evenCountTemplate << endl;

    return 0;
}

void PrintArray(int* a, const int numberOfElements, int i)
{
    cout << setw(4) << a[i];
    if (i < numberOfElements - 1)
        PrintArray(a, numberOfElements, i + 1);
    else
        cout << endl;
}

template <typename T>
void PrintArray(T* a, const int numberOfElements, int i) {
    cout << setw(4) << a[i];
    if (i < numberOfElements - 1)
        PrintArray(a, numberOfElements, i + 1);
    else
        cout << endl;
}

int CountEvenElements(int* a, const int size, int index) {
    if (index == size) {
        return 0;
    }
    return (a[index] % 2 == 0) + CountEvenElements(a, size, index + 1);
}

template <typename T>
int CountEvenElementsTamplate(T* a, const int size, int index, int count) {
    if (index < size) {
        if (a[index] % 2 == 0) {
            return CountEvenElementsTamplate(a, size, index + 1, count + 1);
        }
        return CountEvenElementsTamplate(a, size, index + 1, count);
    }
    return count;
}