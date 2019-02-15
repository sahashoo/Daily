#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int l=0,cnt=0,res=0;
	long long tkn=0;
	for(int i=0;i<n;i++){
		if(i)tkn+=(long long)(i-l)*(long long)(a[i]-a[i-1]);
		while(tkn>k)tkn-=a[i]-a[l++];
		if(i-l+1>cnt)cnt=i-l+1,res=a[i];
	}
	cout<<cnt<<" "<<res;
}