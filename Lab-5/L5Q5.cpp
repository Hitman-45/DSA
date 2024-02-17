#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string add(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        sum %= 10;
        result += to_string(sum);
    }
    reverse(result.begin(), result.end());
    return result;
}

string multiply(string a, string b) {
    if (a == "0" || b == "0") return "0";

    int m = a.size(), n = b.size();
    string result(m + n, '0');

    for (int i = m - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = n - 1; j >= 0; --j) {
            int temp = (a[i] - '0') * (b[j] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = temp % 10 + '0';
            carry = temp / 10;
        }
        result[i] += carry;
    }

    if (result[0] == '0') result.erase(result.begin());
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << multiply(a, b) << endl;
    }
    return 0;
}