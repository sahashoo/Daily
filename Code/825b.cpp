///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int dp[15][15][5];
char c[15][15];

bool check(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			if(c[i][j]=='X'){
				dp[i][j][0]=dp[i][j-1][0]+1;
				dp[i][j][1]=dp[i-1][j][1]+1;
				dp[i][j][2]=dp[i-1][j-1][2]+1;
				if(dp[i][j][0]>=5)return true;
				if(dp[i][j][1]>=5)return true;
				if(dp[i][j][2]>=5)return true;
			}
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=10;i>=1;i--){
		for(int j=10;j>=1;j--){
			if(c[i][j]=='X'){
				dp[i][j][2]=dp[i+1][j-1][2]+1;
				if(dp[i][j][2]>=5)return true;
			}
		}
	}
	return false;
}

void output(){
	cout<<endl<<endl<<"*******"<<endl<<endl;;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			cout<<dp[i][j][2]<<" ";
		}
		cout<<endl;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			char l=c[i][j];
			if(l=='.')c[i][j]='X';
			if(check())return cout<<"YES",0;
			c[i][j]=l;
			//output();
		}
	}
	cout<<"NO";
	
}
