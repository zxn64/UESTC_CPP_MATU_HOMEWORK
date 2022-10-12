#include <iostream>

int main() {
    for (int i = 100; i < 200; ++i) {
        if (i % 3 && i % 7) std::cout << i;
    }
    return 0;
}
