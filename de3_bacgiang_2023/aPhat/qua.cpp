#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define M 103
using namespace std;
const int li=5e5+1;

int n;
int dp[N],a[N],w[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("qua.inp","r",stdin);
    freopen("qua.out","w",stdout);

    cin >> n;
    for (int i=1; i<=n; i++) cin >>a[i] >>w[i];

    dp[0] = 0;a[n+1] = 1000000000;
    int res=0;
    for(int i=1;i<=n+1;i++){
        dp[i] = w[i];
        for(int j=0;j<i;j++){
            if(a[i] > a[j])dp[i] = max(dp[i],dp[j]+w[i]);
        }
        res=max(res,dp[i]);
    }
    cout<<res;
}


