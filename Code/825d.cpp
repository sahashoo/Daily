///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,a[300];
string s,t;
vector<int>b;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s>>t;
	for(int i=0;i<s.size();i++){
		if(s[i]!='?')a[s[i]]++;
		else b.push_back(i);
	}
	while(b.size()){
		for(int i=0;i<t.size();i++){
			if(a[t[i]]>0)a[t[i]]--;
			else{
				s[b.back()]=t[i];
				b.pop_back();
				if(b.empty()) break;
			}
		}
	}
	cout<<s;
}
