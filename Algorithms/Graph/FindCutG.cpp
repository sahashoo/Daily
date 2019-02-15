//Finding Cut_Vertexs and Cut_Edegs in G=(V,E) 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int DpCutE[maxn],DpCutV[maxn],HCutV[maxn],HCutE[maxn];
bool MrkCutE[maxn],MrkCutV[maxn],IsCutE[maxn],IsCutV[maxn];
vector<pair<int,int> > g[maxn];

void CutV(int v,int par){
	DpCutV[v]=HCutV[v];
	MrkCutV[v]=true;
	int NumCutV=0;
	for(int i=0;i<g[v].size();i++){
		int u=g[v][i].first;
		if(MrkCutV[u]==false){
			HCutV[u]=HCutV[v]+1;
			CutV(u,v);
			DpCutV[v]=min(DpCutV[v],DpCutV[u]);
			NumCutV++;
		}
		else if(u!=par)DpCutV[v]=min(DpCutV[v],DpCutV[u]);
	}
	if(v==1&&NumCutV>1)IsCutV[v]=true;
}

void CutE(int v,int par,int ind){
	DpCutE[v]=HCutE[v];
	MrkCutE[v]=true;
	for(int i=0;i<g[v].size();i++){
		int u=g[v][i].first,ind=g[v][i].second;
		if(MrkCutE[u]==false){
			HCutE[u]=HCutE[v]+1;
			CutE(u,v,ind);
			DpCutE[v]=min(DpCutE[v],DpCutE[u]);
		}
		else if(u!=par)DpCutE[v]=min(DpCutE[v],DpCutE[u]);
	}
	if(v!=1&&DpCutE[v]==HCutE[v])IsCutE[ind]=true;
}
 
int main(){	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(make_pair(v,i));
		g[v].push_back(make_pair(u,i));
	}
}
