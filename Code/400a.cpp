#include<bits/stdc++.h>
using namespace std;
const int N=110;
int t,a[15];
string s[N];
vector<int>v[N];

int32_t main(){
    cin>>t;
    for(int i=0;i<t;i++){
		cin>>s[i];
        for(int j=1;j<13;j++){
            memset(a,0,sizeof(a));
            if(12%j==0){
                for(int k=0;k<12;k++)if(s[i][k]=='X')a[k%j]++;
                for(int k=0;k<12;k++){
					if(a[k]==12/j){
						v[i].push_back(12/j);
						break;
                    }
                }
            }
        }
    }
	for(int i=0;i<t;i++){
        cout<<v[i].size()<<" ";
        sort(v[i].begin(),v[i].end());
        for(auto x:v[i])cout<<x<<"x"<<12/x<<" ";
        cout<<endl;
	}
}