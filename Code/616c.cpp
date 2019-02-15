#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,q,dp1[555][555],dp2[555][555];
char s[555][555]; 

int main(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin>>s[i][j];
			dp1[i][j]=dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
			dp2[i][j]=dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1];
			if(s[i][j]=='.'&&i>1&&s[i-1][j]=='.')dp1[i][j]++;
			if(s[i][j]=='.'&&j>1&&s[i][j-1]=='.')dp2[i][j]++;
		}
	}
	cin>>q;
	for(ll i=0;i<q;i++){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		cout<<dp1[c][d]-dp1[c][b-1]-dp1[a][d]+dp1[a][b-1]+dp2[c][d]-dp2[c][b]-dp2[a-1][d]+dp2[a-1][b]<<endl;
    }
}