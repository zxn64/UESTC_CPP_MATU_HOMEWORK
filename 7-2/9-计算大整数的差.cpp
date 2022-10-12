#include <iostream>
#include <cstdlib>
#include <string>

int main() {
    {
        using namespace std;
        string a, b, temp;
        cin >> a >> b;
        if (a == b) {
            cout << 0;
            return 0;
        }
        for (int i = 0; i < abs((int) a.length() - (int) b.length()); ++i) {
            temp.push_back('0');
        }
        if (a.length() < b.length()) a = temp + a;
        else if (b.length() < a.length()) b = temp + b;
        bool negative = a < b;
        if (negative) swap(a, b);
        for (int i = (int) a.length() - 1; i >= 0; --i) {
            if (a[i] >= b[i]) {
                a[i] = a[i] - b[i] + '0';
            } else {
                a[i] = a[i] + 10 - b[i] + '0';
                a[i - 1] -= 1;
            }
        }
        if (negative) cout << '-';
        else cout << '+';
        cout << a;
    }
    return 0;
}