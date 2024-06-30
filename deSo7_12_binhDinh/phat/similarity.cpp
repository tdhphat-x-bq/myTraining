#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr h[N];

vector<inr> solve(inr a[],inr b[],inr n ,inr m){
    vector<inr>ans(3);
    ans[1]=ans[2]=-1;
    ans[0] = 0;
    for(int i=n;i>0;i--){
        map<inr,int>mp;
        for(int j=1;j<=n-i+1;j++){
            inr v = a[i+j-1]-a[j-1];
            mp.insert({v,j});
        }
        for(int j=1;j<=m-i+1;j++){
            inr v = b[i+j-1] - b[j-1];
            auto it = mp.find(v);
            if(it != mp.end()){
                //cout<<i<<" "<<it->second<<" "<<j<<endl;
                ans[0] = i;
                ans[1] = it -> second;
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
    h[0]=1;
    for(int i=1;i<N;i++)h[i]=h[i-1]*317;
    inr n,m;
    cin>>n;
    inr a[n+1];
    for(int i=1;i<=n;i++){
        inr x;cin>>x;
        a[i] = a[i-1]+h[x];
    }
    cin>>m;
    inr b[m+1];
    for(int i=1;i<=m;i++){
        inr x;cin>>x;
        b[i] = b[i-1]+h[x];
    }
    vector<inr>res(3);
    if(n<m){
        res=solve(a,b,n,m);
    }else {
        res=solve(b,a,m,n);
        swap(res[1],res[2]);
    }
    cout<<res[0]<<" "<<res[1]<<" "<<res[2];
}
