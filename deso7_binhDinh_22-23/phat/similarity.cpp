#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
using namespace std;

inr a[N],b[N],h[N];

vector<inr> solve(inr *x,inr *y,inr n,inr m){
    vector<inr>ans(3);
    ans[0] = 0;ans[1] = -1;ans[2] = -1;
    for(inr i=n;i>0;i--){
        map<inr,inr>mp;
        for(inr j=1;j<=n-i+1;j++){
            inr v = x[j+i-1] - x[j-1];
            mp.insert({v,j});
        }
        for(inr j=1;j<=m-i+1;j++){
            inr u = y[j+i-1] - y[j-1];
            auto it = mp.find(u);
            if(it != mp.end()){
                ans[0] = i;
                ans[1] = it->second;
                ans[2] = j;
                return ans;

            }
        }
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("similarity.inp","r",stdin);
    freopen("similarity.out","w",stdout);
    inr n,m;

    h[0] = 1;
    for(inr i=1;i<N;i++)h[i] = h[i-1] * 317;
    cin>>n;
    for(inr i=1;i<=n;i++){
        inr x;
        cin>>x;
        a[i] = a[i-1] + h[x];
    }
    cin>>m;
    for(inr i=1;i<=m;i++){
        inr x;
        cin>>x;
        b[i] = b[i-1]+h[x];
    }
    vector<inr>res;
    if(n<m)res=solve(a,b,n,m);
    else {
        res=solve(b,a,m,n);
        swap(res[1],res[2]);
    }
    cout<<res[0]<<" "<<res[1]<<" "<<res[2];
}

