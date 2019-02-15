#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x,y,r[501],c[501],d1,d2;
int main(){
	cin>>n;
	if(n==1){cout<<1;return 0;}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int xx;
			cin>>xx;
			r[i]+=xx;
			c[j]+=xx;
			if(i==j)d1+=xx;
			if(i==n+1-j)d2+=xx;
			if(!xx)x=i,y=j;
		}
	}
	r[0]=r[n];
	ll res=r[x-1]-r[x];
	if(res<=0){cout<<-1;return 0;}
	r[x]+=res;
	c[y]+=res;
	if(x==y)d1+=res;
	if(x==n+1-y)d2+=res;
	for(ll i=1;i<=n;i++){
		if(r[i]!=r[x]||c[i]!=r[x]){cout<<-1;return 0;}
	}
	if(d1!=r[x]||d2!=r[x]){cout<<-1;return 0;}
	cout<<res;
	return 0;
}