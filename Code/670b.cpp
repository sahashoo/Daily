#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,k,arr[990000],ans;

int main(){
	cin>>n>>k;
	k--;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		if(k>=i)	k=k-i;
	}
	cout<<arr[k];
}