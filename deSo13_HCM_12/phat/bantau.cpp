#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n,k;
inr a[N],dp[M][M];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bantau.inp","r",stdin);
    freopen("bantau.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++)dp[i][j]=inf;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        inr sum=0,hmax=0;
        for(int j=i;j>0;j--){
            sum+=a[j];
            hmax=max(hmax,a[j]);

        }
        dp[i][0] = min(dp[i][0],hmax*i-sum);

    }
    for(int i=1;i<=k;i++){

        for(int j=1;j<=n;j++){
            inr sum=0,hmax=0;
            for(int k=j;k>0;k--){
                sum+=a[k];
                hmax=max(hmax,a[k]);
                dp[j][i] = min(dp[j][i],dp[k-1][i-1] + (j-k+1)*hmax-sum);
            }
        }
    }
    cout<<dp[n][k];
}
