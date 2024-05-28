#include<bits/stdc++.h>
#define int long long
using namespace std;

struct st{
    int id, ele;
};

bool cmp(st ai, st bi){
    if(ai.ele == bi.ele){
        return ai.id < bi.id;
    }
    return ai.ele > bi.ele;
}

main() {
    int n;
    cin>>n;
    vector<st>a(n+1);
    int s[n+2], l[n+2], r[n+2];
    s[0] = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s[i] = x;
        a[i].id = i;
        a[i].ele = x;
    }
    s[n+1] = 0;
    sort(a.begin()+1,a.end(),cmp);
    l[1] = 0;
    l[n] = s[n-1];
    l[n+1] = 0;
    r[0] = 0;
    r[1] = s[2];
    r[n] = 0;
    for(int i=2;i<n;i++){
        l[i] = i-1;
        r[i] = i+1;
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res += a[i].ele + s[l[a[i].id]] + s[r[a[i].id]];

        l[n+1] = 0;
        r[0] = 0;
        //s[a[i].id]=0;
        l[r[a[i].id]] = l[a[i].id];
        r[l[a[i].id]] = r[a[i].id];

    }
    cout<<res;
}
