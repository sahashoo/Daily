#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;

int32_t main(){
	int n,k;cin>>n>>k;
	int tot=0,cnt=0;
	for(int i=1;i<=k;i++){
		int a;cin>>a;
		if(a%2)a++,cnt++;
		tot+=a;
	}
	if(tot>8*n||(tot==8*n&&k==4*n&&cnt<n))cout<<"NO";
	else cout<<"YES";
}