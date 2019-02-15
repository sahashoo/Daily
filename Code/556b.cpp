#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d;

int main(){
	cin>>n>>d;
	for(ll i=1;i<n;i++){
		ll a;
		cin>>a;
		if(i!=(a+d*(i&1?1:-1)+n)%n){cout<<"No"<<endl;return 0;}
	}
	cout<<"Yes"<<endl;
}