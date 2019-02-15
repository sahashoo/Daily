#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,a[N];

int32_t main(){
	cin>>n;
	for(int i=1;i<=2*n;i++)cin>>a[i];
	sort(a+1,a+(2*n)+1);
	if(a[n]!=a[n+1])cout<<"YES";
	else cout<<"NO";
}