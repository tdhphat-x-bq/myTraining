#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define M 1003
using namespace std;

int n;
int a[N],b[N],dp[M][M];
int res;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("paflower.inp","r",stdin);
    freopen("paflower.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!(a[i] == -1 and b[j] == -1)){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            res=max(res,dp[i][j]);
        }
    }
    cout<<res;
}
