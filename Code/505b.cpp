#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[20],tre[20],mi,ma,r,l,x,ans,num,sum;

void che(ll d){
    if(!d){
        mi=1e9+10,ma=0,num=0,sum=0;
		for(ll i=1;i<=n;i++){
			if(tre[i]){
				num++;
				sum+=a[i];
				ma=max(ma,a[i]);
				mi=min(mi,a[i]);
			}
		}
		if(ma-mi>=x&&num>=2&&sum>=l&&sum<=r) ans++;
		return ;
    }
    tre[d]=0;
    che(d-1);
    tre[d]=1;
    che(d-1);
}

int main(){
    cin>>n>>l>>r>>x;
    for(ll i=1;i<=n;i++) cin>>a[i];
    che(n);
    cout<<ans<<endl;
}