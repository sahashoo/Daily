#include<bits/stdc++.h>
using namespace std;
long long a[100007],n,t,ans,ch[5];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ch[1]=1;
	t=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])ch[t]++;
		else t++,ch[t]++;
		if(t==4)break;
	}
	ans=1;
	for(int i=1;i<=3;i++){
		//cout<<ch[i]<<" ";
		if(ch[i])ans*=ch[i];
		ch[5]+=ch[i];
		if(ch[5]>=3){
			if(i==2&&ch[1]==1)ans=((ch[2]-1)*(ch[2])/2);
			if(i==2&&ch[1]==2)ans=ch[2];
			if(i==1)ans=((ch[1]-1)*(ch[1]-2)*(ch[1])/6);
			//cout<<ch[5]<<" ";
			break;
		}
	}
	cout<<ans;
}