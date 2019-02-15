#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+7,INF=1e9+7;
int n,a[maxn],mx=-INF,x,y,ans;
vector<int> g[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(a[i],mx);
	for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(a[i]==mx)x++;
        else if(a[i]==mx-1)y++;
    }
	ans=mx+2;
    for(int i=1;i<=n;i++){
		if(a[i]==mx)x--;
		else if(a[i]==mx-1)y--;
		for(int j=0;j<g[i].size();j++){
			int v=g[i][j];
			if(a[v]==mx)x--,y++;
			else if(a[v]==mx-1)y--;
        }
		if(x==0){
            ans=min(ans,mx+1);
            if(y==0)ans=min(ans,mx);
        }
        if(a[i]==mx)x++;
        else if(a[i]==mx-1)y++;
		for(int j=0;j<g[i].size();j++){
			int v=g[i][j];
			if(a[v]==mx)x++,y--;
			else if(a[v]==mx-1)y++;
        }
    }
	cout<<ans;
}