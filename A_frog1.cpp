#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int>& arr, int n, vector<int>& dp) {
    if (n == 1) return 0;
    if (dp[n] != -1) return dp[n];

    int cost1 = INT_MAX, cost2 = INT_MAX;
    if (n - 1 >= 1) cost1 = abs(arr[n - 1] - arr[n - 2]) + minCost(arr, n - 1, dp);
    if (n - 2 >= 1) cost2 = abs(arr[n - 1] - arr[n - 3]) + minCost(arr, n - 2, dp);

    return dp[n] = min(cost1, cost2);
}

void solve(void){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it : arr) cin >> it;
    vector<int> dp(n + 1, -1);
    cout << minCost(arr, n, dp) << endl;
}

signed main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        cin.tie(nullptr);
        auto _clock_start = chrono::high_resolution_clock::now();
    #endif

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();    // function goes here.

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}
