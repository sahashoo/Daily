#include<bits/stdc++.h>
#define ll long long
struct edge{int u,w,ind;edge(int u=0,int w=0,int ind=0):u(u),w(w),ind(ind){}};
using namespace std;
const int maxn=3e5+1;
int n,m,s;ll dist[maxn],wt;
bool mrk[maxn];
vector<edge>g[maxn];
vector<int>res;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[v].push_back(edge(u,w,i));
		g[u].push_back(edge(v,w,i));
	}
	cin>>s;
	fill(dist,dist+n+1,1e18+7);dist[s]=0;
	priority_queue<pair<ll,int> >Q;Q.push(pair<ll,int>(-dist[s],s));
	while(Q.empty()==false){
		int v=Q.top().second;ll d=-Q.top().first;Q.pop();
		if(d!=dist[v])continue;
		for(int i=0;i<g[v].size();i++){
			int u=g[v][i].u;
			ll add=g[v][i].w;
			if(d+add<dist[u]){
				dist[u]=d+add;
				Q.push(pair<ll,int>(-dist[u],u));
			}
		}
	}
	for(int i=1;i<=n;i++){
		ll w=1e18+7;int ind=-1;
		for(int j=0;j<g[i].size();j++){
			int u=g[i][j].u;ll add=g[i][j].w;
			if(dist[i]-add==dist[u]&&add<w){
				w=add;
				ind=g[i][j].ind;
			}
		}
		if(ind!=-1){wt+=w;res.push_back(ind);}
	}
	cout<<wt<<endl;
	for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
}