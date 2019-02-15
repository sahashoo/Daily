#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,arr[110000],k,b;

int main(){
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		if(i>0&&arr[i]<arr[i-1]){k++;b=i;}
	}
	if(k==0) cout<<0;
	else if(k==1&&arr[n-1]<=arr[0]) cout<<n-b;
	else cout<<-1;
}