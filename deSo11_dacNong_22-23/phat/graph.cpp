#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

vector<inr>adj[10001];
int visited[10001],l[10001];
string ok;

void dfs(inr u){
    visited[u] = 1;
    for(inr v:adj[u]){
        if(visited[v] == 0){
            l[v]=l[u]+1;
            dfs(v);
        }else if((l[v]-l[u])%2==0){
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
    int q;cin>>q;
    while(q--){
        for(int i=1;i<=10000;i++)adj[i].clear();
        ok="NO";
        fill(visited+1,visited+10001,0);
        fill(l+1,l+10001,1);
        inr n,m;cin>>n>>m;
        for(int i=1;i<=m;i++){
            inr a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(visited[i] == 0)dfs(i);
            if(ok=="YES")break;
        }
        cout<<ok<<endl;
    }

}
