///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
int a[107];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0,x;i<n;i++)cin>>x,a[x]++;
	int mx=0,cnt=0;
	for(int i=0;i<101;i++)
		for(int j=0;j<a[i];j++)
			cnt++,mx=max(mx,(cnt+i)/(i+1));
	cout<<mx;
}