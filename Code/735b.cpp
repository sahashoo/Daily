#include<bits/stdc++.h>
using namespace std;
int n,n1,n2,arr[100007],sum1,sum2;
double ans;

int main(){
	cin>>n>>n1>>n2;
	for(int i=1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	if(n1>n2)swap(n1,n2);
	for(int i=n;i>=n-n1-n2+1;i--){
		if(n-n1+1<=i)ans+=(double)arr[i]/n1;
		else ans+=(double)arr[i]/n2;
	}
	cout<<setprecision(8)<<ans;
}