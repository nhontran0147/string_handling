#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = -1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
const ll M = 1000000007;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);	
	#endif
	vector<int>temp=manacher_odd("abacd");
	for(auto it:temp) cout<<it<<" ";
    return 0;
}