#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

struct seq{
    inr ele,l;
};

bool cmp(seq a,seq b){
    if(a.ele == b.ele)return a.l < b.l;
    return a.ele < b.ele;
}

inr n,q;
inr a[N],dp[N],sl[N],sr[N],b[N];
seq s[N];
stack<inr>maxl,maxr;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seq.inp","r",stdin);
    freopen("seq.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i].ele = a[i];
    }
    a[0] = a[n+1] = inf;
    maxl.push(0);maxr.push(n+1);
    for(int i=1;i<=n;i++){
        while(a[maxl.top()] <= a[i]) maxl.pop();
        sl[i] = maxl.top();
        maxl.push(i);
    }
    for(int i=n;i>0;i--){
        while(a[maxr.top()] <= a[i]) maxr.pop();
        sr[i] = maxr.top();
        maxr.push(i);
    }
    //for(int i=1;i<=n;i++)cout<<sl[i]<<" "<<sr[i]<<endl;
    //cout<<endl;
    for(int i=1;i<=n;i++){
        s[i].l = sr[i]-i+i-sl[i]-1;
    }

    sort(s+1,s+n+1,cmp);
    //for(int i=1;i<=n;i++)cout<<s[i].ele<<" "<<s[i].l<<endl;
    for(int i=1;i<=n;i++){
        dp[i] = max(dp[i-1],s[i].l);
        b[i]=s[i].ele;
    }
    while(q--){
        int x;cin>>x;
        inr tmp= upper_bound(b+1,b+n+1,x) - b -1;
        cout<<dp[tmp]<<endl;
    }
}
