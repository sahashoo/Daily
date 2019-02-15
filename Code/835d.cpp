#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e3+7;
int dp[maxn][maxn],res[maxn];

int32_t main(){
	string s;cin>>s;
	int sln=s.size();
	for(int i=1;i<=sln;i++){
		for(int l=0;l<sln-i+1;l++){
			int r=l+i;
			if(i==1){dp[l][r]=1;continue;}
			if(i==2){dp[l][r]=(s[l]==s[r-1]?2:0);continue;}
			if(s[l]!=s[r-1]||dp[l+1][r-1]==0)continue;
			dp[l][r]=1;
			int mid=l+r>>1;
			if(i%2)(dp[l][mid]&&dp[mid+1][r]?dp[l][r]=dp[l][mid]+1:i=i);
			else (dp[l][mid]&&dp[mid][r]?dp[l][r]=dp[l][mid]+1:i=i);
		}
	}
	for(int i=1;i<=sln;i++){
		for(int l=0;l<sln-i+1;l++){
			res[dp[l][l+i]]++;
		}
	}
	for(int i=sln-1;i>0;i--)res[i]+=res[i+1];
	for(int i=1;i<=sln;i++)cout<<res[i]<<" ";
}