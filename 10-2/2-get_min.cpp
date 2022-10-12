#include <iostream>

using namespace std;

template<typename T>
T get_min(T *array, unsigned long long length) {
    T ans = array[0];
    for (int i = 1; i < length; ++i) {
        ans = min(ans, array[i]);
    }
    return ans;
}

int main() {
    int arr_int[6] = {1, 2, 3, 4, 5, 6};
    double arr_double[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    cout << get_min(arr_int, 6) << endl;
    cout << get_min(arr_double, 6) << endl;
    return 0;
}
