#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
pair<int,int>pos[5];

int32_t main(){
	for(int i=0;i<3;i++)cin>>pos[i].F>>pos[i].S;
	sort(pos,pos+3);
	
	if((pos[0].F==pos[1].F&&pos[1].F==pos[2].F)||(pos[0].S==pos[1].S&&pos[1].S==pos[2].S))return cout<<1,0;
	
	if(pos[0].F==pos[1].F)
		if(pos[2].S<=pos[0].S||pos[2].S>=pos[1].S)return cout<<2,0;
	
	if(pos[1].F==pos[2].F)
		if(pos[0].S<=pos[1].S||pos[0].S>=pos[2].S)return cout<<2,0;

	for(int i=0;i<3;i++)swap(pos[i].F,pos[i].S);
	sort(pos,pos+3);

	if(pos[0].F==pos[1].F)
		if(pos[2].S<=pos[0].S||pos[2].S>=pos[1].S)return cout<<2,0;
	
	if(pos[1].F==pos[2].F)
		if(pos[0].S<=pos[1].S||pos[0].S>=pos[2].S)return cout<<2,0;
	
	cout<<3;
}