#include<bits/stdc++.h>
using namespace std;
int n,arr[105];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				cout<<j+1<<" "<<j+2<<endl;
				swap(arr[j],arr[j+1]);
			}
		}
	}
}