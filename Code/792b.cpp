#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;
int a[maxn];
vector<int>pos;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
	pos.resize(n);
    for(int i=0;i<n;i++)pos[i]=i+1;
	for(int i=0;i<k;i++)cin>>a[i];
	int ldr=0;
	for(int i=0;i<k;i++){
		int nwpos=(ldr+a[i])%n;
		cout<<pos[nwpos]<<" ";
        pos.erase(pos.begin()+nwpos);
        n--;ldr=nwpos%n;
    }
}