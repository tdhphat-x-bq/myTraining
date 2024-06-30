#include<bits/stdc++.h>
#define inr long long
#define N 1000006
using namespace std;

struct qua{
    inr ai,wi;
};

inr n,res,bit[N];
qua q[N];
vector<inr>mang;

void update(inr idx,inr delta){
    while(idx <= N){
        bit[idx] =max(bit[idx],delta);
        idx += idx & (-idx);
    }
}

inr get(inr idx){
    inr res = 0;
    while(idx >0){
        res =max(res,bit[idx]);
        idx -= idx & (-idx);
    }
    return res;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("qua.inp","r",stdin);
    freopen("qua.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q[i].ai>>q[i].wi;
        mang.push_back(q[i].ai);
    }
    sort(mang.begin(),mang.end());
    mang.erase(unique(mang.begin(),mang.end()),mang.end());
    for(int i=1;i<=n;i++){
        q[i].ai = lower_bound(mang.begin(),mang.end(),q[i].ai) - mang.begin() +1;
        //cout<<q[i].ai<<" ";
    }

    for(int i=1;i<=n;i++){
        inr tmp = get(q[i].ai-1);
        res=max(res,tmp + q[i].wi);
        update(q[i].ai,tmp + q[i].wi);
    }
    cout<<res;
}


