///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7;
int dist[maxn],s,t,n,m,k;
bool mrk[maxn];
vector<int> g[maxn];

bool BFS(int x){
	memset(dist,-1,sizeof(dist));
	queue<int>Q;Q.push(s);
	dist[s]=0;
	while(Q.size()){
		int v=Q.front();Q.pop();
		if(mrk[v])dist[v]=0;
		if(dist[v]>x)continue;
		for(auto u:g[v]){
			if(dist[u]==-1||dist[u]>dist[v]+1){
				if(dist[v]+1>x)continue;
				dist[u]=dist[v]+1;
				Q.push(u);
			}
		}
	}
	return(dist[t]!=-1);
}

int BS(int l,int r){
	if(r-l<=1)return(BFS(l)?l:r);
	int mid=(l+r)/2;
	if(BFS(mid))return BS(l,mid);
	return BS(mid,r);
}

void input(){
	cin>>n>>m>>k;
	for(int i=0;i<k;i++){
		int a;cin>>a;
		mrk[a]=true;
	}
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>s>>t;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	if(BFS(n)==false)return cout<<-1,0;
	cout<<BS(1,n);
}