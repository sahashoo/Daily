#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,m,arr[maxn];
string s[maxn],ans;
bool mark[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=m;i++)cin>>arr[i];
    ans=s[arr[1]];
    mark[arr[1]]=true;
    for(int i=2;i<=m;i++){
        mark[arr[i]]=true;
        if(ans.size()!=s[arr[i]].size())return cout<<"No",0;
        for(int j=0;j<ans.size();j++)if(s[arr[i]][j]!=ans[j])ans[j]='?';
    }
    for(int i=1;i<=n;i++){
        if(mark[i]==false&&ans.size()==s[i].size()){
            bool check=true;
            for(int j=0;j<ans.size();j++)if(s[i][j]!=ans[j]&&ans[j]!='?')check=false;
            if(check)return cout<<"No",0;
        }
    }
    cout<<"Yes"<<endl<<ans;
}
