#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int a[maxn],n;
long long sum;
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0,x;i<n;i++)cin>>x,sum+=x;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	cout<<(a[n-1]+a[n-2]>=sum?"YES":"NO");
}
