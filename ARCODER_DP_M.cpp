#include <bits/stdc++.h>
//TC DP = NO OF STATES X TIME TAKEN BY STATES ; HERE IT IS N*X^2, giving tle
using namespace std;
#define int long long
#define MOD 1000000007

int x = 0;
int n = 0;
vector<int> v;
vector<vector<int>> dp;

int rec(int j, int sum) {
    if (sum == 0) return 1;
    if (j >= n || sum < 0) return 0;

    if (dp[j][sum] != -1) {
        return dp[j][sum] % MOD;
    }

    dp[j][sum] = 0;
    for (int i = 0; i <= min(sum, v[j]); i++) {
        dp[j][sum] = (dp[j][sum] + rec(j + 1, sum - i)) % MOD;
    }

   // cout << "j is " << j << " " << sum << " combinations: " << dp[j][sum] << endl;
    int x = dp[j][sum] % MOD;
    return x;
}

signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    v.resize(n);
    dp.resize(n, vector<int>(x + 1, -1));

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = rec(0, x);
    cout << ans << endl;
    return 0;
}
