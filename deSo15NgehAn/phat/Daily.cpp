#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

struct daily{
    inr si,fi,ci,ri;
};

inr n,m;
inr a[N];
daily d[N];

bool check(inr mid){
    for(int i=1;i<=m;i++){
        inr kc=mid/d[i].ci,p=d[i].si,cnt=0;
        while(true){
            inr tmp=p;
            p=lower_bound(a+p+1,a+n+1,a[p]+kc)-a;
            if(a[p]-a[tmp]>kc)p--;
            if(p==tmp)return false;
            if(p>=d[i].fi)break;
            cnt++;
        }
        if(cnt>d[i].ri)return false;
    }
    return true;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("daily.inp","r",stdin);
    freopen("daily.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    inr l=0,r=0,ans;
    for(int i=1;i<=m;i++){
        cin>>d[i].si>>d[i].fi>>d[i].ci>>d[i].ri;
        r=max(r,(a[d[i].fi]-a[d[i].si])*d[i].ci);
    }

    while(l<=r){
        inr mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<ans;
}
