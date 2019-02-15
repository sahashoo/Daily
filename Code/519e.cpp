///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7,MAXLog=20;
int n,m,par[maxn][20],h[maxn],cnt[maxn];
vector<int>g[maxn],ans;
bool mrk[maxn];

void Input(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>m;
}

void DFS(int v){
	cnt[v]=1;
	for(int i=0;i<g[v].size();i++){
		int u=g[v][i];
		if(par[v][0]!=u){
			par[u][0]=v;
			h[u]=h[v]+1;
			DFS(u);
			cnt[v]+=cnt[u];
		}
	}
}

void Preprocess(){
	DFS(1);
	for(int j=1;j<MAXLog;j++)
		for(int i=1;i<=n;i++)
			par[i][j]=par[par[i][j-1]][j-1];
}

int GoUp(int v,int dist){
	for(int i=MAXLog-1;i>=0;i--)if(dist>=(1<<i))v=par[v][i],dist-=(1<<i);
	return v;
}

int LCA(int u,int v){
    if(h[v]>h[u])swap(u,v);
    u=GoUp(u,h[u]-h[v]);
    for(int i=MAXLog-1;i>=0;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
    //for(int i=MAXLog-1;i>=0;i--)if(h[u]-(1<<i)>=h[v])u=par[u][i];
	if(u==v)return v;
	//for(int i=MAXLog-1;i>=0;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
    return par[v][0];
}

int32_t main(){
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Input();
	Preprocess();
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		int lca=LCA(a,b),dist=h[a]+h[b]-(2*h[lca]);
		if(dist==0)ans.push_back(n);
		else if(dist%2)ans.push_back(0);
		else if(h[a]-h[lca]==dist/2){
			a=GoUp(a,dist/2-1),b=GoUp(b,dist/2-1);
			ans.push_back(n-cnt[a]-cnt[b]);
		} 
		else if(h[a]-h[lca]>dist/2){
			a=GoUp(a,dist/2-1);
			ans.push_back(cnt[par[a][0]]-cnt[a]);
		} 
		else{
			b=GoUp(b,dist/2-1);
			ans.push_back(cnt[par[b][0]]-cnt[b]);
		}
	}
	for(auto x:ans)cout<<x<<endl;
}
