#include<bits/stdc++.h>
using namespace std;
int n,m,arr[110000];
set<int> s;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	for(int i=n;i>=1;i--){
		s.insert(arr[i]);
		arr[i]=s.size();
	}
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		cout<<arr[a]<<endl;
	}
}