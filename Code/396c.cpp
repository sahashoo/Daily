#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=3e5+10;
const int MAX=4*MAXN;
const int mod=1e9+7;
int n,bgn[MAXN],sz[MAXN],h[MAXN];
vector<int>g[MAXN];

int ord;
void pre_dfs(int v,int p){
	bgn[v]=ord++;
	sz[v]=1;
	for(int u:g[v]){
		h[u]=h[v]+1;
		pre_dfs(u,v);
		sz[v]+=sz[u];
	}
}

void add(int &a,int b){
    b=(b+mod)%mod;
    a=(a+b)%mod;
}

struct segment{
	int seg[MAX],lzy[MAX];
	
    inline void shift(int x,int v,int l,int r){
		add(lzy[v],x);
		if(l+1==r)add(seg[v],x);
    }
    void relax(int v,int l,int r){
		int mid=(l+r)/2,lc=v*2,rc=lc+1;
		if(l+1==r)return;
		if(lzy[v]==0)return;
		shift(lzy[v],lc,l,mid);
		shift(lzy[v],rc,mid,r);
		lzy[v]=0;
    }

    void update(int L,int R,int x,int v=1,int l=0,int r=n){
		relax(v,l,r);
		if(L>=r||R<=l)return;
		if(L<=l&&R>=r){
			shift(x,v,l,r);
			return;
		}
		int mid=(l+r)/2,lc=v*2,rc=v*2+1;
		update(L,R,x,lc,l,mid);
		update(L,R,x,rc,mid,r);
    }

    int get(int pos,int v=1,int l=0,int r=n){
		relax(v,l,r);
		if(r-l<=1)return seg[v];
		int mid=(l+r)/2,lc=v*2,rc=v*2+1;
		if(pos<mid)
			return get(pos,lc,l,mid);
		else
			return get(pos,rc,mid,r);
    }
}a,b;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
	for(int i=2;i<=n;i++){
		int p;cin>>p;
		g[p].push_back(i);
	}
	pre_dfs(1,-1);
	int q;cin>>q;
	while(q--){
	    int type;cin>>type;
	    if(type==1){
		    int v,x,k;cin>>v>>x>>k;
			a.update(bgn[v],bgn[v]+sz[v],(x+h[v]*k)%mod);
			b.update(bgn[v],bgn[v]+sz[v],k);
		}
	    if(type==2){
		    int v;cin>>v;
		    int ans=(a.get(bgn[v])-b.get(bgn[v])*h[v]%mod+mod)%mod;
			cout<<ans<<'\n';
		}
	}
}