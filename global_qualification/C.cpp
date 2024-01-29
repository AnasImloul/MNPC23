#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t-- != 0) {
        long long n;
        cin >> n;

        int ans[10] = {0};

        for (int d = 0; d < 10; ++d) {
            long long x = (d == 0) ? 100 : d;
            int cnt = (d == 0) ? 1 : 0;

            while (x <= n) {
                ++cnt;
                x *= 10;
                x += d;
            }

            ans[d] = cnt;
        }

        for (int i = 0; i < 10; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
