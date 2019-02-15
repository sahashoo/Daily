#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long n,arr[maxn],mrk[maxn];

void Output(){
	for(int j=0;j<n;j++)cout<<mrk[j];
	cout<<endl;
}

void subset(int i){
	if(i==n)return Output();
	subset(i+1);
	mrk[i]=1;
	subset(i+1);
	mrk[i]=0;
}

int main(){
	cin>>n;
	//for(int i=0;i<n;i++)cin>>arr[i];
	subset(0);
}