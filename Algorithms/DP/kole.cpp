#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int n,val[maxn],w[maxn],dp[maxn][maxn],wt;

int knapsnak(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=wt;j++){
            if(w[i]>j)dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-w[i]]);
        }
    }
    return dp[n][wt];
}

int kole(){
	for(int i=0;i<=8;i++)dp[i][0]=1;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=18;j++){
            if(i>j)dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
        }
    }
    return dp[8][18];
}

int32_t main(){
    // cin>>n>>wt;
    // for(int i=1;i<=n;i++)cin>>w[i]>>val[i];
    cout<<kole()<<endl;;
}
