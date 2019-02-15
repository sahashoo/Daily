///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int ind=1;ind<=n;ind++){
		int x,y,res=0;cin>>x>>y;
		for(int i=1;i*i<=x;i++)
			if(x%i==0)
				res+=(a[i]<ind-y)+(i*i!=x&&a[x/i]<ind-y),
				a[i]=a[x/i]=ind;
		cout<<res<<'\n';
	}
}
