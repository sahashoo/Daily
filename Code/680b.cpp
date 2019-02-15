#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
pair<int,int>arr[150];

int main(){
	cin>>n>>a;
	a--;
	for(int i=0;i<n;i++){
		cin>>arr[i].first;
	}
	for(int i=0;i<n;i++){
		if(arr[a-abs(a-i)].first==1&&a+abs(a-i)>n-1&&arr[a-abs(a-i)].second==0){
			ans++;
			arr[a-abs(a-i)].second++;
		}	 
		if(arr[a+abs(a-i)].first==1&&a-abs(a-i)<0&&arr[a+abs(a-i)].second==0){
			ans++;
			arr[a+abs(a-i)].second++;
		}
		if(arr[a-abs(a-i)].first==1&&arr[a+abs(a-i)].first==1&&arr[a-abs(a-i)].second==0&&arr[a+abs(a-i)].second==0){
			ans+=2;
			arr[a+abs(a-i)].second++;
			arr[a-abs(a-i)].second++;
		}
	}
	if(arr[a].first==1)	ans--;
	cout<<ans;
}