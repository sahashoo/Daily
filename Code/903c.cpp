///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
map<int,int>mp;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],mp[a[i]]++;
	sort(a,a+n,greater<int>());
	mx=mp[a[0]];
	for(int i=0;i<n;i++){
		int tmp=mp[a[i]];
		if(tmp>mx)mx=tmp;
	}
	cout<<mx;
}