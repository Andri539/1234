#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class RandomSequenceGenerator {
private:
    int a, b, c, m;
    std::vector<int> sequence;

public:
    RandomSequenceGenerator(int a, int b, int c, int m) : a(a), b(b), c(c), m(m) {
        sequence.push_back(rand() % 100);
        sequence.push_back(rand() % 100);
    }

    int next() {
        int nextValue = (a * sequence[sequence.size() - 1] +
            b * sequence[sequence.size() - 2] + c) % m;
        sequence.push_back(nextValue);
        std::cout << "Generated value: " << nextValue << std::endl;
        return nextValue;
    }

    std::vector<int> getSequence() const {
        return sequence;
    }
};

int main() {
    int a = 2, b = 3, c = 5, m = 100;
    srand(time(0));
    RandomSequenceGenerator testGen(a, b, c, m);
    std::cout << "V1 = " << testGen.next() << ", V2 = " << testGen.next() << std::endl;
    testGen.next();
    testGen.next();
    testGen.next();
    return 0;
}
