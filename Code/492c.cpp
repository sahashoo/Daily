#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum,sumkol,n,r,avg,ans;
pair<ll,ll> a[100007];

int main(){
	cin>>n>>r>>avg;
	sumkol=avg*n;
	for(ll i=0;i<n;i++){
		cin>>a[i].second>>a[i].first;
		sum+=a[i].second;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(sum>=sumkol)break;
		ll k=min(sumkol-sum,r-a[i].second);
		sum+=k;
		ans+=k*a[i].first;
	}
	cout<<ans;
}