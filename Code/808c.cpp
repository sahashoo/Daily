#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
int n,cup[150],v;
pair<int,int> arr[150];

int32_t main(){
	cin>>n>>v;
	for(int i=0;i<n;i++){
		cin>>arr[i].q;
		arr[i].w=i;
		if(arr[i].q%2==1)cup[i]=(arr[i].q/2)+1,v-=(arr[i].q/2)+1;
		else cup[i]=arr[i].q/2,v-=arr[i].q/2;
		if(v<0)return cout<<-1,0;
	}
	if(v>0){
		sort(arr,arr+n);
		for(int i=n-1;i>=0;i--){
			if(v<=0)break;
			if(v<=arr[i].q-cup[arr[i].w]){
				cup[arr[i].w]=cup[arr[i].w]+v;
				v=0;
			}
			if(v>arr[i].q-cup[arr[i].w]){
				v-=arr[i].q-cup[arr[i].w];
				cup[arr[i].w]=arr[i].q;
			}
		}
	}
	if(v>0)return cout<<-1,0;
	for(int i=0;i<n;i++)cout<<cup[i]<<" ";
}