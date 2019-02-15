//min edit to convert s to d
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int dp[maxn][maxn];
string s,d;
vector<pair<int,string> > c;

int med(string s,string d){
	for(int i=0;i<=s.size()+1;i++)dp[i][0]=i;
	for(int i=0;i<=d.size()+1;i++)dp[0][i]=i;
	for(int i=1;i<=s.size();i++){
		for(int j=1;j<=d.size();j++){
			if(s[i-1]==d[j-1])dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
		}
	}
	/*
	int i=s.size(),j=d.size();
	while(i>=0&&j>=0){
		if(dp[i][j]==dp[i-1][j-1])i--,j--;
		else if(dp[i][j]==dp[i-1][j-1]+1){c.push_back(make_pair(i,"Convert"));i--;j--;}
		else if(dp[i][j]==dp[i-1][j]+1){c.push_back(make_pair(i,"Del"));i--;}
		else if(dp[i][j]==dp[i][j-1]+1){c.push_back(make_pair(i,"Add"));j--;}
	}
	*/
	return dp[s.size()][d.size()];
}

int main(){
	cin>>s>>d;
	cout<<med(s,d)<<endl;
}