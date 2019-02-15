#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn],l[maxn],r[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	r[n-1]=n-1;
	for(int i=n-2;i>=0;i--)r[i]=(a[i]<=a[i+1]?r[i+1]:i);
	for(int i=1;i<n;i++)   l[i]=(a[i-1]>=a[i]?l[i-1]:i);
	while(m--){
		int L,R;cin>>L>>R;
		cout<<(r[L-1]>=l[R-1]?"Yes":"No")<<'\n';
	}
}