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
	string s;
	int sf=0,fs=0,n;
	cin>>n>>s;
	for(int i=1;i<s.size();i++){
		if(s[i]=='F'&&s[i-1]=='S')sf++;
		else if(s[i]=='S'&&s[i-1]=='F')fs++;
	}
	if(sf>fs)cout<<"YES";
	else cout<<"NO";
}
