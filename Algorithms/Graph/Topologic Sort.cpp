#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+100;
int m,n,in[MAXN],ord_num[MAXN];
vector<int>g[MAXN],ord;

void topologic_sort(){
	queue<int>Q;
	
	for(int i=1;i<=n;i++)
		if(in[i]==0)Q.push(i);
	
	while(Q.size()){
		int v=Q.front();Q.pop();
		ord.push_back(v);
		ord_num[v]=ord.size()-1;
	
		for(int u:g[v]){
			in[u]--;
			if(in[u]==0)
				Q.push(u);
		}
		
	}
	
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		in[v]++;
	}
	
	topologic_sort();
	for(int x:ord)cout<<x<<" ";
	
}