#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
const int INF=1e9+7;
int width,n,data[maxn][maxn],m[maxn],split[maxn];
string s[maxn];

int justify(){
	for(int i=1;i<=n;i++){
		data[i][i]=width-s[i].size();
		for(int j=i+1;j<=n;j++)data[i][j]=data[i][j-1]-s[j].size()-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(data[i][j]<0)data[i][j]=INF;
			else data[i][j]=pow(data[i][j],2);
		}
	}
	for(int i=n;i>0;i--){
		m[i]=data[i][n];
		split[i]=n;
		for(int j=n;j>i;j--){
			if(data[i][j-1]==INF)continue;
			if(m[i]>m[j]+data[i][j-1]){
				m[i]=m[j]+data[i][j-1];
				split[i]=j;
			}
		}
	}
	return m[1];
}

int main(){
	cin>>n>>width;
	for(int i=1;i<=n;i++)cin>>s[i];
	justify();
	cout<<m[1]<<endl;
	for(int i=1;i<=n;i++){
		cout<<s[i]<<" ";
		if(split[i]!=split[i+1])cout<<endl;
	}
}