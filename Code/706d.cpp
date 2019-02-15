#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
multiset<int>mst;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;cin>>q;
	mst.insert(0);
	while(q--){
		int x;char c;
		cin>>c>>x;
		if(c=='+')mst.insert(x);
		if(c=='-')mst.erase(mst.find(x));
		if(c=='?'){
			int cur=0;
			for(int i=29;i>=0;i--){
				cur|=(~x)&(1<<i);
				if(mst.lower_bound(cur)==mst.lower_bound(cur+(1<<i)))cur^=(1<<i);
			}
			cout<<(cur^x)<<'\n';
		}
	}
}