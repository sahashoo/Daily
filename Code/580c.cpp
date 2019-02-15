#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll m,n,cat[100005];
bool visited[100005];
vector<ll>adj[100005];

void input(){
	cin>>n>>m;
    for(ll i=1;i<=n;i++)	cin>>cat[i];
    for(ll i=1;i<n;i++){
		ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int dfs(int x,int s){
    if(cat[x]) s++;
    else s=0;
    if(s>m||visited[x])	return 0;
    visited[x]=1;
    ll ans=0;
    if(adj[x].size()==1&&x>1)	return 1;
    for(ll i=0;i<adj[x].size();i++)	ans+=dfs(adj[x][i],s);
    return ans;
}
int main(){
	input();
    cout<<dfs(1,0)<<endl;
}