///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=1e5+7;
int ind[MAXN],b[MAXN];
pair<int,int>a[MAXN];
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,l,r;cin>>n>>l>>r;
	for(int i=1;i<=n;i++)cin>>a[i].S;
	for(int i=1;i<=n;i++)cin>>a[i].F,ind[i]=a[i].F;
	sort(a+1,a+n+1);
	b[1]=l;
	int num=b[1]-a[1].S;
	for(int i=2;i<=n;i++){
		int tmp=a[i].S+num;
		if(tmp>=r)return cout<<-1,0;
		else b[i]=(tmp<l?l:tmp+1);
		num=b[i]-a[i].S;
	}
	for(int i=1;i<=n;i++)cout<<b[ind[i]]<<" ";
}
