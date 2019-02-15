///age yekam bekeshi be ham moshkel khasi pish nemid ._.
#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e3+7;
int n,m,ans,mns=maxn;
string s,t;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s>>t;
    for(int i=0;i<=m-n;i++){
        int cnt=0;
        for(int j=0;j<n;j++)if(t[i+j]!=s[j])cnt++;
        if(mns>cnt){
            mns=cnt;
            ans=i;
        }
    }
    cout<<mns<<endl;
    for(int i=0;i<n;i++)if(s[i]!=t[ans+i])cout<<i+1<<" ";
}
