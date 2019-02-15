#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,arr[100007],sum,c[100007];
set<ll> s;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){cin>>arr[i];sum+=arr[i];}
	if(sum%2||n<2){cout<<"NO"<<endl;return 0;}
	s.clear();
	ll tot=sum;
	for(int i=n;i>0;i--){
		s.insert(tot);
		if(tot==sum/2){cout<<"YES"<<endl;return 0;}
		if(s.count(sum/2+arr[i])){cout<<"YES"<<endl;return 0;}
		tot-=arr[i];
	}
	tot=sum;
	s.clear();
	for(int i=1;i<=n;i++){
		s.insert(tot);
		if(tot==sum/2){cout<<"YES"<<endl;return 0;}
		if(s.count(sum/2+arr[i])){cout<<"YES"<<endl;return 0;}
		tot-=arr[i];	
	}
	cout<<"NO"<<endl;
}