#include<bits/stdc++.h>
using namespace std;
int n,arr[110000];
int main(){
	cin>>n;
	for(int i=1;i<n+1;i++){
		if(i<=90)for(int j=2;j<=i;j++)if((i+1)%j==0){arr[i]=2;break;}
		if(i>90)for(int j=2;j*j<=i+1;j++)if((i+1)%j==0){arr[i]=2;break;}
	}
	if(n>2)cout<<2<<endl;
	else cout<<1<<endl;
	for(int i=1;i<=n;i++){
		if(arr[i]==2)cout<<arr[i]<<" ";
		else cout<<1<<" ";
	} 
}