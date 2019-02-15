#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7,LG=20;
int n,m,ancestor[maxn][LG],Parent[maxn],h[maxn];
vector<int>child[maxn];
bool DFSMrk[maxn];
 
void Input(){
	cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>par[i];
        g[par[i]].push_back(i);
    }
}

void precompLCA(int v,int p){
	for(auto u:g[v]){
		if(u==p)continue;
		d[u]=h[u]=h[v]+1;
		anc[u][0]=v;
		for(int i=1;i<LG;i++)
			anc[u][i]=anc[anc[u][i-1]][i-1];
		precompLCA(u,v);
	}
}

int LCA(int v,int u){
	if(h[u]>h[v])swap(u,v);
	int depth=h[v]-h[u];
	for(int i=0;i<lgN;i++)
		if(depth&(1<<i))v=anc[v][i];
	if(v==u)return v;
	for(int i=lgN-1;i>=0;i--)
		if(anc[u][i]!=anc[v][i])
			u=anc[u][i],v=anc[v][i];
	return anc[v][0];
}

// void makesamelevel(int v,int depth){
	// for(int i=0;i<LG;i++)
		// if(depth&(1<<i))v=anc[v][i];
// }

// int LCA(int v,int u){
	// if(h[u]>h[v])swap(u,v);
	// int depth=h[v]-h[u];
	// makesamelevel(v,depth);
	// if(v==u)return v;
	// for(int i=LG-1;i>=0;i--)
		// if(anc[u][i]!=anc[v][i])
			// u=anc[u][i],v=anc[v][i];
	// return anc[v][0];
// }

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Input();
	Preprocess();
	int u,v;cin>>u>>v;
	cout<<LCA(u,v);
}
