///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
set<char>del,bad;

void add(string &s){
	for(char c:s){
		del.insert(c);
		if(bad.find(c)!=bad.end())bad.erase(c);
	}
}

void shock(string &s){
	set<char>st;
	for(char c:s)st.insert(c);
	for(auto x:bad)
		if(st.find(x)==st.end())
			del.insert(x);
	bad.clear();
	for(char c:s)
		if(del.count(c)==0)bad.insert(c);
	for(auto x:del)if(bad.find(x)!=bad.end())bad.erase(x);
}

void guess(char c){
	if(bad.find(c)!=bad.end())
		bad.erase(c);
	del.insert(c);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,cnt=0;cin>>n;
	char m;string s;
	for(char c='a';c<='z';c++)bad.insert(c);
	while(n--){
		cin>>m>>s;
		if(bad.size()<=1)cnt+=(m!='.');
		if(m=='.')add(s);
		else if(m=='!'&&bad.size()>1)shock(s);
		else guess(s[0]);
	}
	cout<<max(cnt-1,0ll);
}
