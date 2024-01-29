#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Function to check if it's possible to reach the end of the array
int solve(int i, int odd, vector<int>& larger, vector<int>& smaller, vector<vector<int>>& cache) {
    if (i == -1) return 0;
    if (i == larger.size() - 1) return 1;
    if (cache[i][odd] != -1) return cache[i][odd];

    int nextIndex = (odd == 1) ? larger[i] : smaller[i];
    int res = solve(nextIndex, 1 - odd, larger, smaller, cache);

    return cache[i][odd] = res;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int& num : nums) {
        cin >> num;
    }

    vector<int> larger(n, -1);
    set<pair<int, int>> s1;

    for (int i = n - 1; i >= 0; i--) {
        auto it = s1.lower_bound({nums[i] + 1, -1});
        if (it != s1.end()) larger[i] = it->second;
        s1.insert({nums[i], i});
    }

    vector<int> smaller(n, -1);
    set<pair<int, int>, greater<>> s2;

    for (int i = n - 1; i >= 0; i--) {
        auto it = s2.upper_bound({nums[i] - 1, n});
        if (it != s2.end()) smaller[i] = -it->second;
        s2.insert({nums[i], -i});
    }

    vector<vector<int>> cache(n, vector<int>(2, -1));
    int res = 0;

    for (int i = 0; i < n; i++) {
        res += solve(i, 1, larger, smaller, cache);
    }

    cout << res << endl;

    return 0;
}
