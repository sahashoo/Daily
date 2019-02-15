#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
pair<int,pair<int,int> >a[200007];

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i].second.first;
	for(int i=0;i<n;i++){
		cin>>a[i].second.second;
		a[i].first=a[i].second.first-a[i].second.second;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(i<k)ans+=a[i].second.first;
		else ans+=min(a[i].second.first,a[i].second.second);
	}
	cout<<ans;
}
