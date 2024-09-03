#include <bits/stdc++.h>
//#define int long long file works for small input and on local but  not for long input on cf judge 
using namespace std;
/*int gcd(int a ,int b,int c,int d )
{
   if(a>b)
   swap(a,b);
   if(a==b)
   return b;
   if(a==0)
    return b;
   if(a==1||b==1)
   return 1;
   
 return gcd(a-b,b);
}
*/
signed main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int t;
cin>>t;
while(t--)
{
   set<int> k;
   int n,a,b ;
   vector<int> v;
   cin>>n>>a>>b;
   int x,temp =gcd(a,b);
   //cout<<"gcd for "<<a<<" " <<b<<" ="<<temp<<endl;
   for(int i=0;i<n;i++)
   {
    cin>>x;
    x%=temp;
    v.push_back(x);
   }
    sort(v.begin(),v.end());
    x = INT_MAX;
    for(int i=0;i<n;i++ )
    {
        if(i==0)
        x = min(x,v[n-1]-v[0]);
        x = min(x,v[i-1]+temp-v[i]);
    }
    cout<<x<<endl;
}

}
