#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
using namespace std;

inr n,m;
inr a[M][M],f[M][M],x[M][M];
inr ans[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("messages.inp","r",stdin);
    freopen("messages.out","w",stdout);

    cin>>n>>m;
    for(inr i=1;i<=n;i++){
        for(inr j=1;j<=m;j++){
            cin>>a[i][j];
            f[i][j] = 1000000;
        }
    }
    for(inr i=1;i<=n;i++){
        f[i][1] = a[i][1];
        for(inr j=2;j<=m;j++){
            for(inr k=0;k<=i;k++){
                inr sum = f[k][j-1] + a[i-k][j];
                if(sum < f[i][j]){
                    f[i][j] = sum;
                    x[i][j] = k;
                }
            }
        }
    }
    inr res = 1000000,jmin = 0;
    for(inr i=1;i<=m;i++){
        if(res > f[n][i]){
            res = f[n][i];
            jmin = i;
        }
    }
    cout<<res<<endl;
    inr i=n;
    while(jmin > 0){
        ans[jmin] = i-x[i][jmin];
        i = x[i][jmin];
        jmin--;
    }
    for(inr i=1;i<=m;i++)cout<<ans[i]<<endl;

}
