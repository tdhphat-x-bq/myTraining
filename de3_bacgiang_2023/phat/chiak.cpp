#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1000000000
using namespace std;

inr n,k,res;
inr a[N];
inr p[N];
unordered_map<inr,inr>cnt;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("chiak.inp","r",stdin);
    freopen("chiak.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i] = (p[i-1] + a[i] + (inr)1e9 * k ) % k;
    }
    for(int i=1;i<=n+1;i++){
        cnt[p[i]]++;
    }
    for(auto it:cnt){
           // cout<<it.first<<" "<<it.second<<endl;
        int d=it.second;
        res+= d*(d-1)/2;
    }
    cout<<res;
}


