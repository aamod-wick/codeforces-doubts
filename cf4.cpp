#include <bits/stdc++.h>

using namespace std;
long long check(long long sum,long long i,long long j,long long m)
{
if(i*j<=m)
return max(i*j,sum);
else
return max(sum,m - (m%i));

}
long long closest(long long i,long long j, long long k,long long m)
{
  if((i*j + (i+1)*k)<=m)
  {
     return i*j + (i+1)*k;
  }
  long long x= m%i,y = m-i*j;
  if(y>((i+1)*x))
 

}
*
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t=0;
cin>>t;
while(t--)
{
  long long n,m;
  cin>>n>>m;
map<long long,long long> map;
vector<long long> a;
a.resize(n);
for(int i=0;i<n;i++)
{
    cin>>a[i];
    map[a[i]]++;
}
long long sum =0, x =0;
int money_not_enough =0;
sort(a.begin(),a.end());
auto it =map.begin();
it++;
auto temp =map.begin();

sum = check(sum,temp->first,temp->second,m);

for(;it!=map.end();it++)
{
    if(it->first-temp->first>1)
    {
        sum = check(sum,it->first,it->second,m);
        sum = check(sum,temp->first,temp->second,m);
    }
       
    else
    {
        if(((it->first*it->second)+(temp->first*temp->second))<=m)
        {
            sum = max(sum,(it->first*it->second+temp->first*temp->second));
           
        }
        else
        {
          if(m%temp->first)
            sum = max(sum,m - (m%temp->first)+min(it->second,(m%temp->first)));
            //cout<<"collective :"<<sum<<endl;
        }
    }
    temp++;
}
//sum = check(sum,temp->first,temp->second,m);
cout<<max(sum,m)<<endl;
}
    return 0;
}