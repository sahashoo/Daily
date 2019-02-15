#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int ab;

int BS(int l,int r){
	if(r-l==1){
		if(r*r*r==ab)return r;
		else return l;
	}
	int m=l+r>>1;
	if(m*m*m>ab)return BS(l,m);
	else if(m*m*m==ab)return m;
	else return BS(m,r);
} 

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--){
		int a,b;cin>>a>>b;
		ab=a*b;
		int bs=BS(1,maxn);
		if(bs*bs*bs!=ab||a%bs||b%bs)cout<<"No\n";
		else cout<<"Yes\n";
	}
}