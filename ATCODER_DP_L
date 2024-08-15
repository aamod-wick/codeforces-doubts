#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MOD 1000000000+7
int x =0;
int y=0;
int n=0;
vector<int> v;
vector<vector<int>> dp;
int rec(int front,int back)
{
    int turn =(n-(front -back +1))%2;

if(dp[front][back]!=0)
return dp[front][back];

if(front == back)
dp[front][back] = turn*-1*v[front];
else if(back - front == 1)
{
   dp[front][back] = turn*-1*max(v[front],v[back]);
   turn = (turn+1)/2; 
   dp[front][back] = turn*-1*min(v[front],v[back]);
   return dp[]
}
if(front - back )

}
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;

v.resize(n);
dp.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        dp[i].resize(n);
    }
















    return 0;
}
