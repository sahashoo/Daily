#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=5e5+100,MOD=1e9+7,INF=1e18+7;
int n,a[maxn],mn=INF,cnt;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		int d=abs(a[i]-a[i+1]);
		if(mn>d)mn=d,cnt=0;
		if(mn==d)cnt++;
	}
	cout<<mn<<" "<<cnt;
}