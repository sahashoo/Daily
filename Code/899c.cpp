///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
int dif;
vector<int>vec;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	if(n%4==0){
		dif=0;
		for(int i=1;i<=n;i++)
			if(i%4==0||i%4==1)vec.push_back(i);
	}
	if(n%4==1){
		dif=1;
		for(int i=1;i<=n;i++)
			if(i%4==2||i%4==1)vec.push_back(i);
	}
	if(n%4==2){
		dif=1;
		for(int i=1;i<=n;i++)
			if(i%4==3||i%4==2)vec.push_back(i);
	}
	if(n%4==3){
		dif=0;
		vec.push_back(3);
		for(int i=4;i<=n;i++)
			if(i%4==0||i%4==3)vec.push_back(i);
	}
	cout<<dif<<"\n"<<vec.size()<<" ";
	for(int x:vec)cout<<x<<" ";
}
