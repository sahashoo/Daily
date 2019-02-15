#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,l,a[100],b[100],c[100],p;
int main(){
	cin>>n>>l;
	for(ll i=0;i<n;i++){cin>>a[i];c[a[i]]=1;}
	for(ll i=0;i<n;i++)	cin>>b[i];
	for(ll i=0;i<l;i++){
		ll d=1;
		p=0;
		for (ll j=0;j<n;j++){
			if (c[(i+b[j])%l]==0){d=0;break;}
			p+=b[j];
		}
		if(d==1){cout<<"YES"<<endl;return 0;}
	}
	cout<<"NO"<<endl;
}