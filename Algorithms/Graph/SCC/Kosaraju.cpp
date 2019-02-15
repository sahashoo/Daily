//Finding Strongly Connected Component
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int n,m,p;
bool mrk[maxn],mrk2[maxn];
vector<int> g[maxn],reversg[maxn],ans[maxn];
stack<int> s;

void input(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        reversg[v].push_back(u);
    }
}

void dfs(int v){
    mrk[v]=true;
    for(int i=0;i<g[v].size();i++){
        int u=g[v][i];
        if(mrk[u]==false)dfs(u);
    }
    s.push(v);
}

void reversdfs(int v,int par){
    mrk2[v]=true;
    ans[par].push_back(v);
    for(int i=0;i<reversg[v].size();i++){
        int u=reversg[v][i];
        if(mrk2[u]==false)reversdfs(u,par);
    }
}

void kosaraju(){
    for(int i=1;i<=n;i++)if(mrk[i]==false)dfs(i);
    while(s.size()){
        int v=s.top();
        s.pop();
        if(mrk2[v]==false){
            p++;
            reversdfs(v,p);
        }
    }
}

void output(){
	cout<<endl<<endl;
    cout<<p<<endl;
    for(int i=1;i<=p;i++){
		cout<<ans[i].size()<<" ";
        for(int j=0;j<ans[i].size();j++)cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

int32_t main(){
    input();
    kosaraju();
    output();
}
