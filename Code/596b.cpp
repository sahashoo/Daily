#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,b,ans;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		ans+=abs(a-b);
		b=a;
	}
	cout<<ans;
}