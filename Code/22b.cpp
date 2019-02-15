#include<bits/stdc++.h>
using namespace std;
int ans,n,m,dp[50][50];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			dp[i][j]=c-48;
		}
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int a=i;a<=n;a++){
				for(int b=j;b<=m;b++){
					if(dp[a][b]+dp[i-1][j-1]-dp[a][j-1]-dp[i-1][b]==0){
						ans=max(ans,2*(b+a-j-i+2));
					}
				}
			}
		}
	}
	cout<<ans<<endl;;
}