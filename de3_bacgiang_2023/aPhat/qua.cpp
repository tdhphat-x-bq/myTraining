#include<bits/stdc++.h>
#define inr long long
#define N 1000006
using namespace std;

struct gift{
    inr a,w,id;
};

gift b[N+3];
inr n;
inr dp[N],t[N],res;
map<inr,inr>M;
vector<inr>mang;

bool cmp_label(gift x,gift y){
    return x.a < y.a;
}

bool cmp_id(gift x,gift y){
    return x.id < y.id;
}

inr get(inr x){
    inr res=0;
    while(x>0){
        res=max(res,t[x]);
        x -= (x & (-x));
    }
    return res;
}

void update(inr x ,inr delta){
    while(x <= N){
        t[x] =max(t[x],delta);
        x += (x & (-x));
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("qua.inp","r",stdin);
    freopen("qua.out","w",stdout);

    cin >> n;
    for (inr i=1; i<=n; i++) {
        cin>>b[i].a>>b[i].w;
        b[i].id = i;
    }
    sort(b+1,b+n+1,cmp_label);
    // cout<<M.size()<<endl;
    // for(inr i=1;i<=n;i++)cout<<b[i].a<<" "<<b[i].w<<" "<<b[i].id<<endl;
    // cout<<endl;
    for(inr i=1;i<=n;i++){
        mang.push_back(b[i].a);
    }
    mang.erase(unique(mang.begin(),mang.end()),mang.end());
    for(inr i=1;i<=n;i++){
        b[i].a = lower_bound(mang.begin(),mang.end(),b[i].a) - mang.begin() +1;

    }
    // cout<<endl;
    // for(inr i=1;i<=n;i++)cout<<b[i].a<<" "<<b[i].w<<" "<<b[i].id<<endl;
    // cout<<endl;
    sort(b+1,b+n+1,cmp_id);
    // for(inr i=1;i<=n;i++)cout<<b[i].a<<" "<<b[i].w<<" "<<b[i].id<<endl;
    // cout<<endl;
    for(inr i=1;i<=n;i++){
        inr x= get(b[i].a-1);
        dp[i] = x+b[i].w;
        res=max(res,dp[i]);
        update(b[i].a,dp[i]);
    }
    cout<<res;

}


