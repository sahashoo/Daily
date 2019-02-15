#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=55;
int n,arr[maxn][maxn];
int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>arr[i][j];
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            bool ch=false;
            if(arr[x][y]!=1){
                for(int s=1;s<=n;s++){
                    for(int t=1;t<=n;t++){
                        if(ch)break;
                        if(arr[x][s]+arr[t][y]==arr[x][y]&&(s!=y||x!=t))ch=true;
                    }
                    if(ch)break;
                }
                if(ch==false)return cout<<"No",0;
            }
        }
    }

    cout<<"Yes"<<endl;
}
