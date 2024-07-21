#include<bits/stdc++.h>
// # edu dp contest  atcoder question 2 B FROG 2
using namespace std;
void dp(int pos,vector<int> &cost,vector<int>&height,int k)
    {
        if(pos==0)
        {cost[pos] = 0;
           // cout<<"pos"<<pos<< ":"<<cost[pos]   ;         
        return;}
        else
        {
            int minimum = INT_MAX;
            for(int i =1;i<=k && pos-i>=0;i++ ){

            //cout<<height[pos] -height[pos-k]<<endl;
            minimum = min(abs(height[pos]-height[pos-i])+cost[pos-i],minimum);
            }
            cost[pos] =minimum;
            //cout<<"pos"<<pos<< ":"<<cost[pos]    ;        
            return ;

        }
 
    }
int main()
    {
        #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
int n,k;
vector<int> height,cost;
cin>>n>>k;
height.resize(n),cost.resize(n);
for(int i=0;i<n;i++)
{
    cin>>height[i];
}
for(int pos =0;pos<n;pos++)
{
    dp(pos,cost,height,k);
}
cout<<cost[n-1]<<endl;
    }
