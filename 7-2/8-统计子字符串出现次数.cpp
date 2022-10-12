#include <iostream>
#include <cstring>

int SubStrNum(char *str, char *substr) {
    int len_str = strlen(str), len_substr = strlen(substr), count = 0;
    for (int i = 0; i <= len_str - len_substr; ++i) {
        for (int j = 0; j < len_substr; ++j) {
            if (str[i + j] != substr[j]) break;
            if (j == len_substr - 1) {
                i += j;
                ++count;
            }
        }
    }
    std::cout << "match times=" << count;
    return count;
}