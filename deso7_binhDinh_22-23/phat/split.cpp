#include <iostream>
using namespace std;
const int li=1e3+1;
int dp[li][li];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("split.inp","r",stdin);
    freopen("split.out","w",stdout);
    string s,x;
    int n,m,k; cin>>n>>m>>k;
    cin >> s >> x;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s[i-1]==x[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            //cout << dp[i][j];
        }
        //cout << endl;
    }
    dp[n][m]= dp[n][m]==0 ? -1 :dp[n][m];
    cout << dp[n][m];
    return 0;
}
