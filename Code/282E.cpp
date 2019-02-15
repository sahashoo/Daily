///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
struct node{
	int c[2];
}NUL;
vector<node>trie;
int a[MAXN];

inline void add(int x){
	vector<bool>bin;
	while(x)bin.push_back(x%2),x/=2;
	while(bin.size()<42)bin.push_back(0);
	int cur=0;
	while(bin.size()){
		bool a=bin.back();bin.pop_back();
		if(trie[cur].c[a]==-1)
			trie.push_back(NUL),
			trie[cur].c[a]=trie.size()-1;
		cur=trie[cur].c[a];
	}
	trie[cur].is=true;
}

inline int query(int x){
	vector<bool>bin;
	while(x)bin.push_back(x%2),x/=2;
	while(bin.size()<42)bin.push_back(0);
	int cur=0,ret=0;
	while(bin.size()){
		if(trie[cur].c[1-bin.back()]!=-1)
			cur=trie[cur].c[1-bin.back()],ret=2*ret+1;
		else cur=trie[cur].c[bin.back()],ret*=2;
		bin.pop_back();
	}
	return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	NUL.c[0]=NUL.c[1]=-1;
	trie.push_back(NUL);
	int n;cin>>n;
	int tmp=0,mx=0,tot=0;
	for(int i=0;i<n;i++)cin>>a[i],tot^=a[i];
	add(0);
	for(int i=0;i<n;i++){
		tmp^=a[i];
		add(tmp);
		mx=max(mx,query(tmp^tot));
	}
	cout<<mx;
}
