#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
using namespace std;

inr n,a[N],t[N],ans,res;
vector<inr>mang;

void update(inr id,inr val){
    while(id < N){
        t[id] = max(t[id],val);
        id += id & (-id);
    }
}

inr get(inr id){
    inr res = 0;
    while(id >0 ){
        res=max(res,t[id]);
        id -= id&(-id);
    }
    return res;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mang.push_back(a[i]);
    }
    sort(mang.begin(),mang.end());
    mang.erase(unique(mang.begin(),mang.end()),mang.end());
    for(int i=1;i<=n;i++){
        a[i] = lower_bound(mang.begin(),mang.end(),a[i]) - mang.begin() +1;
    }
    for(int i=1;i<=n;i++){
        inr tmp = get(a[i]-1);
        ans = max(ans,tmp+1);
        update(a[i],tmp+1);
    }
    for(int i=0;i<N;i++)t[i] = 0;
    for(int i=n;i>0;i--){
        inr tmp = get(a[i]-1);
        res = max(res,tmp+1);
        update(a[i],tmp+1);
    }

    cout<<n-max(res,ans);
}

