#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e5+7;
const int M=110;
int a[M][MAXN],dp[M][MAXN];
bool chk=true;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        int OK=false;
        string s;cin>>s;
		for(int j=0;j<m;j++)
            a[i][j]=(s[j]=='1'),OK|=(s[j]=='1');
		chk&=OK;
    }
    if(chk==false)return cout<<-1,0;
    for(int i=0;i<n;i++){
        int t=1,cur=m-1;
        while(a[i][cur--]==0)t++;
        for(int j=0;j<m;j++){
            if(a[i][j]==1)t=0;
            dp[i][j]=t++;
        }
        t=1,cur=0;
        while(a[i][cur++]==0)t++;
        for(int j=m-1;j>=0;j--){
            if(a[i][j]==1)t=0;
            dp[i][j]=min(t++,dp[i][j]);
        }
    }
    /*for(int i=0;i<n;i++,cout<<endl)
        for(int j=0;j<m;j++)
            cout<<dp[i][j]<<" ";*/
    int res=INF;
    for(int j=0;j<m;j++){
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=dp[i][j];
        res=min(res,sum);
    }
    cout<<res;
}
