#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7;
const int mod=1e9+7;
int dp1[maxn],dp2[maxn],ans,fact[maxn];
string s;

void precom(){
    for(int i=0;i<s.size();i++){
        dp1[i]+=dp1[i-1];
        if(s[i]=='(')dp1[i]++;
    }
    for(int i=s.size()-1;i>=0;i--){
        dp2[i]+=dp2[i+1];
        if(s[i]==')')dp2[i]++;
    }
    fact[0]=1;
	for(int i=1;i<maxn;i++)fact[i]=(fact[i-1]*i)%mod;
}

int exp(int x,int y){
    if(!y)return 1;
    int j=exp(x,y/2);
    j=(j*j)%mod;
    if(y%2)j=(j*x)%mod;
    return j;
}

int32_t main() {
    cin>>s;
	precom();
	for(int i=0;i<s.size();i++){
        if(s[i]!='('||dp2[i]==0)continue;
		int c=(fact[dp1[i]+dp2[i]-1]*exp((fact[dp1[i]]*fact[dp2[i]-1])%mod,mod-2))%mod;
        ans=(ans+c)%mod;
	}
	cout<<ans<<endl;
}

