#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1000000007;


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

    int n;	
    cin>>n;

    for(int i=0;i<n;++i){
    	string s;
    	cin>>s;
    	int u = 0;
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