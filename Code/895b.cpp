///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int maxn=1e5+7;
int a[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k,x;cin>>n>>x>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int l=0,r=0;
	long long ans=0;
	for(int i=0;i<n;i++){
		while(r<n)
			if(a[r]<a[i]||(a[r]/x)-((a[i]-1)/x)<=k)r++;
			else break;
		while(l<n)
			if(a[l]<a[i]||(a[l]/x)-((a[i]-1)/x)<k)l++;
			else break;
		if(l>n-1)break;
		ans+=r-l;
	}
	cout<<ans;
}
