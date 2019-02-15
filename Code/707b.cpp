#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,d[110000],w[110000],u[110000],v[110000],mi=9e9;
void input(){
	cin>>n>>m>>k;
	for(ll i=0;i<m;i++)	cin>>u[i]>>v[i]>>w[i];
	for(ll i=0;i<k;i++){
		ll a;
		cin>>a;
		d[a]=1;
	}
}
int main(){
    input();
	for(ll i=0;i<m;i++){
		if(d[u[i]]+d[v[i]]==1)	mi=min(mi,w[i]);
	}
	if(mi==9e9)cout<<"-1"<<endl;
	else cout<<mi<<endl;
}