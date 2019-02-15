#include<bits/stdc++.h>
using namespace std;
long long n;

int main(){
	cin>>n;
	for(int a=0;a<1e3;a++){
		for(int b=0;b<1234;b++){
			if(a*1234567+b*123456<=n)if((n-a*1234567-b*123456)%1234==0){cout<<"YES";return 0;}
		}
	}
	cout<<"NO";
}