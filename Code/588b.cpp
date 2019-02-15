#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int main(){
	cin>>n;
	for(ll i=1;i*i<=n;i++)	if(n%(i*i)==0){n=n/i;i=1;}
	cout<<n<<endl;
}