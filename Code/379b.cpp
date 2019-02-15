#include<bits/stdc++.h>
using namespace std;
int n,a;

int main(){
	cin>>n>>a;
	for(int i=0;i<a;i++)cout<<"PRL";
	for(int i=1;i<n;i++){
		cout<<"R";
		cin>>a;
		for(int j=0;j<a;j++)cout<<"PLR";
	}
}