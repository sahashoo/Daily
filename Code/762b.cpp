#include<bits/stdc++.h>
using namespace std;
long long a,b,c,eq,val,m;
pair<long long,string>arr[500000];

int main(){
	cin>>a>>b>>c>>m;
	for(int i=0;i<m;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr,arr+m);
	for(int i=0;i<m;i++){
		if(a&&arr[i].second=="USB"){a--;eq++;val+=arr[i].first;}
		else if(b&&arr[i].second=="PS/2"){b--;eq++;val+=arr[i].first;}
		else if(c){c--;eq++;val+=arr[i].first;}
	}
	cout<<eq<<" "<<val;
}