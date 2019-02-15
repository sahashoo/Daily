///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
//#define int long long	
using namespace std;
const int maxn=1e6+7,INF=1e9+7;
int n,q,res[maxn],mn;
vector<int>g[maxn];
bool mrk[maxn];

void dfs(int v){
	mrk[v]=true;
	for(int i=0;i<g[v].size();i++){
		int u=g[v][i];
		if(mrk[u]==false){
			res[u]=min(u+1,res[v]);
			dfs(u);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n-1;i++){
		int v,u;cin>>u>>v;u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ti,z,lst=0;cin>>ti>>z;q--;
	int x=(z+lst)%n;
	res[x]=x+1;
	dfs(x);
	mn=INF;
	for(int i=0;i<q;i++){
		cin>>ti>>z;
		x=(z+lst)%n;
		if(ti==2){
			lst=min(mn,res[x]);
			cout<<lst<<endl;
		}
		else mn=min(res[x],mn);
	}
}
