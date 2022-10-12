#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (!(n & 1) || n < 1 || n > 80) {
        std::cout << "error";
        return 0;
    }
    for (int i = 0; i <= n / 2; ++i) {
        for (int j = 0; j < i; ++j) std::cout << ' ';
        for (int j = 0; j < n - i * 2; ++j) std::cout << '*';
        std::cout << std::endl;
    }
    return 0;
}
