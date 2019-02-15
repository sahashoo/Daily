#include<bits/stdc++.h>
using namespace std;
int n,k,arr[550][550],sum,a;

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)for(int j=0;j<k-1;j++)a++,arr[i][j]=a;
	for(int i=0;i<n;i++)for(int j=k-1;j<n;j++)a++,arr[i][j]=a;
	for(int i=0;i<n;i++)sum+=arr[i][k-1];
	cout<<sum<<endl;
	for(int i=0;i<n;i++){for(int j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
}