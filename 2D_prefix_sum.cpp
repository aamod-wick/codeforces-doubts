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
        int n, q;
        cin >> n >> q;
        
        // Initialize the matrix and prefix sum vector
        vector<vector<int>> v(n, vector<int>(n, 0));

        // Input the grid and construct prefix sum row-wise
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                v[i][j] = (c == '*') ? 1 : 0;
                if (j > 0) v[i][j] += v[i][j - 1]; // Add the previous cell in the same row
            }
        }

        // Construct prefix sum column-wise
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
                v[i][j] += v[i - 1][j]; // Add the previous cell in the same column
            }
        }

        // Process each query
        while (q--) {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;

            // Convert to 0-based indexing
            y1--, x1--, y2--, x2--;

            // Calculate the sum of the sub-matrix
            int result = v[y2][x2];
            if (x1 > 0) result -= v[y2][x1 - 1];
            if (y1 > 0) result -= v[y1 - 1][x2];
            if (x1 > 0 && y1 > 0) result += v[y1 - 1][x1 - 1];

            cout << result << endl;
        }
    }

    return 0;
}
