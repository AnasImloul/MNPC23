#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

// Function to perform depth-first search and calculate the number of leafs in the subtree rooted at u
ll dfs(ll u, ll p, const vector<vector<ll>>& tree, vector<ll>& dp) {
    ll leafs = 0;
    for (ll v : tree[u]) {
        if (v != p) {
            leafs += dfs(v, u, tree, dp);
        }
    }
    dp[u] = (leafs == 0) ? 1 : leafs;
    return dp[u];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> weights(n);
        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }

        vector<vector<ll>> tree(n, vector<ll>());

        for (int i = 0; i < n - 1; i++) {
            ll u, v;
            cin >> u >> v;
            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        vector<ll> dp(n, 0);
        dfs(0, -1, tree, dp);

        // Calculate the product of dp values with corresponding weights
        for (int i = 0; i < n; i++) {
            dp[i] *= weights[i];
        }

        ll ans = 0, m = 0;

        // Find the minimum value in dp and accumulate the sum in ans
        for (int i = 0; i < n; i++) {
            m = min(m, dp[i]);
            ans += dp[i];
        }

        // Output the maximum of ans and (ans - m)
        cout << max(ans, ans - m) << endl;
    }

    return 0;
}
