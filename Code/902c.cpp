///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=3e5+7;
int par[MAXN],pr1[MAXN],a[MAXN],h,sum,ind;
bool c,ch;
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>h;
	for(int i=0;i<=h;i++)cin>>a[i],sum+=a[i];
	bool ch=false;
	for(int i=0;i<h;i++){
		if(a[i]>1&&a[i+1]>1){
			ch=true;
			break;
		}
	}
	if(ch==false)return cout<<"perfect",0;
	for(int i=0;i<=h;i++){
		for(int j=1;j<=a[i];j++)
			par[j+ind]=ind;
		ind+=a[i];
	}
	ind=0;
	for(int i=0;i<=h;i++){
		for(int j=1;j<=a[i];j++)
			pr1[j+ind]=ind-c,c=false;
		ind+=a[i];
		if(a[i]>1)c=true;
	}
	cout<<"ambiguous\n"<<endl;
	for(int i=1;i<=sum;i++)cout<<par[i]<<" ";cout<<endl;
	for(int i=1;i<=sum;i++)cout<<pr1[i]<<" ";cout<<endl;
}
