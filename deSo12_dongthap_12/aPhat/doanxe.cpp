#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n,p,w[N];
double l,v[N],dp[N];


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("doanxe.inp","r",stdin);
    freopen("doanxe.out","w",stdout);
    cin>>n>>p>>l;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    fill(dp+1,dp+N+1,inf);
    for(int i=1;i<=n;i++){
        inr sum=0;
        double vmin=inf;
        for(int j=i;j>0;j--){
            sum+=w[j];vmin=min(vmin,v[j]);
            if(sum<=p)dp[i]=min(dp[i],dp[j-1]+l/vmin);
            else break;
        }
    }
    //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    //cout<<endl;
    cout<<setprecision(2)<<fixed<<dp[n];
}
