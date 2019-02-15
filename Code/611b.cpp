#include<bits/stdc++.h>
using namespace std;
long long a,b,t,ans;
int main(){
	cin>>a>>b;
    for(int i=1;i<=60;i++){
		for(int j=0;j<i;j++){
			t=(2LL<<i)-(1LL<<j)-1;
			if(a<=t&&t<=b)ans++;
		}
	}
    cout<<ans;
}