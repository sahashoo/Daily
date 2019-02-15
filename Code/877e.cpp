///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define bugbug(i) cout<< " ------ " << i << endl ;
using namespace std;
void null(){return ;}
const int maxn=2e5+7;
int sgmnt[maxn*4],cnt[maxn],bgn[maxn],n;
bool lzy[maxn*4],cnd[maxn];
vector<int>g[maxn];

int ord;
void dfs(int v){
	bgn[v]=ord++;
	for(auto u:g[v])
		dfs(u),cnt[v]+=cnt[u];
	cnt[v]++;
}

inline void input(){
	cin>>n;
	for(int i=1,p;i<n;i++)
		cin>>p,g[--p].push_back(i);
	dfs(0);
	for(int i=0;i<n;i++)
		cin>>cnd[bgn[i]];
}

void build(int v=1,int l=0,int r=n){
	if(r-l==1)return sgmnt[v]=cnd[l],null();
	int mid=(l+r)/2;
	build(v*2,l,mid);
	build(v*2+1,mid,r);
	sgmnt[v]=sgmnt[v*2]+sgmnt[v*2+1];
}

inline void SendToChild(int v,int l,int r){
	if(lzy[v]==0)return ;
	int mid=(l+r)/2;
	lzy[v]^=1,lzy[v*2+1]^=1,lzy[v*2]^=1;
	sgmnt[v*2]=mid-l-sgmnt[v*2];
	sgmnt[v*2+1]=r-mid-sgmnt[v*2+1];
}

void update(int L,int R,int v=1,int l=0,int r=n){
	if(r<=L||l>=R)return ;
	if(L<=l&&R>=r)
		return lzy[v]^=1,sgmnt[v]=r-l-sgmnt[v],null();
	int mid=(l+r)/2;
	SendToChild(v,l,r);
	update(L,R,v*2,l,mid);
	update(L,R,v*2+1,mid,r);
	sgmnt[v]=sgmnt[v*2]+sgmnt[v*2+1];
}

int count(int L,int R,int v=1,int l=0,int r=n){
	// bugbug(v);
	if(r<=L||l>=R)return 0;
	if(L<=l&&R>=r)return sgmnt[v];
	int mid=(l+r)/2;
	SendToChild(v,l,r);
	return count(L,R,v*2,l,mid)+
		   count(L,R,v*2+1,mid,r);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	input();
	build();
	int q,v;cin>>q;
	string t;
	while(q--){
		cin>>t>>v;v--;
		if(t=="pow")update(bgn[v],bgn[v]+cnt[v]);//,cout<<"*";
		else cout<<count(bgn[v],bgn[v]+cnt[v])<<"\n";
		// cout<<" "<<bgn[v]<<" "<<bgn[v]+cnt[v]-1<<endl;
	}
}
