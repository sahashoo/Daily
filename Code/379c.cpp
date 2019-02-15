#include<bits/stdc++.h>
using namespace std;
int n,a[300007];
pair<int,int> p[300007];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){cin>>p[i].first;p[i].second=i;}
	sort(p,p+n);
	a[p[0].second]=p[0].first;
	for(int i=1;i<n;i++)a[p[i].second]=max(a[p[i-1].second]+1,p[i].first);
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}