#include<bits/stdc++.h>
using namespace std;
bool check(vector<long long> cow,long long distance,long long k)
{
    long long prev =cow[0];
    for(int i=0;i<cow.size() && k>0;i++)
    {
     if(cow[i] -prev>=distance)
        {
         k--;
         prev = cow[i];
        }

    }
    if(k>0)
    return false;
    return true;

    
}
int main()
{
int t;
cin>>t;
while(t--)
{
    vector<long long> cow;
    int n=0;
    int no_cows=0;
    cin>>n>>no_cows;
    //long long distance =0;
    for(int i=0;i<n;i++)
    {
        int x =0;
        cin>>x;
        cow.push_back(x);
    }
    long long mid =0,left =0,right =100001,ans =0;
    while(left<=right)
    {
       if(check(cow,mid,no_cows))
       {
        ans =mid;
        left =mid+1;
       }
       else
       {
        right =mid-1;
       }
    }
    cout<<ans<<endl;

}
return 0;
}