#include <bits/stdc++.h>
#define int long long
using namespace std;

// 2D Prefix Sum
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--) {
        int n,q;
        cin >> n>>q;
        
        // Initialize the matrix and prefix sum vector
        vector<int> v(n),diff(n+2);

        // Input the grid and construct prefix sum row-wise
        for (int i = 0; i < n; i++) {
           cin>>v[i];
        }

        // Construct prefix sum column-wise
        for (int j = 0; j < q; j++) {
           int left,right;
           cin>>left>>right;
           diff[left]+=1;
           diff[right+1]-=1;
        }
        for(int j=1;j<n+2;j++)
        {
            diff[j]+=diff[j-1];
        }
        sort(diff.begin(),diff.end());
        sort(v.begin(),v.end());
        int last =n-1,sum=0;
        for(int j=n+1;j>=1;j--)
        {
            int mul =0;
            if(last>=0)
            mul = v[last];
         sum+=mul*diff[j];
         last--;

        }
        cout<<sum<<endl;
        
    }

    return 0;
}
