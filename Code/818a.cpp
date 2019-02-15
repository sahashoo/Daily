#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int n,k,a;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	a=n/(2*(k+1));
	cout<<a<<" "<<a*k<<" "<<n-a*(k+1);
	
}
