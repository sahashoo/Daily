///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e7+1;//+7;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,n,i=0;cin>>n>>a>>b;
	if(n%a==0)return cout<<"YES\n"<<n/a<<" "<<0,0;
	if(n%b==0)return cout<<"YES\n"<<0<<" "<<n/b,0;
	while(i*a<n&&i<MAXN){
		int tmp=n-a*i;
		if(tmp%b==0)
			return cout<<"YES\n"<<i<<" "<<tmp/b,0;
		i++;
	}
	cout<<"NO";
}
