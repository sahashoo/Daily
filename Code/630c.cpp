#include<bits/stdc++.h>
using namespace std;
long long sum,n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)sum+=pow(2,i);
	cout<<sum;
}