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
int dp[maxn],how[maxn];
set<int>st;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,res=0;cin>>n;
	string s;cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]<='Z')st.clear();
		else st.insert(s[i]);
		res=max(res,(int)st.size());
	}
	cout<<res;
}
