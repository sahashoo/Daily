#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7,INF=1e9+7;
int n,mx,ans,arr[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		arr[a]++;
		mx=max(mx,a);
	}
	for(int i=mx;i>0;i--)arr[i]+=arr[i+1];
	for(int i=1;i<=mx;i++){
		if(arr[i]-arr[i+1]!=0){
			int cnt=0;
			for(int j=i;j<=mx;j+=i)cnt+=arr[j];
			cnt*=i;
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
}
