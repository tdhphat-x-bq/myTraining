#include<bits/stdc++.h>
#define int long long
#define N 1000006
using namespace std;

int p[N+1];

void sieve() {
    for(int i=0;i<=N;i++)p[i] = 1;

    p[0] = p[1] = 0;

    for(int i=2;i<=sqrt(N); i++){
        if(p[i] == 1){
            for(int j = i*i;j<=N;j+=i){
                p[j] = 0;
            }
        }
    }
}

main() {
    sieve();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ntmax.inp","r",stdin);
    freopen("ntmax.out","w",stdout);

    string t;
    cin>>t;

    vector<int>a;
    string s = "";
    int P = 0, cnt = 0;
    for(char c:t){
        if(isdigit(c)){
            cnt++;
            s += c;
        }
        else{
            if(!s.empty()){
                int tmp = stoll(s);
                a.push_back(tmp);
            }
            s = "";
        }
    }
    if(!s.empty()){
        int tmp = stoll(s);
        a.push_back(tmp);
    }
    cout<<cnt<<endl;
    for(int x:a){
        if(p[x] == 1){
            P=max(P,x);
        }
    }
    cout<<P;
}

