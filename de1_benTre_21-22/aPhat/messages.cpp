#include<bits/stdc++.h>
#define int long long
using namespace std;

int res[1000006],x[103][103];

main() {
    freopen("messages.inp","r",stdin);
    freopen("messages.out","w",stdout);

    int n,m;
    cin>>n>>m;

    int a[n][m],f[n][m];

    for(int i = 0;i<n;i ++){
        for(int j = 0; j< m;j++){
            cin>>a[i][j];
            if(j == 0){
                f[i][j] = a[i][j];
            }else{
                f[i][j] = 1e9;
            }
        }
    }
    for(int i=1;i<m;i++){
        f[0][i] = a[0][i];
        if(f[0][i-1] < f[0][i]){
            f[0][i] = f[0][i-1];
            x[0][i] = 1;
        }
    }

    for(int i=1;i<n;i++){
        for(int j = 1;j <m; j++){
            f[i][j] = a[i][j];
            if(f[i][j] > f[i][j-1]){
                f[i][j] = f[i][j-1];
                x[i][j] = i+1;
            }
            for(int k = 0; k < i; k++){
                int sum = f[k][j-1] + a[i-k-1][j];
                if(f[i][j] > sum){
                    f[i][j] = sum;
                    x[i][j] = k+1;
                }
            }
        }
    }
    int jmin=0,kq=1e9;
    for(int i=0;i<m;i++){
        if(kq > f[n-1][i]){
            kq = f[n-1][i];
            jmin = i;
        }
    }
    cout<<kq<<endl;
    //cout<<jmin;
    int i=n;
    while(i>0){
        res[jmin] = i-x[i-1][jmin];
        i = x[i-1][jmin];
        jmin--;
    }
    for(int i=0;i<m;i++)cout<<res[i]<<endl;
}

