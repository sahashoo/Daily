///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int l,r;cin>>l>>r;
	int dif=r-l,btr=1,pos=0,res=0;
	while(dif>=btr)res+=btr,btr*=2,pos++;
	while(r>=btr){
		if((((l>>pos)^(r>>pos))&1LL)==1LL)res+=btr;
		btr*=2,pos++;
	}
	cout<<res;
}
