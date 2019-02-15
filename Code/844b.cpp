#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int N=60,maxn=1e5+100,MOD=1e9+7,INF=1e18+7;
int a[N][N];
int c1[N],r1[N];
int c0[N],r0[N];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]==0)c0[j]++,r0[i]++;
			else c1[j]++,r1[i]++;
		}
	}
	int cnt=0;
	for(int i=0;i<m;i++){
		if(c0[i])sum+=pow(2,c0[i])-1-c0[i];
		if(c1[i])sum+=pow(2,c1[i])-1-c1[i];
	}
	for(int i=0;i<n;i++){
		if(r0[i])sum+=pow(2,r0[i])-1;
		if(r1[i])sum+=pow(2,r1[i])-1;
	}
	cout<<sum;
}
