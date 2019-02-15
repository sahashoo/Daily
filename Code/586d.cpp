///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int MAXN=102;
int n,k;
bool dp[3][MAXN];
string s[3];

bool check(int i,int j){
	return (j>=n||s[i][j]=='.'||s[i][j]=='s');
}

inline bool Solve(){
	for(int i=0;i<MAXN;i++)
		dp[0][i]=dp[1][i]=dp[2][i]=false;
	cin>>n>>k;
	for(int i=0;i<3;i++)
		cin>>s[i],dp[i][0]=(s[i][0]=='s');
	for(int t=0;t<n;t++)
		for(int i=0;i<3;i++)
			if(dp[i][t]){
				if(t==n-1)return true;
				if(check(i,t*3+1)==false)continue;
				for(int j=0;j<3;j++){
					if(abs(i-j)<=1){
						bool chk=true;
						for(int l=0;l<3;l++)
							chk&=check(j,t*3+1+l);
						dp[j][t+1]=chk;
					}
				}
			}
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;cin>>q;
	while(q--)
		cout<<(Solve()?"YES":"NO")<<'\n';
}
