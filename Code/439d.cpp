///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,m,a[maxn],b[maxn],res;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
	sort(a,a+n);sort(b,b+m,greater<int>());
	for(int i=0;i<min(n,m)&&b[i]>a[i];i++)res+=abs(a[i]-b[i]);
	cout<<res;
}
