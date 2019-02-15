#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
	cin>>n;
	if(n==1||n==0||n==-1)cout<<-1;
	else cout<<n<<" "<<n+1<<" "<<n*(n+1);
}