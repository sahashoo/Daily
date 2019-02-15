#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[555],ans,n,k;

int main(){
	cin>>n>>k;
	arr[0]=k;
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]+arr[i-1]<k){
			ans+=k-arr[i]-arr[i-1];
			arr[i]+=k-arr[i]-arr[i-1];
		}
	}
	cout<<ans<<endl;
	for(ll i=1;i<=n;i++)	cout<<arr[i]<<" ";
}