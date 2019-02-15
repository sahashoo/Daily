#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ans,arr[2][105];

int main(){
	cin>>n>>m;
	if(m<=n){
		x=m;
		while(x>=0||y<=n){if(x>=0&&y<=n&&y+x>0){arr[0][ans]=x;arr[1][ans]=y;ans++;}x--;y++;}
	}
	else{
		y=n;
		while(y>=0||x<=m){if(y>=0&&x<=m&&y+x>0){arr[0][ans]=x;arr[1][ans]=y;ans++;}y--;x++;}
	}
	cout<<ans<<endl;
	for(int i=0;i<ans;i++)cout<<arr[0][i]<<" "<<arr[1][i]<<endl;
}