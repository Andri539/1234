#include <iostream>
#include <iomanip>
using namespace std;

int CountEvenElements(int* a, const int size);
template <typename T>
int CountEvenElementsTamplate(T* a, const int size);

void PrintArray(int* a, const int numberOfElements);
template <typename T>
void PrintArray(T* a, const int numberOfElements);

int main() {
    const int n = 11;

    int a[n] = { 4, 2, 3, 4, 5, 6, 7, 8, 9, 10, 62 };

    cout << "Started Array:" << endl;
    PrintArray(a, n);

    cout << "Started Array with Tamplate Print:" << endl;
    PrintArray<int>(a, n);

    int evenCountIterative = CountEvenElements(a, n);
    cout << "Number of even elements: " << evenCountIterative << endl;

    int evenCountTemplate = CountEvenElementsTamplate<int>(a, n);
    cout << "Number of even elements (template): " << evenCountTemplate << endl;

    return 0;
}

void PrintArray(int* a, const int numberOfElements)
{
    for (int i = 0; i < numberOfElements; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

template <typename T>
void PrintArray(T* a, const int numberOfElements) {
    for (int i = 0; i < numberOfElements; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

int CountEvenElements(int* a, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

template <typename T>
int CountEvenElementsTamplate(T* a, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}