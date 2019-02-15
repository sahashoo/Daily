#include<bits/stdc++.h>
using namespace std;
long long k;

main(){
	cin>>k;
	if(k<3)return cout<<-1,0;
	if(k%2==0)return cout<<k*k/4-1<<" "<<k*k/4+1,0;
	cout<<(k*k-1)/2<<" "<<(k*k+1)/2;
}