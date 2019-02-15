#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=3e6+7;
int a[MAXN],cnt[MAXN];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0,x;i<n;i++)
		cin>>x,a[x]++;
	for(int i=1;i<MAXN;i++){
		if(a[i]!=0){
			for(int x=i;x<MAXN;x+=i)
				if(x/i!=i)cnt[x]+=a[i]*a[x/i];
				else cnt[x]+=a[i]*(a[i]-1);
		}
	}
	for(int i=1;i<MAXN;i++)cnt[i]+=cnt[i-1];
	int q;cin>>q;
	while(q--){
		int p;cin>>p;
		cout<<(n*(n-1)-cnt[p-1])<<'\n';
	}
}