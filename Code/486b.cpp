#include<bits/stdc++.h>
using namespace std;
int n,m,a[107][107],b[107][107];

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>b[i][j];
			if(b[i][j]==0){
				for(int o=0;o<n;o++)a[o][j]=1;
				for(int o=0;o<m;o++)a[i][o]=1;
			}
			if(a[i][j]!=1)a[i][j]=2;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			bool ch=false;
			for(int o=0;o<n;o++)if(a[o][j]==2)ch=true;
			for(int o=0;o<m;o++)if(a[i][o]==2)ch=true;
			if(ch!=b[i][j]){cout<<"NO";return 0;}
		}
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){cout<<a[i][j]-1<<" ";}
		cout<<endl;
	}
}