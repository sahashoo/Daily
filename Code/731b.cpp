#include<bits/stdc++.h>
using namespace std;
int n,arr[200007];

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n-1;i++){
		if(arr[i]<0){cout<<"NO";return 0;}
		if(arr[i]%2==1)arr[i+1]--;
	}
	if(arr[n-1]%2==1||arr[n-1]<0){cout<<"NO";return 0;}
	cout<<"YES";
}