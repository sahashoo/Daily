#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+7;
const int M=1e9+7;
int h[MAXN],mn[MAXN],ans,k,r;

int32_t main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	mn[0]=M+M;
	for(int i=1;i<=n;i++){
		mn[i]=min(h[i-1],h[i]);
		ans=(ans+k*(mn[i]-1))%M;
		ans=(ans+h[i]-1)%M;
		if(i<n){
			r=min(h[i+1],h[i])-1;
			mn[i]=min(mn[i],h[i+1]);
			r=(r+(k*(mn[i]-1)))%M;
			k=r;
		}
	}
	cout<<ans;
}