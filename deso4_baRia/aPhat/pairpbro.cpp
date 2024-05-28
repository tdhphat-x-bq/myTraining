#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define M 103
using namespace std;

int n,k,res;
int p[N+1];

void sieve(){
    p[0] = p[1] = 0;
    for(int i=2;i<=N;i++)p[i] = 1;

    for(int i=2;i<=sqrt(N);i++){
        if(p[i] == 1){
            for(int j=i*i;j<=N;j+=i)p[j] = 0;
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("pairpbro.inp","r",stdin);
    freopen("pairpbro.out","w",stdout);
    sieve();
    cin>>n>>k;
    for(int i=2;i<=n - k;i++){
        if(p[i] == 1 and p[i+k] == 1)res++;
    }
    cout<<res;
}
