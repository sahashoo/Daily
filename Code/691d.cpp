//age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,m,arr[maxn],ans[maxn],ind[maxn];
bool mrk[maxn];
vector<int>a,b,g[maxn];

void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		//ind[arr[i]]=i;
	}
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void dfs(int v){
	mrk[v]=true;
	a.push_back(v);b.push_back(arr[v]);
	for(auto u:g[v]){
		if(mrk[u]==false){
			dfs(u);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	for(int i=1;i<=n;i++){
		if(mrk[i]==false){
			a.clear();b.clear();
			dfs(i);
			sort(a.begin(),a.end(),greater<int>());
			sort(b.begin(),b.end());
			for(int i=0;i<a.size();i++)arr[a[i]]=b[i];
		}
	}
	for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
}
