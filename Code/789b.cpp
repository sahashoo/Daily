///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=4e5,INF=1e18+7,mod=1e9+7;
int b,q,l,m,res,t;
set<int>s;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>b>>q>>l>>m;
	for(int i=0;i<m;i++){
		int a;cin>>a;
		s.insert(a);
	}
	int i=0;
	while(i<maxn&&abs(b)<=l){
		if(s.count(b)==0)res++;
		b*=q;i++;
	}
	if(res<3000)cout<<res;
	else cout<<"inf";
}
