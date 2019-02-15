///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=2e9;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	while(n--){
		int p,q,x,y;cin>>x>>y>>p>>q;
		if((p==q&&x!=y)||(p==0&&x!=0)){cout<<-1<<'\n';continue;}
		if(p==0&&x==0){cout<<0<<'\n';continue;}
		int l=0,r=INF;
		while(r-l>1){
			int mid=r+l>>1;
			if(mid*q<y||mid*p<x)l=mid;
			else if(mid*q-y>=mid*p-x)r=mid;
			else l=mid;
		}
		int res=r*q-y;
		if(res<r*p-x)res=-1;
		cout<<res<<'\n';
	}
}
