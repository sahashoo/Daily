#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;int k;cin>>s>>k;
	if(k>s.size())return cout<<"impossible",0;
	set<char>st;
	for(int i=0;i<s.size();i++)if(st.count(s[i])==0)st.insert(s[i]);
	if(st.size()>=k)cout<<0;
	else cout<<k-st.size();
}