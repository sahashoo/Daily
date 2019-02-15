///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,a[maxn];

bool polygon(int x){
	if(n/x<3)return false;
	bool can[maxn];
	for(int i=0;i<n;i++){
		if(i<x)can[i]=a[i];
		else can[i]=(can[i-x]&&a[i]);
		if(can[i]&&i>=n-x)return true;
	}
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i*i<=n;i++)
		if(n%i==0&&(polygon(i)||polygon(n/i)))
				return cout<<"YES",0;
	cout<<"NO";
}
