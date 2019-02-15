#include<bits/stdc++.h>
using namespace std;
const int Q=1e5+2,N=1e3+3;//,cnt=1e3+2;
int ans[Q],cnt,m,n,q[Q][3],par[Q];
bool slf[N][N];
vector<int>g[Q];

void dfs(int ind,int p){
	int x=q[ind][1],y=q[ind][2];
	bool did=false;
	if(q[ind][0]==1){
		if(slf[x][y]==false){
			cnt++;
			slf[x][y]=true;
			did=true;
		}
	}
	if(q[ind][0]==2){
		if(slf[x][y]==true){
			cnt--;
			slf[x][y]=false;
			did=true;
		}
	}
	if(q[ind][0]==3){
		for(int i=1;i<=m;i++){
			if(slf[x][i]==true)cnt--,slf[x][i]=false;
			else if(slf[x][i]==false)cnt++,slf[x][i]=true;
		}
	}
	ans[ind]=cnt;
	par[ind]=p;
	// output(ind);
	for(auto x:g[ind])if(p!=x)dfs(x,ind);
	if(did&&q[ind][0]==1){
		cnt--;
		slf[x][y]=false;
	}
	if(did&&q[ind][0]==2){
		cnt++;
		slf[x][y]=true;
	}
	if(q[ind][0]==3){
		for(int i=1;i<=m;i++){
			if(slf[x][i]==true)cnt--,slf[x][i]=false;
			else if(slf[x][i]==false)cnt++,slf[x][i]=true;
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int tq;cin>>n>>m>>tq;
	for(int i=1;i<=tq;i++){
		int t,x;cin>>t;
		if(t<=2){
			cin>>q[i][1]>>q[i][2];
			q[i][0]=t;
			g[i-1].push_back(i);
		}
		else if(t==3){
			cin>>q[i][1];//>>q[i][2];
			q[i][0]=t;
			g[i-1].push_back(i);
		}
		else{
			cin>>x;
			q[i][0]=t;
			g[x].push_back(i);
		}
	}
	dfs(0,-1);
	for(int i=1;i<=tq;i++)cout<<ans[i]<<'\n';
}
