#include <iostream>

int main() {
    int i, j;
    for (i = 0; i < 10; i++) {
        j = i * 10 + 6;
        if (j % 3) continue;
        std::cout << j << ' ';
    }
    return 0;
}
