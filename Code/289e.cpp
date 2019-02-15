///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+7;
int res,n,pw,a[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	pw=1;
	while(pw<=n)pw*=2;
	for(int i=n;i>=0;i--){
		if(a[i]==0){
			while(pw/2>i)pw/=2;
			int i2=pw-1-i;
			a[i]=i2;a[i2]=i;
			res+=2*(i^i2);
		}
	}
	cout<<res<<endl;
	for(int i=0;i<=n;i++)cout<<a[i]<<" ";

}
