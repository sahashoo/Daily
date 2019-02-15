#include<bits/stdc++.h>
using namespace std;
int sum,summi,summa,n,mi[35],ma[35],ans[35];

void mak(int sum1){
	for(int i=0;i<n;i++){
		if(sum1+ma[i]-mi[i]<=sum){sum1+=ma[i];sum1-=mi[i];ans[i]=ma[i];}
		else if(sum1+ma[i]-mi[i]>sum&&sum>sum1){ans[i]=mi[i]+sum-sum1;sum1=sum;}
		if(sum1==sum)return ;
	}
}

int main(){
	cin>>n>>sum;
	for(int i=0;i<n;i++){cin>>mi[i]>>ma[i];summa+=ma[i];summi+=mi[i];ans[i]=mi[i];}
	if(summi<=sum&&summa>=sum)cout<<"YES"<<endl;
	else{cout<<"NO";return 0;}
	mak(summi);
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
}