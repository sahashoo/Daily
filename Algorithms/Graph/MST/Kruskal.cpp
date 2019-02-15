#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
vector<pair<int,pair<int,int> > > g;
vector<pair<int,int> > tree;
int par[100000],ans,n,m;

void input(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int w,x,y;
		cin>>x>>y>>w;x--;y--;
		g.push_back({w,{x,y}});
	}
	for(int i=0;i<n;i++)par[i]=i;
	sort(g.begin(),g.end());
}

int find(int x){
	if(par[x]==x)return	x;
	return find(par[x]);
}

int merg(int x,int y){
	int u=find(y),v=find(x);
	par[u]=v;
}

void kruskal(){
	for(int i=0;i<g.size();i++){
		int u=find(g[i].S.F),v=find(g[i].S.F);
		if(u!=v){
			if(tree.size()){
				merg(g[i].S.S,tree[tree.size()-1].F);
				merg(g[i].S.F,tree[tree.size()-1].F);
			}
			tree.push_back({g[i].S.F,g[i].S.S));
			ans+=g[i].F;
		}
	}
}

int main(){
	input();
	kruskal();
	cout<<ans;
}
