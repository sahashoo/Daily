#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,arr[200007],ans[200007],sum;
pair<ll,ll> q[200007];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<m;i++){
		ll l,r;
		cin>>l>>r;
		q[l-1].first++;
		q[r].first--;
	}
	q[0].second=0;
	for(int i=1;i<n+2;i++){
		q[i].second=i;
		q[i].first+=q[i-1].first;
	}
	sort(q,q+n);
	for(int i=0;i<n;i++)sum+=arr[i]*q[i].first;
	cout<<sum;
}