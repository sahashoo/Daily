#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;
int n,a[maxn],k;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=a[i];
		if(cnt>=8)k-=8,cnt-=8;
		else k-=cnt,cnt=0;
		//cout<<cnt<<" "<<k<<" "<<a[i]<<"******"<<endl;
		if(k<=0)return cout<<i+1,0;
	}
	cout<<-1;
}