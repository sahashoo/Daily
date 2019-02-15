#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int MAXN=1e5+7;
int ans,n,cnt;
bool mrk[MAXN];
vector<int>g[MAXN];

void dfs(int v){
	mrk[v]=true;
	cnt++;
	for(int u:g[v])
		if(mrk[u]==false)dfs(u);
}

inline bool lucky(int x){
	while(x){
		int temp=x%10;
		if(temp!=4&&temp!=7)return false;
		x/=10;
	}
	return true;
}

int32_t main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		if(lucky(w)==false){
			g[v].push_back(u);
			g[u].push_back(v);
		}
	}
	for(int i=1;i<=n;i++)
		if(mrk[i]==false){
			cnt=0;
			dfs(i);
			ans+=cnt*(n-cnt)*(n-cnt-1);
		}
	cout<<ans<<endl;
}