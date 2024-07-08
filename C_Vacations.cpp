#include<bits/stdc++.h>
using ll = long long;
const long double pi=3.141592653589793238462;
const long long mod = 1e9+7;
using namespace std;

ll max(ll a, ll b) { return (a > b) ? a : b;}
ll min(ll a, ll b) { return (a < b) ? a : b;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) { return (a * 1LL * b) / gcd(a, b);}

void solve(){
    int N;
    cin >> N;
    vector<vector<int>> happiness(N, vector<int>(3));
    
    for (int i = 0; i < N; ++i) {
        cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
    }

    vector<vector<int>> dp(N, vector<int>(3, 0));
    
    dp[0][0] = happiness[0][0];
    dp[0][1] = happiness[0][1];
    dp[0][2] = happiness[0][2];
    
    for (int i = 1; i < N; ++i) {
        dp[i][0] = happiness[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = happiness[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = happiness[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }
    
    int result = max({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    cout << result << endl;
}

signed main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        cin.tie(nullptr);
        auto _clock_start = chrono::high_resolution_clock::now();
    #endif

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    solve();

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}
