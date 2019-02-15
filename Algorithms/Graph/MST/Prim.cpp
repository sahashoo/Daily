#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N=1e5+7;
const int INF=1e9+7;
int n,m,dist[N],par[N];
bool mrk[N];
vector<pair<int,int> >g[N],res;
//map<pair<int,int>,int>e;

void input(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[v].push_back({u,w});
		g[u].push_back({v,w});
	//	e[{u,v}]=w;
	//	e[{v,u}]=w;
	}
}

void prim(){
	memset(dist,INF,sizeof(dist));
	memset(par,-1,sizeof(par));
	dist[1]=0;
	set<pair<int,int> >e;
	e.insert({0,1});
	for(int i=0;i<n;i++){
		if(e.empty())return ;
		pair<int,int>vv=*e.begin();
		int v=vv.S;
		e.erase(e.begin());
		if(par[v]!=-1)res.push_back({par[v],v});
		for(auto tmp:g[v]){
			int u=tmp.F,w=tmp.S;
			if(w<dist[u]){
				e.erase({dist[u],u});
				dist[u]=w;par[u]=v;
				e.insert({dist[u],u});
			}
 		}
	}
}
 
int32_t main(){	
	input();
	prim();
	for(auto u:res)cout<<u.F<<" "<<u.S<<'\n';
}
