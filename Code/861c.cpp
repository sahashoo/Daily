///age yekam bekeshi beham is no problem ._.
//vowel  'a', 'e', 'i', 'o' and 'u'
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;
int m[maxn];
bool mrk[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s,t;s="";t="";
	cin>>s;
	m['a']=m['e']=m['i']=m['o']=m['u']=1;
	for(int i=0;i<s.size();i++){
		if(mrk[i]){
			cout<<s[i]<<" ";
			continue;
		}
		else cout<<s[i];
		if(i+2<s.size())
			if(m[s[i]]+m[s[i+1]]+m[s[i+2]]==0&&(s[i]!=s[i+1]||s[i+1]!=s[i+2]))mrk[i+1]=true;
	}
}
