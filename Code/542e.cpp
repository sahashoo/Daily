///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
// #define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int INF=3e10+9237;
const int maxn=1e3+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
vector<int>g[maxn];

bool chk[maxn],col[maxn];
bool check(int v,bool c){
	col[v]=c;
	chk[v]=true;
	for(auto u:g[v]){
		if(chk[u]==true&&col[u]==col[v])return true;
		if(chk[u]==false&&check(u,1-c))return true;
	}
	return false;
}

queue<int>scc;
int num_scc=-1;
bool seen[maxn];
void findscc(int v){
	scc.push(v);
	seen[v]=true;
	for(auto u:g[v])
		if(!seen[u])findscc(u);
}

int dim=0,h[maxn];
void bfs(int v){
	fill(h,h+maxn,INF);
	queue<int>Q;Q.push(v);
	h[v]=0;
	while(Q.size()){
		int v=Q.front();Q.pop();
		dim=max(dim,h[v]);
		for(auto u:g[v]){
			if(h[u]!=INF)continue;
			h[u]=h[v]+1;
			Q.push(u);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,res=0;cin>>n>>m;
	for(int i=0,u,v;i<m;i++)cin>>u>>v,g[u].pb(v),g[v].pb(u);
	for(int i=1;i<=n;i++){
		if(seen[i]==false){
			if(check(i,0))return cout<<-1,0;
			num_scc=i;
			findscc(i);
			while(scc.size())bfs(scc.front()),scc.pop();
			res+=dim;dim=0;
		}
	}
	cout<<res;
}
