///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int MAXN=30;
map<string,int>mp;
set<string>name;
set<string>st[MAXN];

bool suffix(string &s,string &t){
	if(t.size()>s.size())return false;
	int tln=t.size(),sln=s.size();
	for(int i=sln-tln,j=0;i<sln;j++,i++)
		if(s[i]!=t[j])return false;
	return true;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		string s,num;
		int t,ind;
		cin>>s>>t;
		if(name.find(s)==name.end()){
			name.insert(s);
			mp[s]=name.size();
		}
		ind=mp[s];
		while(t--){
			cin>>num;
			st[ind].insert(num);
		}
	}
	for(auto x:mp){
		set<string>mrk;
		for(auto s:st[x.S]){
			if(mrk.find(s)!=mrk.end())continue;
			for(auto t:st[x.S]){
				if(s==t||mrk.find(t)!=mrk.end())continue;
				if(suffix(s,t))mrk.insert(t);
			}
		}
		for(auto s:mrk)st[x.S].erase(s);
	}
	cout<<mp.size()<<endl;
	for(auto x:mp){
		cout<<x.F<<" "<<st[x.S].size()<<" ";
		for(auto s:st[x.S])cout<<s<<" ";
		cout<<endl;
	}
}
