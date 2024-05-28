#include<bits/stdc++.h>
#define int long long
using namespace std;

int p[1000006];

void sieve(){
    for(int i=0;i<1000006;i++){
        p[i] = 1;
    }
    p[0] = p[1] =0;

    for(int i=2;i<=sqrt(1e6); i++){
        if(p[i] == 1){
            for(int j = i*i; j<= 1e6; j+=i){
                p[j] = 0;
            }
        }
    }
}

bool check(int n, int h){
    int sum = 0;
    while(n > 0){
        sum+=(n%10);
        n/=10;
    }
    return (sum == h);
}

main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("docao.inp","r",stdin);
    freopen("docao.out","w",stdout);
    sieve();
    int n,h,cnt=0;
    cin>>n>>h;
    for(int i=2; i<= n;i++){
        if(p[i] == 1){
            if(check(i,h)){
                cnt++;
                cout<<i<<endl;
            }
        }
    }
    cout<<cnt;
}

