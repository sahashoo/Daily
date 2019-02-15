#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7;
vector<int>pos;
pair<int,int>arr[maxn];

int32_t main(){
	int n,d,a,b;cin>>n>>d>>a>>b;
	for(int i=0;i<n;i++){
		int l,h;cin>>l>>h;
		arr[i].F=l*a+b*h;
		arr[i].S=i+1;
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++)if(d>=arr[i].F)d-=arr[i].F,pos.push_back(arr[i].S);
	cout<<pos.size()<<endl;
	for(int i=0;i<pos.size();i++)cout<<pos[i]<<" ";
}
