#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353

int rec(unordered_map<int, int> &m, int pos, vector<int> &pre, int n) {
    if (m.find(pos) != m.end()){   cerr<<pos<<"== "<<m[pos]<<endl;        return m[pos]; }
    if (pos <= n) {   cerr<<pos<<"== "<<pre[pos-1]<<endl;return m[pos] = pre[pos-1];}
   m[pos] = rec(m, floor((pos)*1.0 / 2), pre, n);
   cerr<<pos<<"== "<<m[pos]<<endl;

   return m[pos]; 
}

signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
  

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> v(n), pre(n);
        unordered_map<int, int> m; // Memoization map

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        pre[0] = v[0];
        m[0] = pre[0]; 

        for (int i = 1; i < n; i++) {
            pre[i] = v[i] ^ pre[i -1]; 
           // cerr<<pre[i]<<" ";
        }

        cout << rec(m, l , pre, n) << endl; 
    }

    return 0;
}
