#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll max(ll a, ll b) { return (a > b) ? a : b;}

ll maxKnapsack(ll n, ll w, vector<int>& weight, vector<int>& val, vector<vector<int>>& dp) {
    if (n == 0 || w <= 0) return 0;
    if (dp[n][w] != -1) return dp[n][w];

    int case1 = INT_MIN, case2 = INT_MIN;
    if (w < weight[n - 1]) {
        case1 = maxKnapsack(n - 1, w, weight, val, dp);
    } else {
        case2 = max(maxKnapsack(n - 1, w, weight, val, dp), 
                              val[n - 1] + maxKnapsack(n - 1, w - weight[n - 1], weight, val, dp));
    }
    return max(case1, case2);
}

void solve() {
    ll N, W;
    cin >> N >> W;
    vector<int> weight(N), val(N);
    for(ll i = 0; i < N; i++) {
        cin >> weight[i] >> val[i];
    }
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
    cout << maxKnapsack(N, W, weight, val, dp) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        cin.tie(nullptr);
        auto _clock_start = chrono::high_resolution_clock::now();
    #endif

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}
