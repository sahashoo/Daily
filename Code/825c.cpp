///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,a[maxn],cnt;
double k;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		double q=(double)a[i]/2;
		if(q<=k)k=max(k,(double)a[i]);
		else{
			while(q>k){
				cnt++;
				k*=2;
			}
			k=max(k,(double)a[i]);
		}
	}
	cout<<cnt;
}
