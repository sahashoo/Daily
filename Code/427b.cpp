#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t,c,arr[310000],ans,p=-10;

int main(){
	cin>>n>>t>>c;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>t)	p=i;
		else{
			if(i>c-2){
				if(p<i-c+1)	ans++;
			}
		}
	}
	cout<<ans<<endl;
}