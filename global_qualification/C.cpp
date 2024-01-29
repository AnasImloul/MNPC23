#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t-- != 0) {
        long long n;
        cin >> n;

        // we iterate over all digits from 0 to 9
        for (int d = 0; d <= 9; ++d) {
            long long x = (d == 0) ? 100 : d;
            int cnt = (d == 0) ? 1 : 0;
            /*
            Logic:
            (digit = 1) -> 1, 11, 111, 1111, ... are the numbers that use the digit 1 most frequently,
            so we can just keep multiplying the number by 10 and adding 1 to it until it exceeds n
            since this will generate the numbers 1, 11, 111, 1111, ... in that order

            the same logic applies to all other digits except 0 where we have to start from 10
            and check 10, 100, 1000, ...
            */
            while (x <= n) {
                x = 10 * x + d;
                ++cnt;
            }
            cout << cnt << " ";
        }
        cout << endl;
    }

    return 0;
}
