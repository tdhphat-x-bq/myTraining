#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
using namespace std;

struct so{
    inr ele,li;
};

bool cmp(so a,so b){
    if(a.ele == b.ele) return a.li < b.li;
    return a.ele < b.ele;
}


inr n,q;
inr a[N],b[N],maxr[N],maxl[N],l[N],dp[N];
stack<inr>sl,sr;
so s[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("seq.inp","r",stdin);
    //freopen("seq.out","w",stdout);

    cin>>n>>q;
    for(inr i=1;i<=n;i++){
        cin>>a[i];
        s[i].ele = a[i];
    }
    a[0] = a[n+1] = 1e9+1;

    sl.push(0);sr.push(n+1);

    for(inr i  = 1;i<=n;i++){
        while(a[i] >= a[sl.top()]) sl.pop();
        maxl[i] = sl.top();
        sl.push(i);
    }
    for(inr i=n;i>0;i--){
        while(a[i] >= a[sr.top()]) sr.pop();
        maxr[i] = sr.top();
        sr.push(i);
    }
    for(inr i=1;i<=n;i++){
        l[i] = (i-maxl[i])+ (maxr[i]-i)-1;
        s[i].li = l[i];
        //cout<<a[i]<<" "<<a[maxl[i]]<<" "<<a[maxr[i]]<<" "<<l[i]<<endl;
    }

    sort(s+1,s+n+1,cmp);
    for(inr i=1;i<=n ;i++){
        dp[i] = max(dp[i-1],s[i].li);
        b[i] = s[i].ele;
        //cout<<b[i]<<" ";
        cout<<s[i].ele<<" "<<dp[i]<<endl;
    }
    //cout<<endl;
    while(q--){
        int x;cin>>x;
        int tmp = upper_bound(b+1,b+n+1,x) - b -1;
        //cout<<tmp<<endl;
        if(tmp == 0)cout<<0<<endl;
        else{
            cout<<dp[tmp]<<endl;
        }
    }
}
