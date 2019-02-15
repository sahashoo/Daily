///adp1e yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+1863;
const int N=170;
int a[N],ans[N],dp1[N][N][N],dp2[N][N];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]=(a[i]==-1?-INF:a[i]);
	string s;cin>>s;s="#"+s;
	memset(dp1,-64,sizeof dp1 );
	memset(dp2,-64,sizeof dp2 );
	for(int i=1;i<=n;i++)
		dp1[i][i][1]=0,
		dp2[i][i]=a[1],
		dp2[i+1][i]=0;
	for(int i=2;i<=n;i++){
		for(int l=1;l+i-1<=n;l++){
			int r=l+i-1;
			if(s[l]==s[r]){
				dp1[l][r][2]=max(dp1[l][r][2],dp2[l+1][r-1]);
				for(int k=3;k<=i;k++)
					dp1[l][r][k]=max(dp1[l][r][k],dp1[l+1][r-1][k-2]);
			}
			for(int k=l;k<r;k++)
				for(int len=1;len<=k-l+1;len++)
					dp1[l][r][len]=max(dp1[l][r][len],dp1[l][k][len]+dp2[k+1][r]);
			for(int k=l+1;k<=r;k++)
				for(int len=1;len<=r-k+1;len++)
					dp1[l][r][len]=max(dp1[l][r][len],dp1[k][r][len]+dp2[l][k-1]);
			for(int k=1;k<=i;k++)
				dp2[l][r]=max(dp2[l][r],dp1[l][r][k]+a[k]);
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1];
		for(int j=1;j<=i;j++)
			ans[i]=max(ans[i],ans[j-1]+dp2[j][i]);
	}
	cout<<ans[n];
}
