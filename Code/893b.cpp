#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int x,mx=1;cin>>x;
	for(int i=1;i<=30;i++){
		int tmp=(1<<i)-1;
		tmp*=(1<<(i-1));
		if(tmp!=0&&x%tmp==0)mx=tmp;
	}
	cout<<mx;
}
