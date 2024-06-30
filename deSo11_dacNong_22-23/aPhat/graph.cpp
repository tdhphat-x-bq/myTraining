#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 10003
#define mod 1e9+7
#define inf 1e18
using namespace std;

vector<inr>adj[M];
inr visited[M],d[M];
string ok;

void dfs(int u){
    if(ok == "YES")return;
    visited[u]=1;
    for(int v:adj[u]){
        if(visited[v] == 0){
            d[v]=d[u]+1;
            dfs(v);
        }else if((d[v]-d[u])%2==0){
            ok="YES";
            return;
        }
    }
}


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("graph.inp","r",stdin);
    freopen("graph.out","w",stdout);
    int t;cin>>t;
    while(t--){
        ok="NO";
        for(int i=0;i<M;i++)adj[i].clear();
        fill(visited,visited+M,0);
        fill(d,d+M,1);
        int n,m;cin>>n>>m;
        for(int i=1;i<=m;i++){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                dfs(i);
            }
            if(ok=="YES")break;
        }
        cout<<ok<<endl;
    }
}

