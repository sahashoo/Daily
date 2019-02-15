#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int N=2e5+100,INF=1e18+7;;
int a[N],ans[N];
pair<int,int>b[N];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i].F,b[i].S=i;
	sort(a,a+n);reverse(a,a+n);
	sort(b,b+n);
	for(int i=0;i<n;i++)ans[b[i].S]=a[i];
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
}