///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int a[maxn],n,x,mn=1e9+7;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>x;
	for(int i=1;i<=n;i++)cin>>a[i],mn=min(mn,a[i]);
	int ansx=mn*n;
	while(a[x]!=mn){a[x]--;ansx++;x=(x==1?n:x-1);}
	for(int i=1;i<=n;i++)cout<<(i==x?ansx:a[i]-mn)<<" ";
	//cout<<endl<<mn;
}