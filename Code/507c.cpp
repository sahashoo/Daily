#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll alt[55];
vector<ll>anc;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int h;ll n;cin>>h>>n;
	alt[0]=1;for(int i=0;i<51;i++)alt[i]=alt[i-1]+(1LL<<i);
	n+=alt[h-1];
	ll x=n;anc.push_back(x);
	while(x!=1)x/=2,anc.push_back(x);
	ll res=0,v=1;
	bool smt=false;
	// for(int i=0;i<anc.size();i++)cout<<anc[i]<<" ";
	// cout<<endl;
	while(v!=n){
		vector<ll>ftr;
        for(int i=0;i<h;i++){
            ftr.push_back(v);
            if(smt)v=v*2+1;
			else v=v*2;
			smt=!smt;
		}
		if(v==n){res+=h;break;}
		ftr.push_back(v);
		reverse(ftr.begin(),ftr.end());
        for(int i=1;i<=h;i++){
            if(anc[i]==ftr[i]){
                res+=alt[i-1]+h-i+1;
                h=i-1;v=ftr[i-1];
				if(v==ftr[i]*2)v=ftr[i]*2+1,smt=false;
                else v=ftr[i]*2,smt=true;
                break;
            }
        }
	}
	cout<<res<<endl;
}