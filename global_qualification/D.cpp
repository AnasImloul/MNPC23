#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int queryType;
        cin >> queryType;
        if (queryType == 0) {
            int i;
            char c;
            cin >> i >> c;
            S[i - 1] = c;
        } else if (queryType == 1) {
            string p;
            cin >> p;
            size_t index = S.find(p);
            if (index != string::npos) {
                cout << index + 1 << endl; // Adjusting index to 1-based
            } else {
                cout << -1 << endl;
            }
        }
    }
}
