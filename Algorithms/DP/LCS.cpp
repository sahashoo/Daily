#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7,maxn=1e3+7;
int dp[maxn][maxn];

int LCS(string &s,string &t){
	for(int i=0;i<s.size();i++)
		for(int j=0;j<t.size();j++)
			dp[i+1][j+1]=max(max(dp[i][j+1],dp[i+1][j]),(s[i]==t[j]?dp[i][j]+1:-INF));
	return dp[s.size()][t.size()];
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s,t;cin>>s>>t;
	cout<<LCS(s,t);
}