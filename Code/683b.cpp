#include<bits/stdc++.h>
using namespace std;
int n,vis[150]; 
char g[150];
string s;

void dfs(char u){
	vis[u]=3;
	if(vis[g[u]]!=3&&g[u])dfs(g[u]);
	s=s+u;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		string d;
		cin>>d;
		for(int i=1;i<d.size();i++)vis[d[i]]=2,g[d[i-1]]=d[i];
		if(vis[d[0]]!=2)vis[d[0]]=1;
	}
	for(int i='a';i<='z';i++)if(vis[i]==1)dfs(i);
	reverse(s.begin(),s.end());
	cout<<s;
}