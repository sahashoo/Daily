#include<bits/stdc++.h>
using namespace std;
const int maxn=17;
int mxl[maxn],mxr[maxn],start,n,m;

int solve(int i,bool left){
	if(i==start){
		if(left)return mxr[i];
		else return(m+1-mxl[i]);
	}
	if(left){
        return min(m+2+solve(i-1,0),solve(i-1,1)+((mxr[i])*2)+1);
	}
	else{
        return min(m+2+solve(i-1,1),solve(i-1,0)+(((m+1)-mxl[i])*2)+1);
	}
}

int main(){
    cin>>n>>m;
	start=n-1;
	for(int i=0;i<n;i++){
		mxr[i]=0;
		mxl[i]=m+1;
		for(int j=0;j<m+2;j++){
			char c;cin>>c;
			if(c=='1'){
				start=min(start,i);
				mxr[i]=max(mxr[i],j);
				mxl[i]=min(mxl[i],j);
			}
		}
	}
	cout<<solve(n-1,1);
}
