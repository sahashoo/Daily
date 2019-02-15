///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=507;
int n,k,c[N];
bool dp[2][N][N];
vector<int>res;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>c[i];
	int t=1;
	dp[0][0][0]=dp[0][c[0]][0]=dp[0][c[0]][c[0]]=true;
	for(int i=1;i<n;i++){
		for(int j=0;j<=k;j++){
			for(int o=0;o<=j;o++){
				dp[t][j][o]=dp[1-t][j][o];
				if(c[i]<=j)
					dp[t][j][o]=(dp[t][j][o]||dp[1-t][j-c[i]][o]);
				if(c[i]<=o)
					dp[t][j][o]=(dp[t][j][o]||dp[1-t][j-c[i]][o-c[i]]);
			}
		}
		t=1-t;
	}
	for(int i=0;i<=k;i++)if(dp[(n-1)%2][k][i])res.push_back(i);
	cout<<res.size()<<endl;
	for(auto x:res)cout<<x<<" ";
}
