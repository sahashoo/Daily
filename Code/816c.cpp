#include<bits/stdc++.h>
#define q first
#define w second
using namespace std;
const int maxn=105;
int n,m,g[maxn][maxn],g2[maxn][maxn],minc[maxn],minr[maxn],tact,minc2[maxn],minr2[maxn],tact2;

int32_t main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        minc[i]=500007;
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            g2[i][j]=g[i][j];
            minc[i]=min(minc[i],g[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            g[i][j]-=minc[i];
        }
    }
    for(int j=1;j<=m;j++){
        minr[j]=500007;
        for(int i=1;i<=n;i++){
            minr[j]=min(minr[j],g[i][j]);
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            g[i][j]-=minr[j];
            if(g[i][j]!=0)return cout<<-1,0;
        }
    }
    for(int i=1;i<=n;i++)tact+=minc[i];
    for(int i=1;i<=m;i++)tact+=minr[i];
    for(int j=1;j<=m;j++){
        minr2[j]=500007;
        for(int i=1;i<=n;i++){
            minr2[j]=min(minr2[j],g2[i][j]);
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            g2[i][j]-=minr2[j];
        }
    }
    for(int i=1;i<=n;i++){
        minc2[i]=500007;
        for(int j=1;j<=m;j++){
            minc2[i]=min(minc2[i],g2[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            g2[i][j]-=minc2[i];
        }
    }
    for(int i=1;i<=m;i++)tact2+=minr2[i];
    for(int i=1;i<=n;i++)tact2+=minc2[i];
    if(tact<tact2){
        cout<<tact<<endl;
        for(int i=1;i<=n;i++)while(minc[i]>0)cout<<"row "<<i<<endl,minc[i]--;
        for(int i=1;i<=m;i++)while(minr[i]>0)cout<<"col "<<i<<endl,minr[i]--;
    }
    else{
        cout<<tact2<<endl;
        for(int i=1;i<=m;i++)while(minr2[i]>0)cout<<"col "<<i<<endl,minr2[i]--;
        for(int i=1;i<=n;i++)while(minc2[i]>0)cout<<"row "<<i<<endl,minc2[i]--;
    }
}
