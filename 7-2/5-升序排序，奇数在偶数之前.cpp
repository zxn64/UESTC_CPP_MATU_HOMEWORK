#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> array;

bool cmp(int a, int b) {
    if ((a & 1) ^ (b & 1)) {
        if (a & 1) return true;
        return false;
    }
    return a < b;
}

int main() {
    int temp;
    while (array.size() < 10) {
        std::cin >> temp;
        if (temp < 0) break;
        array.push_back(temp);
    }
    std::sort(array.begin(), array.end(), cmp);
    for (int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << ' ';
    }
    return 0;
}
