#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,z;
int main(){
	cin>>n>>m>>z;
	cout<<z/(m*n/(__gcd(n,m)));
}