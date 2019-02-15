//cutting rod (for finding used part left mean used up mean noting)
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,len,val[maxn],rod[maxn],dp[maxn][maxn];

int cr(){
	for(int i=1;i<=len;i++){
		for(int j=1;j<=n;j++){
			if(rod[j]<=i)dp[i][j]=max(dp[i][j-1],dp[i-rod[j]][j]+val[j]);
			else dp[i][j]=dp[i][j-1];
		}
	}
	return dp[len][n];
}

int main(){
	cin>>len>>n;
	for(int i=1;i<=n;i++)cin>>rod[i]>>val[i];
	cout<<cr()<<endl;
}
