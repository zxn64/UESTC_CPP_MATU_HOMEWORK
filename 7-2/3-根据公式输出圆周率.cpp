#include <iostream>

const double eps = 1e-8;

int main() {
    int step = 1;
    double PI = 0;
    while (1.0 / (step * 2 - 1) > eps) {
        if (step & 1) PI += 1.0 / (step * 2 - 1);
        else PI -= 1.0 / (step * 2 - 1);
        ++step;
    }
    std::cout.precision(6);
    std::cout << "steps=" << step << " PI=" << PI * 4;
    return 0;
}
