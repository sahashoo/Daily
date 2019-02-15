///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+7;
int a[MAXN],c[MAXN],st[MAXN],fn[MAXN],n;
long long seg[MAXN*4],lzy[MAXN*4];
vector<int>g[MAXN];

inline void shift(int v,int l,int r){
	if(lzy[v]==0)return ;
	seg[v]=(1ll<<lzy[v]);
	if(r-l>1)
		lzy[v*2]=lzy[v*2+1]=lzy[v];
	lzy[v]=0;
}

void update(int x,int y,int col,int v=1,int l=0,int r=n){
	shift(v,l,r);
	if(y<=l||r<=x)return ;
	if(x<=l&&y>=r){
		lzy[v]=col;
		return shift(v,l,r);
	}
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	update(x,y,col,lc,l,mid);
	update(x,y,col,rc,mid,r);
	seg[v]=seg[rc]|seg[lc];
}

long long get(int x,int y,int v=1,int l=0,int r=n){
	shift(v,l,r);
	if(y<=l||r<=x)return 0;
	if(x<=l&&y>=r)return seg[v];
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	return get(x,y,lc,l,mid)|get(x,y,rc,mid,r);		
}

int ord=0;
void dfs(int v,int p){
	st[v]=ord++;
	for(auto u:g[v])
		if(u!=p)dfs(u,v);
	fn[v]=ord;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int m,t,v,x;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++)
		update(st[i],st[i]+1,c[i]);
	while(m--){
		cin>>t>>v;
		if(t==1)cin>>x,update(st[v],fn[v],x);
		else 
			cout<<__builtin_popcountll(get(st[v],fn[v]))<<'\n';
	}
}
