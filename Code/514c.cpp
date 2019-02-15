///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=7123456789,P=23;
const string uni="abc";
map<int,set<int> >mp;

inline int Hash(string &s){
	int ret=0;
	for(auto &c:s)
		ret=(P*ret+c)%mod;
	return ret;
}

inline bool check(string &s){
	int h=Hash(s),p=1;
	// cout<<h<<endl;
	for(int i=s.size()-1;i>=0;i--){
		for(auto c:uni){
			if(c==s[i])continue;
			int tmp=h;
			tmp=(tmp+mod-p*s[i])%mod;
			tmp=(tmp+p*c)%mod;
			// cout<<tmp<<endl;
			if(mp[s.size()].find(tmp)!=mp[s.size()].end())
				return true;
		}
		p=(p*P)%mod;
	}
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	string s;
	while(n--)cin>>s,mp[s.size()].insert(Hash(s));
	while(m--)cin>>s,cout<<(check(s)?"YES\n":"NO\n");
}
