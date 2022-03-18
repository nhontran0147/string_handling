#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1000000007;
// Tính vị trí của xâu xoay vòng có thứ tự từ điển nhỏ nhất của xâu s[]
int minmove(string s) {
	int n = (int)s.length();
	int x, y, i, j, u, v; // x là vị trí chuỗi nhỏ nhất trước chuỗi y.
	for (x = 0, y = 1; y < n; ++ y) {
		i = u = x;
		j = v = y;
		while (s[i] == s[j]) {
			++ u; ++ v;
			if (++ i == n) i = 0;
			if (++ j == n) j = 0;
			if (i == x) break; // tất cả kí tự đều bằng nhau
		}
		if (s[i] <= s[j]) y = v;
		else {
			x = y;
			if (u > y) y = u;
		}
	}
	return x;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);	
	// #endif
	string s;
	cin>>s;
	cout<<minmove(s);
    return 0;
}