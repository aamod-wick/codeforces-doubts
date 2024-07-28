#include <bits/stdc++.h>
#include <string>

using namespace std;

const int base1 = 5317;
const int base2 = 2391;
const int mod = 1e9 + 7;

// Only contains "good" letters
set<char> letters;
set<pair<long long,long long>>distinct;
long long pow(int n, int k) {
    long long temp = 1;
    for (int i = 0; i < k; i++) {
        temp = (temp * n) % mod;
    }
    return temp;
}

int goo(int start, const string &s, int k) {
    int ans = 0;
    int count = 0;
     long long hash1 = 0,hash2 =0;

    for (int i = start; i < s.length(); i++) {
        if (letters.find(s[i]) == letters.end()) {
            count++;
        }
        if (count > k) {
            return ans;
        }
        
         hash1 = (hash1 * base1 + s[i] - 'a' + 1) % mod;
        hash2 = (hash2 * base2 + s[i] - 'a' + 1) % mod;
        pair<long long,long long> p;
        p.first =hash1;
        p.second = hash2;
        distinct.insert(p);
        ans++;
    }

    return ans;
}

pair<int, string> check(int len, const string &s) {
    set<long long> a;
    set<long,long>b;
    string x;
    x.resize(len);
    long long hash1 = 0,hash2 =0;

    for (int i = 0; i < len; i++) {
        hash1 = (hash1 * base1 + s[i] - 'a' + 1) % mod;
        hash2 = (hash2 * base2 + s[i] - 'a' + 1) % mod;
    }

    a.insert(hash1);
    long long power = pow(base1, len - 1);

    for (int i = len; i < s.length(); i++) {
        hash1 = (hash1 - (s[i - len] - 'a' + 1) * power % mod + mod) % mod;
        hash1 = (hash1 * base1 + s[i] - 'a' + 1) % mod;
        
        hash2 = (hash2 - (s[i - len] - 'a' + 1) * power % mod + mod) % mod;
        hash2 = (hash2 * base2 + s[i] - 'a' + 1) % mod;
        if (a.find(hash1) != a.end() ) {
            for (int j = 0; j < len; j++) {
                x[j] = s[i - len + 1 + j];
            }
            return {1, x};
        }
        a.insert(hash1);
    }

    return {-1, "random"};
}

string longestDupSubstring(const string &s) {
    int left = 1;
    int right = s.length()/3 +1;
    string ans;
    while (left <= right) {
        int mid = (left + right) / 2;
        pair<int, string> p = check(mid, s);
        if (p.first == -1) {
            right = mid - 1;
        } else {
            ans = p.second;
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    int k = 0;
    cin >> s;
    string g;
    cin >> g;
    cin >> k;

    for (int i = 0; i < 26; i++) {
        if (g[i] == '1') {
            letters.insert('a' + i);
        }
    }

    int ans = 0;

    for (int start = 0; start < s.length(); start++) {
        ans += goo(start, s, k);
    }

    cout <<distinct.size()<< endl;

    return 0;
}
