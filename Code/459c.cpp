#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+7;
int n,k,d,a[N][N];

bool pw(){
	int dcp=d,tmp=1;
	while(tmp<=n&&dcp)tmp*=k,dcp--;
	return n>tmp;
}

void FILL(int id){
	int ind=id;
	for(int i=d-1;i>=0;i--)a[i][ind]=id%k,id/=k;
}

int32_t main(){
	cin>>n>>k>>d;
	if(pw())return cout<<-1,0;
	for(int i=0;i<n;i++)FILL(i);
	for(int i=0;i<d;i++){
		for(int j=0;j<n;j++)cout<<a[i][j]+1<<" ";
		cout<<endl;
	}
}