#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

typedef long long ll;

using namespace std;

ll comb[54][54];

// Build Pascal's triangle for O(1) combination calculation
void build () {
    for (ll i = 0; i < 54; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
    }
    for (ll i = 1; i < 54; i++) {
        for (ll j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

// Generate all possible subset sums of the elements in nums[start, end)
vector<ll> generateSubSums(vector<ll>& nums, int start, int end) {
    if (start >= end) return {0};
    vector<ll> res((1 << (end - start)), 0);
    for (int j = start; j < end; j++) {
        int k = 1 << (j - start);
        for (int i = 0; i < k; i++) {
            res[i + k] = res[i] + nums[j];
        }
    }
    return res;
}

// Check if it's possible to get target by summing a subset of nums
// Time complexity: O(2^(n / 2))
bool isPossible(vector<ll>& nums, ll target) {
    int m = static_cast<int>(nums.size() / 2);

    auto left = generateSubSums(nums, 0, m - 1);
    auto right = generateSubSums(nums, m - 1, static_cast<int>(nums.size()));

    unordered_set<ll> leftSet(left.begin(), left.end());

    return any_of(right.begin(), right.end(), [&](ll num) {
        return leftSet.count(target - num) > 0;
    });
}

int main() {
    build();
    ll t;
    cin >> t;
    while (t--) {
        ll n, target;
        cin >> n >> target;
        vector<ll> nums(n);
        for (ll i = 0; i < n; i++) {
            ll a, b; cin >> a >> b;
            // the number of groups from a people where b people are selected
            nums[i] = comb[a][b];
        }
        // having '1 / target' probability of selecting a random group
        // is the same as having 'target' groups
        cout << (isPossible(nums, target) ? "done" : "deal with it") << endl;
    }
}