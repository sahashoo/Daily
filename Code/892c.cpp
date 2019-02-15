#include<bits/stdc++.h>
using namespace std;
const int inf=1e18;
const int maxn=1e6;
int a[maxn],b[maxn],len=inf;
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int cnt=0;
	for(int i=0;i<n;i++)cnt+=(a[i]==1);
	if(cnt)return cout<<n-cnt,0;
	for(int l=0;l<n;l++){
		for(int i=0;i<n;i++)b[i]=a[i];
		for(int r=l+1;r<n;r++){
			b[r]=gcd(b[r],b[r-1]);
			if(b[r]==1)
				len=min(len,r-l);
		}
	}
	cout<<(len==inf?-1:n-1+len);
}
