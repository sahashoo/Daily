#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+100;
int a[maxn],mx;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int m;cin>>m;
	while(m--){
		int h,w;cin>>w>>h;
		int tmp=max(mx,a[w]);
		mx=tmp+h;
		cout<<tmp<<'\n';
	}
}