///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int N=3e4+7;
int cnt[N],dp[N][500],d;
bool mrk[N][500];

int solve(int pos,int dst){
	int l=dst-d+250;
	if(pos>=30001||pos<=0||dst<=0)return 0;
	if(mrk[pos][l])return dp[pos][l];
	mrk[pos][l]=true;
	dp[pos][l]=cnt[pos]+
		max(solve(dst+pos+1,dst+1),
		max(solve(dst+pos-1,dst-1),
		solve(dst+pos,dst)));
	return dp[pos][l];
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n>>d;
	for(int i=0,x;i<n;i++)cin>>x,cnt[x]++;
	cout<<solve(d,d);
}