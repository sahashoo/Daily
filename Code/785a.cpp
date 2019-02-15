#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int ans,n;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        if(s[0]=='T')ans+=4;
        if(s[0]=='C')ans+=6;
        if(s[0]=='O')ans+=8;
        if(s[0]=='D')ans+=12;
        if(s[0]=='I')ans+=20;
    }
    cout<<ans;

}
