#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,b,d;cin>>n>>b>>d;
	int cnt=0,sum=0;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		sum+=(a<=b?a:0);
		if(sum>d)sum=0,cnt++;
	}
	cout<<cnt;
}