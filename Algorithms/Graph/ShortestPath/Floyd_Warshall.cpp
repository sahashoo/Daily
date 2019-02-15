#include<bits/stdc++.h>
//400D
using namespace std;
const int maxn=1e4+7;
const int INF=1e9+10;
int n,m,dp[maxn][maxn];

void input(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=INF;
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        dp[u][v]=w;
        dp[v][u]=w;
    }
}

void Floyd_Warshall(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}

void output(){
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j]!=INF)cout<<dp[i][j]<<" ";
            else cout<<"n ";
        }
        cout<<endl;
    }
}

int32_t main(){
    input();
    Floyd_Warshall();
    output();
}
