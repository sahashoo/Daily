#include<bits/stdc++.h>
using namespace std;
int n,sum,v1,v2,t[1000007];
vector<int> g[1000007];

void dfs(int v){
	for(int u: g[v])dfs(u),t[v]+=t[u];
    if(t[v]==sum/3&&v!=g[0][0]){
        if(!v1)v1=v,t[v]=0;
        else if(!v2)v2=v,t[v]=0;
    }
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
		int p;
		cin>>p>>t[i];
		sum+=t[i];
        g[p].push_back(i);
    }
    if(sum%3)return cout<<-1,0;
    dfs(g[0][0]);
    if(v1&&v2)cout<<v1<<" "<<v2;
    else cout<<-1;
}