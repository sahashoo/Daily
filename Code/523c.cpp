#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
int l,r,k,sefr;
string s,t;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s>>t;
    for(l=0,k=0;l<t.size()&&k<s.size();l++)if(t[l]==s[k])k++;
    for(r=t.size()-1,k=s.size()-1;r>=0&&k>=0;r--)if(t[r]==s[k])k--;
    cout<<max(sefr,r-l+2);
}
