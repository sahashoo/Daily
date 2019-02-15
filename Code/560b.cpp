#include<bits/stdc++.h>
using namespace std;
int a[3],b[3];

int main(){
	for(int i=0;i<3;i++)cin>>a[i]>>b[i];
	if(max(a[1],a[2])<=a[0]&&b[1]+b[2]<=b[0]){cout<<"YES";return 0;}
	swap(a[1],b[1]);
	if(max(a[1],a[2])<=a[0]&&b[1]+b[2]<=b[0]){cout<<"YES";return 0;}
	swap(a[2],b[2]);
	if(max(a[1],a[2])<=a[0]&&b[1]+b[2]<=b[0]){cout<<"YES";return 0;}
	swap(a[1],b[1]);
	if(max(a[1],a[2])<=a[0]&&b[1]+b[2]<=b[0]){cout<<"YES";return 0;}
	swap(a[0],b[0]);
	if(max(a[1],a[2])<=a[0]&&b[1]+b[2]<=b[0]){cout<<"YES";return 0;}
	swap(a[1],b[1]);
	if(max(a[1],a[2])<=a[0]&&b[1]+b[2]<=b[0]){cout<<"YES";return 0;}
	swap(a[2],b[2]);
	if(max(a[1],a[2])<=a[0]&&b[1]+b[2]<=b[0]){cout<<"YES";return 0;}
	swap(a[1],b[1]);
	if(max(a[1],a[2])<=a[0]&&b[1]+b[2]<=b[0]){cout<<"YES";return 0;}
	cout<<"NO";
}