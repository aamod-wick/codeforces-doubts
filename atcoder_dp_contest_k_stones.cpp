#include <bits/stdc++.h>

using namespace std;

int rec(int i,int j,vector<vector<int>>& dp,vector<int>& w)
{
if(i==0)
{
//dp[0][0]=-1;
//dp[0][1] =-1;
dp[0][j]=-1;
return -1;
}
if(dp[i][j]!=0)
//return -1*dp[i][j];
return dp[i][j];
if(w[0]>i)
{
   dp[i][j] = -1;
   dp[i][(j+1)%2] =1;//-1;
   return 1;
}/*
for(int k=0;k<w.size();k++)
{ if(w[k] == i)
{
    dp[i][j] =1;
    dp[i][(j+1)%2] =1;
return -1;
}
}
int x = -2;
for(int k=0;k<w.size();k++)
{
if(i>=w[k])
{
x = max(rec(i-w[k],(j+1)%2,dp,w),x);
dp[i][j] = x;
dp[i][(j+1)%2]=x;
}
}
//cout<<"i:"<<i<<" j: "<<j<<"teble:"<<dp[i][j]<<endl;
return -1*dp[i][j];
*/
for (int k = 0; k < w.size(); k++) {
        if (i >= w[k]) {
            if (rec(i - w[k], (j + 1) % 2, dp, w) == -1) {  // If next player loses
                return dp[i][j] = 1;  // Current player wins
            }
        }
    }

    return dp[i][j] = -1;  // If all moves lead to the current player losing
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    vector<vector<int>> dp;
vector<int> w;
   
    cin>>n>>k;
     dp.resize(k+1);
    for(int i=0;i<k+1;i++)
    dp[i].resize(2);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        w.push_back(x);
    }
    //cout<<"k is : "<<k;
    sort(w.begin(),w.end());
    rec(k,0,dp,w);
    //cout<<"k is : "<<k;
    if( dp[k][0]== -1)
    cout<<"Second"<<endl;
    else if(dp[k][0]== +1)
    cout<<"First"<<endl;
    else
    cout<<"ZERO ERROR"<<endl;
   /* */
    return 0 ;
} //debug segmentation fault
/*
#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>>& dp, vector<int>& w) {
    if (i == 0) return dp[i][j] = -1;  // Base case: no stones left means the current player loses

    if (dp[i][j] != 0) return dp[i][j];  // Return precomputed result

    for (int k = 0; k < w.size(); k++) {
        if (i >= w[k]) {
            if (rec(i - w[k], (j + 1) % 2, dp, w) == -1) {  // If next player loses
                return dp[i][j] = 1;  // Current player wins
            }
        }
    }

    return dp[i][j] = -1;  // If all moves lead to the current player losing
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<vector<int>> dp(k + 1, vector<int>(2, 0));  // DP table

    int result = rec(k, 0, dp, w);

    if (result == -1)
        cout << "Second" << endl;
    else if (result == 1)
        cout << "First" << endl;
    else
        cout << "ZERO ERROR" << endl;

    return 0;
}





*/
