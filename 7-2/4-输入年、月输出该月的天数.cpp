#include <iostream>

bool IsLeapYear(int year) {
    if (!(year % 100) && year % 400) return false;
    if (year % 4) return false;
    return true;
}

const int days[12] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

int main() {
    int year, month;
    std::cin >> year >> month;
    std::cout << "days:";
    if (IsLeapYear(year) && month % 12 == 2) std::cout << 29;
    else std::cout << days[month % 12];
    return 0;
}
