#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n,m,a,b;cin>>n>>m>>a>>b;
    if(m*a>b)cout<<(n/m)*b+min((n%m)*a,b);
	else cout<<n*a;
}