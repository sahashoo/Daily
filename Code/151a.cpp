#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n,k,l,c,d,p,nl,np;cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	int slc=c*d,btl=(k*l)/nl,slt=p/np;
	int mn=min(slc,min(slt,btl));
	cout<<mn/n;
}