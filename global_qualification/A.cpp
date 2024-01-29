#include <iostream>

using namespace std;

int main() {

    long double a, b, c;
    cin >> a >> b >> c;

    if (b > 0) cout << (a >= c / b ? "Yes" : "No");
    else if (b == 0) cout << (c <= 0 ? "Yes" : "No");
    else cout << (a <= c / b ? "Yes" : "No");

}