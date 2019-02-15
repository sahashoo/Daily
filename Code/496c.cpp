#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s[105];

int32_t main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<n;i++){
        if(s[i]>s[i+1]){
            int col=0;
            for(int j=0;j<m;j++)if(s[i][j]>s[i+1][j]){col=j;break;}
            for(int t=1;t<=n;t++)s[t][col]='a';
            ans++;
            i=0;
        }
    }
    cout<<ans;
}
