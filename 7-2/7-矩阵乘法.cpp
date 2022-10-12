#include <iostream>

void Matrix_Mul(int a[3][2], int b[2][4]) {
    int ans;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            ans = 0;
            for (int k = 0; k < 2; ++k) {
                ans += a[i][k] * b[k][j];
            }
            std::cout << ans << ' ';
        }
        std::cout << std::endl;
    }
}