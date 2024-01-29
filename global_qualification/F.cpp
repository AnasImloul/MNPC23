#include <iostream>
#include <vector>
#include <unordered_set>

typedef long long ll;

using namespace std;

ll comb[54][54];

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

bool isPossible(vector<ll>& nums, ll target) {
    int m = static_cast<int>(nums.size() / 2);

    auto left = generateSubSums(nums, 0, m - 1);
    auto right = generateSubSums(nums, m - 1, static_cast<int>(nums.size()));

    unordered_set<ll> leftSet(left.begin(), left.end());

    for (ll& r : right) {
        if (leftSet.count(target - r)) return true;
    }
    return false;
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
            nums[i] = comb[a][b];
        }
        cout << (isPossible(nums, target) ? "done" : "deal with it") << endl;
    }
}