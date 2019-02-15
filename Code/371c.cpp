///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=3e12;
int na,nb,nc,pa,pb,pc,r,ca,cb,cc;

inline bool check(int t){
	int a=max(0ll,((t*ca)-na)*pa);
	int b=max(0ll,((t*cb)-nb)*pb);
	int c=max(0ll,((t*cc)-nc)*pc);
	// cout<<" - "<<a<<" "<<b<<" "<<c<<" - ";
	return r>=(a+b+c);
}

inline int BS(int l,int r){
	while(r-l>1){
		int mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	return l;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;cin>>s;
	cin>>na>>nb>>nc>>pa>>pb>>pc>>r;
	for(int i=0;i<s.size();i++)
		ca+=(s[i]=='B'),
		cb+=(s[i]=='S'),
		cc+=(s[i]=='C');
	cout<<BS(0,INF);
}
