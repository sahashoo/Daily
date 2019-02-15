#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int a[maxn],clw,res;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		res+=(clw<=0);
		clw--;
		if(a[i]>=clw)clw=a[i];
	}
	cout<<res;
}
