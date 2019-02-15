///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn],b[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],b[i]=a[i];
	sort(a,a+n);
	int cnt=0;
	for(int i=0;i<n;i++)cnt+=(a[i]!=b[i]);
	cout<<(cnt<3?"YES":"NO");
}