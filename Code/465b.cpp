#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mi,n,arr[1500],ans;
int main(){
	cin>>n;
	for(ll i=0;i<n;i++){cin>>arr[i];if(arr[i])	mi=i;}
	for(ll i=0;i<mi+1;i++){
		if(arr[i])	ans++;
		if(arr[i-1]&&!arr[i])	ans++;
	}
	cout<<ans<<endl;
}