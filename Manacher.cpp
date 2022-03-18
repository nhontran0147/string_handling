#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1000000007;
const ll N = 1000007;
const char DUMMY = '.';

int lps[2*N+5];
//tim ra chuoi palindrom dai nhat xuat hien trong xau S O(n)
int manacher(string s,int n) {
  //int n = strlen(s);
  string p (2*n+3, '#');
  p[0] = '^';
  for (int i = 0; i < n; i++) p[2*(i+1)] = s[i];
  p[2*n+2] = '$';

  int k = 0, r = 0, m = 0;
  int l = p.length();
  for (int i = 1; i < l; i++) {
    int o = 2*k - i;
    lps[i] = (r > i) ? min(r-i, lps[o]) : 0;
    while (p[i + 1 + lps[i]] == p[i - 1 - lps[i]]) lps[i]++;
    if (i + lps[i] > r) k = i, r = i + lps[i];
    m = max(m, lps[i]);
  }
  return m;
} 

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    cout<<manacher(s,(int)s.size()); //dau vao la xau s co do dai n;
    return 0;
}
