#include<bits/stdc++.h>
#define int long long
#define ld long double
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
bool mrk[MAXN];

bool vow(char c){
	// a, e, i, o, u and y
	if(c=='a')return true;
	if(c=='e')return true;
	if(c=='i')return true;
	if(c=='o')return true;
	if(c=='u')return true;
	if(c=='y')return true;
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a;cin>>a;
	string s;cin>>s;
	bool is=false;
	for(int i=0;i<sz(s);i++){
		if(is==false||vow(s[i])==false)cout<<s[i];
		if(vow(s[i]))is=true;
		else is=false;
	}
}
