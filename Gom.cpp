//////////////////////KMP
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
string d,b;
    cin>>d;
    cin>>b;
    int n=(int)d.size();
    int m=(int)b.size();
    kmppre(b,m);
    kmp(d,b,n,m);
    cout<<cnt;
////////////////end_KMP
// Manacher (Longest Palindromic String) - O(n)
int lps[2*M+5];
int manacher(string &s,int &n) {
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
int n; cin>>n; string s; cin>>s;
cout<<manacher(s,n);
///////end_manacher
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
string s;cin>>s;lyndon(s);
////end_lyndon
////manacher_select
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
vector<int>temp=manacher_odd("abacd");
  for(auto it:temp) cout<<it<<" ";
////end_manacher_select;
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
cout<<minmove(s);
////end_minimal_string_rotation;
//for trie
const ll N = 250000+5;
int trie[N][26], trien = 0; //*trien* dai dien cho so node cua cay
int finish_u[N],fs[N];
//them mot ki tu vao cay
int add(int u, char c){
  c-='a';
  if (trie[u][c]) return trie[u][c];
  return trie[u][c] = ++trien; //ki tu c chua xuat hien thi tang them mot node
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin>>n;for(int i=0;i<n;++i){
      string s;cin>>s;int u = 0;
    //them 1 string vao trie
    for(char c : s){
       u=add(u, c);
    }
    finish_u[u]=1;
    }
    for(int i=trien;i>=0;i--){
      for(int j=0;j<26;++j)
        if(trie[i][j]) fs[i]=max(fs[i],fs[trie[i][j]]);
      fs[i]+=finish_u[i];
    }
    cout<<fs[0];
    return 0;
}
///end_trie;