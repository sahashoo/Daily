#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+12;
long long dp[MAXN][2],c[MAXN],n;
string s[MAXN],t[MAXN];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){cin>>c[i];dp[i][0]=1e16+12;dp[i][1]=1e16+12;}
    dp[1][0]=0;
	dp[1][1]=c[1];
	for(int i=1;i<=n;i++){
        cin>>s[i];
        t[i]=s[i];
        reverse(t[i].begin(),t[i].end());
        if(i>1){
            if(s[i]>=s[i-1])dp[i][0]=dp[i-1][0];
            if(s[i]>=t[i-1])dp[i][0]=min(dp[i][0],dp[i-1][1]);
            if(t[i]>=s[i-1])dp[i][1]=dp[i-1][0]+c[i];
            if(t[i]>=t[i-1])dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
        }
    }
	if(min(dp[n][0],dp[n][1])<1e16+12)cout<<min(dp[n][0],dp[n][1]);
	else cout<<-1;
}