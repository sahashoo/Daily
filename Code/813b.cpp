///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e18;
int x,y,l,r,mx=-1;
set<int>s;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>x>>y>>l>>r;
	int pwy=1,pwx=1;
    while(pwx<=maxn/x){
		//cout<<"HERE";
		pwy=1;
        while(pwy<=maxn/y)s.insert(pwy+pwx),pwy*=y;
        s.insert(pwy+pwx);
		pwx*=x;
    }
	pwy=1;
	while(pwy<=maxn/y)s.insert(pwy+pwx),pwy*=y;
    s.insert(pwx+pwy);
    int ans=-1,v=l-1;
    bool ok=1;
    for(set<int>::iterator x=s.begin();x!=s.end();x++){
        if((*x)>v&&(*x)<=r)ans=max(ans,(*x)-v-1),v=(*x);
        if((*x)>r){ans=max(ans,r-v);ok=false;break;}
    }
    if(ok)ans=max(ans,r-v);
    cout<<max((int)0,ans);
}
