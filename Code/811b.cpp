#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e4+7;
int n,m,p[maxn];
bool ch[maxn];

int32_t main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=m;i++){
		int l,r,x,s=0;cin>>l>>r>>x;
		for(int j=l;j<=r;j++)if(p[j]<p[x])s++;
		if(s+l==x)ch[i]=true;
		else ch[i]=false;
	}
    for(int i=1;i<=m;i++){
        if(ch[i])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
