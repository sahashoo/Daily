#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e9+7;
int val,vla;
bool a;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>vla>>val;
    for(int i=1;i<maxn;i++){
        //cout<<vla<<"**"<<val<<endl;
        if(a==false){
            if(vla>=i)vla-=i,a=true;
            else return cout<<"Vladik",0;
        }
        else{
            if(val>=i)val-=i,a=false;
            else return cout<<"Valera",0;
        }
    }

}
