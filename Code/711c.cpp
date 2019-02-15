#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=150,INF=1e18+7;
int n,m,k,a[N],c[N][N],dp[N][N][N];

int check(int pos,int col,int cnt){
    if(cnt>k)return INF;
    if(pos==n){
        if(cnt==k)return 0;
        else return INF;
    }
    if(dp[pos][col][cnt])return dp[pos][col][cnt];
    if(a[pos])dp[pos][col][cnt]=check(pos+1,a[pos],cnt+(a[pos]!=col));
    else{
        int tmp=INF;
        for(int i=0;i<m;i++)
			tmp=min(tmp,check(pos+1,i+1,cnt+(i+1!=col))+c[pos][i]);
        dp[pos][col][cnt]=tmp;
    }
    return dp[pos][col][cnt];
}

int32_t main(){
    cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>c[i][j];
	int ans=check(0,0,0);
    cout<<(ans==INF?-1:ans);
}