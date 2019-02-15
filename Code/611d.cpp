///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=5007,INF=1e18+7,mod=1e9+7;
int dp[maxn][maxn],n,d[maxn][maxn];
string s;

int Dp(int l,int r){
	if(r>=n)return 0;
	if(dp[l][r]==-1){
		int res=0;
		if(r==n- 1)res=1;
		else{
			res=Dp(l,r+1);
			if(s[r+1]!='0'){
				int k=d[l][r + 1];
				if(l+k>=r+1)res=(res+Dp(r+1,2*r+2-l))%mod;
				else if(r+1+k<n){
					if(s[l+k]<s[r+1+k])res=(res+Dp(r+1,2*r+1- l))%mod;
					else res=(res+Dp(r+1,2*r+2-l))%mod;
				}
			}
		}
		dp[l][r]=res;
	}
	return dp[l][r];
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i=0;i<maxn;i++)for(int j=0;j<maxn;j++)dp[i][j]=-1;
	cin>>n>>s;
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(s[i]==s[j])d[i][j]=d[i+1][j+1]+1;
			else d[i][j]=0;
		}
	}
	cout<<Dp(0,0);
}
