#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
string s;
int c;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    s='$'+s;
    for(int i=1;i+i<s.size();i++)if(s[i]!=s[s.size()-i])c++;
    if((c<=1&&(s.size()-1)%2)||c==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
