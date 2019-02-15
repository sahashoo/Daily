#include<bits/stdc++.h>
using namespace std;
int n,m,ans,w[1007];

int main(){
	cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ans+=min(w[x],w[y]);
    }
	cout<<ans;
}