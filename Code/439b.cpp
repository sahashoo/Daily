#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,x,arr[110000],ans;
int main(){
	cin>>n>>x;
	for(ll i=0;i<n;i++)	cin>>arr[i];
	sort(arr,arr+n);
	for(ll i=0;i<n;i++){
		ans+=arr[i]*x;
		x--;
		if(x<1)	x=1;
	}
	cout<<ans<<endl;
}