//example of bitmasking and greedy with proof for refference 
#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod = 1000000007;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;  
    while (t--) {
        int n;
        cin >> n;

        if (n <= 0) {
            cout << -1 << endl;
            continue;
        }

        vector<int> v(n + 1, 0);  
        int k = 0; 

       
        map<int, int> m;
        m[1] = 1;
        m[2] = 0;
        v[0] = 2;
        v[1] = 1;
        for (int i = 2; i < n; i++) {
            v[i] = i + 1;
        }

        if (n % 2 == 0) {
            int small = 0;
            int target;
    if (n > 0 && (n & (n - 1)) == 0) {
    // n is a power of 2
    target = 2 * n - 1;
    } else {
    // n is not a power of 2
    target = (1 << static_cast<int>(ceil(log2(n)))) - 1;
    }   
         // cout<<target<<" taregt"<<endl;
            // Find the smallest `i` such that `n | i` equals `target`
            for (int i = 0; i < n-1; i++) {
                if ((n | v[i]) == target) {
                    small = i;
                    break;
                }
            }

            int nd = 0;
            //this is to find `i` such that `(i & small) | n == target` and `i != small`
            for (int i = n - 2; i >=0; i--) {
                if (((v[i] & v[small])|n) == target && i!=small) {
                    nd = i;
                    break;
                }
            }
           // cout<<v[small]<<v[nd]<<" ---"<<endl;
            if(small == n-3 && nd==n-2)
            swap(v[small],v[nd]);
            else if (small== n-3)
            {
                swap(v[n-3],v[nd]);
                swap(v[nd],v[n-2]);
            }
            else if (nd == n-2)
            {
                swap(v[small],v[n-2]);
                swap(v[small],v[n-3]);
            }
           //cout<<" small : nd : :" <<v[small]<<v[nd]<<endl;
             
                else{
                swap(v[small], v[n-2]);
                swap(v[nd], v[n - 3]);
        }
        }
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 2 == 0)
                k |= v[i];
            else
                k &= v[i];
        }
        // Output the result of `k`
        cout << k << endl;

        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
