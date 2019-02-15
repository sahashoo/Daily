#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	while(q--){
		int u;string s;cin>>u>>s;
		for(int i=0;i<s.size();i++){
			int bit=u&(-u);
			if(s[i]=='L')u-=bit>>1;
			if(s[i]=='R')u+=bit>>1;
			if(s[i]=='U'){
				if((u+bit)%(bit<<2)==0)u-=bit;
				else if(u+bit<=n)u+=bit;
			}
		}
		cout<<u<<'\n';
	}
}