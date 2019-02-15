#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,wt,coin[maxn],dp[maxn],dpw[maxn][maxn];

int changing(){
    for(int i=1;i<maxn;i++)dp[i]=maxn;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=wt;i++){
            if(i>=coin[j]){
                dp[i]=min(dp[i],1+dp[i-coin[j]]);
            }
        }
    }
    return dp[wt];
}

int ways(){
	for(int i=1;i<maxn;i++)dpw[0][i]=1;
	for(int i=1;i<=wt;i++){
		for(int j=1;j<=n;j++){
			if(coin[j]<=i)dpw[i][j]=dpw[i][j-1]+dpw[i-coin[j]][j];
			else dpw[i][j]=dpw[i][j-1];
		}
	}
	return dpw[wt][n];
}

int32_t main(){
    cin>>n>>wt;
    for(int i=1;i<=n;i++)cin>>coin[i];
    cout<<changing()<<endl<<ways();
}
