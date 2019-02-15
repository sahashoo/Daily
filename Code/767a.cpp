#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
bool arr[MAXN];
int n,N;
int main(){
	cin>>n;
	N=n;
	for(int i=1;i<=n;++i){
		int a;
		cin>>a;
		arr[a]=true;
		while(arr[N])	cout<<N--<<" ";
		cout<<endl;
	}
}