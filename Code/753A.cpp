#include<bits/stdc++.h>
using namespace std;
int n,x=2;
int main(){
	cin>>n;
	while(x*(x+1)/2<=n){
		x++;
	}
	cout<<x-1<<endl;
	for(int i=0;i<x-1;i++){
		if(i==x-2){
			cout<<n-(x*(x-1)/2)+x-1<<endl;
			break;
		}
		cout<<i+1<<" ";
	}
}