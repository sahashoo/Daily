///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s,res="";cin>>s;
	bool bl=false;
	for(int i=0;i<s.size();i++){
		int cnt=0;char c=s[i];
		while(s[i]==c)i++,cnt++;
		i--;
		if(cnt>=2){
			if(bl)bl=false,res+=s[i];
			else bl=true,res+=s[i],res+=s[i];
		}
		else bl=false,res+=s[i];
	}
	cout<<res;
}
