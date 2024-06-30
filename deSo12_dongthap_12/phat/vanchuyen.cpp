#include <bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define inf 1e18
#define mod 1e9+7
using namespace std;

vector<pair<inr,inr>>adj[N];
inr n,m,s,t;

void dijkstra(inr s){
    //mang luu khoang cach duong di
    vector<inr>d(n+1,inf);
    priority_queue<pair<inr,inr>,vector<pair<inr,inr>>,greater<pair<inr,inr>>>pq;
    pq.push({0,s});
    d[s]=0;
    while(!pq.empty()){
        pair<inr,inr>t = pq.top();pq.pop();
        inr u=t.second,kc=t.first;
        if(d[u] < kc)continue;
        for(auto it:adj[u]){
            inr v=it.first,w=it.second;
            if(d[u] + w < d[v]){
                d[v]=d[u]+w;
                pq.push({d[v],v});
            }
        }
    }
    cout<<d[t];
}

main(){
    freopen("vanchuyen.inp","r",stdin);
    freopen("vanchuyen.out","w",stdout);
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        inr ai,bi,ci;cin>>ai>>bi>>ci;
        adj[ai].push_back({bi,ci});
        adj[bi].push_back({ai,ci});
    }
    dijkstra(s);
}
