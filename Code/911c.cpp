#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >mp;
int a[3];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=0;i<3;i++)cin>>a[i];
	sort(a,a+3);
	for(int j=0;j<a[0];j++){
		for(int i=1;i<=a[2]+a[0]+a[1];i++)
			if(i%a[0]!=j)mp[i%a[1]].push_back(i);
		if(mp.size()<=2){
			if(mp.size()<=1)return cout<<"YES",0;
			for(auto xx:mp){
				bool c=true;
				vector<int>x=xx.second;
				if(x.size())
					for(int i=1;i<x.size();i++)
						if(x[0]%a[2]!=x[i]%a[2])c=false;
				if(c)return cout<<"YES",0;
			}
		}
	}
	cout<<"NO";
}
