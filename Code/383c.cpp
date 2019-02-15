#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7;
int n,m,sgmnt[maxn*5],bgn[maxn],cls[maxn],a[maxn],t;
bool mrk[maxn],h[maxn];
vector<int>g[maxn];

void dfs(int v){
	mrk[v]=true;bgn[v]=t++;
	for(auto u:g[v]){
		if(mrk[u]==false){
			h[u]=1-h[v];
			dfs(u);
		}
	}
	cls[v]=t;
}

void update(int L,int R,int val,int v=1,int l=0,int r=n){
	if(r-l<=1||(L<=l&&R>=r)){sgmnt[v]+=val;return ;}
	int mid=l+r>>1;
	if(R<=mid){
		update(L,R,val,v*2,l,mid);
		return ;
	}
	if(L>=mid){
		update(L,R,val,v*2+1,mid,r);
		return ;
	}
	update(L,R,val,v*2,l,mid);
	update(L,R,val,v*2+1,mid,r);
	return ;
}

int act(int id,int v=1,int l=0,int r=n){
	if(r-l<=1)return sgmnt[v];
	int mid=l+r>>1;
	if(id<mid)return act(id,v*2,l,mid)+sgmnt[v];
	else return act(id,v*2+1,mid,r)+sgmnt[v];
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++){
		int u,v;cin>>u>>v;u--;v--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
	while(m--){
		int typ,x;cin>>typ>>x;x--;
		if(typ==1){
			int val;cin>>val;
			update(bgn[x],cls[x],(h[x]?val:-val));
		}
		else cout<<a[x]+(act(bgn[x])*(h[x]?1:-1))<<'\n';
	}
}