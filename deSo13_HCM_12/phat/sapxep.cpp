#include <bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define inf 1e18
#define mod 1e9+7
using namespace std;

struct sx{
    inr ele,l,r;
};

sx s[N];
inr n;
inr a[N],b[N];
priority_queue<inr>lon; // tang dan
priority_queue<inr,vector<inr>,greater<inr>>nho; // giam dan
inr pos[N],change[4*N],laz[4*N];

void push(inr id,inr l,inr m,inr r){
    if(laz[id]){
        change[id*2]+=((m-l+1)*laz[id]);
        change[id*2+1]+=((r-m)*laz[id]);
        laz[id*2]+=laz[id];
        laz[id*2+1]+=laz[id];
        laz[id]=0;
    }
}

void update(inr id,inr l,inr r,inr u,inr v,inr x ){
    if(l > v or r < u)return;
    if(l >= u and r <= v){
        change[id]+=(r-l+1)*x;
        laz[id]+=x;
        return;
    }
    inr m=(l+r)/2;
    push(id,l,m,r);
    update(id*2,l,m,u,v,x);
    update(id*2+1,m+1,r,u,v,x);
    change[id]=change[id*2]+change[id*2+1];
}

inr get(inr id,inr l,inr r,inr u){
    if(l>u or r<u)return 0;
    if(l == u and r == u){
        return change[id];
    }
    inr m=(l+r)/2;
    push(id,l,m,r);
    inr t1=get(id*2,l,m,u),t2=get(id*2+1,m+1,r,u);
    return t1+t2;
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("sapxep.inp","r",stdin);
    freopen("sapxep.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        pos[a[i]]=i;
        s[a[i]].ele = i;
        s[a[i]].l = i-1;
        s[a[i]].r = i+1;
        //update(1,1,n,i,i,0);
    }
    sort(b+1,b+n+1,greater<inr>());
    for(int i=1;i<=n/2;i++){
        lon.push(b[i]);
    }
    for(int i=n/2+1;i<=n;i++)nho.push(b[i]);
    for(int i=1;i<n;i++){
        inr ans=0,tmp=0,vitri=0;
        if(i%2==1){
            tmp=nho.top();
            vitri = get(1,1,n,pos[nho.top()]);
            ans=abs(pos[nho.top()] + vitri - nho.top());
            update(1,1,n,1,s[nho.top()].l,1);
            s[a[s[nho.top()].l]].r = s[nho.top()].r;
            s[a[s[nho.top()].r]].l = s[nho.top()].l;
            nho.pop();
        }else{
            tmp=lon.top();
            vitri = get(1,1,n,pos[lon.top()]);
            ans=abs(pos[lon.top()] + vitri - lon.top());
            update(1,1,n,s[lon.top()].r,n,-1);
            s[a[s[lon.top()].l]].r = s[lon.top()].r;
            s[a[s[lon.top()].r]].l = s[lon.top()].l;
            lon.pop();
        }
        cout<<ans<<endl;
        // for(int i=1;i<=n;i++){
        //     cout<<s[a[i]].ele<<" "<<s[a[i]].l<<" "<<s[a[i]].r<<endl;
        // }
    }
    cout<<0;
}
