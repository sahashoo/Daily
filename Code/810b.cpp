#include<bits/stdc++.h>
#define q first
#define w second
using namespace std;
long long n,f,ans,k[100007],l[100007],arr[100007],ac;

int main(){
	cin>>n>>f;
	for(long long i=0;i<n;i++){
		cin>>k[i]>>l[i];
		if(l[i]<=k[i])ans+=l[i];
		if(l[i]>k[i]){
			ans+=k[i];
			arr[ac]=min(l[i]-k[i],k[i]);
			ac++;
		}
	}
	long long siz=min(f,ac);
	sort(arr,arr+ac);
	for(long long i=1;i<=siz;i++){
		ans+=arr[ac-i];
	}
	cout<<ans;
}