#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1000000007;
const int N = 1e6 + 5;
int b[N];
int cnt=0;

//thiết lập đánh dấu xâu b
void kmppre(string &p,int m) {
  b[0] = -1;
  for (int i = 0, j = -1; i < m; b[++i] = ++j)
    while (j >= 0 and p[i] != p[j])
      j = b[j];
}

//truy tìm vị trí xâu b xuất hiện xâu trong a
void kmp(string &s,string &p,int n,int m) {  
  for (int i = 0, j = 0; i < n;) {
    while (j >= 0 and s[i] != p[j]) j=b[j];
    i++, j++;
    if (j == m) {
      //vitri: match position i-j
    	//soluong: cout<<(i-j+1)<<" "; 
      //cnt++;
      j = b[j];
    }
  }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);	
	// #endif
    string d,b;
    cin>>d;
    cin>>b;
    int n=(int)d.size();
    int m=(int)b.size();
    kmppre(b,m);
    kmp(d,b,n,m);
    cout<<cnt;
    return 0;
}