#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int p[5],r[5],l[5],s[5];
int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=1;i<=4;i++){
        cin>>l[i%4]>>s[i%4]>>r[i%4]>>p[i%4];
    }
    for(int i=0;i<4;i++){
        if(l[i]==1&&(p[i]==1||p[(i+3)%4]==1))return cout<<"YES",0;
        if(r[i]==1&&(p[i]==1||p[(i+1)%4]==1))return cout<<"YES",0;
        if(s[i]==1&&(p[i]==1||p[(i+2)%4]==1))return cout<<"YES",0;
    }
    cout<<"NO";
}
