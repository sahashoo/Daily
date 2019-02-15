#include<bits/stdc++.h>
using namespace std;
vector<long long> arr;
long long  n,k;

int main(){
	cin>>n>>k;
	for(long long i=1;i<=sqrt(n);i++){
		if(n%i==0){
		arr.push_back(i);
		if(i!=n/i)arr.push_back(n/i);
		}
	}
	sort(arr.begin(),arr.end());
	if(arr.size()<k)cout<<"-1"<<endl;
	else cout<<arr[k-1]<<endl;
}