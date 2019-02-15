#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=1e5+7;
unordered_map<int,int>par[MAXN],ans[MAXN];

int root(int a,int c){
	int temp=par[a][c];
	return temp>0?par[a][c]=root(temp,c):a;
}

int32_t main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		a=root(a,c),b=root(b,c);
		if(a==b)continue;
		if(par[a][c]>par[b][c])swap(a,b);
		par[a][c]+=par[b][c]-1;
		par[b][c]=a;
	}
	int q;cin>>q;
	while(q--){
		int a,b,res=0;cin>>a>>b;
		if(par[a].size()>par[b].size())swap(a,b);
		if(ans[a].find(b)==ans[a].end()){
			for(auto x:par[a])
				if(par[b].find(x.F)!=par[b].end()
				  &&root(b,x.F)==root(a,x.F))
					res++;
			ans[a][b]=res;
		}
		cout<<ans[a][b]<<'\n';
	}
}