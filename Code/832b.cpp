///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n;
string s,cop;
bool star,mrk[255];

bool check(string p,string t){
	if(p.size()!=t.size())return false;
	for(int i=0;i<t.size();i++){
		if(p[i]!='?'){
			if(p[i]!=t[i]){
				return false;
			}
		}
		else if(mrk[t[i]]==false)return false;
	}
	return true;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string g;int q;
	cin>>g>>s>>q;
	for(auto c:g)mrk[c]=true;
	auto sp=s.find('*');
	while(q--){
		string t;cin>>t;
		if(t.size()+1<s.size())cout<<"NO"<<'\n';
		else if(sp==string::npos)cout<<(check(s,t)?"YES":"NO")<<'\n';
		else{
			bool OK=check(s.substr(0,sp),t.substr(0,sp));
			reverse(s.begin(),s.end());
			reverse(t.begin(),t.end());
			sp=s.size()-sp-1;
			OK&=check(s.substr(0,sp),t.substr(0,sp));
			reverse(s.begin(),s.end());
			reverse(t.begin(),t.end());
			sp=s.size()-sp-1;
			for(int i=sp;i<t.size()-(s.size()-sp-1);i++)
				OK&=(mrk[t[i]]==false);
			if(OK)cout<<"YES"<<'\n';
			else cout<<"NO"<<'\n';
		}
	}

}
