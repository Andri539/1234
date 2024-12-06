#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


void CreateArrayWithRandomElements(int* c, int numberOfElements, int start, int end);
void PrintArray(int* c, const int numberOfElements);
int CountElements(int* c, int numberOfElements);
int SumElements(int* c, int numberOfElements);
void TurnToZero(int* c, int numberOfElements);

int main()
{
	srand((unsigned)time(NULL));

	const int n = 25;
	int c[n];

	int Low = 5;
	int High = 90;
	CreateArrayWithRandomElements(c, n, Low, High);
	cout << "Array with Random elements:" << endl;
	PrintArray(c, n);
	cout << "Number of right elements: " << setw(1) << CountElements(c, n) << endl;
	cout << "Sum of right elements: " << setw(1) << SumElements(c, n) << endl;
	TurnToZero(c, n);
	PrintArray(c, n);
}

void CreateArrayWithRandomElements(int* c, int numberOfElements, int start, int end) {

	for (int i = 0; i < numberOfElements; i++) {
		c[i] = start + rand() % (end - start + 1);
	}
}
void PrintArray(int* c, const int numberOfElements)
{
	for (int i = 0; i < numberOfElements; i++) {
		cout << setw(4) << c[i];
	}
	cout << endl;
}

int CountElements(int* c, int numberOfElements) {
	int count = 0;
	for (int i = 0; i < numberOfElements; i++) {
		if (c[i] % 2 == 0 || i % 8 != 0) {
			count++;
		}
	}
	return count;
}

int SumElements(int* c, int numberOfElements) {
	int sum = 0;
	for (int i = 0; i < numberOfElements; i++) {
		if (c[i] % 2 == 0 || i % 8 != 0) {
			sum += c[i];
		}
	}
	return sum;
}

void TurnToZero(int* c, int numberOfElements) {
	for (int i = 0; i < numberOfElements; i++) {
		if (c[i] % 2 == 0 || i % 8 != 0) {
			c[i] = 0;
		}
	}
}