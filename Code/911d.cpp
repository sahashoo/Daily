#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e5+7;
int a[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			cnt+=(a[i]>a[j]);
	bool res=cnt%2;
	int m;cin>>m;
	while(m--){
		int l,r;cin>>l>>r;
		int tmp=r-l+1;
		cnt=tmp*(tmp-1)/2;
		if(cnt%2)res=!res;
		cout<<(res?"odd":"even")<<'\n';
	}
}
