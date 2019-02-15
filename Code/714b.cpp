#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
set<ll>s;
vector<ll>arr;

int main(){
	cin>>n;
	for(ll i=0;i<n;i++){
		ll a;
		cin>>a;
		if(!s.count(a)){s.insert(a);arr.push_back(a);}
	}
	if(s.size()>=4){cout<<"NO";return 0;}
	if(s.size()<=2){cout<<"YES";return 0;}
	else{
		sort(arr.begin(),arr.end());
		if(2*arr[1]==arr[0]+arr[2])	cout<<"YES";
		else	cout<<"NO";
	}
}