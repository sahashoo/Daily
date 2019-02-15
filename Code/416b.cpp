#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e4+100,N=10;
int a[M][N];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>m>>n;
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	
	for(int i=2;i<=m;i++)a[i][1]+=a[i-1][1];
	for(int j=2;j<=n;j++)a[1][j]+=a[1][j-1];
	
	for(int i=2;i<=m;i++)
		for(int j=2;j<=n;j++)
			a[i][j]+=max(a[i-1][j],a[i][j-1]);
	
	for(int i=1;i<=m;i++)cout<<a[i][n]<<" ";
}