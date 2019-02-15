#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,k,arr[maxn],bdn,bgr;

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		arr[a]++;
	}
	int t=n/k;
	for(int i=1;i<=k;i++){
		if(arr[i]<t)bgr+=t-arr[i];
		if(arr[i]>t)bdn+=arr[i]-t;
	}
	cout<<max(bdn,bgr)<<endl;
}
