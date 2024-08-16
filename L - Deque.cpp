//corrected file AC
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MOD 1000000000+7
int x =0;
int y=0;
int n=0;
vector<int> v;
vector<vector<int>> ready;
vector<vector<int>> dp;
int rec(int front,int back)
{
    int turn =(n-(front -back +1))%2;

if(ready[front][back]!=0)
return dp[front][back];
//cout<<"Value under consideration "<<front<<" "<<back<<"turn "<<turn<<endl;//
if(front == back)
{
ready[front][back] = 1;
dp[front][back] = turn*-1*v[front] +(turn*-1+1)*v[front];
}
else
{
    if(turn==1)
    {
     dp[front][back] = min(rec(front,back-1)-v[back],rec(front+1,back)-v[front]);
     
    }
    else
    dp[front][back] = max(rec(front,back-1)+v[back],rec(front+1,back)+v[front]);
   ready[front][back] =1;
   
}
 //cout<<"calculated value : "<<dp[front][back]<<endl;//
 return dp[front][back];

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
ready.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        dp[i].resize(n);
        ready[i].resize(n);
    }

int ans =rec(0,n-1);
cout<<ans<<endl;
return 0;
}
