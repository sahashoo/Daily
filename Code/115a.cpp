#include<bits/stdc++.h>
using namespace std;
int n,ans,par[3000],len;

void input(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>par[i];
}
int dfs(int v){
	len++;
	if(par[v]!=-1)	dfs(par[v]);
	else return len;
}
int main(){
	input();
	for(int i=1;i<=n;i++){
		len=0;
		if(par[i]!=-1)	ans=max(ans,dfs(i));
	}
	if(!ans){cout<<1;return 0;}
	cout<<ans;
}