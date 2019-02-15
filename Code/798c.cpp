#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int n,g,ans,cnt;

int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        g=gcd(g,a);
        if(a%2==1)cnt++;
        else ans+=(cnt/2)+2*(cnt%2?1:0),cnt=0;
    }
    ans+=(cnt/2)+2*(cnt%2?1:0);
    cout<<"YES"<<endl;
    if(g==1)cout<<ans<<endl;
    else cout<<0<<endl;
}
