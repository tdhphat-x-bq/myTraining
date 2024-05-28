#include<bits/stdc++.h>
#define int long long
using namespace std;

int c[1000006];

void sieve() {
    for(int i=0;i<1e6;i++){
        c[i] = 1;
    }
    for(int i=2;i<=sqrt(1e6);i++){
        for(int j=i*i; j<=1e6;j+=i){
            c[j] += i;
            if(i != sqrt(j)){
                c[j] += j/i;
            }
        }
    }
}

main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ghh.inp","r",stdin);
    freopen("ghh.out","w",stdout);
    sieve();
    int n;cin>>n;

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(c[x] >= x)cout<<1<<endl;
        else cout<<0<<endl;
    }
}
