#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
int n,dp[100][100],ans=INF,siz;
string s[100];

void precomp(){
    siz=s[1].size();
    for(int i=1;i<=n;i++){
        s[i]=s[i]+s[i];
        for(int j=0;j<siz;j++)dp[i][j]=INF;
    }
    for(int i=0;i<siz;i++)dp[1][i]=i;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    precomp();
    for(int i=2;i<=n;i++){
        for(int j=0;j<siz;j++){
            for(int k=0;k<siz;k++){
                if(s[i].substr(j,siz)==s[i-1].substr(k,siz)){
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+j);
                }
            }
        }
    }
    for(int i=0;i<siz;i++)ans=min(dp[n][i],ans);
    if(ans==INF)cout<<-1<<endl;
    else cout<<ans<<endl;
}
