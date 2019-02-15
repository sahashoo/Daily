///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7;
int n;
pair<int,int> a[maxn],b[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].S>>a[i].F;
		b[i]=a[i];
	}
	sort(b,b+n,greater<pair<int,int> >());
	// cout<<"\n\n**********\n\n";
	// for(int i=0;i<n;i++)cout<<b[i].S<<" "<<b[i].F<<endl;	
	for(int i=0;i<n;i++)if(a[i].S!=a[i].F)return cout<<"rated",0;	
	for(int i=0;i<n;i++)if(a[i]!=b[i])return cout<<"unrated",0;
	cout<<"maybe";
}
