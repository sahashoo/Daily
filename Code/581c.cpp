#include<bits/stdc++.h>
using namespace std;
int n,k,a[100007],ans;

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans+=a[i]/10;
		a[i]=10-(a[i]%10);
	}
	sort(a,a+n);
	int i=0,x=a[0];
	while(k>=x&&i<n){
		k-=a[i];
		if(a[i]!=0)ans++;
		i++;x=a[i];
	}
	ans+=k/10;
	ans=min(ans,n*10);
	cout<<ans;
}