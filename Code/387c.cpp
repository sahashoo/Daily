///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
string s,res[maxn],cur;
int cnt,ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')res[cnt]+=s[i];
		else cnt++,res[cnt]=s[i];
	}
	for(int i=1;i<=cnt;i++){
		if(cur.size()>res[i].size()||(cur.size()==res[i].size()&&cur>=res[i]))ans++;
		else ans=1;
		cur+=res[i];
	}
	cout<<ans;
}
