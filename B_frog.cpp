#include<bits/stdc++.h>
using namespace std;

int minCost(int n, int k, vector<int>&arr, vector<vector<int>>& dp){
    if(n == 1) return 0;

    if(dp[n][k] != -1) return dp[n][k];

    int mini = INT_MAX;

    for(int i = 1; i <= k && n - i >= 1; i++){
        mini = min(mini, abs(arr[n - 1] - arr[n - i - 1]) + minCost(n - i, k, arr, dp));
    }

    return dp[n][k] = mini;
}

void solve(void){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &it : arr) cin >> it;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    cout << minCost(n, k, arr, dp) << endl;
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

    solve();

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}
