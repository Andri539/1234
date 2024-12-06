#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

//Recurtion way

void CreateArrayWithRandomElements(int* c, int numberOfElements, int start, int end, int i);
void PrintArray(int* c, const int numberOfElements, int i);
int CountElements(int* c, int numberOfElements, int count, int i);
int SumElements(int* c, int numberOfElements, int sum, int i);
void TurnToZero(int* c, int numberOfElements, int i);

int main()
{
	srand((unsigned)time(NULL));

	const int n = 25;
	int c[n];

	int Low = 5;
	int High = 90;
	CreateArrayWithRandomElements(c, n, Low, High, 0);
	cout << "Array with Random elements:" << endl;
	PrintArray(c, n, 0);
	cout << "Number of right elements: " << setw(1) << CountElements(c, n, 0, 0) << endl;
	cout << "Sum of right elements: " << setw(1) << SumElements(c, n, 0, 0) << endl;
	TurnToZero(c, n, 0);
	PrintArray(c, n, 0);
}

void CreateArrayWithRandomElements(int* c, int numberOfElements, int start, int end, int i) {
	c[i] = start + rand() % (end - start + 1);
	if (i < numberOfElements - 1) {
		CreateArrayWithRandomElements(c, numberOfElements, start, end, i + 1);
	}
}
void PrintArray(int* c, const int numberOfElements, int i)
{
	cout << setw(4) << c[i];
	if (i < numberOfElements - 1)
		PrintArray(c, numberOfElements, i + 1);
	else
		cout << endl;
}

int CountElements(int* c, int numberOfElements, int count, int i) {
	if (i < numberOfElements) {
		if (c[i] % 2 == 0 || i % 8 != 0) {
			count++;
		}
		return CountElements(c, numberOfElements, count, i + 1);
	}
	return count;
}

int SumElements(int* c, int numberOfElements, int sum, int i) {
	if (i < numberOfElements) {
		if (c[i] % 2 == 0 || i % 8 != 0) {
			sum += c[i];
		}
		return SumElements(c, numberOfElements, sum, i + 1);
	}
	return sum;
}

void TurnToZero(int* c, int numberOfElements, int i) {
	if (i < numberOfElements) {
		if (c[i] % 2 == 0 || i % 8 != 0) {
			c[i] = 0;
		}
		TurnToZero(c, numberOfElements, i + 1);
	}
}
