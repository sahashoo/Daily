#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N=1e5+7;
int res[N],bst;
pair<int,int>a[N];

int32_t main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].F>>a[i].S;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int ind=lower_bound(a,a+n,make_pair(a[i].F-a[i].S,0))-a-1;
		if(ind<0)res[i]=1;
		else res[i]=1+res[ind];
		bst=max(bst,res[i]);
	}
	cout<<n-bst;
}