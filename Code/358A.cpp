#include<bits/stdc++.h>
using namespace std;
long long n,x,y,a[1500];

int main(){
    cin>>n;
    for(int i=0;i<n;i++)	cin>>a[i];
    for(int i=0;i<n;i++){
		for(int j=i+2;j<n;j++){ 
			if ((a[j]>a[i]&&a[j]>a[i+1])||(a[j]<a[i]&&a[j]<a[i+1])) x++;
			else y++;
		}
		if(x&&y){cout<<"yes";return 0;}
	}
	cout<<"no";
	return 0;
}