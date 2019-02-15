#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;
int sum;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	bool ans=false;
	for(int i=0,a=0;i<n;i++){
		cin>>a;
		sum+=a;
		if(a%2)ans=true;
	}
	if(sum%2||ans)cout<<"First";
	else cout<<"Second";
}
