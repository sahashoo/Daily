///age yekam bekeshi be ham moshkel khasi pish nemid ._.
#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
int n,cnt[maxn],k;
string pas;
set<string> st;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        if(st.count(s)==0)cnt[s.size()]++,st.insert(s);
    }
    for(int i=1;i<107;i++)cnt[i]+=cnt[i-1];
    cin>>pas;
    int pl=pas.size();
    int mn=(((cnt[pl-1])/k)*5)+cnt[pl-1]+1;
    int mx=(((cnt[pl])/k)*5)+cnt[pl];
    if(cnt[pl]%k==0)mx-=5;
    cout<<mn<<" "<<mx;
}
