///age yekam bekeshi be ham moshkel khasi pish nemid ._.
#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
int n,cnt[maxn],p;
string s;

int32_t main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='B'){
            //cout<<i<<endl;
            p++;
            cnt[p]++;
            for(int j=i+1;j<n;j++){
                if(s[j]=='B')cnt[p]++;
                if(s[j]=='W'||j==n-1){i=j;break;}
            }
        }
    }
    cout<<p<<endl;
    for(int i=1;i<=p;i++)cout<<cnt[i]<<" ";
}
