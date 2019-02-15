#include<bits/stdc++.h>
using namespace std;
int n,s,arr[110000];
int main(){
	cin>>n;
	s=n;
	for(int i=0;i<n;i++)	cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		arr[i-1]+=arr[i-2];
		if(arr[i]<arr[i-1]){
			s--;
			arr[i]=0;
		}
	}
	cout<<s;
}