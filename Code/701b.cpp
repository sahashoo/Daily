#include<bits/stdc++.h>
using namespace std;
long long n,m;
set<int> a,b;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a.insert(x);b.insert(y);
		cout<<(n-a.size())*(n-b.size())<<" ";
	}
}