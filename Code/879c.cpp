///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
int bit[12][3];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<=11;i++)bit[i][1]=1;
	for(int i=0,x;i<n;i++){
		char c;cin>>c>>x;
		for(int i=0;i<11;i++)
			for(int j=0;j<2;j++){
				int tmp=x&(1<<i);
				if(c=='^')bit[i][j]^=(tmp!=0);
				else if(c=='|')bit[i][j]|=(tmp!=0);
				else bit[i][j]&=(tmp!=0);
			}
	}
	cout<<"2\n| ";
	int tmp=0;
	for(int i=0;i<10;i++)
		if(bit[i][0]==bit[i][1])
			tmp+=(1<<i);
	cout<<tmp<<"\n^ ";
	tmp=0;
	for(int i=0;i<10;i++)
		if(bit[i][1]==0)tmp+=(1<<i);
	cout<<tmp;
}
