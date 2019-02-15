#include<bits/stdc++.h>
using namespace std;
int m,d,ans;
int main(){
	cin>>m>>d;
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)	m=31;
	else if(m==2) m=28;
	else m=30;
	ans=(m-8+d)/7;
	if((m-8+d)%7>0)	ans++;
	cout<<ans+1<<endl;
}