#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
int a,n,arr[MAXN];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<n-1;i++){
		while(arr[i]>=arr[i+1]){
			a++;
			arr[i+1]++;
		}
	}
	cout<<a;
}