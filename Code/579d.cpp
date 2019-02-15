///so if you just yekam bekeshi be ham kheli khobe mishe
///it's just a copy 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+7;
int sor[MAXN],por[MAXN],a[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k,x;cin>>n>>k>>x;
	int num=1;
	while(k--)num*=x;
	for(int i=1;i<=n;i++)
		cin>>a[i],por[i]=por[i-1]|a[i];
	for(int i=n;i>0;i--)sor[i]=sor[i+1]|a[i];
	int res=0;
	for(int i=1;i<=n;i++)
		res=max(res,(a[i]*num)|por[i-1]|sor[i+1]);
	cout<<res;
}
