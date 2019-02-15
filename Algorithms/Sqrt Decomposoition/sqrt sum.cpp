#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=1e5+7;
const int SQ=320;
vector<pair<pair<int,int>,pair<int,int> > > bc[SQ];// {r,l},{k,id}
int res[MAXN],a[MAXN];

int32_t main(){
	int n,arr[n];
	int SQ=sqrt(n);
	int A[SQ];
	
	//start preprocess
	for(int i=0;i<n;i++)
		A[i/SQ]+=arr[i];
	//end preprocess
	
	//Query ?
		int l,r;//input
		int ans=0;//answer
		int p=l;//our position on arr
		while(p%SQ){
			ans+=arr[p];
			p++;//our step size is 1
		}
		int R=((p/SQ)*SQ)+SQ;//right-most index of A[p/SQ]
		while(R<r){
			ans+=A[p/SQ];
			p+=SQ;//we are walking on A so our step size is SQ
			R=((p/SQ)*SQ)+SQ;//calculating R again
		}
		while(p<=r){
			ans+=arr[p];
			p++;//we came back to arr so step size is 1
		}
	//end of ?
	
	//Query #
		int val,id;//new value and id of changed index on arr
				   // actully input
		A[id/SQ]-=arr[id];
		arr[id]=val;
		A[id/SQ]+=arr[id];
	//
}