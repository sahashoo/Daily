#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e5+7;
int n,m,par[maxn],finish[maxn],order[maxn];
vector<int>g[maxn],grvs[maxn];
bool mrk[maxn],mrk1[maxn];
map<int,bool>result;

void input(){
    // N is the number of variables and M is the number of clauses
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		/*
			Each clause form u or v
	        1 <= x <= N for an uncomplemented variable x
	        -N <= x <= -1 for a complemented variable x
	        -x is the complement of a variable x
        */
		// Internally, complement of variable x is represented as N+x.
        if(u>0){
            if(v>0){
				g[n+u].pb(v);
				g[n+v].pb(u);
				grvs[u].pb(n+v);
				grvs[v].pb(n+u);
            }
			else{
				g[n+u].pb(n-v);
				g[-v].pb(u);
				grvs[u].pb(-v);
				grvs[n-v].pb(n+u);
            }
        }
		else{
            if(v>0){
				g[-u].pb(v);
				g[n+v].pb(n-u);
				grvs[n-u].pb(n+v);
				grvs[v].pb(-u);
			}
			else{
				g[-u].pb(n-v);
				g[-v].pb(n-u);
				grvs[n-u].pb(-v);
				grvs[n-v].pb(-u);
            }
        }
    }
}

// running DFS on the reverse graph
int cnt=0;
void dfs_rvs(int v){
	mrk[v]=true;
	for(auto u:grvs[v])if(mrk[u]==false)dfs_rvs(u);
	finish[v]=++cnt;
}

// running DFS on the actual graph
void dfs(int v,int p){
    mrk1[v]=true;
	par[v]=p;
	for(auto u:g[v])if(mrk[u]==false)dfs(u,p);
}

// check if u & v are in the same connected component
bool SCC(int u,int v){
    return par[u]==par[v];
}

bool sat_2(){
    // run dfs on the reverse graph to get reverse postorder
	for(int i=n*2;i>0;i--){
		if(mrk[i]==false)dfs_rvs(i);
		order[finish[i]]=i;
	}
	// run dfs on the actual graph in reverse postorder
	for(int i=n*2;i>0;i--)if(mrk1[i]==false)dfs(order[i],order[i]);

    // check if a variable and its complement belong in the same SCC in reverse postorder
    for(int i=n*2;i>0;i--){
		int u=order[i];
		if(u>n){
			if(SCC(u,u-n))return false;
			if(result.find(par[u])==result.end())result[par[u]]=true,result[par[u-n]]=false;
        }
		else{
			if(SCC(u,u+n))return false;
			if(result.find(par[u])==result.end())result[par[u]]=true,result[par[u+n]]=false;
		}
    }
	return true;

}

int32_t main(){
	input();
	if(sat_2()==false)cout<<"Unsatisfiable"<<endl;
	else{
		cout<<"Satisfying Assignment"<<endl;
		for(int i=1;i<=n;i++)cout<<i<<" : "<<(result[par[i]]?"True":"False")<<'\n';
	}
}
