#include<bits/stdc++.h>
using namespace std;
int n,m,g;
int main(){
	cin>>n>>m;
	while((n>0&&m>1)||(n>1&&m>0)){
		if(m>=n){
			m=m-2;
			n--;
			g++;
		}
		else{
			m--;
			n=n-2;
			g++;
		}
	}
	cout<<g;
}