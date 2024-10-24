#include <bits/stdc++.h>
//#define int long long
using namespace std;
int mod = 1000000007;
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t ;
    cin >> t;  // Number of test cases
    while (t--) {
        int n,m,k;
        cin >> n>>m>>k;

        // Map to store the frequency of each bitmask
        deque<int>l;
        string s1 ,s="L";
        cin>>s1;
        s+=s1;
        int flag =0;
        for(int i=1;i<n+1;i++)
        {
            if(s[i]=='L')
            l.push_back(i);
        }
        int last = 0;
        for(int last=0;last<n+1;)
        {
            if(l.empty())
            {
                if(last+m+k<n+1)
                {
                    flag=-1;
                    break;
                }
                while(last<n+1 ||k>0 )
                {
                    last++;
                    k--;
                    if(s[last]=='C')
                    {flag=-1;
                    break;}
                    
                } 
                if(last<n+1)
                {flag=-1;
                break;}
            }

            else if(l.front()<=last+m)
            {
                last = l.front();
            }
            else if(l.front()>=last+m)
            {
                last +=m;
                while(s[last]!='L' ||k>0 )
                {
                    last++;
                    k--;
                    if(s[last]=='C')
                    {flag=-1;
                    break;}
                    
                } 
                if(s[last]!='L')
                {flag=-1;
                break;}
            }
            
        }
        if(flag==-1)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
        }
    

    return 0;
}
