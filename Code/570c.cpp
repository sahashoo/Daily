#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
string s;
int main(){
    cin>>n>>m>>s;
    for(int i=0;i<s.size();i++)if(s[i]=='.'&&s[i-1]=='.')ans++;
    for(int i=1;i<=m;i++){
        int x;char c;
        cin>>x>>c;
        if(s[x-1]=='.'&&c!='.'){
            if(s[x-2]=='.') ans--;
            if (s[x]=='.') ans--;
            s[x-1]='x';
        }
		else if(c=='.'&&s[x-1]!='.'){
            if(s[x-2]=='.') ans++;
            if(s[x]=='.') ans++;
            s[x-1]='.';
        }
        cout<<ans<<endl;
    }
}