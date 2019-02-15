///age yekam bekeshi be ham moshkel khasi pish nemid ._.
#include<bits/stdc++.h>
//#define int long long
#define q first
#define w second
using namespace std;
const int maxn=5e3+1;
const int INF=1e9+7;
int tt,n,m,res[maxn][maxn],dp[maxn][maxn],d[maxn];
vector<pair<int,int> >g[maxn];
queue<int>q;

void input(){
    cin>>n>>m>>tt;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        d[v]++;
        g[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++)if(d[i]==0)q.push(i);
    for(int i=0;i<maxn;i++)for(int j=0;j<maxn;j++)dp[i][j]=INF;
    dp[1][1]=0;
}

/*void dfs(int v){
    for(int i=0;i<g[v].size();i++){
        int u=g[v][i].q,t=g[v][i].w;
        for(int j=2;j<=n;j++)if(dp[u][j]>=dp[v][j-1]+t)res[u][j]=v,dp[u][j]=dp[v][j-1]+t;
        dfs(u);
    }
}*/

void bfs(){
    while(q.size()){
        int v=q.front();q.pop();
        for(int i=0;i<g[v].size();i++){
            int u=g[v][i].q,t=g[v][i].w;
            for(int j=2;j<=n;j++)if(dp[u][j]>=dp[v][j-1]+t)res[u][j]=v,dp[u][j]=dp[v][j-1]+t;
            d[u]--;
            if(d[u]==0)q.push(u);
        }
    }
}

void output(int v,int i){
    if(res[v][i]&&i)output(res[v][i],i-1);
    cout<<v<<" ";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
	bfs();
    for(int i=n;i>=2;i--){
        if(dp[n][i]&&dp[n][i]<=tt){
            cout<<i<<endl;
            output(n,i);
            return 0;
        }
    }
}
