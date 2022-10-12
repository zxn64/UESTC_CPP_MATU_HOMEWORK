#include <iostream>

int main() {
    int ans = 1, n;
    std::cin >> n;
    if (n > 12) {
        std::cout << "12!=479001600";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        ans *= i;
    }
    std::cout << n << "!=" << ans;
    return 0;
}
