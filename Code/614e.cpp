///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
string res;
int n,a[maxn],cnt,g;

void makestring(){
	string s;
    for(char i='a';i<'a'+n;i++)
        for(int j=0;j<a[i]/g/2;j++)
            s+=i;
    for(char i='a';i<'a'+n;i++)
		if((a[i]/g)%2)
			s+=i;
    for(char i='a'+n-1;i>='a';i--)
        for(int j=0;j<a[i]/g/2;j++)
            s+=i;
    while(g--){
		res+=s;
        reverse(s.begin(),s.end());
    }
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i='a';i<'a'+n;i++){
        cin>>a[i];
        g=__gcd(g,a[i]);
        cnt+=(a[i]%2);
    }
    cout<<g*(cnt<2)<<endl;
	makestring();
	cout<<res;
}
