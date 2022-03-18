#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1000000007;
//tim cac xau lyndon (co thu tu tu` dien nho nhat);
void lyndon(string s) {
	int n = (int) s.length();
	int i = 0;
	while (i < n) {
		int j = i + 1, k = i;
		while (j < n && s[k] <= s[j]) {
			if (s[k] < s[j]) k = i;
			else ++k;
			++j;
		}
		while (i <= k) {
			cout << s.substr(i, j - k) << ' ';
			i += j - k;
		}
	}
	cout << endl;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	string s;
	cin>>s;
	lyndon(s);
    return 0;
}